// create a circular linked list and list some functions
#include<iostream>
using namespace std;

class node{
    int data;
    node* next;
    public:
    node(){
       
        this->next=NULL;
    }
    node(int data,node*next=NULL){
        this->data=data;
        this->next=next;
    }
    ~node(){
        next=NULL;
    }
    friend class circularlist;
};

class circularlist{
    node*tail;
    public:
    circularlist(){
        tail=NULL;
    }
    circularlist(int data){
        tail->data=data;
        tail->next=tail;
    }

    // add at begin
    void addatbegin(int data){
        if(tail==NULL){
            tail=new node(data);
            tail->next=tail;
            return;
        }
        node*temp=new node(data);
        temp->next=tail->next;
        tail->next=temp;
    }

    // add at end
    void addatend(int data){
        if(tail==NULL){
            tail=new node(data);
            tail->next=tail;
            return;
        }
        node*temp=new node(data);
        temp->next=tail->next;
        tail->next=temp;
        tail=temp;
    }

    // display
    void display(){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        node*temp=tail->next;
        while(temp!=tail){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<tail->data<<" ";
        cout<<endl;
    }

    // count lenght
    int length(){
        if(tail==NULL){
            return 0;
        }
        int ans=1;
        node*temp=tail->next;
        while(temp!=tail){
            ans++;
            temp=temp->next;
        }
        return ans;
    }

    // add at position
    void addatpos(int data,int i){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return ;
        }
        if(i<1){
            cout<<"Not allowed"<<endl;
            return;
        }
        if(i==1){
            addatbegin(data);
            return;
        }
        int n=1;
        node*temp=new node(data);
        node*track=tail->next;
        while(track!=tail && n<(i-1)){
            track=track->next;
            n++;
        }
        if(n+1==i && track==tail){
            addatend(data);
            return;
        }
        else if(track==tail && n+1<i){
            cout<<"Index not exists"<<endl;
            return;
        }
        // otherwise add it
        temp->next=track->next;
        track->next=temp;
        return;

    }

