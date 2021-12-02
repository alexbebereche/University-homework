#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 128
#define ARRAY_SIZE 100
struct Rezervare {
	unsigned int idRezervare;
	char*denumireHotel;
	unsigned char nrHotel;
	unsigned char nrCamereRezervate;
	char*numeClient;
	char*perioadaRezervarii;
	float pret;
};
int positionHashFunction(char *str, int size) {
	int sum = 0;
	for (int i = 0; i < strlen(str); i++)
		sum += str[i];

	return sum % size;
}
char inserareLinearPRobing(Rezervare* ht, int size, Rezervare r) {
	if (ht != NULL) {
		int pos = positionHashFunction(r.denumireHotel, size); 
		printf("Pozitia: %d for %s -- id: %d nrCamere: %d nrCamere rez: %d, client %s, perioada: %s, %5.2f\n", pos, r.denumireHotel,r.idRezervare,r.nrHotel,r.nrCamereRezervate,r.numeClient,r.perioadaRezervarii,r.pret);

		
		char inserted = 0; 
		for (int i = pos; i < size && !inserted; i++) {
			if (ht[i].denumireHotel == NULL) { 
				ht[i] = r;
				inserted = 1;
			}
		}

		return inserted;
	}

	return -1;
}
int gradOcupare(Rezervare*ht,int size, char*denumireHotel, char*perioada,int nrCamere) {
	int gradOcup = 0;
	if (ht) {
		int pos = positionHashFunction(denumireHotel, size);
		char found = 0;
		for (int i = pos; i < size && !found; i++)
		{
			if (ht[i].denumireHotel == 0)
				found = -1; 
			else if ((strcmp(ht[i].denumireHotel, denumireHotel) == 0)&& (strcmp(ht[i].perioadaRezervarii, perioada) == 0))
			{
				gradOcup += ht[i].nrCamereRezervate;
			}
		}

		
	}
	return gradOcup;
}
void inserareVect(Rezervare*ht, int size, Rezervare**vect,char*denumireClient,char*denumireHotel,int&nr) {
	if (ht) {
		int pos = positionHashFunction(denumireHotel, size);
		char found = 0;
		int j = 0;
		nr = 0;
		for (int i = pos; i < size && !found; i++)
		{
			if (ht[i].denumireHotel == 0)
				found = -1;
			else if ((strcmp(ht[i].denumireHotel, denumireHotel) == 0) && (strcmp(ht[i].numeClient, denumireClient) == 0))
			{
				vect[j] = (Rezervare*)malloc(sizeof(Rezervare) * 1);
				vect[j]->idRezervare = ht[i].idRezervare;
				vect[j]->denumireHotel = (char*)malloc(sizeof(char)*(strlen(ht[i].denumireHotel) + 1));
				strcpy(vect[j]->denumireHotel, ht[i].denumireHotel);
				vect[j]->nrHotel = ht[i].nrHotel;
				vect[j]->nrCamereRezervate = ht[i].nrCamereRezervate;
				vect[j]->numeClient = (char*)malloc(sizeof(char)*(strlen(ht[i].numeClient) + 1));
				strcpy(vect[j]->numeClient, ht[i].numeClient);
				vect[j]->perioadaRezervarii = (char*)malloc(sizeof(char)*(strlen(ht[i].perioadaRezervarii) + 1));
				strcpy(vect[j]->perioadaRezervarii, ht[i].perioadaRezervarii);
				vect[j]->pret = ht[i].pret;
				

				
				
			}
			nr++;
			j++;
		}


	}
	
	

}
float calculIncasari(Rezervare**vect, char*perioada) {
	float incasari = 0;
	for (int i = 0; i < 2; i++) {
		if (strcmp(vect[i]->perioadaRezervarii, perioada) == 0) {
			incasari = vect[i]->nrCamereRezervate*vect[i]->pret;
		}
	}
	return incasari;
}
int nrCamereRezervate(Rezervare*ht, char*numeClient, int size) {
	int gradOcup = 0;
	if (ht) {
		char found = 0;
		for (int i = 0; i < size && !found; i++)
		{
			if (ht[i].denumireHotel != NULL) {
				if ((strcmp(ht[i].numeClient, numeClient) == 0))
				{

					gradOcup += ht[i].nrCamereRezervate;
				}
			}
			
		
		}


	}
	return gradOcup;
}
void main() {
	FILE* f;
	f = fopen("Rezervari.txt", "r");
	char buffer[1200];
	char* token;
	Rezervare r;
	
	Rezervare * HTable; // vector alocat la run-time
	int size = ARRAY_SIZE;

	// allocation of the hash table
	HTable = (Rezervare*)malloc(size * sizeof(Rezervare));
	for (unsigned int i = 0; i < size; i++) {
		HTable[i].denumireHotel = NULL; // initially, the all positions are marked as "available"
		HTable[i].numeClient = NULL;
	}

	while (fgets(buffer, sizeof(buffer), f))
	{
		token = strtok(buffer, ",");
		r.idRezervare = atoi(token);


		token = strtok(NULL, ",");
		r.denumireHotel = (char*)malloc(sizeof(char)*(strlen(token) + 1));
		strcpy(r.denumireHotel, token);

		token = strtok(NULL, ",");
		r.nrHotel = atoi(token);

		token = strtok(NULL, ",");
		r.nrCamereRezervate = atoi(token);

		token = strtok(NULL, ",");
		r.numeClient = (char*)malloc(sizeof(char)*(strlen(token) + 1));
		strcpy(r.numeClient, token);

		token = strtok(NULL, ",");
		r.perioadaRezervarii = (char*)malloc(sizeof(char)*(strlen(token) + 1));
		strcpy(r.perioadaRezervarii, token);


		token = strtok(NULL, ",");
		r.pret = atof(token);
		char insert = inserareLinearPRobing(HTable, size, r);
		int newSize = size;

		while (!insert) {

			Rezervare*newHTable;
			newSize += ARRAY_SIZE;
			newHTable = (Rezervare*)malloc(newSize * sizeof(Rezervare));

			for (int i = 0; i < newSize; i++) {
				newHTable[i].denumireHotel = NULL;
			}
			insert = 1;
			for (int i = 0; i < size && insert; i++) {
				if (HTable[i].denumireHotel)
					insert = inserareLinearPRobing(newHTable, newSize, HTable[i]);
			}

			if (!insert) {
				free(newHTable);
			}
			else {
				free(HTable);			
				HTable = newHTable;
				size = newSize;
				insert = inserareLinearPRobing(HTable, size, r);
			}

		}
	}
	char denumireHotel[] = "Central";
	char denumireHotel2[] = "Hotel Parc";
	char perioada[] = "2021.05.22";
	char perioada2[] = "2021.05.26";
	int gradOcup = 0;
	gradOcup = gradOcupare(HTable, size, denumireHotel2, perioada,40);
	printf("\nGradul de ocupare este %d\n", gradOcup);
	int nr;
	char denumireClient[] = "Ivan Cristina";
	char denumireClient2[] = "Popescu Maria";
	Rezervare**vect = (Rezervare**)malloc(sizeof(Rezervare*) * size);
	
	
	inserareVect(HTable, size, vect,denumireClient,denumireHotel,nr);
	for (int i = 0; i < nr-1; i++) {
		printf("\n %d %s nrCamere: %d, nrCamere rez: %d, client: %s, perioada: %s %5.2f", vect[i]->idRezervare,vect[i]->denumireHotel,
			vect[i]->nrHotel,vect[i]->nrCamereRezervate,vect[i]->numeClient,vect[i]->perioadaRezervarii,vect[i]->pret);
		
	}
	float incasari = 0;
	incasari = calculIncasari(vect, perioada2);
	printf("\nTotal incasari: %5.2f\n", incasari);
	
	int nrCamereREz = nrCamereRezervate(HTable, denumireClient2, size);
	printf("\nNr camere ocupate de client este %d\n", nrCamereREz);

	// dezalocare tabela de dispersie
	for (unsigned int i = 0; i < size; i++) {
		if (HTable[i].denumireHotel) {
			free(HTable[i].denumireHotel); 
			free(HTable[i].numeClient);
		}
	}
	free(HTable); // dezalocare vector de rezervari
	HTable = NULL;
	for (int i = 0; i < nr-1; i++) {
		if (vect[i]->denumireHotel) {
			free(vect[i]->denumireHotel);
			free(vect[i]->numeClient);
		}
	}
	free(vect);
	vect = NULL;
}