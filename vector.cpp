#include<iostream>
vector construct();
vector construct(size_t);
vector construct(size_t, int);
void resize(vector&, size_t);
void recap(vector&);

struct vector{
int* arr;
size_t size;
size_t cap;
};



int main(){


}

void recap( vector& ob){
	if(ob.cap == 0){
		ob.cap = 4;
		ob.arr = new int[ob.cap]{0};
	}else{
		ob.cap = 2;
		int* ptr = new int[ob.cap]{0};
		for(int i = 0; i < ob.size; ++i){
			ptr[i] = ob.arr[i];
		}
		delete[] ob.arr;
		ob.arr = ptr;
		ptr = nullptr;
	}
} 


void resize(vector& ob, size_t new_size){
	if(ob.size > new_size){
		ob.size = new_size;
	}
	else{
		if(new_size > ob.cap){
			ob.cop = new_size;
			int* ptr = new int[ob.cap];
			for(int i = 0; i < size; ++i){
				ptr[i] = ob.arr[i];
				}
			for(int i = 0; i < size; ++i){
				ptr[i] = 0;
			}
			ob.size = new_size;
			delete[] ob.arr;
			ob.arr = ptr;
			ptr = nullptr;
		}
	for(int i = ob.size; i < new_size; ++i){
		ob.arr[i] = 0;
	}
	ob.size = new_size;
		}	
}

vector construct(size_t size, int value){
	vector ob;
	ob.size = size;
	ob.cap = size;
	ob.arr = new int[ob.cap];
	for(int i = 0; i < size; ++i){
		ob.arr[i] = value;
	}
return ob;
}


vector construct(size_t size){
	vector ob;
	ob.size = size;
	ob.cap = size;
	ob.arr = new int[ob.cap]{0};
return ob;
}

vector construct(){
	vector ob;
	ob.size = 0;
	ob.cap = 0;
	ob.arr = nullptr;
return ob;
}
