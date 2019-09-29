#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coeffs.h"


int  main(void) //main function begins
{
//Given-
double **a = createMat(3,1);
a[0][0] =1;
a[1][0] =0;
a[2][0] =0;
saveMat(a,"a.dat",3,1);

double **b = createMat(3,1);
b[0][0] =1;
b[1][0] =1;
b[2][0] =0;
saveMat(b,"b.dat",3,1);

double **c = createMat(3,1);
c[0][0] =1;
c[1][0] =1;
c[2][0] =1;
saveMat(c,"c.dat",3,1);

double **n = createMat(3,1);
n[0][0] =1;
n[1][0] =1;
n[2][0] =1;
saveMat(n,"n.dat",3,1);

double k = 1;
saveVal("k.dat",k);

//Finding λ1,λ2,λ3
double l1 = findl(k,n,a);
double l2 = findl(k,n,b);
double l3 = findl(k,n,c);

double **A = scalmul(a,3,1,l1);
saveMat(A,"A.dat",3,1);
double **B = scalmul(b,3,1,l2);
saveMat(B,"B.dat",3,1);
double **C = scalmul(c,3,1,l3);
saveMat(C,"C.dat",3,1);
double ar = area(A,B,C);

print(A,3,1);
print(B,3,1);
print(C,3,1);


double answer = pow((6*ar),2); 
printf("answer = %lf\n",answer); 

}