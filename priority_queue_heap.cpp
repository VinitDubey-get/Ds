// to implement priority queue using heap data structure which is implemented through vectors
#include<iostream>
#include<vector>
using namespace std;


class Pqueue{
    vector<int>heap;

    public:
    Pqueue(){
    }
    void insert(int element){
        
           heap.push_back(element);
           heapify(1);
    
     
    }
    
    void heapify(int pos){
         if(pos > heap.size()-1){
            return;
        }
        if(heap.size()>2*pos-1 && heap[pos-1] > heap[2*pos-1]){
            //  swap(heap[pos-1],heap[2*pos-1]);
            int temp=heap[pos-1];
            heap[pos-1]=heap[2*pos-1];
            heap[2*pos-1]=temp;
            
             heapify(2*pos);
        }
        if(heap.size()>2*pos && heap[pos-1] > heap[2*pos]){
            swap(heap[pos-1],heap[2*pos]);
             heapify(2*pos+1);
        }
    }
    
    // element with max priority is at root of the heap and we would deleting the max priority elmeent
    void dele(){ 
        if(heap.size()==0){
            cout<<"Empty Priority Queue"<<endl;
            return;
        }
        if(heap.size()==1){
            heap.pop_back();
            return;
        }
        // means heap has more than 1 element into it
        int last=heap[heap.size()-1];
        heap.pop_back();
        heap[0]=last;

        // calling the down bubbling function
        heapify(1);
    }

    // printing 
    void display(){
        if(heap.size()==0){
            cout<<"Empty heap"<<endl;
            return;
        }
        for(int i=0;i<heap.size();i++){
            cout<<heap[i]<<" ";
        }
        cout<<endl;
        
    }
};



int main(){
   Pqueue a;
   a.insert(4);
   a.display();
   a.insert(5);
   a.insert(6);a.display();
   a.insert(15);a.display();
   a.insert(9);a.display();
   a.insert(7);a.display();
   a.insert(20);a.display();
   a.insert(16);a.display();
   a.insert(25);a.display();
   a.insert(14);a.display();
   a.insert(12);a.display();
   a.insert(11);a.display();
   a.insert(8);a.display();
//   a.insert(3);
   a.dele();
  a.dele();
  a.dele();
   
   
   a.display();
}
