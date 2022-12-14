// to apply binary search
#include<iostream>
using namespace std;


template<typename T>class search{
    T* arr;
    int size;
    public:
    search(int size=0){
        this->size=size;
        arr=new T[size];
        for(int i=0;i<size;i++){
            arr[i]=0;
        }
    }
    void set(){
        cout<<"Enter the elements in sorted order of the list"<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
    }
    void get(){
        cout<<"The elements of the list are :-  "<<endl;
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    // iterative
    int iterativels(T key){
       int st=0;
       int end=size-1;
       while(st<end){
        int mid=(st+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        else if(arr[mid]>key){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
       }
       return -1;
    }

    // recursive
    private:
    int solve(T key,int st,int end){
        // base case
        if(st>end){
            return -1;
        }
        int mid=(st+end)/2;
        if(arr[mid]==key){
            return mid;
        }
        

        if(arr[mid]>key){
            solve(key,st,mid-1);
        }
        else{
            solve(key,mid+1,end);
        }
    }
    public:
    int recursivels( T key){
        return solve(key,0,size-1);
    }

};

int main(){

    bool flag=true;
    while(flag){
        cout<<"Enter the choice of data type"<<endl;
        cout<<"1. For interger"<<endl;
        cout<<"2. For characters"<<endl;
        cout<<"3. For flaot"<<endl;
        
        
        int c;
        cin>>c;
        
        cout<<"Enter the size of the array"<<endl;
        int size;
        cin>>size;
        if(c==1){
          search<int>A1(size);
           A1.set();
             A1.get();
             cout<<"Enter the vaule to be searched for"<<endl;
             int key;
           cin>>key;
           int ans=A1.recursivels(key);
           if(ans==-1){
            cout<<"The value is not present in the list"<<endl;
           }
           else{
            cout<<"The value is present at index "<<ans<<" in the list"<<endl;
           }


        }
        else if(c==2){
          search<char>A2(size);
           A2.set();
           
             A2.get();
             cout<<"Enter the vaule to be searched for"<<endl;
             char key;
           cin>>key;
           int ans=A2.iterativels(key);
           if(ans==-1){
            cout<<"The value is not present in the list"<<endl;
           }
           else{
            cout<<"The value is present at index "<<ans<<" in the list"<<endl;
           }
        }
        else if(c==3){
           search<float>A3(size);
            A3.set();
            
             A3.get();
             cout<<"Enter the vaule to be searched for"<<endl;
             float key;
           cin>>key;
           int ans=A3.recursivels(key);
           if(ans==-1){
            cout<<"The value is not present in the list"<<endl;
           }
           else{
            cout<<"The value is present at index "<<ans<<" in the list"<<endl;
           }
        }
        else{
            cout<<"You entered a wrong choice"<<endl;
        }

       
      
        cout<<"Do you want to continue :- 0/1"<<endl;
        cin>>flag;
    }




    // search<char>A(5);
    // A.set();
    // A.get();
    // cout<<A.iterativels('A')<<endl;
}
