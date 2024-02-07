#include "LibreriaSudoku.h"

int main(int argc, char *argv[]){
int s, id;
int scelta, continua = 1;
int riga = 9, colonna = 9; 
int griglia[riga][colonna], griglia2[riga][colonna];
int max = 3, min = 1, random;

	do{
	  	if(continua != 0) printf("\t\t\t\tBENVENUTO NEL SUDOKU\n\n\n");
		if(continua == 0) printf("\t\t\t\tProva a risolverlo\n\n\n");
		srand(time(NULL));
		random = rand() % (max-min+1)+min;
		id = 0;
		if(inserisciRandom(riga, colonna,griglia,griglia2,random, id) == 1){
			printf("Errore in apertura del file");
			return 1;
		}
		id ++;
		stampa(riga, colonna,griglia,griglia2);
		do{
			s=1;
			while(s == 1){
				s = 0;
				printf("\nScegli cosa fare:\n1) Stampa il Sudoku\n2) Inserisci un numero\n3) Elimina un numero\n4) Completa Sudoku\n5) Aiuto\n6) Cambia Sudoku\n7) Esci\n");
				scanf("%d",&scelta);
				if(scelta<1 || scelta>7){
					printf("\nScelta non valida");
					s = 1;
				}
			}
			switch (scelta){
				case 1:
				stampa(riga, colonna,griglia, griglia2);
				break;
				case 2:
				if(inserisciNumero(riga, colonna, griglia, griglia2) == 1) s = 1;
				break;
				case 3:
				rimuovi(riga, colonna,griglia,  griglia2);
				break;
				case 4:
				if(inserisciRandom(riga, colonna,griglia,griglia2,random, id) == 1){
					printf("Errore in apertura del file");
					return 1;
				}
				break;
				case 5:
				if(aiuto(riga, colonna,griglia,griglia2,random) == 1){
					printf("Errore in apertura del file");
					return 1;
				}
				break;
			}	
		
		}while(scelta != 6 && scelta != 4 && scelta != 7 && s != 1);
		
		if(scelta != 7 && scelta != 6){
			printf("\n\nSe vuoi risolvere un altro Sudoku digita 0, in caso contrario digita un altro numero\n");
			scanf("%d", &continua);
		}
	
		if(scelta == 6) continua = 0;
			
	}while(scelta != 7 && continua == 0);
	
	printf("\n\nArrivederci torna presto!");
	
	return 0;
	}
