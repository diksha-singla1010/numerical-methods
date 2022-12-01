#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#define max 20
void main()
{
    float a[max][max],x[max],ratio;
    int i,j,k,n;
    clrscr();
    /*reading the number of unknowns*/
    printf("enter the number of unknowns:");
    scanf("%d",&n);
    printf("enter the values for augmented matrix:\n");
    for(i=1;i<=n;i++)
    {
	for(j=1;j<=(n+1);j++)
	{
	   printf("enter the value for a[%d][%d]=",i,j);
	   scanf("%f",&a[i][j]);
	}
    }
    /*applying gauss elimination*/
    for(i=1;i<=n-1;i++)
    {
     //  printf("working\n");
       if(a[i][i]==0.0)
       {
	   printf("mathematical error..\n");
	   exit(1);
       }
       for(j=i+1;j<=n;j++)
       {
	   ratio=a[j][i]/a[i][i];
	   for(k=1;k<=(n+1);k++)
	   {
	      a[j][k]=a[j][k]-ratio*a[i][k];
	   }
       }
    }
    /*applying back substitution*/
    x[n]=a[n][n+1]/a[n][n];
    for(i=n-1;i>=1;i--)
    {
       x[i]=a[i][n+1];
       for(j=i+1;j<=n;j++)
       {
	  x[i]=x[i]-a[i][j]*x[j] ;
       }
       x[i]=x[i]/a[i][i];
    }
    /* displaying the solution*/
    printf("the soltuion is:\n");
    for(i=1;i<=n;i++)
    {
	printf("x[%d] = %0.3f\n",i,x[i]);
    }
    getch();
}