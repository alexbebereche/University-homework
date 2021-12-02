#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
struct Reteta {
	unsigned int nrReteta;
	char* numeMedic;
	unsigned char nrMed;
	char** denumiriMed;
	float*preturi;
    unsigned char* cantitati;
	unsigned char* procenteVanzare;
	
	
};
struct NodD{
	Reteta info;
	NodD*prev, *next;
};
struct ListaDubla {
	NodD*prim, *ultim;
};
ListaDubla inserareNodSfarsit(ListaDubla lst, Reteta r)
{
	NodD * nou;
	nou = (NodD*)malloc(sizeof(NodD));
	nou->info = r;
	nou->next = 0;
	nou->prev = lst.ultim;

	if (!lst.prim) 
		lst.prim = lst.ultim = nou; 
	else {
		lst.ultim->next = nou;
		lst.ultim = nou;
	}

	return lst;
}
void afisareListaDubla(ListaDubla lst) {
	NodD* temp = lst.prim;
	while (temp != NULL) {
		printf("\nNr reteta- %d, medic: %s,nr med-%d",temp->info.nrReteta,temp->info.numeMedic, temp->info.nrMed);
		for (int i = 0; i < temp->info.nrMed; i++)
		{
			printf(", %s,pret- %f cantitate %d procent %d", temp->info.denumiriMed[i], temp->info.preturi[i], temp->info.cantitati[i], temp->info.procenteVanzare[i]);
		}
	
		temp = temp->next;
	}
}
void afisareListaDublaInvers(ListaDubla lst) {
	NodD* temp = lst.ultim;
	while (temp != NULL) {
		printf("\nNr reteta- %d, medic: %s,nr med-%d", temp->info.nrReteta, temp->info.numeMedic, temp->info.nrMed);
		for (int i = 0; i < temp->info.nrMed; i++)
		{
			printf(", %s,pret- %f cantitate %d procent %d", temp->info.denumiriMed[i], temp->info.preturi[i], temp->info.cantitati[i], temp->info.procenteVanzare[i]);
		}

		temp = temp->prev;
	}
}
float incasariMedicament(ListaDubla lst, char*denumireMedicament) {
	NodD*temp = lst.prim;
	float suma = 0;
	while (temp != NULL) {
		if (temp->info.nrMed != 0) {
			for (int i = 0; i < temp->info.nrMed; i++) {
				if (strcmp(temp->info.denumiriMed[i], denumireMedicament) == 0) {
					
					//float reducere= temp->info.cantitati[i]*temp->info.preturi[i]*temp->info.procenteVanzare[i]*0.01;
					suma += temp->info.cantitati[i] * temp->info.preturi[i];
				}
			}
		}temp = temp->next;
	}
	return suma;
	
}
float valoareCompensata(ListaDubla lst, char*denumireMedicament) {
	NodD*temp = lst.prim;
	float suma = 0;
	while (temp != NULL) {
		if (temp->info.nrMed != 0) {
			for (int i = 0; i < temp->info.nrMed; i++) {
				if (strcmp(temp->info.denumiriMed[i], denumireMedicament) == 0) {

					//float reducere= temp->info.cantitati[i]*temp->info.preturi[i]*temp->info.procenteVanzare[i]*0.01;
					suma += temp->info.cantitati[i] * temp->info.preturi[i];
				}
			}
		}temp = temp->next;
	}
	return suma;

}

void inserareVect2(ListaDubla lst, int&nr, Reteta**vect) {
	NodD*temp = lst.prim;

	nr = 0;
	while (temp != NULL) {
		nr++;
		temp = temp->next;
	}
	temp = lst.prim;
	int i = 0;

		while (temp!= NULL) {
			vect[i]=(Reteta*)malloc(sizeof(Reteta)*1);
			vect[i]->nrReteta = temp->info.nrReteta;
			vect[i]->numeMedic = (char*)malloc(sizeof(char)*(strlen(temp->info.numeMedic) + 1));
			strcpy(vect[i]->numeMedic, temp->info.numeMedic);
			vect[i]->nrMed = temp->info.nrMed;
			printf("\n%d %s %d", vect[i]->nrReteta, vect[i]->numeMedic, vect[i]->nrMed);
			vect[i]->denumiriMed = (char**)malloc(sizeof(char*)*temp->info.nrMed);
			vect[i]->preturi = (float*)malloc(sizeof(float)*temp->info.nrMed);
			vect[i]->cantitati = (unsigned char*)malloc(sizeof(unsigned char)*(temp->info.nrMed));
			vect[i]->procenteVanzare = (unsigned char*)malloc(sizeof(unsigned char)*(temp->info.nrMed));
			for (int j = 0; j <= temp->info.nrMed - 1; j++) {
				vect[i]->denumiriMed[j] = (char*)malloc(sizeof(char)*(strlen(temp->info.denumiriMed[j]) + 1));
				strcpy(vect[i]->denumiriMed[j], temp->info.denumiriMed[j]);
				printf(" %s ", vect[i]->denumiriMed[j]);

			}
			for (int j = 0; j <= temp->info.nrMed - 1; j++) {
				vect[i]->preturi[j] = temp->info.preturi[j];
				printf(" %5.2f ", vect[i]->preturi[j]);
			}
			for (int j = 0; j <= temp->info.nrMed - 1; j++) {
				vect[i]->cantitati[j] = temp->info.cantitati[j];
				printf(" %d ", vect[i]->cantitati[j]);
			}
			for (int j = 0; j <= temp->info.nrMed - 1; j++) {
				vect[i]->procenteVanzare[j] = temp->info.procenteVanzare[j];
				printf(" %d ", vect[i]->procenteVanzare[j]);
			}

			temp = temp->next;
			i++;

		}

	//return vect;

}
void afisareVect(Reteta**vect,int nr) {
	printf("\n %d", nr);
	for (int i =0; i <nr; i++) {

		printf("\n%d %s %d ",vect[i]->nrReteta,vect[i]->numeMedic,vect[i]->nrReteta);
		for (int j = 0; j <= vect[i]->nrMed - 1; j++) {
			printf(" %s ",vect[i]->denumiriMed[j]);

		}
		for (int j = 0; j <= vect[i]->nrMed - 1; j++) {
			printf(" %5.2f ", vect[i]->preturi[j]);
		}
		for (int j = 0; j <= vect[i]->nrMed - 1; j++) {

			printf(" %d ", vect[i]->cantitati[j]);
		}
		for (int j = 0; j <= vect[i]->nrMed - 1; j++) {

			printf(" %d ", vect[i]->procenteVanzare[j]);
		}
	}
}

