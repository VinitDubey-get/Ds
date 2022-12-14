// to implement sorting using templates
#include<iostream>
using namespace std;

template<typename T>class sort{
    T*arr;
    int size;
    public:
    sort(int size=0){
        this->size=size;
        arr=new T[size];
        
    }
    void set(){
        cout<<"Enter the elements"<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }
    void get(){
        cout<<"Elements of the array are :-"<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void bubblesort(){
        for(int i=0;i<size-1;i++){
            for(int j=0;j<size-i-1;j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }

    void selectionsort(){
        
        for(int i=0;i<size-1;i++){
            int pos=i;
            int temp=arr[i];
            for(int j=i+1;j<size;j++){
                if(temp>arr[j]){
                   temp=arr[j];
                   pos=j;
                }
            }
            swap(arr[i],arr[pos]);
        }
    }
    void insertionsort(){
        for(int i=1;i<size;i++){
            int temp=arr[i];
            int j;
            for(j=i;j>0 && arr[j-1]>temp;j--){
                arr[j]=arr[j-1];
            }
            arr[j]=temp;
        }
    }
};
int main(){
    bool flag=true;
    while(flag){
        cout<<"Enter the type of data type to be sorted"<<endl;
        cout<<"1. For interger"<<endl;
        cout<<"2. For characters"<<endl;
        cout<<"3. For flaot"<<endl;
        
        
        int c;
        cin>>c;
        switch(c){
            case 1:{
                cout<<"Enter the size of the array"<<endl;
                int size;
                cin>>size;
                sort<int>a(size);
                a.set();
                a.get();
                cout<<"Which sorting algo do you want to apply"<<endl;
                cout<<"1. For bubble sort"<<endl;
                cout<<"2. For Selection sort"<<endl;
                cout<<"3. For insertion sort"<<endl;
                int n;
                cin>>n;
                if(n==1){
                   a.bubblesort();
                }else if(n==2){
                   a.selectionsort();
                }
                else{
                    a.insertionsort();
                }
                cout<<"After perfoming sorting "<<endl;
                a.get();
                break;
            }

            case 2:{
                cout<<"Enter the size of the array"<<endl;
                int size;
                cin>>size;
                sort<char>a(size);
                a.set();
                a.get();
                cout<<"Which sorting algo do you want to apply"<<endl;
                cout<<"1. For bubble sort"<<endl;
                cout<<"2. For Selection sort"<<endl;
                cout<<"3. For insertion sort"<<endl;
                int n;
                cin>>n;
                if(n==1){
                   a.bubblesort();
                }else if(n==2){
                   a.selectionsort();
                }
                else{
                   a.insertionsort();
                }
                cout<<"After perfoming sorting "<<endl;
                a.get();
                break;
            }
            case 3:{
                cout<<"Enter the size of the array"<<endl;
                int size;
                cin>>size;
                sort<float>a(size);
                a.set();
                a.get();
                cout<<"Which sorting algo do you want to apply"<<endl;
                cout<<"1. For bubble sort"<<endl;
                cout<<"2. For Selection sort"<<endl;
                cout<<"3. For insertion sort"<<endl;
                int n;
                cin>>n;
                if(n==1){
                   a.bubblesort();
                }else if(n==2){
                   a.selectionsort();
                }

                else{
                   a.insertionsort();
                }
                cout<<"After perfoming sorting "<<endl;
                a.get();
                break;
            }
            default:{
                cout<<"Enter a valid choice"<<endl;
                break;
            }

        }
        cout<<"Do you want to continue 0/1"<<endl;
        cin>>flag;
    }
}
