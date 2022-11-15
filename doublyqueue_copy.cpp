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
    int key;
    int b;
    MyDoubleendedqueue<int> obj;

    do
    {
        cout << "Enter the choice from the given  option" << endl;
        cout << "1. Empty" << endl;
        cout << "2. Front of queue" << endl;
        cout << "3. BAck of queue" << endl;
        cout << "4. BAck Enqueue in queue" << endl;
        cout << "5. Front Enqueue in queue" << endl;
        cout << "6. Front dequeue in queue" << endl;
        cout << "7. back dequeue in queue" << endl;
        cin >> key;
        switch (key)
        {
        case 1:
            if (obj.empty())
            {
                cout << "Empty circular Linked lists Queue" << endl;
            }
            else
            {
                cout << "Non empty" << endl;
            }
            break;
        case 2:
            cout << obj.Frontelement() << endl;
            break;

        case 3:
            cout << obj.backelement() << endl;
            break;

        case 4:
            obj.enqueueBack(9);
            obj.enqueueBack(95);
            obj.enqueueBack(954);
            obj.enqueueBack(9549);
            obj.enqueueBack(95490);
            obj.enqueueBack(954948);
            obj.display();

            break;
        case 5:
            obj.enqueueFront(7);
            obj.enqueueFront(75);

            obj.display();

            break;
        case 6:
            obj.dequeueFront();
            obj.display();
            break;
        case 7:
            obj.dequeueBack();
            obj.display();
            break;
        }
        cout << "Enter 0 if want to exit  else press 1" << endl;
        cin >> b;
    } while (b != 0);
    return 0;
}



/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    MyDounleendedqueue<int> obj1;
    MyDounleendedqueue<char> obj1;
    MyDounleendedqueue<bool> obj1;
    MyDounleendedqueue<double> obj1;
    
    cout<<"Which data type do you want to work upon"<<endl;
    cout<<"1. Integers"<<endl;
    cout<<"2. Characters"<<endl;
    cout<<"3. Boolean"<<endl;
    cout<<"4. Double"<<endl;
    int ch;
    cin>>ch;
    
    while(true){
        cout<<"Menu "<<endl;
        cout<<"1. To print the front element of queue"<<endl;
        cout<<"2. To print the last element of queue"<<endl;
        cout<<"3. Insertion at front"<<endl;
        cout<<"4. Insertion at end"<<endl;
        cout<<"5. deletion at front"<<endl;
        cout<<"6. deletion at back"<<endl;
        cout<<"7. to check whether queue is empty or not"<<endl;
        int n;
        cin>>n;
        
        if(n==1){
            if(ch==1){
                if(obj1.Frontelement()==-1{
                    cout<<"queue is empty"<<endl;
                }
                else{
                    cout<<obj1.Frontelement()<<endl;
                }
            }
            else if(ch==2){
                
            }
            else if(ch==3){
                
            }
            else if(ch==4){
                
            }
        }
        
        
    }

    return 0;
}
