#include<stdio.h>
#include<conio.h>
float f(float);
void main()
{
    int i,n;
    float a,b,h,sum,sum4=0,sum2=0,ans;
    clrscr();
    printf("enter the limits of intergral:");
    scanf("%f %f",&a,&b);
    printf("enter the number of subinterval:");
    scanf("%d",&n);
    h=(b-a)/n;
    sum=f(a)+f(b);
    for(i=1;i<n;i+=2)
    {
       sum4=sum4+f(a+i*h);
    }
    for(i=2;i<n;i+=2)
    {
       sum2=sum2+f(a+i*h);
    }
     sum=sum+2*sum4+4*sum2;
     ans=(h*sum)/3;
     printf("value=%f",ans);
    getch();
}
float f(float x)
{
    return (1/(1+(x*x))) ;
}