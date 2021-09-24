/* Program - 10 : Write a program that generates all the per of a given set of
digits, with or without repetition. */

#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
  
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
 
 
 
void without_per(char *a, int l, int r)
{
int i;
if (l == r)
    cout<<a<<"\n\n";
    //printf("%s\n", a);
else
{
    for (i = l; i <= r; i++)
    {
        swap(a[l], a[i]);
        without_per(a, l+1, r);
        swap(a[l], a[i]); //backtrack
    }
}
}



void with_per(char * nums, char * permutations, int last, int index){
   int i, len = strlen(nums);
   for ( i = 0; i < len; i++ ) {
      permutations[index] = nums[i] ;
      if (index == last)
         cout<<permutations <<"\n";
      else
         with_per (nums, permutations, last, index+1);
   }
}
  
// Driver code

int main(){
	int i,n,opt;
	char nums[100];
	char choice='y';
	
    cout<<"\nEnter the number of digits whose per you want to find (less than 100) : ";
    cin>>n;
    while(n>100)
    {
      cout<<"\nPlease enter a number less than 100 : ";
      cin>>n;
    }

    for(i=0;i<n;i++)
    {
      cout<<"\nEnter digit "<<i+1<<" : ";
      cin>>nums[i];
      while(!isdigit(nums[i]))
        {
          cout<<"\nPlease enter a digit : ";
          cin>>nums[i];
        }
    }
    nums[i]='\0';
    cout<<"\nEntered set of digits is : { ";
    for(i=0;i<n;i++)
    cout<<nums[i]<<" , ";
    cout<<"\b\b } "<<endl;
    cout<<"\nAll per of { ";
    for(i=0;i<n;i++)
    cout<<nums[i]<<" , ";
    cout<<"\b\b } are :-\n\n";
	int len = strlen(nums) ;
    char permutations[len];
	
	while(choice=='y'||choice=='Y'){
        cout<<"\nPLEASE ENTER YOUR CHOICE\n";
        cout<<"\n 1) PERMUTATION WITH REPEATATION\n";
        cout<<"\n 2) PERMUTATION WITHOUT REPEATATION\n"<<endl;;
		cout<<"\nEnter choice either '1' or '2':"<<endl;
		cin>>opt;
		switch(opt){
		case 1:
			cout<<endl<<"ALL PERMUTATION WITH REPEATATION OF "<<nums<<" ARE: "<<endl;			
			with_per(nums, permutations, len-1, 0);
			break;
		case 2:
			cout<<endl<<"ALL PERMUTATION WITHOUT REPEATATION OF "<<nums<<"ARE: "<<endl;
            int n = strlen(nums);
            without_per(nums, 0, n-1);
            break;
        }
		cout<<"________________________________________________________________"<<endl;
        cout<<endl;        
        cout<<"\nWanna Continue ? Press 'Y' Or 'y ': ";
		cin>>choice;
		cout<<"________________________________________________________________"<<endl;
	}
	
	
   
   return 0;
    
}