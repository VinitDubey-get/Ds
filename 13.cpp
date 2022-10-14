#include<iostream>
using namespace std;

template<class T>
class Diagonal{
	T *arr;
	int size;
	public:
		Diagonal(int size=0){
			this->size=size;
			arr=new T[size];
			cout<<"Enter diagoanl elements "<<endl;
				for(int i=0;i<size;i++){
					cout<<"Enter A["<<i<<"]["<<i<<"]"<<"th element "<<endl;
		        	cin>>arr[i];
	         	}
		}
		void display(){
			cout<<"Elements of the matrix are "<<endl;
			for(int i=0;i<size;i++){
				for(int j=0;j<size;j++){
				    if(i==j){
						cout<<arr[i]<<" ";
					}
					else{
						cout<<"0"<<" ";
					}

				}
				cout<<endl;
			}
		}
		void set(int i,int j,T key){
			if(i<1 || j<1 || i>size || j>size){
				cout<<"Invalid coordinates "<<endl;
				return;
			}
			if(i!=j && key!=0){
				cout<<"This is a diagonal matrix & element should not be zero"<<endl;
			}
			else{
				arr[i-1]=key;
			}
		}
		int get(int i,int j){
			if(i<1 || j<1 || i>size || j>size){
				return -1;
			}
			if(i!=j){
				return 0;
			}
			else{
				return arr[i-1];
			}
		}
		~Diagonal(){
			delete []arr;
			
		}
	
		
};

template<class T>
class TriDiagonal{
	T *arr;
	int size;
	int n;
	public:
		TriDiagonal(int n=0){
			if(size<0){
				cout<<"Not permitted"<<endl;
				return;
			}
			this->n=n;
			this->size=3*n-2;
			arr=new T[size];
			cout<<"Enter the elements in lower diagoanl "<<endl;
			int i;
			for(i=0;i<n-1;i++){
				cin>>arr[i];
			}
			cout<<"Enter the middle diagonal elements"<<endl;
			for(i=n-1;i<2*n-1;i++){
				cin>>arr[i];
			}
			cout<<"Enter the upper diagonal elements"<<endl;
			for(i=2*n-1;i<size;i++){
				cin>>arr[i];
			}
		}

        void display(){
			for(int i=0;i<n;i++){
				for(int j=0;j<n;j++){
					if((i-j) == 1 ){
                       cout<<arr[j]<<" ";
					}
					else if((i-j)==0){
						cout<<arr[n-1+i]<<" ";
					}
					else if((j-i)==1){
						cout<<arr[2*n-2+j]<<" ";
					}
					else{
						cout<<"0"<<" ";
					}
				}
				cout<<endl;
			}
		}

		void set(int i,int j,T elem){
			if(i<1 || j<1 || i>size || j>size){
				cout<<"Invalid coordinates "<<endl;
				return;
			}
			if(i-j==0){
				arr[n+i-2]=elem;
			}
			else if(i-j==1){
				arr[i-2]=elem;
			}
			else if(i-j==-1){
				arr[2*n+i-2]=elem;
			}
			
		}
		int get(int i,int j){
			if(i<1 || j<1 || i>size || j>size){
				return -1;
			}
			if(i-j==0){
				return arr[n+i-2];
			}
			else if(i-j==1){
			   return arr[i-2];
			}
			else if(i-j==-1){
			   return arr[2*n+i-2];
			}
			else{
				return 0;
			}
		}
		~TriDiagonal(){
			delete[]arr;
		}
};

template<class T>
class LowerTriangular{
	T *arr;
	int size;
	int n;
	public:
		LowerTriangular(int size=0){
		
			if(size<0){
				cout<<"Not permitted"<<endl;
				return;
			}
			this->n=size;
			this->size=(size*(size+1))/2;
			arr=new T[this->size];
			
			cout<<"Enter the non-zero elements row wise"<<endl;
			for(int i=0;i<this->size;i++){
				cin>>arr[i];
			}
		}
        
