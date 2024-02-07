#include "LibreriaSudoku.h"

void stampa(int a1, int a2,int a[][a2], int a3[][a2]){

	char simbolo = '#';
	int i;
	int j;
	
	printf("\n\n\t\t");
	for(i = 0; i < a1; i++){
		printf("%d ", i);
		if(i == 2 || i == 5)	printf("  ");
	}
	printf("\n\n");

	for(i = 0; i < a1; i++){
		printf("\n\t%d\t", i);
		for(j = 0; j < a2; j++){
			if(a[i][j] == -1){
				printf("%c ",simbolo);
			}
			if(a[i][j] == a3[i][j] && a[i][j] != -1 && a3[i][j] != -1){
				colore(9);
				printf("%d ",a3[i][j]);
				colore(15);
			}
			
			if(a[i][j] != a3[i][j]){
				printf("%d ",a[i][j]);

			}
			if(j == 2 || j == 5)	printf("| ");
		}
		if(i == 2 || i == 5)	printf("\n\t\t----------------------");
		if(i == 8 || j == 8)	printf("\n");
	}
}

int inserisciNumero(int a1, int a2, int a[][a2], int a3[][a2]){
	
	int posy, posx, numero;
		
		
	printf("\n\nIn che casella vuoi inserire il numero?");
	scanf("%d-%d",&posy,&posx); 

	if(posx >= 9 || posx < 0 || posy >= 9 || posy < 0){

		printf("\nCoordinate non valide\n");
		return 1;
	}

	if(a[posy][posx]== 1 || a[posy][posx]== 2 || a[posy][posx]== 3 || a[posy][posx]== 4 || a[posy][posx]== 5 || a[posy][posx]== 6 || a[posy][posx]== 7 || a[posy][posx]== 8 || a[posy][posx]== 9){

		printf("\nValore gia inserito in questa posizione\n");
		return 1;
	}



	printf("\nDigitare il numero da inserire nella casella %d-%d\n", posy, posx);
	scanf("%d",&numero); 

 	if(numero >= 10 || numero <= 0 || numero >= 10 || numero <= 0){

		printf("\nValore non valido\n");
		return 1;
	}		

	
	if(controllo(a1, a2, a, numero, posy, posx)== 0){
	
		a[posy][posx] = numero;
		printf("\nNumero aggiunto con successo\n");
		
		if(controlloFinale(a1, a2, a) == 0){
			
			return 1;
		}
		
		return 0;
		
	}

	return 1;
}


int rimuovi(int a1, int a2, int a[][a2], int a3[][a2]){

	int posy, posx, count=0, count2 = 0, i, j;
	
	for(i = 0; i < a1; i++){
		for(j = 0; j < a2; j++){
			if(a[i][j] == -1){
				count++;
			}
			if(a3[i][j]==-1){
				count2++;
			}
		}
	}

	if(count < count2){
	
			
			
		printf("Scegli in quale posizione rimuovere il numero\n");
		scanf("%d-%d", &posy, &posx);
		
		if(posx >= 9 || posx < 0 || posy >= 9 || posy < 0){

			printf("\nCoordinate non valide\n");
			return 1;
		}		

		if(a[posy][posx]== -1){

			printf("\nQuesta cella e vuota\n");
			return 1;
		}
		
		if(a[posy][posx] == a3[posy][posx]){
			 printf("\nQuesto numero non e rimuovibile\n");
			return 1;
		}	
	
		a[posy][posx] = -1;
		printf("\nNumero rimosso con successo\n");
		return 0;

	}else{
	    printf("\nPrima inserisci un numero\n");
		return 1;
	}
}

