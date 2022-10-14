// to create doubly linked list and it's related functions  
// assuming that the tail pointer also exists
#include<iostream>
using namespace std;

template<class T>
class node{
  
    T data;
    node<T> *next;
    node<T> *prev;
    public:
    node(T data,node<T>* next=NULL,node<T> *prev=NULL){
       this->data=data;
       this->next=next;
       this->prev=prev;
    }
    ~node(){
        next=NULL;
        prev=NULL;
       
    }
    template<class U>friend class doublylist;
};

template<class T>
class doublylist{
    node<T>*head;
    node<T>*tail;

    public:
    // blank constructor
    doublylist(){
       head=tail=NULL;
    }
    // with an single element
    doublylist(T data){
        head=new node<T>(data);
        tail=head;
    }
    // display func
    void display(){
         
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        node<T>*temp=head;
        while(temp!=tail->next){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

    // add at begin
    void addatbegin(T data){
        if(head==NULL){
            head=new node<T>(data);
            tail=head;
            return;
        }
        // here 1 or more nodes in the list
        node<T>*temp=new node<T>(data);
        temp->next=head;
        temp->prev=NULL;
        head->prev=temp;
        head=temp;

    }
    // add at last
    void addatend(T data){
        if(tail==NULL){
            tail=new node<T>(data);
            head=tail;
            return ;
        }
        // here means 1 or more nodes in the list
        node<T> *temp=new node<T>(data);
        temp->next=NULL;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;

    }
    // count no of nodes in list
    int count(){
        if(head==NULL){
            return 0;
        }
        int ans=0;
        node<T>*temp=head;
        while(temp!=NULL){
            ans++;
            temp=temp->next;
        }
        return ans;
    }
    // // void emp(){
    // //     if(head==NULL){
    // //         return;
    // //     }
    // //     delete head;
    // //     delete tail;
    // //     return;
    // // }
    // //
    // ~doublylist(){
    //     delete head;
    //     delete tail;
    // }


    // add at position i 
    void addatpos(T data,int i){
        if(i<1){
            cout<<"Not allowed"<<endl;
            return;
        }
        if(i==1){
            addatbegin(data);
            return;
        }
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n<i ){
            n++;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"postion does not exist"<<endl;
            return;
        }
        // need to place at place of temp
        node<T>*add=new node<T>(data);
        temp->prev->next=add;
        add->prev=temp->prev;
        add->next=temp;
        temp->prev=add;
    }
    // add before pos i 
    void addbeforepos(T data,int i){
        if(i<1){
          cout<<"Not allowed"<<endl;
          return;
        }
        if(i==1){
            addatbegin(data);
            return;
        }
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n<i){
            n++;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"position does not exist"<<endl;
            return;
        }
        // add before the temp
        node<T>*add=new node<T>(data);
        temp->prev->next=add;
        add->prev=temp->prev;
        add->next=temp;
        temp->prev=add;

    }