        void display(){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i>=j){
                        int pos=((i*(i-1))/2+(j-1));
						cout<<arr[pos]<<" ";
					}
					else{
						cout<<"0"<<" ";
					}
				}
				cout<<endl;
			}
		}

		void set(int i,int j,T key){
			if(i<1 || j<1 || i>size || j>size){
				cout<<"Invalid coordinates "<<endl;
				return;
			}
			if(i<j){
				return;
			}
			int pos=((i*(i-1))/2+(j-1));
			arr[pos]=key;

			
		}
		int get(int i,int j){
			if(i<1|| j<1 || i>size || j>size){
				return -1;
			}
			if(i<j){
				return 0;
			}
			else{
				int pos=((i*(i-1))/2+(j-1));
				return arr[pos];
			}
		}
		~LowerTriangular(){
			delete[]arr;
		}
		
		
};

template<class T>
class upperTriangular{
	T *arr;
	int size;
	int n;
	public:
		upperTriangular(int size=0){
		    this->n=size;
			this->size=(size*(size+1))/2;
			if(size<0){
				cout<<"Not permitted"<<endl;
				return;
			}
			arr=new T[this->size];
			cout<<"Enter the non-zero elements column wise"<<endl;
			for(int i=0;i<this->size;i++){
				cin>>arr[i];
			}
		}
        
		void display(){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i<=j){
						int pos=((j*(j-1))/2+(i-1));
						cout<<arr[pos]<<" ";
					}
					else{
						cout<<"0"<<" ";
					}
				}
				cout<<endl;
			}
		}

		void set(int i,int j,T key){
			if(i<1 || j<1 || i>size || j>size){
				cout<<"Invalid coordinates "<<endl;
				return;
			}
			if(i>j){
				return;
			}
			int pos=((j*(j-1))/2+(i-1));
			arr[pos]=key;
			
		}
		int get(int i,int j){
			if(i<1 || j<1 || i>size || j>size){
				return -1;
			}
			if(i>j){
				return 0;
			}
			else{
				int pos=((j*(j-1))/2)+(i-1);
				return arr[pos];
			}
		}
		~upperTriangular(){
			delete[]arr;
		}
};

template<class T>
class symmetric{
	T*arr;
	int size;
	int n;
	public:
		symmetric(int size=0){
			this->n=size;
			this->size=(size*(size+1))/2;
			if(size<0){
				cout<<"Not permitted"<<endl;
				return;
			}
            arr=new T[this->size];
			cout<<"Enter the elements in lower triangular form"<<endl;
			for(int i=0;i<this->size;i++){
				cin>>arr[i];
			}
			
		}
        
        

		void display(){
           for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i>=j){
					int pos=((i*(i-1))/2+(j-1));
				    cout<<arr[pos]<<" ";
				}
				else{
					
					int pos=((j*(j-1))/2+(i-1));
				    cout<<arr[pos]<<" ";
				}
			}
			cout<<endl;
		   }

		}
		void set(int i,int j,T key){
			if(i<1 || j<1 || i>size || j>size){
				cout<<"Invalid coordinates "<<endl;
				return;
			}
		
			
			if(i>=j){
					int pos=((i*(i-1))/2+(j-1));
				arr[pos]=key;
			}
			else{
			   swap(i,j);
			   	int pos=((i*(i-1))/2+(j-1));
			   arr[pos]=key;
			}
			
			
		}
		int get(int i,int j){
			if(i<1 || j<1 || i>size || j>size){
				return -1;
			}
			
			
			if(i>=j){
				int pos=((i*(i-1))/2+(j-1));
			   return arr[pos];
			}
			else{
			   swap(i,j);
			   int pos=((i*(i-1))/2+(j-1));
			   return arr[pos];
			}
			 
			
		}
		~symmetric(){
			delete[]arr;
		}
		
};


