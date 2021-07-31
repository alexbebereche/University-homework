#include "assignment.h";
#include <iostream>;


/*
	Sa se implementeze functia withdraw ce accepta doi parametri:
	- balance - reprezinta balanta contului curent
	- amount - reprezinta suma pe care dorim sa o extragem din cont
	Functia trebuie sa respecte urmatoarele cerinte:
	- La apelul functiei withdraw se va extrage din balanta suma dorita
	(Exemplu: In urma apelului withdraw(2000, 1000), balanta va avea valoarea 1000)
	- Daca balanta este negativa si se incearca efectuarea unei tranzactii
	se va aplica o penalizare de 10% asupra balantei, fara a efectua tranzactia
	(Exemplu: pentru o balanta de -1000, la incercarea efectuarii unei tranzactii
	balanta va avea valoarea de -1100).
	- Daca suma pe care dorim sa o extragem este negativa, se va efectua operatia de
	depunere. (pentru o balanta de 1000, la apelul functiei cu un amount de -200, vom
	obtine balanta cu valoarae 1200)
	- Daca suma dorita este mai mare decat valoarea balantei, nu se va efectua nicio operatie
	- Daca se va efectua operatia de withdraw cu amount 0, se va aplica o penalizare de 5% asupra balantei

*/

using namespace std;

void withdraw(double *balance, double amount) {


	if (*balance >= amount)
	{



		{
			if (amount < 0)
				*balance = *balance + (-amount); //depundere, se efectueaza(1)
			//if (amount > *balance)  //nicio operatie
			else

				//daca se efectueaza cu 0 amount(1)
				if (amount == 0)
					*balance = *balance - 0.05*(*balance);
				else
					*balance = *balance - amount;
		}



	}
	if (*balance < 0)
		*balance = *balance + 0.1*(*balance);   //nu se efectueaza tranzactia(0)


}

int main() {


	double balance;



	//negative balance
	balance = -1000;
	cout << "\nwithdraw(-1000, 2000): ";
	withdraw(&balance, 2000);
	cout << balance;

	//negative amount
	balance = 10;
	cout << "\nwithdraw(10, -10): ";
	withdraw(&balance, -10);
	cout << balance;

	//balance too low
	balance = 1000;
	cout << "\nwithdraw(1000, 2000): ";
	withdraw(&balance, 2000);
	cout << balance;

	//zero amount
	balance = 1000;
	cout << "\nwithdraw(1000,0 ): ";
	withdraw(&balance, 0);
	cout << balance;

	//right test
	balance = 2000;
	cout << "\nwithdraw(2000, 1000): ";
	withdraw(&balance, 1000);
	cout << balance;



	/*both are negative, i assume i add abs(amount) to balance instead of -10% and then add...
	balance = -1000;
	cout << "\nwithdraw(-1000, -2000): ";
	withdraw(&balance,(double) -2000);
	cout << balance;*/




}