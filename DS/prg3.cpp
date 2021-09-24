#include<iostream>
using namespace std;

class Relation{
    private:
    int** arr;
    int size;
    int* set;
    public:
    Relation(){
        arr=NULL;
        size=0;
    }
    void set_size(){
        cout<<"Enter the size of the set."<<endl;
        cin>>size;
        set=new int[size];
        cout<<"Enter elements of the set."<<endl;
        for(int i=0;i<size;i++)
            cin>>set[i];
        arr=new int*[size];
        for(int i=0;i<size;i++)
            arr[i]=new int[size];
        for(int i=0;i<size;i++)    //initalizing matrix with zero at all positions.
            for(int j=0;j<size;j++)
                arr[i][j]=0;
    }
    void enter(){
        int a,b,i,num;
        cout<<"Enter the number of elements in the relation."<<endl;
        cin>>num;
        for(int i =0;i<num;i++)
        {
			cout<<"Enter pair number "<<(i+1)<<"respectively"<<endl;
			cin>>a>>b;
			int p,q;
			for(int m=0;m<size;m++)
			{
				if(a==set[m])
				p=m;
				if(b==set[m])
				q=m;	
			}
			arr[p][q]=1;
		}
        show_matrix();
    }
    void show_matrix(){
        cout<<"The Relation matrix is:"<<endl;
        for(int i=0;i<size+1;i++){
            for(int j=0;j<size+1;j++){
                if(i==0&& j==0)
                    cout<<"  ";
                else if(i==0)
                    cout<<set[j-1]<<" ";
                else if(j==0)
                    cout<<set[i-1]<<" ";
                else
                    cout<<arr[i-1][j-1]<<" ";}
            cout<<endl;
        }
    }
    bool reflexive()
	{
	 	for(int i=0;i<size;i++){
            if(arr[i][i]!=1)
                return false;
         }
         return true;
	}
    
};
int main(){
    Relation r;
    r.set_size();
    r.enter();
    int ch;
    char c;
        do{

        cout<<"Enter your choice to check whether relation is:"<<endl;
        cout<<"1: Reflexive Relation"<<endl;
        cout<<"2: Symmetric Relation"<<endl;
        cout<<"3: Transitive Relation"<<endl;
        cout<<"4: Anti-symmetric Relation"<<endl;
        cout<<"5: Equivalence Relation"<<endl;
        cout<<"6: Partial Order Relation"<<endl;
        cin>>ch;
        switch(ch){
            case 1:{
                if(r.reflexive())
                    cout<<"The entered relation is reflexive."<<endl;
                else
                    cout<<"The entered relation is not reflexive."<<endl;
                    break; 
            }
        }
        
    
    cout<<"Do you want to continue? Enter y for yes."<<endl;
        cin>>c;
    }while(c=='y');
    return 0;
}