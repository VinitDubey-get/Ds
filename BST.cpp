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
            bool flag2=true;
            while(flag2){
                if(dt==1){
                cout<<"Enter the number to insert "<<endl;
                int data;
                cin>>data;
                a.insertion(data);
                }
                else if(dt==2){
                cout<<"Enter the character to insert "<<endl;
                char data;
                cin>>data;
                b.insertion(data);
                }
                else if(dt==3){
                    cout<<"Enter the boolean number to insert "<<endl;
                bool data;
                cin>>data;
                c.insertion(data);
                
                }
                else{
                    cout<<"Enter the double  to insert "<<endl;
                double data;
                cin>>data;
                d.insertion(data);
                }
                cout<<"Do you want to insert more 0/1"<<endl;
                cin>>flag2;
            }
        }
        else if(n==2){
             if(dt==1){
                  cout<<"Enter the element to be searched"<<endl;
                  int key;
                  cin>>key;
                  if(a.search(key)){
                    cout<<key<<" is present in tree "<<endl;
                  }
                  else{
                    cout<<key<<" is not present in tree"<<endl;
                  }
            }
            else if(dt==2){
                 cout<<"Enter the element to be searched"<<endl;
                  char key;
                  cin>>key;
                  if(b.search(key)){
                    cout<<key<<" is present in tree "<<endl;
                  }
                  else{
                    cout<<key<<" is not present in tree"<<endl;
                  }
            }
            else if(dt==3){
                 cout<<"Enter the element to be searched"<<endl;
                  bool key;
                  cin>>key;
                  if(c.search(key)){
                    cout<<key<<" is present in tree "<<endl;
                  }
                  else{
                    cout<<key<<" is not present in tree"<<endl;
                  }
            } 
            else{
                cout<<"Enter the element to be searched"<<endl;
                  double key;
                  cin>>key;
                  if(d.search(key)){
                    cout<<key<<" is present in tree "<<endl;
                  }
                  else{
                    cout<<key<<" is not present in tree"<<endl;
                  }
            }
        }
        else if(n==3){
            bool flag2=true;
            while(flag2){
                cout<<"1. Preorder"<<endl;
                cout<<"2. Inorder"<<endl;
                cout<<"3. Postorder"<<endl;
                cout<<"Which traversal do you want to perform"<<endl;
                int choice;
                cin>>choice;
                if(choice==1){
                    if(dt==1){
                        cout<<"Preorder Traversal is : ";
                        a.preorder();
                    }
                    else if(dt==2){
                         cout<<"Preorder Traversal is : ";
                        b.preorder();
                    }
                    else if(dt==3){
                        cout<<"Preorder Traversal is : ";
                        c.preorder();
                    }
                    else if(dt==4){
                        cout<<"Preorder Traversal is : ";
                        d.preorder();
                    }
                }
                else if(choice==2){
                     if(dt==1){
                        cout<<"Preorder Traversal is : ";
                        a.inorder();
                    }
                    else if(dt==2){
                         cout<<"Preorder Traversal is : ";
                        b.inorder();
                    }
                    else if(dt==3){
                        cout<<"Preorder Traversal is : ";
                        c.inorder();
                    }
                    else if(dt==4){
                        cout<<"Preorder Traversal is : ";
                        d.inorder();
                    }
                }
                else if(choice==3){
                    if(dt==1){
                        cout<<"Preorder Traversal is : ";
                        a.postorder();
                    }
                    else if(dt==2){
                         cout<<"Preorder Traversal is : ";
                        b.postorder();
                    }
                    else if(dt==3){
                        cout<<"Preorder Traversal is : ";
                        c.postorder();
                    }
                    else if(dt==4){
                        cout<<"Preorder Traversal is : ";
                        d.postorder();
                    }
                }
                else{
                    cout<<"Wrong choice"<<endl;
                }
                cout<<endl;
                cout<<"Do you want to continue 0/1"<<endl;
                cin>>flag2;
            }
        }
        else{
            cout<<"Wrong choice"<<endl;
        }
        cout<<"Do you want to continue 0/1"<<endl;
        cin>>flag;
    }
}
