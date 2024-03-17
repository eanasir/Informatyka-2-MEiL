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
	f = fopen("plik1.txt", "w");
	g = fopen("plik2.csv", "w");
	double a = 0; //górna granica ca³kowania
	double b = 4*atan(1); //dolna granica ca³kowania
	int n = 10; //liczba punktow dziel¹cych przedzia³ ca³kowania
	int m = 16; //najwy¿sza potêga dwójki w ci¹gu u¿ywanym w pêtli
	double (*wskaznikFunkcja1)(double);//deklaracja wskaŸnika do pierwszej funkcji
	double (*wskaznikFunkcja2)(double);
	wskaznikFunkcja1 = &mojaFunkcja1;
	wskaznikFunkcja2 = &mojaFunkcja2;
	double bladCalkowania1 = fabs(ca³kaAnalityczna_1(a, b) - trapez(a, b, wskaznikFunkcja1, n));
	for (int i = 1; i <= m; i++) {
		int nCiag = pow(2, i);// n = 2,4,8,...,2^m
		fprintf(f, "%d %4.16lf %4.16lf %4.16lf %4.16lf\n", nCiag, trapez(a, b, wskaznikFunkcja1, nCiag), fabs(2 - trapez(a, b, wskaznikFunkcja1, nCiag)), simpson(a, b, wskaznikFunkcja1, nCiag), fabs(2 - simpson(a, b, wskaznikFunkcja1, nCiag)));
		fprintf(g, "%4.16lf,%4.16lf,%d\n", ca³kaAnalityczna_1(a, b),simpson(a, b, wskaznikFunkcja1, nCiag), nCiag);
	}

}

double mojaFunkcja1(double x) {
	return sin(x);
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
double gauss(double (*pf)(double)) {
	double xi[] = { -0.9061798459386639927976269, -0.5384693101056830910363144, 0.0,0.5384693101056830910363144 ,0.9061798459386639927976269 };
	double wi[] = { 0.2369268850561890875142640 , 0.4786286704993664680412915 ,0.5688888888888888888888889 ,0.478628670499366468041291 ,0.2369268850561890875142640};

}
