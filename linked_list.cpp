// creating linked list and applying all insertion and deletion in it
#include<iostream>
using namespace std;

template<class T>
class node{
   T data;
   node<T> *next;
   public:
   node(T data,node<T> *loc=NULL){
    this->data=data;
    this->next=loc;
   }

   ~node(){
   }
   template<class U>friend class linkedlist;
};
template<class T>
class linkedlist{
    node<T>*head;
    
    
    public:
    linkedlist(){
        head=NULL;
    }
    linkedlist(T data){
       head=new node<T>(data);
    }
    // display LL
    void display(){
        if(head==NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }

    // count length
    int length(){
        if(head==NULL){
            return 0;
        }
        int cnt=0;
        node<T>*temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    // add at starting of ll
    void addstart(T data){
        head=new node<T>(data,head);
    }
    // add at last
    void addlast(T data){
        if(head==NULL){
            head=new node<T>(data,head);
            return;
        }
        node<T>*temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new node<T>(data);

        
    }
    // add at pos i 
    void addatpos(T data,int i){
        if(i<1){
            cout<<"not allowed"<<endl;
            return;
        }
        if(i==1){
            addstart(data);
            return;
        }
        if(head==NULL){
            cout<<"List is empty";
            return;
        }
        int n=1;
        node<T>*prev,*temp;
        temp=head;
        prev=head;
        while(n<i && temp!=NULL){
            prev=temp;
            temp=temp->next;
            n++;
        }
        if(temp==NULL){
            cout<<"position does not exist"<<endl;
            return;
        }
        prev->next=new node<T>(data,temp);
    }

    // add after pos i
    void addafterpos(T data,int i){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        int n=1;
        node <T>*temp=head;
        while(n<i && temp!=NULL){
            n++;
            temp=temp->next;
        }
        if(temp==NULL){
           cout<<"position does not exist"<<endl;
           return ;
        }
        node <T>*p=new node<T>(data,temp->next);
        temp->next=p;
    }

    // add before pos i
    void addbeforepos(T data,int i){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(i==1){
            addstart(data);
            return;
        }
        node<T>*prev,*temp;
        prev=head;
        temp=head;
        int n=1;
        while(n<i && temp!=NULL){
            prev=temp;
            temp=temp->next;
            n++;
        }
        if(prev==NULL){
           cout<<"postion doe not exists"<<endl;
           return;
        }
        else{
            prev->next=new node<T>(data,temp);
        }

    }

    // add after element n
    void addafterelem(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        node<T> *temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                break;
            }
            
            temp=temp->next;
            
        }
        if(temp==NULL){
            cout<<"Element does not exist to insert"<<endl;
            return;
        }
        temp->next=new node<T>(data,temp->next);

        
    }

    //add before element n
    void addbeforeelem(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        if(head->data==key){
            addstart(data);
            return;
        }
        node<T>*prev,*temp;
        prev=NULL;
        temp=head;
        while(temp!=NULL){
            if(temp->data==key){
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Element does not exits"<<endl;
            return;
        }
        prev->next=new node<T>(data,temp);
    }

    // add at element
    void addatelem(T data,T key){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;
        }
        node<T>*temp=head;
        while(temp!=NULL && temp->data!=key){
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Element does not exist"<<endl;
            return;
        }
        temp->data=key;
        return;

    }


    // functions to delete 
    //deletion from begin
    void deletebegin(){
        if(head==NULL){
            cout<<"List already empty"<<endl;
            return;
        }
        node<T>*temp=head;
        head=head->next;
        delete temp;
    }
    // delete at end
    void deleteend(){
        if(head==NULL){
            cout<<"List alredy empty"<<endl;
            return;
        }
        if(head->next==NULL){
            node<T>*temp=head;
            delete temp;
            head=NULL;
            return;
        }
        node<T>*prev=NULL;
        node<T>*curr=head;
        while(curr->next!=NULL){
            prev=curr;
            curr=curr->next;
        }
        delete curr;
        prev->next=NULL;
    }

    // delete at particular pos i 
    void deletepos(int i){
        if(head==NULL){
            cout<<"List already empty"<<endl;
            return;
        }
        if(i==1){
            deletebegin();
            return;
        }
        int n=1;
        node<T>*curr=head;
        node<T>*prev=NULL;
        while(curr!=NULL && n<i){
            prev=curr;
            curr=curr->next;
            n++;
        }
        if(curr==NULL){
            cout<<"Position does not exist"<<endl;
            return;
        }
        prev->next=curr->next;
        delete curr;

    }

    // delete before pos i 
    void deletebefore(int i){
        if(head==NULL){
            cout<<"List is empty"<<endl;
            return;

        }
        if(i<=1){
            cout<<"Not allowed"<<endl;
            return;
        }
        if(i==2){
            deletebegin();
            return;
        }
        node<T>*curr=head;
        node<T>*prev=NULL;
        int n=1;
        while(n<i-1 && curr!=NULL){
            n++;
            prev=curr;
            curr=curr->next;

        }
        if(curr==NULL){
            cout<<"Postion does not exist for this"<<endl;
            return;
        }
        else{
            prev->next=curr->next;
            delete curr;
            return;
        }
    }

