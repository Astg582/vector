#include<iostream>
vector construct();
vector construct(size_t);
vector construct(size_t, int);
void resize(vector&, size_t);
void recap(vector&);
void push_beak(vector&, int);
void insetr(vector&, size_t, int);
void pop-back(vector& ob);
void clear(vector& ob);
void destructer(vector& ob);
int back(vector& ob);
int front(vector& ob);
bool empty(vector& ob);
int& at(vector& ob, size_t index);


struct vector{
int* arr;
size_t size;
size_t cap;
};



int main(){


}
void pop-back(vector& ob){
 if(ob.size != 0){
		--ob.size;	
 }
}

void clear(vector& ob){
	ob.cap = 0;
	ob.size = 0;
	delete[] ob.arr;
	ob.arr = nullptr;
}

void destructer(vector& ob){
	claer(ob);
}

int back(vector& ob){
	return ob.arr[on.size];
}

int front(vector& ob){
	return ob.arr[0];
}

bool empty(vector& ob){
	return ob.size == 0;
}

int& at(vector& ob, size_t index){
	if(index >= ob.size){
		throw std::out_of_range();
	}
	return ob.arr[index]; 
}

void insetr(vector& ob, size_t index, int value){
	if(index >= ob.size){
		throw std::cout_of_range();
	}
	 if(ob.size == ob.cap){
		recap(ob);
	}
	size_t i = size;
	while(i != index){
		ob.arr[i] = ob.arr[i-1];
		--i;
	}
	ob.arr[i] = value;
	++ob.size;
}

void push_beak(vector& ob, int val){
	if(ob.size == ob.cap){
		recap(ob);
	}
	ob.arr[ob.size] = val;
	ob.size += 1; 
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
