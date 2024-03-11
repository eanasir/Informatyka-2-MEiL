#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include "kwad.h"
double mojaFunkcja1(double x);
double mojaFunkcja2(double x);
double ca³kaAnalityczna_1(double a, double b);
double ca³kaAnalityczna_2(double a, double b);



int main() {
	FILE* f, * g;
	f = fopen("plik1.csv", "w");
	g = fopen("plik2.csv", "w");
	double a = 1; //górna granica ca³kowania
	double b = 5; //dolna granica ca³kowania
	int n = 10; //liczba punktow dziel¹cych przedzia³ ca³kowania
	int m = 4; //najwy¿sza potêga dwójki w ci¹gu u¿ywanym w pêtli
	double (*wskaznikFunkcja1)(double);//deklaracja wskaŸnika do pierwszej funkcji
	double (*wskaznikFunkcja2)(double);
	wskaznikFunkcja1 = &mojaFunkcja1;
	wskaznikFunkcja2 = &mojaFunkcja2;
	double bladCalkowania1 = fabs(ca³kaAnalityczna_1(a, b) - trapez(a, b, wskaznikFunkcja1, n));
	for (int i = 1; i <= m; i++) {
		int nCiag = pow(2, i);// n = 2,4,8,...,2^m
		fprintf(f, "%lf,%lf,%d\n", ca³kaAnalityczna_1(a, b), trapez(a, b, wskaznikFunkcja1, nCiag), nCiag);
		fprintf(g, "%lf,%lf,%d\n", ca³kaAnalityczna_1(a, b),simpson(a, b, wskaznikFunkcja1, nCiag), nCiag);
	}

}

double mojaFunkcja1(double x) {
	return 1.0 / (x * x);
}
double mojaFunkcja2(double x) {
	return 1.0/ (x);
}
double ca³kaAnalityczna_1(double a, double b) {
	return ((1.0 / a)- (1.0 / b));
}
double ca³kaAnalityczna_2(double a, double b) {
	return (log(a) - log(b));
}

