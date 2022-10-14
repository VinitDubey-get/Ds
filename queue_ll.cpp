// implementing queue using linked list taking only one refrence 
#include<iostream>
using namespace std;

class node{
    int data;
    node*next;
    public:
    node(int data,node*loc=NULL){
       this->data=data;
       this->next=loc;
    }
    ~node(){
        data=NULL;
        next=NULL;
    }
    friend class queue;
};

class queue{
    node* rear;
    public:
    queue(){
        rear=NULL;
    }
    queue(int data){
        rear=new node(data);
        rear->next=rear;

    }
    int length(){
        if(rear==NULL){
            return 0;
        }
        int cnt=1;
        node*temp=rear->next;
        while(temp!=rear){
            temp=temp->mext;
            cnt++;
        }
        return cnt;

    }
    int aagevala(){
        if(rear==NULL){
            return -1;
        }
        else{
            return rear->next->data;
        }
    }
    int last(){
        if(rear==NULL){
            return -1;
        }
        else{
            return rear->data;
        }

    }
    bool empty(){
        return (rear==NULL);
    }

    void enqueue(int data){
        if(rear==NULL){
            rear=new node(data);
            rear->next=rear;
            return;
        }
        node*temp=new node(data);
        temp->next=rear->next;
        rear->next=temp;
        rear=temp;
        

    }
    void dequeu(){
        if(rear==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        node*temp=rear->next;
        rear->next=temp->next;
        delete temp;

    }

};
int main(){
    queue a;
    a.enqueue(5);
    a.enqueue(1);
    a.enqueue(3);
    a.enqueue(4);
    a.enqueue(7);
    cout<<a.length()<<endl;

}