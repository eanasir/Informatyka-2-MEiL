#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>  
#include <math.h>  
#include <stdlib.h>  
#include <time.h>  
#include "winbgi2.h"

void yWallBounce(double* x, double* y, double* xV, double* yV, int N, double x_max, double x_min, double y_wall)
{
    for (int i = 0; i < N; i++)
    {
        if ((y[i] <= (y_wall + 14.0)) && (y[i] >= (y_wall - 14.0)) && (x[i] >= x_min) && (x[i] <= x_max))
        {
            yV[i] = -0.95 * yV[i];
        }
    }
}
int checkballtubestop(double* x, double* y, int N, int a, int b)
{
    int z = 0;
    for (int i = 0; i < N; i++)
    {
        if (x[i] > a && x[i] < b && y[i] < 75)
            z = 1;

    }

    return z;
}
void backToBox(double* x, double* y, double* xV, double* yV, int N)
{
    for (int i = 0; i < N; i++)
    {

        if ((x[i] <= 50.0) || (y[i] >= 780.0) || (x[i] >= 580.0) || (y[i] <= 50) || ((x[i] > 50.0) && (x[i] <= 188.0) && (y[i] > 50.0) && (y[i] <= 200.0)) || ((x[i] >= 488.0) && (x[i] < 580.0) && (y[i] > 50.0) && (y[i] <= 200.0)))
        {
            x[i] = 75.0;
            y[i] = 640.0;

        }
    }
}
void result(double* x, double* y, int n, int* tabwyn, int* nr)
{

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (x[i] > 190 && x[i] < 490 && y[i] < 65)
        {
            tabwyn[j] = nr[i];
            j++;
        }


    }
    printf("---------------------------------------------------------------------------------------------------\n");
    printf("\tWYGRANE LICZBY TO:");
    for (int k = 0; k < 6; k++)
        printf("\t%d", tabwyn[k]);
    printf("\n---------------------------------------------------------------------------------------------------");
}

void checkballtube2(double* x, double* y, double* xV, double* yV, int N, int a, int b)
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] > a && x[i] < b && y[i] < 340)
            line(a, 350, b, 350);
        yWallBounce(x, y, xV, yV, N, b, a, 350);

    }
}
void line3()
{
    setcolor(RED);
    line(190, 350, 490, 350);
}
void checkballtube(double* x, double* y, double* xV, double* yV, int N, int a, int b)
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] > a && x[i] < b && y[i] < 340)
            yV[i] = yV[i] - 0.01;
    }

}
void linetube(double* x, double* y, double* xV, double* yV, int N, int a, int b, int* check)
{
    for (int i = 0; i < N; i++)
    {
        if (x[i] > a && x[i] < b && y[i] < 65)
        {
            yV[i] = 0;
            xV[i] = 0;
            setcolor(RED);
            line(a, 85, b, 85);
            yWallBounce(x, y, xV, yV, N, b, a, 85);
            line(a, 91, b, 91);
            yWallBounce(x, y, xV, yV, N, b, a, 91);
            *check = 1;

        }

    }

}
void line1()

{

    setcolor(RED);
    line(50, 200, 50, 780);
    line(50, 780, 580, 780);
    line(580, 780, 580, 200);
    line(50, 200, 188, 200);
    line(488, 200, 580, 200);
    line(185, 50, 491, 50);


    //pionowe linie od blokady z lewej  
    line(93, 200, 93, 600);
    line(99, 200, 99, 600);
    line(139, 200, 139, 600);
    line(145, 200, 145, 600);
    line(191, 200, 191, 600);
    line(185, 200, 185, 600);

    //pionowe linie od blokady z prawej  
    line(535, 200, 535, 600);
    line(541, 200, 541, 600);
    line(485, 200, 485, 600);
    line(491, 200, 491, 600);

    // linie poziome 
    line(93, 600, 99, 600);
    line(139, 600, 145, 600);
    line(185, 600, 191, 600);
    line(485, 600, 491, 600);
    line(535, 600, 541, 600);


    //pionowe linie od boksow  
    for (int i = 0; i <= 6; i++)
        line(185 + i * 50, 350, 185 + i * 50, 50);
    for (int i = 0; i <= 6; i++)
        line(191 + i * 50, 350, 191 + i * 50, 50);
    for (int i = 0; i <= 4; i++)
        line(235 + i * 50, 350, 241 + i * 50, 350);
}

void check0(int* check)

{

    for (int i = 0; i < 49; i++)
        check[i] = 0;

}



void circlerandom(int n, double* x, double* y, int* check, char string_text[], int* nr, int* color) {

    int z = 0;
    int max = 49;
    int min = 0;
    int L = max - min;
    int nr0;
    int i = 0;

    while (i < 30)
    {
        nr0 = rand() % L;
        if (check[nr0] == 0)
        {

            x[nr0] = 73 + n * 46;
            y[nr0] = 586 - z * 28.5;
            color[nr0] = i;
            if (n == 0)
            {

                setcolor(0.9);
            }
            if (n == 1)
            {

                setcolor(0.7);
            }

            if (n == 2)
            {

                setcolor(0.5);
            }

            circle(x[nr0], y[nr0], 14);

            sprintf(string_text, "%d", nr0);
            nr[nr0] = nr0;



            settextstyle(0, 0, 1);
            outtextxy(x[nr0] - 8.0, y[nr0] - 8.0, string_text);
            z = z + 1;
            if (z == 10)
            {
                z = 0;

                n = n + 1;
            }
            check[nr0] = 1;
            i++;
        }

    }

    while (i < 49)
    {
        nr0 = rand() % L;

        if (check[nr0] == 0)
        {
            color[nr0] = i;

            if (n == 3)
            {

                setcolor(0.3);
            }
            if (n == 4)
            {

                setcolor(0.1);
            }
            nr[nr0] = nr0;
            x[nr0] = 465 + (n - 2) * 46;
            y[nr0] = 586 - z * 28.5;
            circle(x[nr0], y[nr0], 14);
            sprintf(string_text, "%d", nr0);
            settextstyle(0, 0, 1);
            outtextxy(x[nr0] - 8.0, y[nr0] - 8.0, string_text);

            z = z + 1;
            if (z == 10)

            {

                z = 0;

                n = n + 1;

            }
            check[nr0] = 1;
            i++;
        }



    }

}

