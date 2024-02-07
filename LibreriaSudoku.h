#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>
#include <time.h>

void stampa(int a1, int a2,int a[][a2], int a3[][a2]);
static void inizializza(int a1, int a2,int a[][a2], int a3[][a2]);
int inserisciNumero(int a1, int a2, int a[][a2], int a3[][a2]);
int rimuovi(int a1, int a2, int a[][a2], int a3[][a2]);
static int controllo(int a1, int a2, int a[][a2], int n, int y, int x);
static int controlloFinale(int a1, int a2, int a[][a2]);
static void colore(unsigned short color);
int inserisciRandom(int a1, int a2, int a[][a2], int a3[][a2], int random, int id);
int aiuto(int a1, int a2, int a[][a2], int a3[][a2], int random);