int cantitate(ListaDubla lst, char*denumireMed) {
	NodD*temp = lst.prim;
	float cant = 0;
	while (temp != NULL) {
		if (temp->info.nrMed != 0) {
			for (int i = 0; i < temp->info.nrMed; i++) {
				if (strcmp(temp->info.denumiriMed[i], denumireMed) == 0) {

					//float reducere= temp->info.cantitati[i]*temp->info.preturi[i]*temp->info.procenteVanzare[i]*0.01;
					cant += temp->info.cantitati[i];
				}
			}
			temp = temp->next;
		}
	}
	return cant;
}
ListaDubla stergereStudentDbl(ListaDubla lstD) { // stergere primul nod din lista dubla (fara salvare/extragere student)
	NodD * tmp = lstD.prim;

	if (tmp) { // exista cel putin un nod in lista dubla
		lstD.prim = lstD.prim->next;
		if (lstD.prim)
			lstD.prim->prev = 0;
		else {
			// exista un singur nod in lista
			lstD.ultim = 0;
		}

		free(tmp->info.numeMedic); // dezalocare nume student (nivel 3 de indirectare)
			// dezalocare locatie de tip Student (nivel 2 de indirectare)
		free(tmp);			// dealocare nod lista dubla (nivel 1 de indirectare)
	}

	return lstD;
}
float valoareCompensata(Reteta**vect,int nr) {
	float reducere = 0;
	for (int i = 0; i < nr - 1; i++) {
		for (int j = 0; j < vect[i]->nrMed - 1; j++) {
			reducere= vect[i]->cantitati[j] *vect[i]->preturi[j] * vect[i]->procenteVanzare[j] * 0.01;
		}
	}
	return reducere;
}
void main()
{
	FILE* f;
	f = fopen("Retete.txt", "r");
	char buffer[1200];
	char* token;
	Reteta r;
	ListaDubla lst;
	lst.prim = lst.ultim = NULL;
	while (fgets(buffer, sizeof(buffer), f))
	{
		token = strtok(buffer, ",");
		r.nrReteta = atoi(token);
	   

		token = strtok(NULL, ",");
		r.numeMedic = (char*)malloc(sizeof(char)*(strlen(token) + 1));
		strcpy(r.numeMedic, token);

		token = strtok(NULL, ",");
		r.nrMed = atoi(token);
	
		r.denumiriMed = (char**)malloc(sizeof(char*) * (strlen(token) + 1));
		for (int i = 0;i< r.nrMed; i++) {
			token = strtok(NULL, ",");
			r.denumiriMed[i] = (char*)malloc(sizeof(char)*(strlen(token) + 1));
			strcpy(r.denumiriMed[i], token);
		}
		//token = strtok(NULL, ",");
		r.preturi = (float*)malloc(sizeof(float)*(strlen(token) + 1));
		for (int i = 0; i < r.nrMed; i++) {
			token = strtok(NULL, ",");
			r.preturi[i] = atof(token);

		}

		r.cantitati = (unsigned char*)malloc(sizeof(unsigned char)*(strlen(token) + 1));
		for (int i = 0; i < r.nrMed; i++) {
			token = strtok(NULL, ",");
			r.cantitati[i] = atoi(token);

		}
		r.procenteVanzare = (unsigned char*)malloc(sizeof(unsigned char)*(strlen(token) + 1));
		for (int i = 0; i < r.nrMed; i++) {
			token = strtok(NULL, ",");
			r.procenteVanzare[i] = atoi(token);

		}
	
		

		
		lst = inserareNodSfarsit(lst, r);

	}
	afisareListaDubla(lst);
	char denumireMed[] = "Paracetamol";
	//afisareListaDublaInvers(lst);
	float suma = incasariMedicament(lst, denumireMed);
	printf("\nIncasarile pt medicament sunt: %f", suma);
	int cant = cantitate(lst, denumireMed);
	printf("\nIncasarile pt medicament sunt: %d", cant);

	
	printf("\nVECTOR\n");
	Reteta**vect=(Reteta**)malloc(sizeof(Reteta*)*4);
	
	int nr =0;
	printf("\n----------------");
	inserareVect2(lst, nr,vect);

	//printf("\nlungime vect: %d\n", nr);
	afisareVect(vect, nr);
	float reducere = 0;
	reducere = valoareCompensata(vect, nr);
	printf("\n%5.2f", reducere);
	while (lst.prim)
	{
		lst = stergereStudentDbl(lst);
	}
	afisareListaDubla(lst);
	fclose(f);

	

}