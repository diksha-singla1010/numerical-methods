#include<stdio.h>
#include<conio.h>
#define max 20
void main()
{
   float a[max][max],x[max],ratio;
   int i,j,k,n;
   clrscr();
   printf("enter the number of unknowns:");
   scanf("%d",&n);
   printf("enter the augmented matrix:\n");
   for(i=1;i<=n;i++)
   {
      for(j=1;j<=(n+1);j++)
      {
	 a[i][j]=0.0;
	 printf("enter the value of a[%d][%d]=",i,j);
	 scanf("%f",&a[i][j]);
      }
   }
   for(i=1;i<=n;i++)
   {
       for(j=1;j<=n;j++)
       {
	  if(i!=j)
	  {
	     ratio=a[j][i]/a[i][i];
	     for(k=1;k<=(n+1);k++)
	     {
		a[j][k]=a[j][k]-ratio*a[i][k];
	     }
	  }
       }
   }
   for(i=1;i<=n;i++)
   {
      x[i]=0.0;
      x[i]=a[i][n+1]/a[i][i];
   }
   for(i=1;i<=n;i++)
   {
      printf("a[%d]=%f\n",i,x[i]);
   }
   getch();
}