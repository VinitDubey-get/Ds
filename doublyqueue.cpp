#include <iostream>
using namespace std;

class Qnode
{
    int e;
    Qnode *next;

public:
    Qnode(int e = 0, Qnode *next = NULL)
    {
        this->e = e;
        this->next = next;
    }
    friend class MyDoubleendedqueue;
};

class MyDoubleendedqueue
{
    Qnode *front;
    Qnode *back;

public:
    MyDoubleendedqueue()
    {
        front = back = NULL;
    }
    bool empty()
    {
        return (front == NULL);
    }
    int Frontelement()
    {
        if (empty())
        {
            cout << "linked lists Queue is empty" << endl;
            return -1;
        }
        else
        {
            return front->e;
        }
    }
    int backelement()
    {
        if (empty())
        {
            cout << "linked lists Queue is empty" << endl;
            return -1;
        }
        else
        {
            return back->e;
        }
    }
    void enqueueBack(int e)
    {
        Qnode *p = new Qnode(e);
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
    void enqueueFront(int e)
    {
        Qnode *p = new Qnode(e);
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
            Qnode *p = front;
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
            Qnode *p = front;
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
            cout << "empty Queue LInked Lists" << endl;
            return;
        }
        Qnode *p = front;

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
    MyDoubleendedqueue obj;

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
