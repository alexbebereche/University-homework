#include "assignment2.h"
#include <iostream>
using namespace std;

//aici se implementeaza metodele

/*
input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- numarul de elemente din vector ce sunt mai mari sau egale cu valoarea data
*/

int numarElementeMaiMari(int* valori, int nrValori, int valoarePrag) {

	int i, c = 0;
	for (i = 0; i < nrValori; i++)
		if (valori[i] >= valoarePrag)
			c++;

	return c;
}
/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou (creat in HEAP) ce contine toate elementele mai mari sau egale cu valoarea prag
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

int* filtrareElementeMaiMari(int* valori, int nrValori, int valoarePrag) {

	int* vectorMareEgal;
	int c, i;
	c = numarElementeMaiMari(valori, nrValori, valoarePrag);
	vectorMareEgal = new int[c];

	if (c == 0)
	{
		vectorMareEgal = NULL;
		return vectorMareEgal;
	}
	else {
		c = 0;
		for (i = 0; i < nrValori; i++)
			if (valori[i] >= valoarePrag) {
				vectorMareEgal[c] = valori[i];
				c++;


			}

	}
	return vectorMareEgal;


}


/*
Functia extrage dintr-un vector dat toate elementele ce sunt mai mari sau egale cu o valoare prag data

input
- un vector de numere intregi
- dimensiunea vectorului
- o valoare data
return
- un vector nou ce contine toate elementele mai mari sau egale cu valoarea prag; pointerul catre noul vector este primit in lista de argumente
- NULL daca in vectorul initial nu exista elemente mai mari sau egale
*/

void filtrareElementeMaiMari2(int* valori, int nrValori, int valoarePrag, int** valoriMaiMari) {

	*valoriMaiMari = filtrareElementeMaiMari(valori, nrValori, valoarePrag);

}

/*
Functia extrage elementul de pe pozitia index

input
- un vector de numere intregi
- dimensiunea vectorului
- indexul elementului (valoare pentru index trebuie sa fie validata) - daca valoarea pentru index nu este ok atunci se arunca o exceptie de tip
		ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
return
- elementul de pe pozitia index
- exceptie daca indexul nu este valid
*/

int getElement(int* valori, int nrValori, int index) {

	if ((index >= 0) && (index < nrValori))
		return valori[index];
	else
		throw new ExceptieAssignment2();

}


/*
Functia extrage un subvector din vectorul primit - [index_start, index_final]

input
- un vector de numere intregi
- dimensiunea vectorului
- index start si index final
	- daca valoarea pentru oricare index nu este ok atunci se arunca o exceptie de tip
		ExceptieAssignment2 cu "throw new ExceptieAssignment2()"
	- daca index start este egal cu index final atunci se returneaza un sub-vector ce contine elementul de pe pozitia index start
	- daca index start este mai mare decat index final atunci se arunca o exceptie de tip ExceptieAssignment2
return
- un vector nou
- dimensiunea vectorului nou este returnata prin referinta dimensiuneSubvector din lista de argumente
- exceptie daca indexul nu este valid
*/

int* slice(int* valori, int nrValori, int indexStart, int indexFinal, int& dimensiuneSubvector) {
	int i, c = 0;

	if (indexStart > indexFinal || indexStart < 0 || indexFinal < 0 || indexFinal >= nrValori)
		throw new ExceptieAssignment2();

	dimensiuneSubvector = indexFinal - indexStart + 1;
	int* vectorNou;
	vectorNou = new int[dimensiuneSubvector];
	if (dimensiuneSubvector == 1)
		vectorNou[0] = valori[indexStart];

	for (i = indexStart; i <= indexFinal; i++) {
		vectorNou[c] = valori[i];
		c++;
	}
	return vectorNou;


}

int main() {

	int vectorInitial[] = { 23,67,89,102,560,1000 };
	int nrElemente = 6;
	int* vector,*rezultat;
	int i;
	int rez;
	int dim;



//test 1
	
	cout << "normal test"<<"\nno of elements >=100 is: " << numarElementeMaiMari(vectorInitial, nrElemente, 100);
	cout << "\nlimit test" << "\nno of elements >=100 is: " << numarElementeMaiMari(vectorInitial, nrElemente, 102);
	cout << "\nout test" << "\nno of elements >=100 is: " << numarElementeMaiMari(vectorInitial, nrElemente, 2000);

	cout << "\n----------------------";
	
//test 2
	vector = filtrareElementeMaiMari(vectorInitial, nrElemente, 100);
	cout << "\nnormal test:100";
	cout << "\nthe elements are ";
	for(i=0; i< numarElementeMaiMari(vectorInitial, nrElemente, 100);i++)

	cout <<vector[i]<<" " ;

	// prag 2000
	vector = filtrareElementeMaiMari(vectorInitial, nrElemente, 2000);
	cout << "\n test:2000";
	cout << "\nthe elements are ";
	for (i = 0; i < numarElementeMaiMari(vectorInitial, nrElemente, 2000); i++)

		cout << vector[i] << " ";

	cout << "\n----------------------";
//test 3
	filtrareElementeMaiMari2(vectorInitial, nrElemente, 100,&rezultat);
	cout << "\nnormal test:100";
	cout << "\nthe elements are ";
	for (i = 0; i < numarElementeMaiMari(vectorInitial, nrElemente, 100); i++)

		cout << rezultat[i] << "  ";

	cout << "\nNULL test: 2000";
	cout << "\nthe elements are ";
	for (i = 0; i < numarElementeMaiMari(vectorInitial, nrElemente, 2000); i++)

		cout << rezultat[i] << "  ";

	cout << "\n----------------------";
//test 4
	cout << "\nnormal test:67";
	rez = getElement(vectorInitial, nrElemente, 1);
	cout <<"\nthe element from position with index 1: " << rez;


	cout << "\nnormal test: i";
	for (i = 0; i < nrElemente; i++)
	{
		rez = getElement(vectorInitial, nrElemente, i);
		cout << "\nthe element from position with index " << i << " is " << rez;
	}
	//EXCEPTIONS
	//cout << "\nnegative test:-1";
	//rez = getElement(vectorInitial, nrElemente, -1);
	//cout << "\nthe element from position with index -1: " << rez;

	/*cout << "\nlimit test:nr el";
	rez = getElement(vectorInitial, nrElemente, nrElemente);
	cout << "\nthe element from position with index 6: " << rez;

	cout << "\nbigger test:1000";
	rez = getElement(vectorInitial, nrElemente+1, 1000);
	cout << "\nthe element from position with index 1000: " << rez;*/

	int index;
	cout << "\nask for input:(exception here) ";
	cout << "\nchoose index:";
		cin >> index;
	cout << "\n";
	rez = getElement(vectorInitial, nrElemente, index);
	cout << "\nthe element from position with index 1000: " << rez; 


	cout << "\n----------------------";



//test 5

	cout << "\nstart index:";
	int indexStart;
	cin >> indexStart;
	cout << "\nfinal index:";
	int indexFinal;
	cin >> indexFinal;
	rezultat = slice(vectorInitial, nrElemente, indexStart, indexFinal, dim);
	cout << "\n subvector is: ";
	for (i = 0; i <= indexFinal - indexStart; i++)
		cout << rezultat[i] << " ";
		cout << " and the size is " << dim;

	
}
