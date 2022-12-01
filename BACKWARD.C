#include<stdio.h>
#include<conio.h>
void main()
{
    float x[20],y[20][20],xp,sum,prod,p;
    int i,j,n,k;
    clrscr();
    printf("enter number of points:");
    scanf("%d",&n);
    printf("enter points:\n");
    for(i=0;i<n;i++)
    {
       printf("enter x[%d]=",i);
       scanf("%f",&x[i]);
       printf("enter y[%d]=",i);
       scanf("%f",&y[i][0]);
    }
    for(i=1;i<n;i++)
    {
       for(j=n-1;j>i-1;j--)
       {
	  y[j][i]=y[j][i-1]-y[j-1][i-1];
       }
    }
    printf("backward difference table is:");
    for(i=0;i<n;i++)
    {
       printf("%0.3f",x[i]);
       for(j=0;j<=i;j++)
       {
	  printf("\t%0.3f",y[i][j]);
       }
       printf("\n");
    }
    printf("enter the point to be calculated:\n");
    scanf("%f",&xp);
    i=0;
    while(xp>x[i])
    {
       i++;
    }
    printf("value of i=%d\n",i);
    k=i+1;
    printf("value of k=%d\n",k);
    p=(xp-x[k-1])/(x[1]-x[0]);
    printf("value of p=%d\n",p);
    sum=y[k-1][0];
    printf("value of sum=%d",sum);
    for(i=1;i<=(k-1);i++)
    {
	prod=1.0;
	for(j=0;j<=(i-1);j++)
	{
	    prod=prod*(p+j);
	}
	sum=sum+(y[k-1][i]*prod)/fact(i);
    }
    printf("\nvalue=%f",sum);
    getch();
}
int fact(int m)
{
   int i,prod=1;
   for(i=2;i<=m;i++)
   {
      prod*=i;
   }
   return prod;
}