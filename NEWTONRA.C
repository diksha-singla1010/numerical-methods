#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
double f(double x)
{
    return (x*x*x-4*x-9);
}
double df(double x)
{
    return (3*x*x-4);
}
void main()
{
    float x0,x1,f0,f1,g0,e;
    int step=1,n;
    clrscr();
    printf("enter the initial guess:");
    scanf("%f",&x0);
    printf("enter tolerable error:");
    scanf("%f",&e);
    printf("enter maximum iterations:");
    scanf("%d",&n);
    printf("\nstep\t\tx0\t\tf(x0)\t\tx1\t\tf(x1)");
    do
    {
       f0=f(x0);
       g0=df(x0);
       if(g0==0.0)
       {
	  printf("Mathematical error\n");
	  exit(1);
       }
       x1=x0-(f0/g0);
       printf("\n%d\t\t%f\t%f\t%f\t%f",step,x0,f0,x1,f1);
       x0=x1;
       step=step+1;
       if(step>n)
       {
	   printf("Not convergent");
	   exit(1);
       }
       f1=f(x1);
    }while(fabs(f1)>e);
    printf("\nroot is %f",x1);
    getch();
}