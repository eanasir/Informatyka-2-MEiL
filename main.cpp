#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include "kwad.h"
double mojaFunkcja1(double x);
double mojaFunkcja2(double x);
double ca�kaAnalityczna_1(double a, double b);
double ca�kaAnalityczna_2(double a, double b);



int main() {
	FILE* f, * g;
	f = fopen("plik1.csv", "w");
	g = fopen("plik2.csv", "w");
	double a = 1; //g�rna granica ca�kowania
	double b = 5; //dolna granica ca�kowania
	int n = 10; //liczba punktow dziel�cych przedzia� ca�kowania
	int m = 4; //najwy�sza pot�ga dw�jki w ci�gu u�ywanym w p�tli
	double (*wskaznikFunkcja1)(double);//deklaracja wska�nika do pierwszej funkcji
	double (*wskaznikFunkcja2)(double);
	wskaznikFunkcja1 = &mojaFunkcja1;
	wskaznikFunkcja2 = &mojaFunkcja2;
	double bladCalkowania1 = fabs(ca�kaAnalityczna_1(a, b) - trapez(a, b, wskaznikFunkcja1, n));
	for (int i = 1; i <= m; i++) {
		int nCiag = pow(2, i);// n = 2,4,8,...,2^m
		fprintf(f, "%lf,%lf,%d\n", ca�kaAnalityczna_1(a, b), trapez(a, b, wskaznikFunkcja1, nCiag), nCiag);
		fprintf(g, "%lf,%lf,%d\n", ca�kaAnalityczna_1(a, b),simpson(a, b, wskaznikFunkcja1, nCiag), nCiag);
	}

}

double mojaFunkcja1(double x) {
	return 1.0 / (x * x);
}
double mojaFunkcja2(double x) {
	return 1.0/ (x);
}
double ca�kaAnalityczna_1(double a, double b) {
	return ((1.0 / a)- (1.0 / b));
}
double ca�kaAnalityczna_2(double a, double b) {
	return (log(a) - log(b));
}

