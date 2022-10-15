// implememting queue using array assuming the arrya to be circular in nature
#include<iostream>
using namespace std;

template<class T>
class Myqueue{
    T *arr;
    int size;
    int rear;
    int front;
    int qsize;
    public:
    Myqueue(int size){
        this->size=size;
        qsize=0;
        rear=NULL;
        front=NULL;
        arr=new T[size];
    }
    int length(){
        return qsize;

    }
    bool empty(){
        return (qsize==0);
    }
    T aagevala(){
        if(qsize==0){
            return NULL;
        }
        return arr[front];
    }
    T last(){
        if(qsize==0){
            return NULL;
        }
        
        return arr[rear-1];
    }
    
    
    void enqueue(T data){
      // check for the empty list first
      if(qsize==0){
          front=rear=0;
          arr[rear]=data;
          rear++;
          qsize++;
          return;
      }
      if(qsize==size ){
          cout<<"List full"<<endl;
          return;
      }
      if(front!=0 && rear==size){
          rear=0;
      }
      arr[rear]=data;
      rear++;
      qsize++;
      
    }
    void dequeue(){
        // check for empty queue first
        if(qsize==0){
            cout<<"Empty queue"<<endl;
            return;
        }
        if(front==size-1){
            front=0;
        }
        else{
            front=front+1;
        }
        qsize--;
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


   
   cout<<"Enter the size of the queue "<<endl;
   int size;
   cin>>size;
   
  
   Myqueue<int>a(size);
   Myqueue<char>b(size);
   Myqueue<bool>c(size);
   Myqueue<double>d(size);

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