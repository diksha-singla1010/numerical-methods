#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
/*Defining equation to be solved*/
double f(double x)
{
   return (x*x*x-4*x-9);
}
void main()
{
   float x0,x1,x2,f0,f1,f2,e;
   int step=1;
   clrscr();
   printf("enter first initial guess:");
   scanf("%f",&x0);
   printf("enter second initial guess:");
   scanf("%f",&x1);
   f0=f(x0);
   f1=f(x1);
   if(f0*f1>0)
   {
       printf("incorrect initial guesses\n");
       getch();
       exit(1);
   }
   printf("enter tolerable error:");
   scanf("%f",&e);
   printf("\nstep\t\tx0\t\tx1\t\tx2\t\tf(x2)");
   do
   {
      x2=(x0*f1-f0*x1)/(f1-f0);
      f2=f(x2);
      printf("\n%d\t\t%f\t%f\t%f\t%f",step,x0,x1,x2,f2);
      if(f0*f2<0)
      {
	 x1=x2;
	 f1=f2;
      }
      else
      {
	  x0=x2;
	  f0=f2;
      }
      step=step+1;
   }while(fabs(f2)>e);
   printf("\nroot is %f",x2);
   getch();
}