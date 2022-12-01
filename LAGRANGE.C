#include<stdio.h>
#include<conio.h>
#include<math.h>
#define max 100
void main
{
   float x[max],y[max],xp,yp,y=0;
   int i,j,n;
   clrscr();
   printf("enter number of points:");
   scanf("%d",&n);
   printf("enter points:\n");
   for(i=1;i<=n;i++)
   {
      printf("enter x[%d]=",i);
      scanf("%f",&x[i]);
      printf("enter y[%d]=",i);
      scanf("%f",&y[i]);
   }
   printf("enter interpolating point:");
   scanf("%f",&xp);
   for(i=1;i<=n;i++)
   {
      p=1;
      for(j=1;j<=n;j++)
      {
	  if(i!=j)
	  {
	     p=p*(xp-x[j])/(x[i]-x[j]);
	  }
      }
       yp=yp+p*y[i];
   }
   printf("result:%f\n",yp);

   getch();
}