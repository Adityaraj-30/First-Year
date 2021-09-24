#include<iostream>
#include<math.h>
#include<cmath>
using namespace std;
class Set{
    int *arr;
    int size;
    public:
    Set(){
        size=0;
        arr=NULL;
    }
    void setSize(){
        cout<<"\nEnter Size Of Array : ";
        cin>>size;
        arr=new int[size];
    }
    void Inp_arr(){
        for(int i=0;i<size;i++){
            cout<<"\nEnter Element "<<i+1<<" : ";
            cin>>arr[i];
        }
    }
    void unique(){
        int temp;
        Inp_arr();
         for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(arr[i]==arr[j]){
                    arr[j]=0;
                }
            }
        }
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(arr[i]<arr[j]){
                   temp=arr[i];
                   arr[i]=arr[j];
                   arr[j]=temp;
               }
           }
      }
    }
    int cardinality(){
        int cardinality;
        for(int i=0;i<size;i++){
            if(arr[i]==0){
                cardinality=i;
                break;
            }
            else{
                cardinality=i+1;
            }
        }
        return cardinality;
    }
    void cardi(){
        int c=cardinality();
        cout<<"\nThe Cardinality Of Set A Is : "<<c;
        cout<<endl;
    }
    void print(){
        int n=cardinality();
        cout<<"\nSet A = { ";
        for(int i=0;i<n-1;i++){
            cout<<arr[i]<<" , ";
        }
        cout<<arr[n-1]<<" }\n";
    }
    bool isMember(){
        int car=cardinality();
        int n;
        bool found=false;
        cout<<"\nEnter Element You Wanna Search : ";
        cin>>n;
        for(int i=0;i<car;i++){
            if(arr[i]==n){
                found=true;
                break;
            }
        }
        if(found){
            cout<<"\nThe Element You Entered Is A Member\n";
        }
        else{
            cout<<"\nThe Element You Entered Is Not A Member\n";
        }
    }
    void powerset(){
	cout << '\n';
    int n;
	int cnt = pow(2,n);
	cout << "{";
	cout << "{null} ";
	for(int	i = 1 ; i < cnt; i++){
		cout << "{";
		int temp = i;
		for(int j = 0; j < n; j++){
			if(temp & 1){
				cout << arr[j] << " , ";
			}
			temp = temp >> 1;
		}
		cout << "} ,";
	}
	cout << "}";
}
};
int main(){
    Set A;
    int cases;
    char choice='y';
    A.setSize();
    A.unique();
    A.print();
    cout<<"\n-->Enter 1 To Check The Cardinality Of Set A\n";
    cout<<"\n-->Enter 2 To Check A No Is Member Of Set A\n";
    cout<<"\n-->Enter 3 To Print Power Sets\n";
    while(choice=='y'||choice=='Y'){
        cout<<"\nEnter Your Choice :";
        cin>>cases;
        switch (cases)
        {
        case 1:
            cout<<endl;
            A.cardi();
            cout<<endl;
            break;
        case 2:
            cout<<endl;
            A.isMember();
            cout<<endl;
            break;
        case 3:
            cout<<endl;
            A.powerset();
            cout<<endl;
            break;
        default:
            cout<<endl;
            cout<<"\nYou Entered Wrong Choice\n";
            cout<<endl;
            break;
        }
        cout<<"\nWant to Continue ? Press 'Y' Or 'y ':";
        cin>>choice;
    }
    return 0;
}