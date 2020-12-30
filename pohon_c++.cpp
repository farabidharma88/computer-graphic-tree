#include<bits/stdc++.h>
#include<graphics.h>
#include<math.h>
using namespace std;

double xw, yw;
int warna[600][600];
int xv, yv;
int xwmin = -3, xwmax = 3, ywmin = 0, ywmax = 6;		
int xvmin = 0, xvmax = 600, yvmin = 0, yvmax = 600;	


void wv(double x, double y){
    xv = xvmin + round((x-xwmin)*(xvmax-xvmin)/(xwmax-xwmin));
    yv = yvmax - round((y-ywmin)*(yvmax-yvmin)/(ywmax-ywmin));
}

void vw(double x, double y){
    xw = xwmin + (x-xvmin)*(xwmax-xwmin)/(xvmax-xvmin);
    yw = ywmin + (yvmax-y)*(ywmax-ywmin)/(yvmax-yvmin);
}

main(){
    int pixels[600][600];

    float	a1,a2,a3,a4,a5,
            b1,b2,b3,b4,b5,
            c1,c2,c3,c4,c5,
            d1,d2,d3,d4,d5,
            e1,e2,e3,e4,e5,
            f1,f2,f3,f4,f5;
    double xb, yb;
    double pi = M_PI;
	int alpha = 5, beta = -50, gamma = 60;
    a1 = 1;
    b1 = 0;
    c1 = 0;
    d1 = 1;
    e1 = 0;
    f1 = 0;

    a2 = 0.65*cos(alpha*pi/180);
    b2 = -0.65*sin(alpha*pi/180);
    c2 = 0.65*sin(alpha*pi/180);
    d2 = 0.65*cos(alpha*pi/180);
    e2 = 0;
    f2 = 1.5;

    a3 = 0.5*cos(beta*pi/180);
    b3 = -0.5*sin(beta*pi/180);
    c3 = 0.5*sin(beta*pi/180);
    d3 = 0.5*cos(beta*pi/180);
    e3 = 0;
    f3 = 1.5;

    a4 = 0.5*cos(gamma*pi/180);
    b4 = -0.5*sin(gamma*pi/180);
    c4 = 0.5*sin(gamma*pi/180);
    d4 = 0.5*cos(gamma*pi/180);
    e4 = 0;
    f4 = 1.7;

    initwindow(600,600);
    int points[] = {290,400,310,400,315,550,285,550};
    setcolor(2);		
    setfillstyle(1,2);	
    fillpoly(4,points);

    int k=0;
    do{
        for(int i=1; i<xvmax; i++)
            for(int j=1; j<yvmax; j++)
                pixels[i][j] = getpixel(i,j);

        cleardevice();

        for(int i=1; i<xvmax; i++)
            for(int j=1; j<yvmax; j++){
                if(pixels[i][j] != 0){
                    vw(i,j);
                    xb = a1*xw + b1*yw + e1;
                    yb = c1*xw + d1*yw + f1;
                    wv(xb,yb);
                    putpixel(round(xv), round(yv), 2);
                    xb = a2*xw + b2*yw + e2;
                    yb = c2*xw + d2*yw + f2;
                    wv(xb,yb);
                    putpixel(round(xv), round(yv), 2);
                    xb = a3*xw + b3*yw + e3;
                    yb = c3*xw + d3*yw + f3;
                    wv(xb,yb);
                    putpixel(round(xv), round(yv), 2);
                    xb = a4*xw + b4*yw + e4;
                    yb = c4*xw + d4*yw + f4;
                    wv(xb,yb);
                    putpixel(round(xv), round(yv), 2);
                }
            }
        k++;
    }while(k<8);
     

    getch();
}