    // add after position
    void addafterpos(T data,int i){
        if(i<0){
            cout<<"not allowed"<<endl;
            return;
        }
        if(i==0){
            addatbegin(data);
            return;

        }
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n!=i){
            n++;
            temp=temp->next;

        }
        if(n==i && temp->next==NULL){
            addatend(data);
            return;
        }
        if(temp==NULL && n!=i){
            cout<<"postion does not exist"<<endl;
            return;
        }
        // now add after the temp
        node<T>*add=new node<T>(data);
        temp->next->prev=add;
        add->next=temp->next;
        temp->next=add;
        add->prev=temp;

    }
    
    // add at inplace of particular element
    void  addatkey(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL && temp->data!=key){
           temp=temp->next;
        }
        if(temp==NULL){
            cout<<"This key does not exist in the list"<<endl;
            return;
        }
        temp->data=data;
    }

    //add before any element
    void addbeforekey(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->data==key){
            addatbegin(data);
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL && temp->data!=key){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"This key does not exist "<<endl;
            return;
        }
        node<T>*add=new node<T>(data);
        temp->prev->next=add;
        add->prev=temp->prev;
        add->next=temp;
        temp->prev=add;

    }
    // add after any element 
    void addafterkey(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(tail->data==key){
            addatend(data);
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL && temp->data!=key){
            temp=temp->next;

        }
        if(temp==NULL){
            cout<<"This key does not exist"<<endl;
            return ;
        }
        node<T>* add=new node<T>(data);
        temp->next->prev=add;
        add->next=temp->next;
        add->prev=temp;
        temp->next=add;
    }

    // deletion functions
    
    // delete at begin
    void deletebegin(){
        if(head==NULL){
            cout<<"list empty"<<endl;
            return;
        }
        if(head==tail){
            node<T>*temp=head;
            head=NULL;
            tail=NULL;
             delete temp;
             return;
        }
        // list has 2 or more node
        node<T>*temp=head;
        head=head->next;
        head->prev=NULL;
        delete temp;
    
    }
    
    // delete at end
    void deleteend(){
        if(head==NULL){
            cout<<"list empty"<<endl;
            return;
        }
        if(head==tail){
              node<T>*temp=head;
            head=NULL;
            tail=NULL;
             delete temp;
             return;
        }
        // list has 2 or more elements
        node<T>*temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete temp;
    }




    // delete at pos
    void deleteatpos(int i){
        if(head==NULL){
            cout<<"list empty"<<endl;
            return;
        }
        if(head==tail && i==1){
            node<T>*temp=head;
            head=tail=NULL;
            delete temp;
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n<i){
            n++;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"position does not exist"<<endl;
            return;
        }
        // now we need to delete the element at temp
        if(temp==tail){
            deleteend();
            return;
        }
        if(temp==head){
            deletebegin();
            return;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;

    }
    // delete after position
    void deleteafterpos(int i){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(i<0){
            cout<<"not allowed"<<endl;
            return;
        }
        if(i==0){
            deletebegin();
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n<i){
            n++;
            temp=temp->next;

        }
        if(temp->next==tail && n==i){
            deleteend();
            return;
        }
        if(temp==NULL || temp==tail){
            cout<<"position does not exist"<<endl;
            return;
        }
          node<T>*todel=temp->next;
        temp->next=todel->next;
        todel->next->prev=temp;

        delete todel;
    }

    // delete before position
    void deletebeforepos(int i){
        if(head==NULL){
            cout<<"list is empty"<<endl;
            return;
        }
        if(head==tail){
            cout<<"only one element in the list"<<endl;
            return;
        }
        if(i<=1){
            cout<<"not allowed"<<endl;
            return;
        }
        if(i==2 ){
            deletebegin();
            return;
        }
        int n=1;
        node<T>*temp=head;
        while(temp!=NULL && n<i){
            n++;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Postion does not exist"<<endl;
            return;
        }
        node<T>*todel=temp->prev;
        temp->prev=todel->prev;
        todel->prev->next=temp;
        delete todel;


    
    }

    // delete a key 
    void deletekey(T key){
        if(head==NULL){
            cout<<"Emoty list"<<endl;
            return;
        }
        if(head->data==key){
            deletebegin();
        }
        if(tail->data==key){
            deleteend();
        }
        node<T>*temp=head;
        while(temp!=NULL  && temp->data!=key){
           temp=temp->next;
        }
        if(temp==NULL){
           cout<<"Key is absent in list"<<endl;
           return;
        }
        // delete the temp
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        delete temp;
    }
    void deleteafterkey(T key){
        if(head==NULL){
            cout<<"Empty list "<<endl;
            return;
        }
        if(head==tail){
            cout<<"only one node in list"<<endl;
            return;
        }
        if(tail->prev->data==key){
            deleteend();
        }
        node<T>*temp=head;
        while(temp!=tail && temp->data!=key){
            temp=temp->next;
        } 
        if(temp->data!=key){
            cout<<"key absent "<<endl;
            return;
        }
        if(temp==tail){
            cout<<"no node after this in list"<<endl;
            return ;
        }
        node<T>*todel=temp->next;
        temp->next=todel->next;
        todel->next->prev=temp;
        delete todel;



    }
     void deletebeforekey(T key){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(head==tail){
            cout<<"1 node in list"<<endl;
            return;
        }
        if(head->next->data==key){
            deletebegin();
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL && temp->data!=key){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Key is absent"<<endl;
            return;
        }
        node<T>*todel=temp->prev;
        todel->prev->next=temp;
        temp->prev=todel->prev;
        delete todel;
        
    }

    // creating an ordered linked list
    void createoredered(T data){
        if(head==NULL){
            head=new node<T>(data,head,tail);
            tail=head;
            return;
        }
        if(data<=head->data){
            addatbegin(data);
            return;
        }
        if(data>=tail->data){
            addatend(data);
            return;
        }
        // means we need to insert in middle 
        node<T>*temp=head;
        while(temp->data<data){
            temp=temp->next;
        }
        // here condition arrives when temp->data becomes greater or equal to the give then we need to insert at back of this temp
        node<T>*add=new node<T>(data);
        temp->prev->next=add;
        add->prev=temp->prev;
        add->next=temp;
        temp->prev=add;
        return;
    }

    // sorting the linked list without changing the links only swapping the data into it
    void selectionsort(){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(head==tail){
            cout<<"Only one node in the list"<<endl;
            return ;
        }
        node<T>*temp=head;
        while(temp!=tail){
            node<T>* q=temp->next;
            while(q!=NULL){
                if(temp->data > q->data){
                    swap(temp->data,q->data);
                }
                q=q->next;
            }
            temp=temp->next;
        }
    }

    // sorting using bubble sort
    void bubblesort(){
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(head==tail){
            cout<<"Only one node present in the list"<<endl;
            return;
        }
        int n=count();
        for(int i=0;i<n-1;i++){
            node<T>*p=head;
            node<T>*q=head->next;
            for(int j=0;j<n-i-1;j++){
                if(p->data > q->data){
                    swap(p->data,q->data);

                }
                p=p->next;
                q=q->next;
            }
        }
    }

    // reversing the list
    void reverse(){
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(head==NULL){
            cout<<"Only one node in lsit"<<endl;
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL){
            swap(temp->next,temp->prev);
            temp=temp->prev;
        }
        swap(head,tail);
    }

    void concatenate(doublylist b){
        if(head==NULL){
            head=b.head;
            tail=b.tail;
            return;

        }
        tail->next=b.head;
        b.head->prev=tail;
        tail=b.tail;
        return;

    }

     // merging the two linked list doubly
     doublylist merge(doublylist b){
        if(head==NULL){
            b.bubblesort();
            return b;
        }
        if(b.head==NULL){
            bubblesort();
            return *this;
        }
        bubblesort();
        b.bubblesort();
        node<T>*p=head;
        node<T>*q=b.head;
        doublylist ans;
        while(p!=NULL && q!=NULL){
            if(p->data < q->data){
                ans.addatend(p->data);
                p=p->next;
            }
            else{
                ans.addatend(q->data);
                q=q->next;
            }
        }
        if(p==NULL){
            while(q!=NULL){
                ans.addatend(q->data);
                q=q->next;
            }
        }
        else{
            while(p!=NULL){
                ans.addatend(p->data);
                p=p->next;
            }
        }
        return ans;

     }
    
    
};





