//Function declaration

#include <math.h>
double **createMat(int m,int n);
void readMat(double **p, int m,int n);
void print(double **p,int m,int n);
double **loadtxt(char *str,int m,int n);
double linalg_norm(double **a, int m);
double **linalg_sub(double **a, double **b, int m, int n);
double **linalg_inv(double **mat, int m);
double **matmul(double **a, double **b, int m, int n, int p);
double **transpose(double **a,  int m, int n);
void uniform(char *str, int len);
void gaussian(char *str, int len);
double mean(char *str);
//End function declaration


//Defining the function for matrix creation
double **createMat(int m,int n)
{
 int i;
 double **a;
 
 //Allocate memory to the pointer
a = (double **)malloc(m * sizeof( *a));
    for (i=0; i<m; i++)
         a[i] = (double *)malloc(n * sizeof( *a[i]));

 return a;
}
//End function for matrix creation


//Defining the function for reading matrix 
void readMat(double **p, int m,int n)
{
 int i,j;
 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   scanf("%lf",&p[i][j]);
  }
 }
}
//End function for reading matrix

//Read  matrix from file
double **loadtxt(char *str,int m,int n)
{
FILE *fp;
double **a;
int i,j;


a = createMat(m,n);
fp = fopen(str, "r");

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
   fscanf(fp,"%lf",&a[i][j]);
  }
 }
//End function for reading matrix from file

fclose(fp);
 return a;

}


//Defining the function for printing
void print(double **p, int m,int n)
{
 int i,j;

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  printf("%lf ",p[i][j]);
 printf("\n");
 }
}
//End function for printing

//Defining the function for norm

double linalg_norm(double **a, int m)
{
int i;
double norm=0.0;

 for(i=0;i<m;i++)
 {
norm = norm + a[i][0]*a[i][0];
}
return sqrt(norm);

}
//End function for norm

//Defining the function for difference of matrices

double **linalg_sub(double **a, double **b, int m, int n)
{
int i, j;
double **c;
c = createMat(m,n);

 for(i=0;i<m;i++)
 {
  for(j=0;j<n;j++)
  {
c[i][j]= a[i][j]-b[i][j];
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for inverse of 2x2 matrix


double **linalg_inv(double **mat, int m)
{
double **c, det;
c = createMat(m,m);

det = mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

c[0][0] = mat[1][1]/det;
c[0][1] = -mat[1][0]/det;
c[1][0] = -mat[0][1]/det;
c[1][1] = mat[0][0]/det;

return c;

}
// End  function for inverse of 2x2 matrix


//Defining the function for difference of matrices

double **matmul(double **a, double **b, int m, int n, int p)
{
int i, j, k;
double **c,temp =0;
c = createMat(m,p);

 for(i=0;i<m;i++)
 {
  for(k=0;k<p;k++)
  {
    for(j=0;j<n;j++)
    {
	temp= temp+a[i][j]*b[j][k];
    }
	c[i][k]=temp;
	temp = 0;
  }
 }
return c;

}
//End function for difference of matrices

//Defining the function for transpose of matrix

double **transpose(double **a,  int m, int n)
{
int i, j;
double **c;
//printf("I am here");
c = createMat(n,m);

 for(i=0;i<n;i++)
 {
  for(j=0;j<m;j++)
  {
c[i][j]= a[j][i];
//  printf("%lf ",c[i][j]);
  }
 }
return c;

}
//End function for transpose of matrix

//Defining the function for generating uniform random numbers
void uniform(char *str, int len)
{
int i;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
fprintf(fp,"%lf\n",(double)rand()/RAND_MAX);
}
fclose(fp);

}
//End function for generating uniform random numbers

//Defining the function for calculating the mean of random numbers
double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}
//End function for calculating the mean of random numbers
double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;
double avg = mean(str);
fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Add all numbers in file
temp += pow(x - avg, 2);
}
fclose(fp);

return temp/1000000;

}


//Defining the function for generating Gaussian random numbers
void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}
//End function for generating Gaussian random numbers

//Function for saving matrix to .dat file

void saveMat (double **mat , char *str, int m , int n){
  FILE *fp;
  fp = fopen(str,"w");
  for (int i = 0; i < m; i++){
    for (int j = 0; j < n; j++){
      fprintf(fp , "%lf",mat[i][j]);
    }
    fprintf(fp ,"\n");
  }
  fclose(fp);
}

//end function

//Function for saving a value to .dat file
void saveVal(char *str,double a){
  FILE *fp;
fp = fopen(str,"w");
fprintf(fp, "%lf",a );
fclose(fp);
}

//end function


//Linspace function
double **linspace(double a, double l, int m)
{
//Variable declarations
double d, **ap;
int i,j;

ap = createMat(m,1);

//Common difference
d = (l-a)/(m-1);

 for(i=0;i<1;i++)
 {
  for(j=0;j<m;j++)
  {
ap[j][i] = a+j*d;

  }
 }
//Returning the address of the first memory block
return ap;

}

//End linspace function

double **meshgrid(int len, int begin, double addX, int addY)
{
  double ** ret = createMat(len, len);
  for (int i=0; i<len; i++)
    for (int j=0; j<len; j++){
      ret[i][j] = begin + i*addY + j*addX;
    }
  return ret;
}

//eigen values
double ev1(double **V,double F){
    double e1 = ((V[0][0]+V[1][1]) + (V[0][0]-V[1][1]))/(2*-F);
    return e1;
}

double ev2(double **V,double F){
    double e2 = ((V[0][0]+V[1][1]) - (V[0][0]-V[1][1]))/(2*-F);
    return e2;
}
//end function

void set(double **mat, int row, double x,double y,double z){
mat[row][0]=x; mat[row][1]=y; mat[row][2]=z;
}

double **cross_pdt(double **a, double **b){
double **c = createMat(3,3);
set(c, 0, 0, -*a[2], *a[1]);
set(c, 1, *a[2], 0, -*a[0]);
set(c, 2, -*a[1], *a[0], 0);
return matmul(c, b, 3,3,1);
}


double findl(double k,double **n,double **a){

//lxn^Txa = k
//l = k/(n^Txa)

double **l = (matmul(transpose(n,3,1),a,1,3,1));
 return k/l[0][0];
}

double area(double **A,double **B,double **C){
double ar = linalg_norm((cross_pdt(linalg_sub(A,B,3,1),linalg_sub(A,C,3,1))),3);
return ar/2;
}

double **scalmul(double **a, int m, int n,double p ){
  int i,j;
  double **c;

  c = createMat(m,n);

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = p*a[i][j];
    }
  }

  return c;
}

void equal(double **A,double **B, int m, int n){
  int i,j;
  int count = 0;

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
       if(A[i][j] == B[i][j]){
        count+=1;
       }
    }
  }
  if (count == 9){
   printf("%s\n","Equal" );
  }
  else{
   printf("%s\n","Not Equal" );
  }
}

double det(double **A){

  double determinant = A[0][0] * ((A[1][1]*A[2][2]) - (A[2][1]*A[1][2])) -A[0][1] * (A[1][0]
   * A[2][2] - A[2][0] * A[1][2]) + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

  return determinant;
}








