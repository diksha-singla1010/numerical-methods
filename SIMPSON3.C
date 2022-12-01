#include<stdio.h>
#include<conio.h>
float f(float);
void main()
{
   int i,n;
   float a,b,sum,h,sum2=0.0,sum3=0.0,ans=0.0,x;
   clrscr();
   printf("enter the limits of integral:");
   scanf("%f %f",&a,&b);
   printf("enter the number of subintervals:");
   scanf("%d",&n);
   h=(b-a)/n;
   sum=f(a)+f(b);
   for(i=1;i<n;i+=3)
   {
      x=a+i*h;
      sum3=sum3+f(x)+f(x+h);
   }
   for(i=3;i<=n-3;i+=3)
   {
      sum2=sum2+f(a+i*h);
   }
   sum=sum+3*sum3+2*sum2;
   ans=(3*h*sum)/8;
   printf("value: %f",ans);
   getch();
}
float f(float x)
{
  return (1/(1+(x*x)));
}