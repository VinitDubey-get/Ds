// implement stacks using linked lsit
#include<iostream>
using namespace std;

template<class T>
class node{
    node*next;
    T data;
    public:
    node(T data,node*loc=NULL){
        this->data=data;
        this->next=loc;
    }

    ~node(){
        next=NULL;
    }
    template<class U>
    friend class stacks;
};

template<class T>
class stacks{
    node<T>*top;
    node<T>*head;
    public:
    stacks(){
        top=head=NULL;
    }
    stacks(T data){
        node<T>* temp=new node<T>(data);
        top=temp;
        head=temp;
    }

    void push(T data){
        // check for empty stack first;
        if(head==NULL){
            node<T>*temp=new node<T>(data);
            top=temp;
            head=temp;
            return;
        }
        node<T>*temp=new node<T>(data);
        top->next=temp;
        top=temp;

    }

    void pop(){
        // check for the empty stack first
        if(head==NULL){
            cout<<"Stack empty"<<endl;
            return;
        }
        if(head->next==NULL){
            node<T>*temp=head;
            head=NULL;
            top=NULL;
            delete temp;
            return;
        }
        node<T>*temp=head;
        while(temp->next!=top){
            temp=temp->next;
        }
        node<T>*del=top;
        top=temp;
        delete del;


    }

    bool isempty(){
         if(head==NULL)
            return true;
         else 
         return false;
    }

    T front(){
        if(head==NULL){
            return NULL;
        }
        else {
            return top->data;
        }
    }

    int length(){
        if(head==NULL){
            return 0;
        }
        int cnt=1;
        node<T>*temp=head;
        while(temp!=top){
            temp=temp->next;
            cnt++;
        }
        return cnt;
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


   
   
//    cout<<"Enter the size of the stack "<<endl;
//    int size;
//    cin>>size;
   stacks<int>a();
   stacks<char>b(size);
   stacks<bool>c(size);
   stacks<double>d(size);

   bool flag=true;
   while(flag){
       cout<<"Which operation do you want to perform"<<endl;
       cout<<"1.Push"<<endl;
       cout<<"2.Pop"<<endl;
       cout<<"3. Top element"<<endl;
       cout<<"4. size"<<endl;
       cout<<"5. check for Empty"<<endl;
       int n;
       cin>>n;

       switch(n){
        case 1:{
            if(choice==1){
                cout<<"Enter the element to insert"<<endl;
                int data;
                cin>>data;
                a.push(data);
            }
            else if(choice==2){
                cout<<"Enter the element to insert"<<endl;
                 char data;
                cin>>data;
                b.push(data);
            }
            else if(choice==3){
                cout<<"Enter the element to insert"<<endl;
                  bool data;
                cin>>data;
                c.push(data);
            }
            else if(choice==4){
                cout<<"Enter the element to insert"<<endl;
                 double data;
                cin>>data;
                d.push(data);
            }
            break;

        }
        case 2:{
            if(choice==1){
               a.pop();
            }
            else if(choice==2){
               b.pop();
            }
            else if(choice==3){
                c.pop();
            } 
            else{
               d.pop();
            }
            break;

        }
        case 3:{
             if(choice==1){
                int top=a.front();
                if(top==NULL){
                    cout<<"Stack empty"<<endl;
                }
                else
                cout<<"Top element is "<<top<<endl;
            }
            else if(choice==2){
                 char top=b.front();
                 if(top==NULL){
                    cout<<"Stack empty"<<endl;
                }
                else
                cout<<"Top element is "<<top<<endl;
            }
            else if(choice==3){
                bool top=c.front();
                if(top==NULL){
                    cout<<"Stack empty"<<endl;
                }
                else
                cout<<"Top element is "<<top<<endl;
            }
            else{
                double top=d.front();
                if(top==NULL){
                    cout<<"Stack empty"<<endl;
                }
                else
                cout<<"Top element is "<<top<<endl;
            }
            break;
        }
        case 4:{
              if(choice==1){
               cout<<"size of the stack is "<<a.length()<<endl;
            }
            else if(choice==2){
                cout<<"size of the stack is "<<b.length()<<endl;
            }
            else if(choice==3){
                cout<<"size of the stack is "<<c.length()<<endl;
            }
            else{
                 cout<<"size of the stack is "<<d.length()<<endl;
            }
            break;
        }
        case 5:{
             if(choice==1){
               if(a.isempty()){
                cout<<"Stack is empty"<<endl;
               }
               else 
               cout<<"Stack is not empty"<<endl;
            }
            else if(choice==2){
                if(b.isempty()){
                cout<<"Stack is empty"<<endl;
               }
               else 
               cout<<"Stack is not empty"<<endl;

            }
            else if(choice==3){
                if(c.isempty()){
                cout<<"Stack is empty"<<endl;
               }
               else 
               cout<<"Stack is not empty"<<endl;
            }
            else{
                if(d.isempty()){
                cout<<"Stack is empty"<<endl;
               }
               else 
               cout<<"Stack is not empty"<<endl;
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