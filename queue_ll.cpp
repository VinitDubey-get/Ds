// implementing queue using linked list taking only one refrence 
#include<iostream>
using namespace std;

template<class T>
class node{
    T data;
    node<T>*next;
    public:
    node(T data,node*loc=NULL){
       this->data=data;
       this->next=loc;
    }
    ~node(){
        data=NULL;
        next=NULL;
    }
    template<class U>
    friend class Myqueue;
};

template<class T>
class Myqueue{
    node<T>* rear;
    public:
    Myqueue(){
        rear=NULL;
    }
    Myqueue(T data){
        rear=new node<T>(data);
        rear->next=rear;

    }
    int length(){
        if(rear==NULL){
            return 0;
        }
        int cnt=1;
        node<T>*temp=rear->next;
        while(temp!=rear){
            temp=temp->next;
            cnt++;
        }
        return cnt;

    }
    T aagevala(){
        if(rear==NULL){
            return NULL;
        }
        else{
            return rear->next->data;
        }
    }
    T last(){
        if(rear==NULL){
            return NULL;
        }
        else{
            return rear->data;
        }

    }
    bool empty(){
        return (rear==NULL);
    }

    void enqueue(T data){
        if(rear==NULL){
            rear=new node<T>(data);
            rear->next=rear;
            return;
        }
        node<T>*temp=new node<T>(data);
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
        

    }
    void dequeue(){
        if(rear==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        else if(rear->next==rear){
           
           node<T>*temp=rear;
           rear=NULL;
           delete temp;
           return;
        }
        node<T>*temp=rear->next;
        rear->next=temp->next;
        delete temp;

    }

};
int main(){
    cout<<"which datatype do you want to work upon "<<endl;
   cout<<"1. Integers"<<endl;
   cout<<"2. Characters"<<endl;
   cout<<"3. Boolean"<<endl;
   cout<<"4. Double"<<endl;
   int choice;
   cin>>choice;


   
   
  
   Myqueue<int>a;
   Myqueue<char>b;
   Myqueue<bool>c;
   Myqueue<double>d;

   bool flag=true;
   while(flag){
       cout<<"Which operation do you want to perform"<<endl;
       cout<<"1.Enqueue"<<endl;
       cout<<"2.Dequeue"<<endl;
       cout<<"3. front element"<<endl;
       cout<<"4. Rear Element"<<endl;
       cout<<"5. Length of queue"<<endl;
       cout<<"6. check for Empty"<<endl;
       int n;
       cin>>n;

       switch(n){
        case 1:{
            if(choice==1){
                cout<<"Enter the element to insert"<<endl;
                int data;
                cin>>data;
                a.enqueue(data);
            }
            else if(choice==2){
                cout<<"Enter the element to insert"<<endl;
                 char data;
                cin>>data;
                b.enqueue(data);
            }
            else if(choice==3){
                cout<<"Enter the element to insert"<<endl;
                  bool data;
                cin>>data;
                c.enqueue(data);
            }
            else if(choice==4){
                cout<<"Enter the element to insert"<<endl;
                 double data;
                cin>>data;
                d.enqueue(data);
            }
            break;

        }
        case 2:{
            if(choice==1){
               a.dequeue();
            }
            else if(choice==2){
               b.dequeue();
            }
            else if(choice==3){
                c.dequeue();
            } 
            else{
               d.dequeue();
            }
            break;

        }
        case 3:{
             if(choice==1){
                int top=a.aagevala();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Front element is "<<top<<endl;
            }
            else if(choice==2){
                 char top=b.aagevala();
                 if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Front element is "<<top<<endl;
            }
            else if(choice==3){
                bool top=c.aagevala();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Front element is "<<top<<endl;
            }
            else{
                double top=d.aagevala();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Front element is "<<top<<endl;
            }
            break;
        }
        case 4:{
            if(choice==1){
                int top=a.last();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Rear element is "<<top<<endl;
            }
            else if(choice==2){
                 char top=b.last();
                 if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Rear element is "<<top<<endl;
            }
            else if(choice==3){
                bool top=c.last();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Rear element is "<<top<<endl;
            }
            else{
                double top=d.last();
                if(top==NULL){
                    cout<<"Queue empty"<<endl;
                }
                else
                cout<<"Rear element is "<<top<<endl;
            }
            break;
        }
       
        case 5:{
              if(choice==1){
               cout<<"size of the Queue is "<<a.length()<<endl;
            }
            else if(choice==2){
                cout<<"size of the Queue is "<<b.length()<<endl;
            }
            else if(choice==3){
                cout<<"size of the Queue is "<<c.length()<<endl;
            }
            else{
                 cout<<"size of the Queue is "<<d.length()<<endl;
            }
            break;
        }
        case 6:{
             if(choice==1){
               if(a.empty()){
                cout<<"Queue is empty"<<endl;
               }
               else 
               cout<<"Queue is not empty"<<endl;
            }
            else if(choice==2){
                if(b.empty()){
                cout<<"Queue is empty"<<endl;
               }
               else 
               cout<<"Queue is not empty"<<endl;

            }
            else if(choice==3){
                if(c.empty()){
                cout<<"Queue is empty"<<endl;
               }
               else 
               cout<<"Queue is not empty"<<endl;
            }
            else{
                if(d.empty()){
                cout<<"Queue is empty"<<endl;
               }
               else 
               cout<<"Queue is not empty"<<endl;
            }
            break;
        }
         default:{
            cout<<"Enter right choice"<<endl;
            break;
        }
        

       

       }
        cout<<"Do you want to conitnue"<<endl;
        cin>>flag;
       



   }
}