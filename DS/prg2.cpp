#include<iostream>
#include<cmath>
using namespace std;

class Set
{
	int *arr;
	int size;
	public:
		Set()                               //Not parameterised constructor
		{
			arr=NULL;
			size=0;			
		}
		void SetSize()                      // Input size of array from user
		{
			cout<<"Enter the size of array:";
			cin>>size;
			arr=new int[size];
		}
		void EnterArr()                       //Input array from user
		{
			cout<<"Enter elements of array: ";
			for(int i=0; i<size; i++)
			{
				cin>> arr[i];
			}
		}
		void UniqueSet()                    //Removing Duplicates from array
		{
			for(int i=0; i<size; i++)
			{
				for(int j=(i+1); j<size; j++)
				{
				    if(arr[i]==arr[j])
					{
					  for(int m=j; m<size; m++)
					    {
					  	    arr[m]=arr[m+1];
					    }
					    size=size-1;
					    j=j-1;	
					}	
				}	
        	}
        }
	
	    void Show()                           //Show Set
	    {
	    	cout<<"Set is:"<<endl<<"{ ";
	    	for(int i=0; i<size; i++)
		    {
			    cout<<arr[i]<<" ";
	        }     
	    	cout<<"}"<<endl;		
		}
		
		void Subset(Set C)                    //check one set is Subset of other
		{
			int flag=0;
			for(int i=0; i<(C.size); i++)
			{
				for(int j=0; j<size; j++)
				{
					if(C.arr[i]==arr[j])
					    flag++;
				}
				
			}
			if(flag==C.size)
			    cout<<"Yes, It is a subset"<<endl;
			else
			    cout<<"No, It is not a subset"<<endl;
		}
		
		Set Union(Set C)                     //Union of two Sets
		{
		    Set Union;
			Union.size=size;
			Union.arr=new int[Union.size];
			int k=0,flag=0;
			for(int i=0; i<size; i++)
			{
				Union.arr[k]=arr[i];
				k++;
			} 
			for(int i=0; i<(C.size); i++)
			{
				for(int j=0; j<size;j++)
				{
					if(C.arr[i]==Union.arr[j])
					{
					   flag=1;
					}
				}
				if(flag==0)
				{
			    	Union.arr[k++]=C.arr[i];
			    	Union.size++;
		    	}
		    	flag=0;
			}
		    return Union;
		}
		
		Set Inter(Set C)                      //Intersection of two sets
		{
			Set I;
			I.size=0;
			I.arr=new int[0];
			int flag=0, k=0;
			for(int i=0; i<(C.size); i++)
			{
				for(int j=0; j<size;j++)
				{
					if(C.arr[i]==arr[j])
					{
					   flag=1;
				    }
				}
				if(flag==1)
				{
			    	I.arr[k++]=C.arr[i];
			    	I.size++;
		    	}
		    	flag=0;
			}
			return I;
		}
		
		Set Complement(int* Uni, int Siz)        //Complement of a set  
		{			
			Set Comp;
			Comp.size=0;
			Comp.arr= new int[0];
			int flag=0, k=0;
			for(int i=0; i<Siz; i++)
			{
				for(int j=0; j<size;j++)
				{
					if(Uni[i]==arr[j])
					{
					   flag=1;
					}
				}
				if(flag==0)
				{
			    	Comp.arr[k++]=Uni[i];
			    	Comp.size++;
		    	}
		    	flag=0;
			}
			return Comp;
		}
		