    // add after postion
    void addafterpos(int data,int i){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;

        }
        if(i<0){
            cout<<"Not allowed"<<endl;
            return;
        }
        if(i==0){
            addatbegin(data);
            return;
        }
        if(tail->next==tail && i==1){
            addatend(data);
            return;
        }
        if(tail->next==tail &&  i>1){
            cout<<"Not allowed"<<endl;
            return;
        }
        int cnt=1;
        node*temp=new node(data);
        node*track=tail->next;
        while(track!=tail && cnt<i){
            cnt++;
            track=track->next;

        }
        if(track==tail && cnt==i){
            addatend(data);
            return;
        }
        if(track==tail && cnt<i){
            cout<<"Position does not exits"<<endl;
            return;
        }
        temp->next=track->next;
        track->next=temp;
        return;

    }

    // add before postion
    void addbeforepos(int data,int i){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        } 
        if(i<1){
            cout<<"Not allowed"<<endl;
            return;
        }
        if(i==1){
            addatbegin(data);
            return;
        }
        if(tail->next==tail && i>1){
            cout<<"Not allowed"<<endl;
            return;
        }
        node*temp=new node(data);
        int cnt=1;
        node*track=tail->next;
        while(track!=tail && cnt<(i-1)){
            track=track->next;
            cnt++;
        }
        if(track==tail && cnt+1<i){
            cout<<"Not possible to insert "<<endl;
            return;
        }
        if(track==tail && cnt+1==i){
            addatend(data);
            return;
        }
        temp->next=track->next;
        track->next=temp;
        return;
    }

    // add at key
    void addatkey(int data , int key){
        if(tail==NULL){
            cout<<"List empty"<<endl;
            return;
        }
     
        node*temp=tail->next;
        while(temp!=tail && temp->data!=key){
            temp=temp->next;
        }
        if(temp==tail && temp->data!=key){
            cout<<"Key not found in the list"<<endl;
            return;
        }
        temp->data=data;
        
    }

    // add after a key in the list
    void addafterkey(int data,int key){
        if(tail==NULL ){
            cout<<"List empty"<<endl;
            return;
        }
        
        node*temp=tail->next;
        node*toadd=new node(data);
        while(temp!=tail && temp->data!=key){
            temp=temp->next;

        }
        if(temp==tail && temp->data!=key){
             cout<<"Key not found in the list"<<endl;
             return;
        }
        else if(temp==tail && temp->data==key){
            addatend(data);
            return;
        }
        toadd->next=temp->next;
        temp->next=toadd;

    }
    // add before key
    void addbeforekey(int data,int key){
        if(tail==NULL){
            cout<<"List empty"<<endl;
            return;
        }
        if(tail->next==tail && tail->data==key){
            addatbegin(data);
            return;
        }
        node*toadd=new node(data);
        node*temp=tail->next;
        node*prev=NULL;
        while(temp!=tail && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==tail && temp->data!=key){
            cout<<"Key does not exist in the list"<<endl;
            return;
        }
        if(prev==NULL){
            addatbegin(data);
            return;
        }
        prev->next=new node(data);
        prev->next->next=temp;
        return;
    }

    // delete functions
    
    // delete from begin
    void deleteatbegin(){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            node*temp=tail;
            delete temp;
            tail=NULL;
            return;

        }
        node*temp=tail->next;
        tail->next=temp->next;
        delete temp;
        

    }

    //delete form end
    void deleteatend(){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            node*temp=tail;
            delete temp;
            tail=NULL;
            return;

        }
        node*temp=tail->next;
      
        while(temp->next!=tail){
        
            temp=temp->next;
        }
        temp->next=tail->next;
        node*temp2=tail;
        tail=temp;
        delete temp2;
        
      
    }

    // delete at pos
    void deleteatpos(int i){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        int cnt=1;
        node*temp=tail->next;
        node*prev=NULL;
        while(temp!=tail && cnt<i){
            prev=temp;
            temp=temp->next;
            cnt++;
        }
        if(temp==tail && cnt==i){
            deleteatend();
            return;
        }
        if(temp==tail && cnt<i){
            cout<<"pos does not exist"<<endl;
            return;
        }
        if(prev==NULL){
            deleteatbegin();
            return;
        }
        // mean to delete at mid ie temp vala delete kro
        prev->next=temp->next;
        delete temp;

    }
    
    // delete before pos
    void deletebeforepos(int i){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(i<1){
            cout<<"not allowed"<<endl;
            return;
        }
        node*temp=tail->next;
        node*prev=NULL;
        int cnt=1;
        while(temp!=tail && cnt<i-1){
            cnt++;
            prev=temp;
            temp=temp->next;

        }
        if(temp==tail && cnt+1==i){
            deleteatend();
            return;
        }
        if(temp==tail && cnt+1<i){
            cout<<"Position not exist"<<endl;
            return;
        }
        if(prev==NULL){
            deleteatbegin();
            return;
        }
        prev->next=temp->next;
        delete temp;

    }

    // delete after position
    void deleteafterpos(int i){
        if(tail==NULL){
            cout<<"List is Empty"<<endl;
            return;
        }
        if(i==0){
            deleteatbegin();
            return;
        }
        int cnt=1;
        node*prev=tail->next;
        node*temp=prev->next;

        while(prev!=tail && cnt<i){
             cnt++;
             prev=temp;
             temp=temp->next;
        }
        if(prev==tail){
            cout<<"position does not exist"<<endl;
            return;
        }
        if(temp==tail){
            deleteatend();
            return;
        }
        // now we need to delete temp 
        prev->next=temp->next;
        delete temp;
    }

    // delete a key
    void deleteatkey(int key){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            deleteatbegin();
            return;
        }
        node*prev=NULL;
        node*temp=tail->next;
        while(temp!=tail && temp->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==tail && temp->data!=key){
            cout<<"Key does not exist"<<endl;
            return;
        }
        if(prev==NULL){
            deleteatbegin();
            return;
        }
        if(temp==tail && temp->data==key){
            deleteatend();
            return;
        }
        prev->next=temp->next;
        delete temp;


    }

    // delete node before key
    void deletebeforekey(int key){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            cout<<"Single node in list"<<endl;
            return;
        }
        node*prev=NULL;
        node*temp=tail->next;
        while(temp!=tail && temp->next->data!=key){
            prev=temp;
            temp=temp->next;
        }
        if(temp==tail){
            cout<<"key does not exist in the list"<<endl;
            return;
        }
        if(prev==NULL){
            deleteatbegin();
            return;
        }
        prev->next=temp->next;
        delete temp;
        

    }

    // delete after key
    void deleteafterkey(int key){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        node*temp=tail->next;
        node*next=temp->next;
        while(next!=tail && temp->data!=key){
            temp=next;
            next=next->next;
        }
        if(next==tail && temp->data!=key){
            cout<<"Deletion not possible"<<endl;
            return;
        }
        if(next==tail && temp->data==key){
            deleteatend();
            return;
        }
        temp->next=next->next;
        delete next;
    }

    
    // func to create an ordered CLL
    void createoredered(int data){
        if(tail==NULL){
            tail=new node(data);
            tail->next=tail;
            return;
        }
        if(data>=tail->data){
            addatend(data);
            return;
        }
        node*toadd=new node(data);
        node*temp=tail->next;
        while(temp->next->data<data){
            temp=temp->next;
        }
        if(temp==tail->next){
            addatbegin(data);
            return;
        }
        toadd->next=temp->next;
        temp->next=toadd;
    }

    // to sort a ordered CLL
    void bubblesort(){
        if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            cout<<"only one element"<<endl;
            return;
        }
         int n=length();
         for(int i=0;i<n-1;i++){
            node*p=tail->next;
            node*q=p->next;
            for(int j=0;j<n-i-1;j++){
                if(p->data > q->data){
                    swap(p->data , q->data);
                }
                p=p->next;
                q=q->next;
            }
         }
    }

    void selectionsort(){
         if(tail==NULL){
            cout<<"Empty list"<<endl;
            return;
        }
        if(tail->next==tail){
            cout<<"only one element"<<endl;
            return;
        }
        node*temp=tail->next;
        while(temp!=tail){
            node*q=temp->next;
            while(q!=tail->next){
                if(temp->data > q->data){
                    swap(temp->data , q->data);
                }
                q=q->next;
            }
            temp=temp->next;
        }
    }
    

    // reversing the CLL
    void reverse(){
       if(tail==NULL){
           cout<<"Empty list"<<endl;
           return;
       }
       if(tail->next==NULL){
           cout<<"only 1 element"<<endl;
           return;
       }
       node*ori=tail->next;
       node*prev=tail;
       node*curr=prev->next;
       while(curr!=tail){
           node*temp=curr->next;
           curr->next=prev;
           prev=curr;
           curr=temp;
       }
       curr->next=prev;
       tail=ori;
   }


   // concatenate two LL
   void concatenate(circularlist a){
       if(tail==NULL){
           tail=a.tail;
           return;
       }
       node*ori=tail->next;
       tail->next=a.tail->next;
       a.tail->next=ori;
       tail=a.tail;
   }

  // merging two linked list into one and returning it
      circularlist merge(circularlist a){
       if(tail==NULL){
           a.bubblesort();
           return a;
       }
       else if(a.tail==NULL){
           bubblesort();
           return *this;
       }
       bubblesort();
       a.bubblesort();
       node*p=tail->next;
       node*q=a.tail->next;
       circularlist ans;
       while(p!=tail && q!=a.tail){
           if(p->data < q->data){
               ans.addatend(p->data);
               p=p->next;
           }
           else{
               ans.addatend(q->data);
               q=q->next;
           }
       }
        
       if(p==tail){
           if(p->data < q->data){
               ans.addatend(p->data);
               p=p->next;
           }
           else{
               ans.addatend(q->data);
               q=q->next;
           }
           while(q!=a.tail){
               ans.addatend(q->data);
               q=q->next;
           }
           ans.addatend(q->data);
           
       }else{
           if(p->data < q->data){
               ans.addatend(p->data);
               p=p->next;
           }
           else{
               ans.addatend(q->data);
               q=q->next;
           }
           while(p!=tail){
               ans.addatend(p->data);
               p=p->next;
           }
           ans.addatend(p->data);
           
       }
       return ans;
       
   }


};
   





