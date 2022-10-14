// implememting queue using array assuming the arrya to be circular in nature
#include<iostream>
using namespace std;

class queue{
    int *arr;
    int size;
    int rear;
    int front;
    int qsize;
    public:
    queue(int size){
        this->size=size;
        qsize=0;
        rear=0;
        front=0;
        arr=new int[size];
    }
    int lenght(){
        return qsize;

    }
    bool empty(){
        return (qsize==0);
    }
    int aagevala(){
        if(qsize==0){
            return -1;
        }
        return arr[front];
    }
    int last(){
        if(qsize==0){
            return -1;
        }
        
        return arr[rear-1];
    }
    
    
    void enqueue(int data){
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
    void dequeu(){
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
  queue a(5);
  a.enqueue(1);
  a.enqueue(2);
  a.enqueue(3);
  a.enqueue(4);
  a.enqueue(5);
  a.enqueue(6);
   cout<<"front is "<<a.aagevala()<<endl;
   cout<<"back is "<<a.last()<<endl;
   
 a.dequeu();
 a.dequeu();
 cout<<a.lenght()<<endl;
 cout<<"front is "<<a.aagevala()<<endl;
   cout<<"back is "<<a.last()<<endl;
 a.dequeu();
 a.dequeu();
 cout<<"front is "<<a.aagevala()<<endl;
   cout<<"back is "<<a.last()<<endl;
   

a.enqueue(1);
a.enqueue(2);
a.enqueue(3);
a.enqueue(4);
a.enqueue(2);
cout<<"front is "<<a.aagevala()<<endl;
   cout<<"back is "<<a.last()<<endl;


   
   
   
}