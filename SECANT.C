#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/*defining equation to be solved*/
double f(double x)
{
   return (x*x*x-2*x-5);
}
void main()
{
   float x0=0.0,x1=0.0,x2=0.0,f0=0.0,f1=0.0,f2=0.0,e=0.0;
   int step=1,n=0;
   clrscr();
   printf("enter first initial guess:");
   scanf("%f",&x0);
   printf("enter second initial guess:");
   scanf("%f",&x1);
   printf("enter prescribed tolerance:");
   scanf("%f",&e);
   printf("enter number of iterations desired:");
   scanf("%d",&n);
   printf("\nstep\t\tx0\t\tx1\t\tx2\t\tf(x2)");
   do
   {
       f0=f(x0);
       f1=f(x1);
       if(f0==f1)
       {
	  printf("Mathematical error");
	  getch();
	  exit(1);
       }
       x2=((x0*f1)-(f0*x1))/(f1-f0);
       f2=f(x2);
       printf("\n%d\t\t%f\t%f\t%f\t%f",step,x0,x1,x2,f(x2));
       x0=x1;
       f0=f1;
       x1=x2;
       f1=f2;
       step=step+1;
       if(step>n)
       {
	  printf("not convergent");
	  exit(1);
       }
   }while(fabs(f2)>e);
   printf("\nroot is %f",x2);
   getch();
}