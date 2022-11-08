// creating a binary search tree and applying all thre traversals
#include<iostream>
using namespace std;

template<class T>
class node{
    T data;
    node<T>*left;
    node<T>*right;

    public:
    node(T data,node<T>*left=NULL,node<T>*right=NULL){
        this->data=data;
        this->left=left;
        this->right=right;
    }

    ~node(){
        left=NULL;
        right=NULL;
    }
    template<class U>
    friend class bst;
};

template<class T>
class bst{
    node<T>* root;
    public:
    bst(){
        root=NULL;
    }
    
   void insertion(T data){
      if(root==NULL){
        root=new node<T>(data);
        return;
      }
      node<T>  *prev,*p;
      p=root;
      while(p!=NULL){
        prev=p;
        if(p->data > data){
            p=p->left;
        }
        else{

            p=p->right;
        }
      }

        if(data > prev->data){
            prev->right=new node<T>(data);
        }
        else{
            prev->left=new node<T>(data);
        }
      

    }

   bool search(T data){
        if(root==NULL){
            cout<<"Tree Empty"<<endl;
            return false;
        }
        node<T>*p;
        p=root;
        while(p!=NULL){
             if(p->data == data){
                return true;
             }
             else if(data < p->data){
                p=p->left;
             }
             else{
                p=p->right;
             }
        }
        return false;
    }

    // traversals
private:
   void pre(node<T>* root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<" ";
        pre(root->left);
        pre(root->right);
    } 
     void inor(node<T>* root){
        if(root==NULL){
            return;
        }
       
        inor(root->left);
         cout<<root->data<<" ";
        inor(root->right);
    } 
     void post(node<T>* root){
        if(root==NULL){
            return;
        }
       
        post(root->left);
        post(root->right);
         cout<<root->data<<" ";
    }  




    public:
    void preorder(){
        pre(root);
    }
    void postorder(){
         post(root);
    }
   void inorder(){
        inor(root);
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
    
    bst<int>a;
    bst<char>b;
    bst<bool>c;
    bst<double>d;

    bool flag=true;
    while(flag){
        int n;
        cout<<"Menu"<<endl;
        cout<<"1.Insertion"<<endl;
        cout<<"2.Searching"<<endl;
        cout<<"3.Printing"<<endl;

        cout<<"Enter which operation do you want to perform"<<endl;
        cin>>n;
        if(n==1){
            if(dt==1){

            }
            else if(dt==2){

            }
            else if(dt==3){

            }
            else{

            }
        }
        else if(n==2){
             if(dt==1){

            }
            else if(dt==2){

            }
            else if(dt==3){

            }
            else{
                
            }
        }
        else if(n==3){

        }
        else{
            cout<<"Wrong choice"<<endl;
        }
        cout<<"Do you want to continue 0/1"<<endl;
        cin>>flag;
    }
}