static int controllo(int a1, int a2, int a[][a2], int n, int y, int x){
	int i, j;
	
	if(y>= 0 && y < 3 && x >= 0 && x < 3){
	
		for(i = 0; i < 3; i++){
			for(j = 0; j < 3; j++){

				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in alto a sinistra\n");
					
					return 1;
				}
			}
		}
	}

	if(y>= 0 && y < 3 && x >= 3 && x < 6){
		for(i = 0; i < 3; i++){
			for(j = 3; j < 6; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in alto al centro\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 0 && y < 3 && x >= 6 && x < 9){
		for(i = 0; i < 3; i++){
			for(j = 6; j < 9; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in alto a destra\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 3 && y < 6 && x >= 0 && x < 3){
		for(i = 3; i < 6; i++){
			for(j = 0; j < 3; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 al centro-sinistra\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 3 && y < 6 && x >= 3 && x < 6){
		for(i = 3; i < 6; i++){
			for(j = 3; j < 6; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 al centro-centro\n");
					
					return 1;
				}
			}
		}
	}
	if(y>= 3 && y < 6 && x >= 6 && x < 9){	
		for(i = 3; i < 6; i++){
			for(j = 6; j < 9; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 al centro-destra\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 6 && y < 9 && x >= 0 && x < 3){
		for(i = 6; i < 9; i++){
			for(j = 0; j < 3; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in basso a sinistra\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 6 && y < 9 && x >= 3 && x < 6){
		for(i = 6; i < 9; i++){
			for(j = 3; j < 6; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in basso al centro\n");
					
					return 1;
				}
			}
		}	
	}
	if(y>= 6 && y < 9 && x >= 6 && x < 9){
		for(i = 6; i < 9; i++){
			for(j = 6; j < 9; j++){
				if(a[i][j]== n){
					printf("\nValore gia ripetuto nella griglia 3x3 in basso a destra\n");
					
					return 1;
				}
			}
		}
	}
		for(i = 0; i < 9; i++){
			if(a[i][x] == n){
				printf("\nValore gia ripetuto nella colonna %d\n", x);
				
				return 1;
			}
			if(a[y][i] == n){
				printf("\nValore gia ripetuto nella riga %d\n", y);
				
				return 1;
			}
		}
	return 0;
}
static int controlloFinale(int a1, int a2, int a[][a2]){
	
	int count = 0, i, j;
	for(i = 0; i < a1; i++){
		for(j = 0; j < a2; j++){
			if(a[i][j]== 1 || a[i][j]== 2 || a[i][j]== 3 || a[i][j]== 4 || a[i][j]== 5 || a[i][j]== 6 || a[i][j]== 7 || a[i][j]== 8 || a[i][j]== 9){
				count ++;
			}
		}
	}
	if(count == 81){
		colore(2);
		printf ("\nComplimenti, hai vinto\n");
	    colore(15);
	    return 0;
	}
	return 1;	
}

static void colore(unsigned short colore)
{
	//GetStdHandle() puo recuperare uno standard input output o handle di errore
	//TD_OUTPUT_HANDLE	Il dispositivo di output standard. Inizialmente si tratta del buffer dello schermo della console attivo
	//handle è un riferimento astratto a una risorsa che viene utilizzata quando il software applicativo fa riferimento a blocchi di memoria o oggetti gestiti da un altro sistema come un database o un sistema operativo 
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    //Imposta gli attributi dei caratteri scritti nel buffer dello schermo della console
    SetConsoleTextAttribute(hCon,colore);
}
static void inizializza(int a1, int a2,int a[][a2], int a3[][a2]){
	
	int i , j;

	for(i = 0; i < a1; i++){
		for(j = 0; j < a2; j++){
			a[i][j] = -1;
			a3[i][j] = -1;
		}
	}	
}
//l errore è qua perche se termino con inserisci numero non mi svuota
int inserisciRandom(int a1, int a2, int a[][a2], int a3[][a2], int random, int id){
	
	int n = 11, i, num, riga = 0, j = 0;
    char s[n];
    FILE *pf;

	if(id == 0) inizializza(a1, a2, a, a3);

	if ((pf = fopen("LeggiSud.txt", "r")) == NULL) {
	
    	return 1;
	}
	else{

    	while (fgets(s, n, pf) != NULL){
      	
    		riga++;
    		if(random == 1 && riga >= 1 && riga <= 9 && id == 0
			   || random == 2 && riga >= 21 && riga <= 29 && id == 0 
			   || random == 3 && riga >= 41 && riga <= 49 && id == 0
			   || random == 1 && riga >= 11 && riga <= 19 && id == 1
			   || random == 2 && riga >= 31 && riga <= 39 && id == 1 
			   || random == 3 && riga >= 51 && riga <= 59 && id == 1){


	        	for(i = 0; i < n-2; i++){
	        		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
	        			num = (int)s[i]; 

	    				switch (num){
							case 49:
							num = 1;
							break;
							case 50:
							num = 2;
							break;
							case 51:
							num = 3;
							break;
							case 52:
							num = 4;
							break;
							case 53:
							num = 5;
							break;
							case 54:
							num = 6;
							break;
							case 55:
							num = 7;
							break;
							case 56:
							num = 8;
							break;
							case 57:
							num = 9;
							break;
						}
						a[j][i] = num;
						if(id == 0) a3[j][i] = num;								
					}
				}
				j++;
			}
    	}
	}
	fclose(pf);
	if(id == 1){
		stampa(a1, a2, a, a3);
		controlloFinale(a1, a2, a);
	} 
	return 0;
}

int aiuto(int a1, int a2, int a[][a2], int a3[][a2], int random){
	
	int n = 11, i, riga = 0, num, j = 0, v = 1;
    char s[n];
    FILE *pf;

	if ((pf = fopen("LeggiSud.txt", "r")) == NULL) {
	
    	return 1;
	}
	else{
    	while (v == 1){
      		fgets(s, n, pf);
      		riga ++;
    		if(random == 1 && riga >= 11 && riga <= 19
			   || random == 2 && riga >= 31 && riga <= 39 
			   || random == 3 && riga >= 51 && riga <= 59){

				i = 0;
				
	        	while(i != 9 && v == 1){
	        		if(a[j][i] == -1){
		        		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'){
		        			num = (int)s[i]; 
	
		    				switch (num){
								case 49:
								num = 1;
								break;
								case 50:
								num = 2;
								break;
								case 51:
								num = 3;
								break;
								case 52:
								num = 4;
								break;
								case 53:
								num = 5;
								break;
								case 54:
								num = 6;
								break;
								case 55:
								num = 7;
								break;
								case 56:
								num = 8;
								break;
								case 57:
								num = 9;
								break;
							}
								v = 0;
								printf("nella posizione %d-%d va messo il numero %d",j,i,num);
							} 
					}
					i++;								
				}
				j++;
			}
    	}
	}
	fclose(pf);
	return 0;
}
