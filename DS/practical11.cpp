/* Program - 11 : Write a program to calculate permutation and combination for an input value n and r using recursive formula of
 P(n,r) and C(n,r). */

#include<iostream>
using namespace std;

double factorial(double a);


int main()
{
    double n,r,p,c;
    cout<<"\n\n Enter the value for n : ";
    cin>>n;
    do
    {
        cout<<"\n\n Enter the value for r (less than or equal to n): ";
        cin>>r;
    }
    while(r>n);
    cout<<"\n\n Formula for P(n,r) is    n!\n\t\t\t------\n\t\t\t(n-r)!";
    cout<<"\n\n Formula for C(n,r) is     n!\n\t\t\t--------\n\t\t\tr!(n-r)!";
    p=factorial(n)/factorial(n-r);
    c=factorial(n)/(factorial(r)*factorial(n-r));
    cout<<"\n\n Permutation for n and r , P("<<n<<","<<r<<") is "<<p;
    cout<<"\n\n Combination for n and r , C("<<n<<","<<r<<") is "<<c<<"\n\n";
   
    return 0;
}

double factorial(double a)
{
    if(a==0||a==1)
    return 1;
    else
    return a*factorial(a-1);
}