int main(){
     cout<<"Which data type do you want to workupon :- "<<endl;
    cout<<"1.Integers"<<endl;
    cout<<"2.Characters"<<endl;
    cout<<"3.Boolean"<<endl;
    cout<<"4.Double"<<endl;
    
    int dt;
    cin>>dt;
    
    doublylist<int> obj1;
    doublylist<int> obj2;
    doublylist<char> obj3;
    doublylist<char> obj4;
    doublylist<double> obj5;
    doublylist<double> obj6;
    doublylist<bool> obj7;
    doublylist<bool> obj8;
    
    bool flag=true;
    while(flag){
        int n;
        cout<<"Menu"<<endl;
        cout<<"1.Insertion"<<endl;
        cout<<"2.Deletion"<<endl;
        cout<<"3.Creating a ordered list"<<endl;
        cout<<"4.Sorting"<<endl;
        cout<<"5.Reverse"<<endl;
        cout<<"6.Concatate"<<endl;
        cout<<"7.Merging"<<endl;
        cout<<"Which operation you wish to perform:";
        cin>>n;
        if(n==1){
            bool flag1=true;
            while(flag1){
                int n1;
                cout<<"Menu for insertion"<<endl;
                cout<<"1.Add at Start"<<endl;
                cout<<"2.Add at End"<<endl;
                cout<<"3.Add at Position"<<endl;
                cout<<"4.Add before Position"<<endl;
                cout<<"5.Add after Position"<<endl;
                cout<<"6.Add at Element"<<endl;
                cout<<"7.Add before Element"<<endl;
                cout<<"8.Add after Element"<<endl;
                cout<<"Which operation you wish to perform"<<endl;
                cin>>n1;
                if(n1==1){
                    cout<<"Enter the element you wish to add";
                    if(dt==1){
                            int ele;
                            cin>>ele;
                            obj1.addatbegin(ele);
                            obj1.display();
                    }
                    else if(dt==2){
                            char ele;
                            cin>>ele;
                            obj3.addatbegin(ele);
                            obj3.display();
                    }
                    else if(dt==3){
                            double ele;
                            cin>>ele;
                            obj5.addatbegin(ele);
                            obj5.display();
                    }
                    else if(dt==4){
                        bool ele;
                            cin>>ele;
                            obj7.addatbegin(ele);
                            obj7.display();
                    }
                    
                }
                else if(n1==2){
                      cout<<"Enter the element you wish to add";
                    if(dt==1){
                         int ele;
                        cin>>ele;
                        obj1.addatend(ele);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                         char ele;
                        cin>>ele;
                        obj3.addatend(ele);
                        obj3.display();
                    }
                    else if(dt==3){
                         double ele;
                        cin>>ele;
                        obj5.addatend(ele);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool ele;
                        cin>>ele;
                        obj7.addatend(ele);
                        obj7.display();
                    }
                }
                else if(n1==3){
                     cout<<"Enter the element you wish to add"<<endl;
                   
                    
                    if(dt==1){
                        int ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj1.addatpos(ele,pos);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                         char ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj3.addatpos(ele,pos);
                        obj3.display();
                    }
                    else if(dt==3){
                         double ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj5.addatpos(ele,pos);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj7.addatpos(ele,pos);
                        obj7.display();
                    }
                }
                else if(n1==4){
                     cout<<"Enter the element you wish to add"<<endl;
                   
                    
                    if(dt==1){
                        int ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj1.addbeforepos(ele,pos);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                        char ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj3.addbeforepos(ele,pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        double ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj5.addbeforepos(ele,pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        bool ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj7.addbeforepos(ele,pos);
                        obj7.display();
                    }
                }
                else if(n1==5){
                    cout<<"Enter the element you wish to add"<<endl;
                   
                    
                    if(dt==1){
                        int ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj1.addafterpos(ele,pos);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                        char ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj3.addafterpos(ele,pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        double ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj5.addafterpos(ele,pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        bool ele;
                        cin>>ele;
                        int pos;
                        cout<<"enter the position at which you wish to add"<<endl;
                        cin>>pos;
                        obj7.addafterpos(ele,pos);
                        obj7.display();
                    }
                }
                else if(n1==6){
                    if(dt==1){
                        int key;
                        int ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj1.addatkey(ele,key);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                         char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj3.addatkey(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                         double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj5.addatkey(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj7.addatkey(ele,key);
                        obj7.display();
                    }
                }
                else if(n1==7){
                    if(dt==1){
                         int key;
                        int ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj1.addbeforekey(ele,key);
                        obj1.display();
                    }
                    else if(dt==2){
                        char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj3.addbeforekey(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                         double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj5.addbeforekey(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj7.addbeforekey(ele,key);
                        obj7.display();
                    }
                }
                else if(n1==8){
                    if(dt==1){
                        int key;
                        int ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj1.addafterkey(ele,key);
                        obj1.display();
                    }
                    else if(dt==2){
                        char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj3.addafterkey(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                        double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj5.addafterkey(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                        bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj7.addafterkey(ele,key);
                        obj7.display();
                    }
                }
                cout<<"Do you wish to add more element:";
                cin>>flag1;
                if(flag1==0){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if(n==2){
            bool flag2=true;
            int n2;
            while(flag2){
                cout<<"Menu for Deletion"<<endl;
                cout<<"1.Delete at Start"<<endl;
                cout<<"2.Delete at End"<<endl;
                cout<<"3.Delete at Position"<<endl;
                cout<<"4.Delete before Position"<<endl;
                cout<<"5.Delete after Position"<<endl;
                cout<<"6.Delete at Element"<<endl;
                cout<<"7.Delete before Element"<<endl;
                cout<<"8.Delete after Element"<<endl;
                cout<<"Which operation you wish to perform"<<endl;
                cin>>n2;
                if(n2==1){
                    if(dt==1){
                         obj1.deletebegin();
                         obj1.display();
                    }
                    else if(dt==2){
                         obj3.deletebegin();
                         obj3.display();
                    }
                    else if(dt==3){
                         obj5.deletebegin();
                         obj5.display();
                    }
                    else if(dt==4){
                         obj7.deletebegin();
                         obj7.display();
                    }
                }
                else if(n2==2){
                    if(dt==1){
                         obj1.deleteend();
                         obj1.display();
                    }
                    else if(dt==2){
                        obj3.deleteend();
                         obj3.display();
                    }
                    else if(dt==3){
                        obj5.deleteend();
                         obj5.display();
                    }
                    else if(dt==4){
                        obj7.deleteend();
                         obj7.display();
                    }
                }
                else if(n2==3){
                    int pos;
                    cout<<"Enter the position at which you wish to delete";
                    cin>>pos;
                     if(dt==1){
                        obj1.deleteatpos(pos);
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.deleteatpos(pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.deleteatpos(pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.deleteatpos(pos);
                        obj7.display();
                    }
                }
                else if(n2==4){
                   int pos;
                    cout<<"Enter the position before which you wish to delete";
                    cin>>pos;
                     if(dt==1){
                        obj1.deletebeforepos(pos);
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.deletebeforepos(pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.deletebeforepos(pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.deletebeforepos(pos);
                        obj7.display();
                    }
                }
                else if(n2==5){
                    int pos;
                    cout<<"Enter the position after which you wish to delete";
                    cin>>pos;
                     if(dt==1){
                        obj1.deleteafterpos(pos);
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.deleteafterpos(pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.deleteafterpos(pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.deleteafterpos(pos);
                        obj7.display();
                    }
                }
                else if(n2==6){
                     if(dt==1){
                          int key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj1.deletekey(key);
                           obj1.display();
                    }
                    else if(dt==2){
                        char key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj3.deletekey(key);
                           obj3.display();
                    }
                    else if(dt==3){
                        double key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj5.deletekey(key);
                           obj5.display();
                    }
                    else if(dt==4){
                        bool key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj7.deletekey(key);
                           obj7.display();
                    }
                }
                else if(n2==7){
                    if(dt==1){
                         int key;
                         cout<<"Enter the element before which you wish to delete";
                         cin>>key;
                         obj1.deletebeforekey(key);
                         obj1.display();
                    }
                    else if(dt==2){
                        char key;
                         cout<<"Enter the element before which you wish to delete";
                         cin>>key;
                         obj3.deletebeforekey(key);
                         obj3.display();
                    }
                    else if(dt==3){
                        double key;
                         cout<<"Enter the element before which you wish to delete";
                         cin>>key;
                         obj5.deletebeforekey(key);
                         obj5.display();
                    }
                    else if(dt==4){
                        bool key;
                         cout<<"Enter the element before which you wish to delete";
                         cin>>key;
                         obj7.deletebeforekey(key);
                         obj7.display();
                    }
                }
                else if(n2==8){
                    if(dt==1){
                         int key;
                        cout<<"Enter the element after which you wish to delete";
                        cin>>key;
                        obj1.deleteafterkey(key);
                        obj1.display();
                    }
                    else if(dt==2){
                        char key;
                        cout<<"Enter the element after which you wish to delete";
                        cin>>key;
                        obj3.deleteafterkey(key);
                        obj3.display();
                    }
                    else if(dt==3){
                        double key;
                        cout<<"Enter the element after which you wish to delete";
                        cin>>key;
                        obj5.deleteafterkey(key);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool key;
                        cout<<"Enter the element after which you wish to delete";
                        cin>>key;
                        obj7.deleteafterkey(key);
                        obj7.display();
                    }
                }
                cout<<"Do you wish to peform more operation(0/1);";
                cin>>flag2;
                if(flag2==0){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if(n==3){
           if(dt==1){
                     bool flag3=true;
                    while(flag3){
                        int n3;
                        cout<<"enter the element:";
                        cin>>n3;
                        obj1.createoredered(n3);
                        obj1.display();
                        cout<<"Do you want to enter more element(0/1):";
                        cin>>flag3;
                        if(flag3==0){
                            break;
                        }
                        else{
                            continue;
                        }
                    }    
            }
            else if(dt==2){
                       bool flag3=true;
                    while(flag3){
                        char n3;
                        cout<<"enter the element:";
                        cin>>n3;
                        obj3.createoredered(n3);
                        obj3.display();
                        cout<<"Do you want to enter more element(0/1):";
                        cin>>flag3;
                        if(flag3==0){
                            break;
                        }
                        else{
                            continue;
                        }
                    }      
            }
            else if(dt==3){
                      bool flag3=true;
                    while(flag3){
                        double n3;
                        cout<<"enter the element:";
                        cin>>n3;
                        obj5.createoredered(n3);
                        obj5.display();
                        cout<<"Do you want to enter more element(0/1):";
                        cin>>flag3;
                        if(flag3==0){
                            break;
                        }
                        else{
                            continue;
                        }
                    }       
            }
            else if(dt==4){
                       bool flag3=true;
                    while(flag3){
                        bool n3;
                        cout<<"enter the element:";
                        cin>>n3;
                        obj7.createoredered(n3);
                        obj7.display();
                        cout<<"Do you want to enter more element(0/1):";
                        cin>>flag3;
                        if(flag3==0){
                            break;
                        }
                        else{
                            continue;
                        }
                    }      
            }
        }
        else if(n==4){
            bool flag4=true;
            while(flag4){
                int n4;
                cout<<"Menu for sorting"<<endl;
                cout<<"1.Bubble sort"<<endl;
                cout<<"2.Selection sort"<<endl;
                cout<<"Which sorting you wish to perform;";
                cin>>n4;
                if(n4==1){
                    if(dt==1){
                        obj1.bubblesort();
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.bubblesort();
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.bubblesort();
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.bubblesort();
                        obj7.display();
                    }
                    // obj1.bubblesort();
                    // obj1.display();
                }
                else if(n4==2){
                    if(dt==1){
                         obj1.selectionsort();
                         obj1.display();
                    }
                    else if(dt==2){
                         obj3.selectionsort();
                        obj3.display();
                    }
                    else if(dt==3){
                         obj5.selectionsort();
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.selectionsort();
                        obj7.display();
                    }
                }
                cout<<"DO you want to continue(0/1):";
                cin>>flag4;
                if(flag4==0){
                    break;
                }
                else{
                    continue;
                }
            }
        }
        else if(n==5){
            if(dt==1){
                obj1.reverse();
                obj1.display();
            }
            else if(dt==2){
                obj3.reverse();
                obj3.display();
            }
            else if(dt==3){
                obj5.reverse();
                obj5.display();
            }
            else if(dt==4){
                obj7.reverse();
                obj7.display();
            }
        }
        else if(n==6){
           cout<<"Insert element to add at end of second list"<<endl;
           bool flag2=true;
           while(flag2){
               if(dt==1){
                   int ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj2.addatend(ele);
                obj2.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==2){
                    char ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj4.addatend(ele);
                obj4.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==3){
                    double ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj6.addatend(ele);
                obj6.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==4){
                      bool ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj8.addatend(ele);
                obj8.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
                
                
           }
           if(dt==1){
               obj1.concatenate(obj2);
            obj1.display();
           }
           else if(dt==2){
               obj3.concatenate(obj4);
            obj3.display();
           }
           else if(dt==3){
               obj5.concatenate(obj6);
            obj5.display();
           }
           else if(dt==4){
               obj7.concatenate(obj8);
            obj7.display();
           }
           
        }
        else if(n==7){
            cout<<"Insert element to add at end of second list"<<endl;
           bool flag2=true;
           while(flag2){
               if(dt==1){
                   int ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj2.addatend(ele);
                obj2.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==2){
                    char ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj4.addatend(ele);
                obj4.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==3){
                    double ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj6.addatend(ele);
                obj6.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==4){
                      bool ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj8.addatend(ele);
                obj8.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
                
                
           }
            if(dt==1){
               obj1=obj1.merge(obj2);
            obj1.display();
           }
           else if(dt==2){
              obj3= obj3.merge(obj4);
            obj3.display();
           }
           else if(dt==3){
               obj5=obj5.merge(obj6);
            obj5.display();
           }
           else if(dt==4){
               obj7=obj7.merge(obj8);
            obj7.display();
           }
        }
        cout<<"DO you wish to continue(0/1):";
        cin>>flag;
        if(flag==0){
            break;
        }
        else{
            continue;
        }
    }
    
    return 0;

     
}