void display(double* x, double* y, int N, char string_text[], int* color)
{
    for (unsigned int i = 0; i < N; i++) {

        if (color[i] >= 0 && color[i] < 10)
            setcolor(0.9);
        if (color[i] >= 10 && color[i] < 20)
            setcolor(0.7);
        if (color[i] >= 20 && color[i] < 30)
            setcolor(0.5);
        if (color[i] >= 30 && color[i] < 40)
            setcolor(0.3);
        if (color[i] >= 40 && color[i] < 49)
            setcolor(0.1);
        circle(x[i], y[i], 14.0);
        sprintf(string_text, "%d", i);

        settextstyle(0, 0, 1);
        outtextxy(x[i] - 8.0, y[i] - 8.0, string_text);
    }
}

void addGravity(double* yV, int N)
{
    for (int i = 0; i < N; i++)
    {
        yV[i] = yV[i] + 0.00000981;
    }

}

void move(double* x, double* y, double* xV, double* yV, int N)
{
    for (int i = 0; i < N; i++)
    {
        x[i] += xV[i];
        y[i] += yV[i];
    }
}

void collideBall(double* x, double* y, double* xV, double* yV, int N)
{
    double distance_ij, C, dVx, dVy;
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            distance_ij = pow(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2), 0.5);
            if (distance_ij < 2 * 14.0) {
                C = ((x[i] - x[j]) * (xV[i] - xV[j]) + (y[i] - y[j]) * (yV[i] - yV[j])) / pow(distance_ij, 2);
                dVx = C * (x[j] - x[i]);
                dVy = C * (y[j] - y[i]);
                xV[i] = xV[i] + dVx;
                yV[i] = yV[i] + dVy;
                xV[j] = xV[j] - dVx;
                yV[j] = yV[j] - dVy;
            }
        }
    }
}


void xWallBounce(double* x, double* y, double* xV, double* yV, int N, double y_max, double y_min, double x_wall)
{
    for (int i = 0; i < N; i++)
    {

        if ((x[i] <= (x_wall + 14.0)) && (x[i] >= (x_wall - 14.0)) && (y[i] >= y_min) && (y[i] <= y_max))
        {
            xV[i] = -0.95 * xV[i];
        }
    }
}

void yNarrowWallBounce(double* x, double* y, double* xV, double* yV, int N, double x_max, double x_min, double y_wall)
{
    for (int i = 0; i < N; i++)
    {
        if ((y[i] <= (y_wall + 14.0)) && (y[i] >= (y_wall - 14.0)) && (x[i] >= (x_min - 13.0)) && (x[i] <= (x_max + 13.0)))
        {
            if (yV[i] <= 0) yV[i] = -0.95 * yV[i];

            if (yV[i] <= 0) yV[i] = 0.95 * yV[i];


        }
    }
}


void littleBlow(double* x, double* y, double* xV, double* yV, int N)
{
    for (int i = 0; i < N; i++)
    {

        if ((y[i] <= 800) && (y[i] >= 600) && (x[i] <= 188))
        {
            if ((i % 2) == 0)
                xV[i] = xV[i] + 0.00001;
            if ((i % 2) == 1)
                xV[i] = xV[i] - 0.00001;
        }
    }
    for (int i = 0; i < N; i++)
    {

        if ((y[i] <= 800) && (y[i] >= 600) && (x[i] >= 488))
        {
            if ((i % 2) == 1)
                xV[i] = xV[i] + 0.00001;
            if ((i % 2) == 0)
                xV[i] = xV[i] - 0.00001;
        }
    }
}


void mainBlow(double* x, double* y, double* yV, double* xV, int N)
{
    for (int i = 0; i < N; i++)
    {

        if ((y[i] > 600) && (x[i] >= 188) && (x[i] <= 228))
        {
            yV[i] = yV[i] - 0.00030;
        }
        if ((y[i] > 600) && (x[i] >= 303) && (x[i] <= 343))
        {
            (yV[i] = yV[i]) - 0.00029;
        }
        if ((y[i] > 600) && (x[i] >= 418) && (x[i] <= 458))
        {
            yV[i] = yV[i] - 0.00031;
        }

    }
}

void leftBlow(double* x, double* y, double* yV, double* xV, int N)
{
    for (int i = 0; i < N; i++)
    {

        if ((y[i] >= 630) && (x[i] <= 188))
        {
            yV[i] = yV[i] - 0.00006;
            xV[i] = xV[i] + 0.00018;

        }
    }
}
void rightBlow(double* x, double* y, double* yV, double* xV, int N)
{
    for (int i = 0; i < N; i++)
    {

        if ((y[i] >= 630) && (x[i] >= 480))
        {
            yV[i] = yV[i] - 0.00006;
            xV[i] = xV[i] - 0.00018;

        }
    }
}


void line2()
{
    setcolor(RED);
    line(96, 600, 142, 600);
    line(50, 600, 96, 600);
    line(142, 600, 188, 600);
    line(488, 600, 534, 600);
    line(534, 600, 580, 600);
}