#include<iostream>
using namespace std;
int fib(int);
int main()
{
  int n,i,j,sum=1;
  cout<<"\n Enter index of fibonacci series:";
  cin>>n;
  for(i=1;i<=n;i++)
  cout<<"\t"<<fib(i);
  return 0;
}


int fib(int n)
{
  if(n==1||n==2)
    return(1);
   return (fib(n-1)+fib(n-2));
}