    // delete after pos i 
    void deleteafterpos(int i){
        if(head==NULL){
            cout<<"List already empty"<<endl;
            return;
        }
        if(i==0){
            deletebegin();
            return;
        }
        int n=1;
        node<T>*curr=head;
        node<T>*prev=NULL;
        while(n<=i && curr!=NULL){
            n++;
            prev=curr;
            curr=curr->next;

        }
        if(curr==NULL){
           cout<<"not exist at this postion"<<endl;
        
        }
        else{
            prev->next=curr->next;
            delete curr;
        }
    }


    // delete particular element
    void deleteelme(T data){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(head->next==NULL && head->data==data){
            node<T>* temp=head;
            delete temp;
             head=NULL;
            return;
        }
        node<T>*temp=head;
        node<T> *prev=NULL;
        while(temp!=NULL  && temp->data!=data  ){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Element does not exist"<<endl;
            return;
        }
        prev->next=temp->next;
        delete temp;

    }
    
    // delete eleme before key
    void deletebeforekey(T key){
        if(head==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(head->next==NULL){
            cout<<"Only one element in the list"<<endl;
            return;
        }
        node<T>*curr=head->next;
        node<T>*prev=head;
        while(curr->next!=NULL && curr->next->data!=key){
            prev=curr;
            curr=curr->next;
        }
        if(curr->next==NULL){
            cout<<"Element does not exist"<<endl;
            return;
        }
        prev->next=curr->next;
        delete curr;

    }

    // delete eleme after key
    void deleteafterkey(T key){
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(head->next==NULL){
            cout<<"Only one element in list"<<endl;
            return;
        }
        node<T>*temp=head->next;
        node<T>*prev=head;
        while(temp!=NULL&& prev->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            cout<<"Element does not exist"<<endl;
            return;
        }
        prev->next=temp->next;
        delete temp;
    }
    
    
    // func to create an ordered linked list
    void ordered(T data){
        if(head==NULL){
            head=new node<T>(data);
            return;
        }
        if(data<head->data){
            addstart(data);
        }
        else{
            node<T> *temp=head;
            node<T>*prev=NULL;
            while(temp!=NULL && temp->data < data){
                prev=temp;
                temp=temp->next;
            }
            
            prev->next=new node<T>(data,temp);
            
        }
        
    }

    // selection sort we are only changin the data elements not the actual links
    void selectionsort(){
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(head->next==NULL){
            cout<<"Onlye 1 element in the list"<<endl;
            return;
        }
        node<T>*p=head;
        while(p->next!=NULL){
            node<T>*q=p->next;
            while(q!=NULL){
                if(p->data > q->data){
                    swap(p->data,q->data);
                }
                q=q->next;
            }
            p=p->next;
        }
    }
    
    
    // bubble sort without chaning links
    void sort(){
        if(head==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(head->next==NULL){
            cout<<"Onlye 1 element in the list"<<endl;
            return;
        }
        int n=length();
        for(int i=0;i<n-1;i++){
            node<T>*p=head;
            node<T>*q=head->next;
            for(int j=0;j<n-i-1;j++){
                if(p->data > q->data){
                    swap(p->data , q->data);
                }
                p=p->next;
                q=q->next;
            }
        }
    }

   // Reverse the linked list
   void reverse(){
       if(head==NULL){
           cout<<"Empty list"<<endl;
           return;
       }
       if(head->next==NULL){
           cout<<"only 1 element"<<endl;
           return;
       }
       node<T>*prev=NULL;
       node<T>*curr=head;
       while(curr!=NULL){
           node<T>*temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
       }
       head=prev;
   }

   // concating a ll
   void concatenate(linkedlist a){
       if(head==NULL){
           head=a.head;
           return;
       }
       node<T>*temp=head;
       while(temp->next!=NULL){
           temp=temp->next;
           
       }
       temp->next=a.head;
   }
   
   // merging the list into the same one
   linkedlist merge(linkedlist a){
       if(head==NULL){
           a.sort();
           return a;
       }
       else if(a.head==NULL){
           sort();
           return *this;
       }
       sort();
       a.sort();
       node<T>*p=head;
       node<T>*q=a.head;
       linkedlist ans;
       while(p!=NULL && q!=NULL){
           if(p->data < q->data){
               ans.addlast(p->data);
               p=p->next;
           }
           else{
               ans.addlast(q->data);
               q=q->next;
           }
       }
       if(p==NULL){
           while(q!=NULL){
               ans.addlast(q->data);
               q=q->next;
           }
           
       }else{
           while(p!=NULL){
               ans.addlast(p->data);
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
    
    

    linkedlist<int> obj1;
    linkedlist<int> obj2;
    linkedlist<char> obj3;
    linkedlist<char> obj4;
    linkedlist<double> obj5;
    linkedlist<double> obj6;
    linkedlist<bool> obj7;
    linkedlist<bool> obj8;
    
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
                            obj1.addstart(ele);
                            obj1.display();
                    }
                    else if(dt==2){
                            char ele;
                            cin>>ele;
                            obj3.addstart(ele);
                            obj3.display();
                    }
                    else if(dt==3){
                            double ele;
                            cin>>ele;
                            obj5.addstart(ele);
                            obj5.display();
                    }
                    else if(dt==4){
                        bool ele;
                            cin>>ele;
                            obj7.addstart(ele);
                            obj7.display();
                    }
                    
                }
                else if(n1==2){
                  
                    cout<<"Enter the element you wish to add";
                    if(dt==1){
                         int ele;
                        cin>>ele;
                        obj1.addlast(ele);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                         char ele;
                        cin>>ele;
                        obj3.addlast(ele);
                        obj3.display();
                    }
                    else if(dt==3){
                         double ele;
                        cin>>ele;
                        obj5.addlast(ele);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool ele;
                        cin>>ele;
                        obj7.addlast(ele);
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
                        
                        obj1.addatelem(ele,key);
                        obj1.display();
                    
                    }
                    else if(dt==2){
                         char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj3.addatelem(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                         double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj5.addatelem(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element at which you wish to add"<<endl;
                        cin>>key;
                        
                        obj7.addatelem(ele,key);
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
                     
                        obj1.addbeforeelem(ele,key);
                        obj1.display();
                    }
                    else if(dt==2){
                        char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj3.addbeforeelem(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                         double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj5.addbeforeelem(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                         bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element before which you wish to add"<<endl;
                        cin>>key;
                     
                        obj7.addbeforeelem(ele,key);
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
                        
                        obj1.addafterelem(ele,key);
                        obj1.display();
                    }
                    else if(dt==2){
                        char key;
                        char ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj3.addafterelem(ele,key);
                        obj3.display();
                    }
                    else if(dt==3){
                        double key;
                        double ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj5.addafterelem(ele,key);
                        obj5.display();
                    }
                    else if(dt==4){
                        bool key;
                        bool ele;
                        cout<<"Enter the element you wish to add"<<endl;
                        cin>>ele;
                        cout<<"enter the element after which you wish to add"<<endl;
                        cin>>key;
                        
                        obj7.addafterelem(ele,key);
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
                        obj1.deletepos(pos);
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.deletepos(pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.deletepos(pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.deletepos(pos);
                        obj7.display();
                    }
                    
                }
                else if(n2==4){
                    int pos;
                    cout<<"Enter the position before which you wish to delete";
                    cin>>pos;
                     if(dt==1){
                        obj1.deletebefore(pos);
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.deletebefore(pos);
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.deletebefore(pos);
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.deletebefore(pos);
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
                           obj1.deleteelme(key);
                           obj1.display();
                    }
                    else if(dt==2){
                        char key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj3.deleteelme(key);
                           obj3.display();
                    }
                    else if(dt==3){
                        double key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj5.deleteelme(key);
                           obj5.display();
                    }
                    else if(dt==4){
                        bool key;
                          cout<<"Enter the element at which you wish to delete";
                          cin>>key;
                           obj7.deleteelme(key);
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
                        obj1.ordered(n3);
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
                        obj3.ordered(n3);
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
                        obj5.ordered(n3);
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
                        obj7.ordered(n3);
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
                        obj1.sort();
                        obj1.display();
                    }
                    else if(dt==2){
                        obj3.sort();
                        obj3.display();
                    }
                    else if(dt==3){
                        obj5.sort();
                        obj5.display();
                    }
                    else if(dt==4){
                        obj7.sort();
                        obj7.display();
                    }
                    
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
                obj2.addlast(ele);
                obj2.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==2){
                    char ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj4.addlast(ele);
                obj4.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==3){
                    double ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj6.addlast(ele);
                obj6.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==4){
                      bool ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj8.addlast(ele);
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
                obj2.addlast(ele);
                obj2.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==2){
                    char ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj4.addlast(ele);
                obj4.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==3){
                    double ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj6.addlast(ele);
                obj6.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
               else if(dt==4){
                      bool ele;
                cout<<"Enter the element"<<endl;
                cin>>ele;
                obj8.addlast(ele);
                obj8.display();
                cout<<"Do yo want to add more 0/1"<<endl;
                cin>>flag2;
               }
                
                
           }
            if(dt==1){
              obj1= obj1.merge(obj2);
            obj1.display();
           }
           else if(dt==2){
               obj3=obj3.merge(obj4);
            obj3.display();
           }
           else if(dt==3){
               obj5=obj5.merge(obj6);
            obj5.display();
           }
           else if(dt==4){
              obj7= obj7.merge(obj8);
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