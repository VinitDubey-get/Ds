#include <iostream>
using namespace std;

template<class T>
class Qnode
{
    T e;
    Qnode<T> *next;

public:
    Qnode(T e = 0, Qnode<T> *next = NULL)
    {
        this->e = e;
        this->next = next;
    }
    template<class U>
    friend class MyDoubleendedqueue;
};

template<class T>
class MyDoubleendedqueue
{
    Qnode<T> *front;
    Qnode<T> *back;

public:
    MyDoubleendedqueue()
    {
        front = back = NULL;
    }
    bool empty()
    {
        return (front == NULL);
    }
    T Frontelement()
    {
        if (empty())
        {
            //cout << "linked lists Queue is empty" << endl;
            return NULL;
        }
        else
        {
            return front->e;
        }
    }
    T backelement()
    {
        if (empty())
        {
            //cout << "linked lists Queue is empty" << endl;
            return NULL;
        }
        else
        {
            return back->e;
        }
    }
    void enqueueBack(T e)
    {
        Qnode<T> *p = new Qnode<T>(e);
        if (empty())
        {
            back = front = p;
        }
        else
        {
            back->next = p;
            p->next = NULL;
            back = p;
        }
    }
    void enqueueFront(T e)
    {
        Qnode<T> *p = new Qnode<T>(e);
        if (empty())
        {
            back = front = p;
        }
        else
        {
            p->next = front;
            front = p;
        }
    }
    void dequeueFront()
    {

        if (empty())
        {
            cout << "empty Queue LInked Lists" << endl;
        }
        else
        {
            Qnode<T> *p = front;
            front = front->next;
            delete (p);
        }
    }
    void dequeueBack()
    {

        if (empty())
        {
            cout << "empty Queue LInked Lists" << endl;
        }
        else
        {
            Qnode<T> *p = front;
            while (p->next != NULL && p->next != back)
            {
                p = p->next;
            }
            if (p == back)
            {
                delete (p);
                front = back = NULL;
                return;
            }
            delete (p->next);
            p->next = NULL;
            back = p;
        }
    }
    void display()
    {

        if (empty())
        {
            cout << "empty Queue" << endl;
            return;
        }
        Qnode<T> *p = front;

        while (p != back)
        {
            cout << p->e << " ";
            p = p->next;
        }
        cout << p->e << endl;
    }
};



int main()
{
    MyDoubleendedqueue<int> obj1;
    MyDoubleendedqueue<char> obj2;
    MyDoubleendedqueue<bool> obj3;
    MyDoubleendedqueue<double> obj4;
    
    cout<<"Which data type do you want to work upon"<<endl;
    cout<<"1. Integers"<<endl;
    cout<<"2. Characters"<<endl;
    cout<<"3. Boolean"<<endl;
    cout<<"4. Double"<<endl;
    int ch;
    cin>>ch;
    bool flag=true;
    while(flag){
        cout<<"Menu "<<endl;
        cout<<"1. To print the front element of queue"<<endl;
        cout<<"2. To print the last element of queue"<<endl;
        cout<<"3. Insertion at front"<<endl;
        cout<<"4. Insertion at end"<<endl;
        cout<<"5. deletion at front"<<endl;
        cout<<"6. deletion at back"<<endl;
        cout<<"7. to check whether queue is empty or not"<<endl;
        cout<<"8. To Display queue elements"<<endl;
        int n;
        cin>>n;
        
        if(n==1){
            if(ch==1){
                if(obj1.Frontelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj1.Frontelement()<<endl;
                }
            }
            else if(ch==2){
                      if(obj2.Frontelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj2.Frontelement()<<endl;
                }
            }
            else if(ch==3){
                if(obj3.Frontelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj3.Frontelement()<<endl;
                }
            }
            else if(ch==4){
                if(obj4.Frontelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj4.Frontelement()<<endl;
                }
            }
        }
        else if(n==2){
                          if(ch==1){
                if(obj1.backelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj1.backelement()<<endl;
                }
            }
            else if(ch==2){
                      if(obj2.backelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                   cout<<obj2.backelement()<<endl;
                }
            }
            else if(ch==3){
                if(obj3.backelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj3.backelement()<<endl;
                }
            }
            else if(ch==4){
                if(obj4.backelement()==NULL){
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj4.backelement()<<endl;
                }
            } 
        }
        else if(n==3){
            bool flag1=true;
           while(flag1){
            if(ch==1){
               int data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj1.enqueueFront(data);
            }
            else if(ch==2){
                               char data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj2.enqueueFront(data);
            }
            else if(ch==3){
               bool data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj3.enqueueFront(data);
            }
            else if(ch==4){
               double data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj4.enqueueFront(data);
            }
            cout<<"do you want to insert more elements"<<endl;
            cin>>flag1;
           }
        }
        else if(n==4){
            bool flag1=true;
            while(flag1){
            if(ch==1){
               int data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj1.enqueueBack(data);
            }
            else if(ch==2){
                               char data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj2.enqueueBack(data);
            }
            else if(ch==3){
               bool data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj3.enqueueBack(data);
            }
            else if(ch==4){
               double data;
               cout<<"Enter the element to be inserted"<<endl;
               cin>>data;
               obj4.enqueueBack(data);
            }
            cout<<"do you want to insert more elements   0/1 "<<endl;
            cin>>flag1;
            }
        }
            
       else if(n==5){
            if(ch==1){
               obj1.dequeueFront(); 
            }
            else if(ch==2){
                obj2.dequeueFront();
            }
            else if(ch==3){
                obj3.dequeueFront();
            }
            else if(ch==4){
                 obj4.dequeueFront();
            }
        }
        else if(n==6){
            if(ch==1){
               obj1.dequeueBack(); 
            }
            else if(ch==2){
                obj2.dequeueBack();
            }
            else if(ch==3){
                obj3.dequeueBack();
            }
            else if(ch==4){
                 obj4.dequeueBack();
            }
        }
        else if(n==7){
            if(ch==1){
                if(!obj1.empty()){
                    cout<<"Queue is not empty"<<endl;
                }
                else{
                    cout<<"Queue is  empty"<<endl;
                }
            }
            else if(ch==2){
                                if(!obj2.empty()){
                    cout<<"Queue is not empty"<<endl;
                }
                else{
                    cout<<"Queue is  empty"<<endl;
                }
            }
            else if(ch==3){
                if(!obj3.empty()){
                    cout<<"Queue is not empty"<<endl;
                }
                else{
                    cout<<"Queue is  empty"<<endl;
                }
            }
            else if(ch==4){
                if(!obj4.empty()){
                    cout<<"Queue is not empty"<<endl;
                }
                else{
                    cout<<"Queue is  empty"<<endl;
                }
            }
        
        }
        else if(n==8){
            if(ch==1){
                cout<<"Queue elements are : ";
                obj1.display();
                cout<<endl;
            }
            else if(ch==2){
               cout<<"Queue elements are : ";
                obj2.display();
                cout<<endl;
            }
            else if(ch==3){
               cout<<"Queue elements are : ";
                obj3.display();
                cout<<endl;
            
            }
            else if(ch==4){
                cout<<"Queue elements are : ";
                obj4.display();
                cout<<endl;
            
            }
        }
       cout<<"Do you want to continue 0/1"<<endl;
        cin>>flag;


        
        
    }

    return 0;
}
