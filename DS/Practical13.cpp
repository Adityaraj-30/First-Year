/* Program - 13 : WAP to print the truth table of following logical operations for variables
x and y :
Conjunction , Disjunction , Exclusive OR , Conditional , Bi-conditional , Exclusive NOR ,
Negation , NAND , NOR.
*/

#include<iostream>
using namespace std;

void print_conjunction(char x[],char y[]);
void print_disjunction(char x[],char y[]);
void print_xor(char x[],char y[]);
void print_conditional(char x[],char y[]);
void print_biconditional(char x[],char y[]);
void print_xnor(char x[],char y[]);
void print_negation(char x[],char y[]);
void print_nand(char x[],char y[]);
void print_nor(char x[],char y[]);

int main()
{
    char x[4],y[4];
    int i,j,opt;
    for(i=0;i<4;i++)
    {
        if(i<2)
            x[i]='F';
        else
            x[i]='T';
    }
    for(j=0;j<4;j++)
    {
        if(j%2==0)
            y[j]='F';
        else
            y[j]='T';
    }
    do
    {
        cout<<"\n\n\n\n\t\t\t     Want to print truth table of ?";
        cout<<"\n\n\t 1. Conjunction.\n\n\t 2. Disjunction.\n\n\t 3. Exclusive OR.\n\n\t 4. Conditional.";
        cout<<"\n\n\t 5. Bi-conditional.\n\n\t 6. Exclusive NOR.\n\n\t 7. Negation.\n\n\t 8. NAND.";
        cout<<"\n\n\t 9. NOR.\n\n\t 10. Exit.\n\n Enter your option : ";
        cin>>opt;
        if(opt<1||opt>10)
            cout<<"\n\n\tInvalid option.";
        switch(opt)
        {
            case 1 : print_conjunction(x,y);
            		break;
            case 2 : print_disjunction(x,y);
            		break;
            case 3 : print_xor(x,y);
            		break;
            case 4 : print_conditional(x,y);
            		break;
            case 5 : print_biconditional(x,y);
            		break;
            case 6 : print_xnor(x,y);
            		break;
            case 7 : print_negation(x,y);
            		break;
            case 8 : print_nand(x,y);
            		break;
            case 9 : print_nor(x,y);
            		break;
        }
    }while(opt!=10);
}

void print_conjunction(char x[],char y[])
{
    int i;
    cout<<"\n\n Truth Table of conjunction of x and y is :\n";
    cout<<"\n=================================================\n";
    cout<<"\n|\tx\t|\ty\t|   Conjunction |\n";
    for(i=0;i<4;i++)
    {
        cout<<"\n_________________________________________________\n";
        if(x[i]=='T'&&y[i]=='T')
            cout<<"\n|\t"<<x[i]<<"\t|\t"<<y[i]<<"\t|\t"<<'T'<<"\t|";
        else
            cout<<"\n|\t"<<x[i]<<"\t|\t"<<y[i]<<"\t|\t"<<'F'<<"\t|";
    }
     cout<<"\n_________________________________________________\n";
}

void print_disjunction(char x[],char y[])
{
   int i;
    cout<<"\n\n Truth Table of disjunction of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\tDisjunction\n";
    for(i=0;i<4;i++)
    {
        if(x[i]=='T'||y[i]=='T')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'T';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'F';
    }
}

void print_xor(char x[],char y[])
{
    int i;
    cout<<"\n\n Truth Table of Exclusive OR of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\tExclusive OR\n";
    for(i=0;i<4;i++)
    {
        if(x[i]!=y[i])
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'T';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'F';
    }
}

void print_conditional(char x[],char y[])
{
    int i;
    cout<<"\n\n Truth Table of Conditional of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\t    x->y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]=='T'&&y[i]=='F')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'F';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'T';
    }
}

void print_biconditional(char x[],char y[])
{
 int i;
    cout<<"\n\n Truth Table of Bi-conditional of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\t    x<->y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]!=y[i])
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'F';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t\t"<<'T';
    }
}

void print_xnor(char x[],char y[])
{
     int i;
    cout<<"\n\n Truth Table of Exclusive NOR of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\tNOR x & y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]==y[i])
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'T';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'F';
    }
}

void print_negation(char x[],char y[])
{
     int i;
    cout<<"\n\n Truth Table of Negation of x and Negation of y is :\n";
    cout<<"\n\t\tx\t\ty\t\t-x\t\t-y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]=='F'&&y[i]=='F')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'T'<<"\t\t"<<'T';
        else if(x[i]=='F'&&y[i]=='T')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'T'<<"\t\t"<<'F';
        else if(x[i]=='T'&&y[i]=='F')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'F'<<"\t\t"<<'T';
        else if(x[i]=='T'&&y[i]=='T')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'F'<<"\t\t"<<'F';
    }
}

void print_nand(char x[],char y[])
{
    int i;
    cout<<"\n\n Truth Table of NAND of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\tNAND of x & y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]=='T'&&y[i]=='T')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'F';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'T';
    }
}

void print_nor(char x[],char y[])
{
    int i;
    cout<<"\n\n Truth Table of NOR of x and y is :\n";
    cout<<"\n\t\tx\t\ty\t\tNOR of x & y\n";
    for(i=0;i<4;i++)
    {
        if(x[i]=='F'&&y[i]=='F')
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'T';
        else
        cout<<"\n\n\t\t"<<x[i]<<"\t\t"<<y[i]<<"\t\t"<<'F';
    }
}