int main(){
    cout<<"Enter the data type on which you want to work upon: "<<endl;
    cout<<"1.Integers"<<endl;
	cout<<"2.Characters"<<endl;
	cout<<"3.Boolean"<<endl;
	cout<<"4.Double"<<endl;
	int dt;
	cin>>dt;
			    
   if(dt==1){
          bool flag=true;
   while(flag){
		cout<<"Enter the choice "<<endl;
		cout<<"1. For Diagonal matice"<<endl;
		cout<<"2. For tridiagonal matrice"<<endl;
		cout<<"3. For Lower Triangular matrice"<<endl;
		cout<<"4. For upper triangular matrice"<<endl;
		cout<<"5. for symmetric matrice"<<endl;

		int c;
		cin>>c;
		switch(c){
			case 1:{
				cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				Diagonal<int> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j,key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 2:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				TriDiagonal<int> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j,key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                
                break;
			}
			case 3:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				LowerTriangular<int> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j,key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 4:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				upperTriangular<int> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j,key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 5:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				symmetric<int> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j,key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			default:{
				cout<<"Wrong choice"<<endl;
                break;
			}

			
		}
		cout<<"Do you want to continue 0/1"<<endl;
		cin>>flag;

   }
   }
   else if(dt==2){
           bool flag=true;
   while(flag){
		cout<<"Enter the choice "<<endl;
		cout<<"1. For Diagonal matice"<<endl;
		cout<<"2. For tridiagonal matrice"<<endl;
		cout<<"3. For Lower Triangular matrice"<<endl;
		cout<<"4. For upper triangular matrice"<<endl;
		cout<<"5. for symmetric matrice"<<endl;

		int c;
		cin>>c;
		switch(c){
			case 1:{
				cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				Diagonal<char> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							char key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 2:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				TriDiagonal<char> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							char key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                
                break;
			}
			case 3:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				LowerTriangular<char> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							char key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 4:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				upperTriangular<char> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							char key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 5:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				symmetric<char> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							char key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			default:{
				cout<<"Wrong choice"<<endl;
                break;
			}

			
		}
		cout<<"Do you want to continue 0/1"<<endl;
		cin>>flag;

   }
   }
   else if(dt==3){
           bool flag=true;
   while(flag){
		cout<<"Enter the choice "<<endl;
		cout<<"1. For Diagonal matice"<<endl;
		cout<<"2. For tridiagonal matrice"<<endl;
		cout<<"3. For Lower Triangular matrice"<<endl;
		cout<<"4. For upper triangular matrice"<<endl;
		cout<<"5. for symmetric matrice"<<endl;

		int c;
		cin>>c;
		switch(c){
			case 1:{
				cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				Diagonal<bool> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							bool key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 2:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				TriDiagonal<bool> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							bool key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                
                break;
			}
			case 3:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				LowerTriangular<bool> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							bool key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 4:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				upperTriangular<bool> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							bool key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 5:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				symmetric<bool> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							bool key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			default:{
				cout<<"Wrong choice"<<endl;
                break;
			}

			
		}
		cout<<"Do you want to continue 0/1"<<endl;
		cin>>flag;

   }
   }
   else if(dt==4){
          bool flag=true;
   while(flag){
		cout<<"Enter the choice "<<endl;
		cout<<"1. For Diagonal matice"<<endl;
		cout<<"2. For tridiagonal matrice"<<endl;
		cout<<"3. For Lower Triangular matrice"<<endl;
		cout<<"4. For upper triangular matrice"<<endl;
		cout<<"5. for symmetric matrice"<<endl;

		int c;
		cin>>c;
		switch(c){
			case 1:{
				cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				Diagonal<double> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							double key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 2:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				TriDiagonal<double> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							double key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                
                break;
			}
			case 3:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				LowerTriangular<double> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							double key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 4:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				upperTriangular<double> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							double key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			case 5:{
					cout<<"Enter the size of matrice"<<endl;
				int n;
				cin>>n;
				symmetric<double> a(n);
				
				bool flag2=true;
				while(flag2){
					cout<<"Enter your choice"<<endl;
					cout<<"1. To display matrice"<<endl;
					cout<<"2. to set any particular element "<<endl;
					cout<<"3. to get any particular element"<<endl;
					int c1;
					cin>>c1;
                    switch(c1){
						case 1:{
							a.display();
							break;
						}
						case 2:{
							int i,j;
							double key;
							cout<<"Enter the position "<<endl;
							cin>>i>>j;
							cout<<"Enter element"<<endl;
							cin>>key;
							a.set(i,j,key);
							break;
						}
						case 3:{
							int i,j;
							cout<<"Enter the position"<<endl;
							cin>>i>>j;
							cout<<a.get(i,j)<<endl;
							break;
						}
						default:{
							cout<<"Enter correct choice"<<endl;
							break;
						}
				   }
				   cout<<"Do yo want to continue 0/1"<<endl;
				   cin>>flag2;
				}
				

                break;
			}
			default:{
				cout<<"Wrong choice"<<endl;
                break;
			}

			
		}
		cout<<"Do you want to continue 0/1"<<endl;
		cin>>flag;

   }
   }
   else{
       cout<<"Wrong choice"<<endl;
   }
   
	
}