		Set SetDiff(Set C)                     //Difference of two sets
		{
		    Set Diff;
			Diff.size=0;
			Diff.arr=new int[0];
			int flag=0, k=0;
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<C.size;j++)
				{
					if(arr[i]==C.arr[j])
					{
					   flag=1;
					}
				}
				if(flag==0)
				{
			    	Diff.arr[k++]=arr[i];
			    	Diff.size++;
		    	}
		    	flag=0;
			}
			return Diff;		
		}
		
		Set SymDiff(Set C)                 //Symmetric Difference of two sets
		{
			Set SymDif;
			SymDif.size=0;
			SymDif.arr=new int[0];
			int k=0,flag=0;
			for(int i=0; i<(size); i++)
			{
				for(int j=0; j<C.size;j++)
				{
					if(arr[i]==C.arr[j])
					{
					   flag=1;
					}
				}
				if(flag==0)
				{
			    	SymDif.arr[k++]=arr[i];
			    	SymDif.size++;
		    	}
		    	flag=0;
			}
			for(int i=0; i<(C.size); i++)
			{
				for(int j=0; j<size;j++)
				{
					if(C.arr[i]==arr[j])
					{
					   flag=1;
					}
				}
				if(flag==0)
				{
			    	SymDif.arr[k++]=C.arr[i];
			    	SymDif.size++;
		    	}
		    	flag=0;
			}
			return SymDif;
		}
		
		void CartesianProd(Set C)               //Cartesian Product 
		{
			cout<<"{ ";
			for(int i=0; i<size; i++)
			{
				for(int j=0; j<C.size; j++)
				{
					cout<<"("<<arr[i]<<","<<C.arr[j]<<") ";
				}
			}
			cout<<" }"<<endl;
		}				
};
 int main()                                     //Main Function
 {
 	Set A;
 	A.SetSize();
 	A.EnterArr();
 	A.UniqueSet();
 	A.Show();
	Set B;
	B.SetSize();
	B.EnterArr();
	B.UniqueSet();
	B.Show();
	int x;int a;
	Set D;Set E;
	do{
	cout<<"Enter numbers from 1 to 5 from your choice: "<<endl
	    <<"1) Check a Set is Subset of other or not: "<<endl
	    <<"2) Union and Intersection of two Sets: "<<endl
	    <<"3) Complement of a Set: "<<endl
	    <<"4) Set Difference and Symmetric Difference: "<<endl
	    <<"5) Cartesian Product of Sets: "<<endl
	    <<"6) Exit"<<endl;
	cin>>x;
	
	if(x==1)
	{
		cout<<"What do you want to check?"<<endl
		    <<"1) A is a subset of B or"<<endl
		    <<"2) B is a subset of A"<<endl;
		cin>>a;
		if(a==1)
		   B.Subset(A);
		if(a==2)
		   A.Subset(B);
	} 
	else if(x==2)
	{
		cout<<"Union of ";
	    D=A.Union(B);
		D.Show();
		cout<<"Intersection of ";
		E=A.Inter(B);
		E.Show();  
    }
    else if(x==3)
    {
    	int *arr;int size;
    	cout<<"What do you want to check?"<<endl
    	    <<"1) Complement of Set A or"<<endl
    	    <<"2) Complement of Set B"<<endl;
    	cin>>a;
    	cout<<"Enter size of Universal Set "<<endl;
    	cin>>size;
    	arr= new int[size];
    	cout<<"Enter elements of Universal array:"<<endl;
    	for(int i=0; i<size; i++)
    	{
    		cin>>arr[i];
		}
		if(a==1)
		{
		    D=A.Complement(arr,size);
		    D.Show();
	    }
	    else
	    {
	    	D=B.Complement(arr,size);
	      	D.Show();
		}
	}
	else if(x==4)
	{
		cout<<"What do you want to check? "<<endl
		    <<"1) A-B or 2) B-A "<<endl;
		cin>>a;
		cout<<"Difference of ";
	    if(a==1)
	    {
	        D=A.SetDiff(B);
	        D.Show();
	    }
	    else
	    {
	        D=B.SetDiff(A);
	        D.Show();
	    }
	    cout<<"Symmetric Difference of ";
	    E=A.SymDiff(B);
	    E.Show();
	}
	else if(x==5)
	{
		cout<<"What do you want to check? "<<endl
		    <<"1) AXB or 2) BXA "<<endl;
		cin>>a;
	    if(a==1)
	        A.CartesianProd(B);
	    else 
	        B.CartesianProd(A);
	}
	
    }while(x<=5);
 	return 0;
}