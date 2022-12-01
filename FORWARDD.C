#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
void main()
{
    float x[20],y[20][20],p,prod,sum,px;
    int i,j,n,k;
    clrscr();
    printf("enter number of points:");
    scanf("%d",&n);
    printf("enter the points:\n");
    for(i=0;i<n;i++)
    {
	x[i]=0;
	printf("enter x[%d]=",i);
	scanf("%f",&x[i]);
	y[i][0]=0.0;
	printf("enter y[%d]=",i);
	scanf("%f",&y[i][0]);
    }
    for(i=1;i<n;i++)
    {
	for(j=0;j<n-i;j++)
	{
	   y[j][i]=y[j+1][i-1]-y[j][i-1];
	}
    }
    printf("forward differnce table is:\n");
    for(i=0;i<n;i++)
    {
	printf("%0.2f",x[i]);
	for(j=0;j<n-i;j++)
	{
	   printf("\t%0.2f",y[i][j]);
	}
	printf("\n");
    }
    printf("enter the point for which value is to be interpolated:");
    scanf("%f",&px);
    i=0;
    while(!(x[i])>px)
    {
       i++;
    }
    k=i;
    p=(px-x[k])/(x[1]-x[0]);
    sum=y[k][0];
    for(i=1;i<=n-k;i++)
    {
       prod=1.0;
       for(j=0;j<=(i-1);j++)
       {
	  prod=prod*(p-j);
       }
       sum=sum+(y[k][i]*prod)/fact(i);
    }
    printf("\ninterpolated point = %0.3f",sum);
    getch();
}
int fact(int m)
{
    int i,prod=1;
    for(i=2;i<=m;i++)
    {
       prod=prod*i;
    }
    return prod;
}