int main(){
    circularlist obj1;
    circularlist obj2;
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
                    int ele;
                    cout<<"Enter the element you wish to add";
                    cin>>ele;
                    obj1.addatbegin(ele);
                    obj1.display();
                }
                else if(n1==2){
                    int ele;
                    cout<<"Enter the element you wish to add";
                    cin>>ele;
                    obj1.addatend(ele);
                    obj1.display();
                }
                else if(n1==3){
                    int pos;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the position at which you wish to add"<<endl;
                    cin>>pos;
                    
                    obj1.addatpos(ele,pos);
                    obj1.display();
                }
                else if(n1==4){
                    int pos;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the position before which you wish to add"<<endl;
                    cin>>pos;
                    
                    obj1.addbeforepos(ele,pos);
                    obj1.display();
                }
                else if(n1==5){
                    int pos;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the position after which you wish to add"<<endl;
                    cin>>pos;
                    
                    obj1.addafterpos(ele,pos);
                    obj1.display();
                }
                else if(n1==6){
                    int key;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the element at which you wish to add"<<endl;
                    cin>>key;
                    
                    obj1.addatkey(ele,key);
                    obj1.display();
                }
                else if(n1==7){
                    int key;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the element before which you wish to add"<<endl;
                    cin>>key;
                 
                    obj1.addbeforekey(ele,key);
                    obj1.display();
                }
                else if(n1==8){
                    int key;
                    int ele;
                    cout<<"Enter the element you wish to add"<<endl;
                    cin>>ele;
                    cout<<"enter the element after which you wish to add"<<endl;
                    cin>>key;
                    
                    obj1.addafterkey(ele,key);
                    obj1.display();
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
                    obj1.deleteatbegin();
                    obj1.display();
                }
                else if(n2==2){
                    obj1.deleteatend();
                    obj1.display();
                }
                else if(n2==3){
                    int pos;
                    cout<<"Enter the position at which you wish to delete";
                    cin>>pos;
                    obj1.deleteatpos(pos);
                    obj1.display();
                }
                else if(n2==4){
                    int pos;
                    cout<<"Enter the position before which you wish to delete";
                    cin>>pos;
                    obj1.deletebeforepos(pos);
                    obj1.display();
                }
                else if(n2==5){
                    int pos;
                    cout<<"Enter the position after which you wish to delete";
                    cin>>pos;
                    obj1.deleteafterpos(pos);
                    obj1.display();
                }
                else if(n2==6){
                    int key;
                    cout<<"Enter the element at which you wish to delete";
                    cin>>key;
                    obj1.deleteatkey(key);
                    obj1.display();
                }
                else if(n2==7){
                    int key;
                    cout<<"Enter the element before which you wish to delete";
                    cin>>key;
                    obj1.deletebeforekey(key);
                    obj1.display();
                }
                else if(n2==8){
                    int key;
                    cout<<"Enter the element after which you wish to delete";
                    cin>>key;
                    obj1.deleteafterkey(key);
                    obj1.display();
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
                    obj1.bubblesort();
                    obj1.display();
                }
                else if(n4==2){
                    obj1.selectionsort();
                    obj1.display();
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
            obj1.reverse();
            obj1.display();
        }
        else if(n==6){
            obj1.concatenate(obj1);
            obj1.display();
        }
        else if(n==7){
            obj1.merge(obj1);
            obj1.display();
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