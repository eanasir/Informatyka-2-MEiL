#define _CRT_SECURE_NO_WARNINGS 
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "winbgi2.h"
#include "nonlin.h"


double fun(double x);
double pochodna(double x);
double siecz(double x1, double x2, double (*pf)(double), double eps, int* iter);
double newton(double x, double(*pf)(double), double(*poch)(double), double eps, int* iter);

void main()
{
	FILE* f,* g,*h;
	f = fopen("bisekcja.txt", "w");
	g = fopen("sieczna.txt", "w");
	h = fopen("newton.txt", "w");
	double eps = 1;
	int iter;
	int* i_iter;
	i_iter = &iter;
	
	double a = 0;
	double c = 0.1;
	double b = M_PI;
	for (int i = -51; i < 0;i++) {
		eps = 1 * pow(2, i);
		printf("%lf %d\n\r", bisec(a, b, fun, eps, i_iter), iter);
		fprintf(f, " %d %.16lf\n", iter, eps);

	}
	printf(":3\n\n");
	for (int i = -51; i < 0;i++) {
		eps = 1 * pow(2, i);
		printf("%lf %d\n\r", siecz(a, b, fun, eps, i_iter), iter);
		fprintf(g, " %d %.16lf\n", iter,eps);
	}
	printf(":3\n\r");
	for (int i = -51; i < 0;i++) {
		eps = 1 * pow(2, i);
		printf("%lf %d\n\r", newton(c,fun,pochodna, eps, i_iter), iter);
		fprintf(h, "%d %.16lf\n",iter,eps);
	}

	fclose(f);
	fclose(g);
}
double siecz(double x1,double x2, double (*pf)(double), double eps, int* iter) //funkcja obliczajaca pierwiastek metoda stycznych
{
	double pom;
	*iter = 0;
	while (fabs(pf(x1)) > eps && fabs(x2 - x1) > eps)
	{
		pom = x2 - (pf(x2) * (x2 - x1)) / (pf(x2) - pf(x1));
		x1 = x2;
		x2 = pom;
		(*iter)++;
	}
	return x1;
}
double newton(double x, double(*pf)(double), double(*poch)(double),double eps, int* iter) //funkcja obliczajaca pierwiastek metoda stycznych
{
	double dx = 1;
	*iter = 0;
	while (fabs(x) > eps && fabs(dx) > eps)
	{
		dx = (pf(x) / poch(x));
		x = x - dx;
		(*iter)++;
	}
	return x;
}

double fun(double x) {
	return cos(x) - x;
}
double pochodna(double x) {
	return -1.0 * sin(x) - 1.0;
}