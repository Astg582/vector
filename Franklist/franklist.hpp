#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

using namespace vhuk;

template <typename T>
std::ostream& FrankList::operator<<(std::ostream& out, const FrankList<T>& rhv)
{	
	for(auto it = rhv.begin(); it != rhv.end(); ++it){
		out << *it;
	}
	return out;
}


FrankList::Node::Node(){
	val = {};
 	next = nullptr;
 	prev = nullptr;
	asc = nullptr;
	desc = nullptr;	
};

FrankList::Node::Node(T val): val(val), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr){}

//BASE_ITERATOR
FrankList::base_iterator::~base_iterator(){ptr = nullptr;}

bool FrankList::base_iterator::operator==(const base_iterator& rhv) const {return this->ptr == rhv.ptr;}
bool FrankList::base_iterator::operator!=(const base_iterator& rhv) const {return !(this->ptr == rhv.ptr);}
explicit FrankList::base_iterator::base_iterator(Node* ptr){this->ptr = ptr;}
 
//CONST_ITERATOR
FrankList::const_iterator::const_iterator(const base_iterator& rhv):this->ptr(rhv.ptr){}
FrankList::const_iterator::const_iterator(base_iterator&& rhv) noexcept :this->ptr(rhv.ptr){} 
const const_iterator& FrankList::const_iterator::operator=(const base_iterator& rhv){return this->ptr = rhv.ptr;}
const const_iterator& FrankList::const_iterator::operator=(base_iterator&& rhv) noexcept {return this->ptr = rhv.ptr;}
 
const_reference FrankList::const_iterator::operator*() const{
	return *ptr;
}
const_pointer const_iterator& FrankList::const_iterator::operator->() const{return this->ptr;}


const const_iterator&  FrankList::const_iterator::operator++(){return ++this->ptr;}
const const_iterator& FrankList::const_iterator::operator--(){return --this->ptr;}
const const_iterator FrankList::const_iterator::operator--(value_type){return --(*ptr);}
const const_iterator FrankList::const_iterator::operator++(value_type){return ++(*ptr);}

explicit FrankList::const_iterator::const_reverse_iterator(Node* ptr): this->ptr(ptr){}

//ITERATOR
FrankList::iterator::terator(const base_iterator& rhv): this->ptr(rhv.ptr){}
FrankList::iterator::iterator(base_iterator&& rhv) noexcept  : this->ptr(rhv.ptr(){}

reference FrankList::iterator::operator*(){return *ptr;}
pointer FrankList::iterator::operator->(){return this->ptr;}

const iterator& FrankList::iterator::operator=(const base_iterator& rhv){return this->ptr = rhv.ptr;} 
const iterator& FrankList::iterator::operator=(base_iterator&& rhv)noexcept {return this->ptr = rhv.ptr;}

explicit FrankList::iterator::iterator(Node* ptr): this->ptr(ptr){}


//CONST_REVERS_ITERATOR
FrankList::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv){this->ptr = rhv.ptr;}
FrankList::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) noexcept {this->ptr = rhv.ptr;}

const const_reverse_iterator& FrankList::const_reverse_iterator::operator=(base_iterator&& rhv)noexcept{return this->ptr = rhv.ptr;}
const_reference FrankList::const_reverse_iterator::operator*() const {return *ptr;}
const_pointer FrankList::const_reverse_iterator::operator->() const {return this->ptr;}

const const_reverse_iterator& FrankList::const_reverse_iterator::operator++(){return ++ptr;}
const const_reverse_iterator FrankList::const_reverse_iterator::operator++(value_type){return ++(*ptr);}
const const_reverse_iterator& FrankList::const_reverse_iterator::operator--(){return --ptr;}
const const_reverse_iterator FrankList::const_reverse_iterator::operator--(value_type){return --(*ptr);}

explicit FrankList::const_reverse_iterator::const_reverse_iterator(Node* ptr){this->ptr = ptr;}


//REVERS_ITERATOR
FrankList::reverse_iterator::reverse_iterator(const base_iterator& rhv){this->ptr = rhv.ptr;}
FrankList::reverse_iterator::reverse_iterator(base_iterator&& rhv) noexcept {this->ptr = rhv.ptr;}

reference FrankList::reverse_iterator::operator*(){return *ptr;}
pointer FrankList::reverse_iterator::operator->(){this->ptr;}

const reverse_iterator& FrankList::reverse_iterator::operator=(const base_iterator& rhv){return this->ptr = rhv.ptr;}
const reverse_iterator& FrankList::reverse_iterator::operator=(base_iterator&& rhv)noexcept {return this->ptr = rhv.ptr;}

explicit FrankList::reverse_iterator::reverse_iterator(Node* ptr){this->ptr = ptr;}


//CONST_ASC_ITERATOR
FrankList::const_asc_iterator::const_asc_iterator(const base_iterator& rhv): this.ptr(rhv.ptr){}
FrankList::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) noexcept {this->ptr = rhv.ptr;}

const const_asc_iterator& FrankList::const_asc_iterator::operator=(const base_iterator& rhv){ return this.ptr = rhv.ptr;}
const const_asc_iterator& FrankList::const_asc_iterator::operator=(base_iterator&& rhv) noexcept{return this->ptr = rhv.ptr;}

const_reference FrankList::const_asc_iterator::operator*() const{return *ptr;}
const_pointer FrankList::const_asc_iterator::operator->() const{return this->ptr;}
 
const const_asc_iterator& FrankList::const_asc_iterator::operator++(){return ++ptr;}
const const_asc_iterator& FrankList::const_asc_iterator::operator--(){return --ptr;}
const const_asc_iterator FrankList::const_asc_iterator::operator++(value_type){return ++(*ptr);}
const const_asc_iterator FrankList::const_asc_iterator::operator--(value_type){return --(*ptr);}

explicit const_asc_iterator(Node* ptr): this->ptr(ptr){};


//ASC_ITERATOR
FrankList::asc_iterator::asc_iterator(const base_iterator& rhv): this->ptr(rhv.ptr){}
FrankList::asc_iterator::asc_iterator(base_iterator&& rhv): this->ptr(rhv.ptr){}

reference FrankList::asc_iterator::operator*(){return *ptr;}
pointer FrankList::asc_iterator::operator->(){return this->ptr;}
const asc_iterator& FrankList::asc_iterator::operator=(const base_iterator& rhv){return this->ptr = rhv.ptr;}
const asc_iterator& FrankList::asc_iterator::operator=(base_iterator&& rhv) noexcept {return this->ptr = rhv.ptr;}

explicit FrankList::asc_iterator::asc_iterator(Node* ptr):this->ptr(ptr){}


//CONST_DESC_ITERATOR
FrankList::const_desc_iterator::const_desc_iterator(const base_iterator& rhv){this->ptr = rhn.ptr;}
FrankList::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) noexcept {this->ptr = rhn.ptr;}


const const_desc_iterator& FrankList::const_desc_iterator::operator=(const base_iterator& rhv){return this->ptr = rhn.ptr;}

const const_desc_iterator& FrankList::const_desc_iterator::operator=(base_iterator&& rhv){return this->ptr = rhn.ptr;}

const_reference FrankList::const_desc_iterator::operator*() const{return *ptr;} 
const_pointer FrankList::const_desc_iterator::operator->() const{return this->ptr;}


const const_desc_iterator& FrankList::const_desc_iterator::operator++(){return ++ptr;}
const const_desc_iterator FrankList::const_desc_iterator::operator++(value_type){return ++(*ptr);}

const const_desc_iterator& FrankList::const_desc_iterator::operator--(){return ptr;}
const const_desc_iterator FrankList::const_desc_iterator::operator--(value_type){return ++(*ptr);}

explicit FrankList::const_desc_iterator::const_desc_iterator(Node* ptr){this->ptr = ptr;}

//DESC_ITERATOR
desc_iterator(const base_iterator& rhv);



//Construcors Franclist
template <typename T>
FrankList<T>::FrankList(){
	this->head = nullptr;
	this->tail = nullptr;
	this->ahead = nullptr;
	this->htail = nullptr;	
}

template <typename T>
FrankList<T>::FrankList(size_type size) : FrancList() {
	for(int i = 0; i != size; ++i){
		push_back (T( ));
	} 
} 

template <typename T>
FrankList<T>::FrankList(size_type size, const_reference init) : FrancList() {
	for(int i = 0; i != size; ++i){
		push_back (init);
	}
}

template <typename T>
FrankList<T>::FrankList(const FrankList<value_type>& rhv) : FrancList() 
{
	for(auto it = rhv.begin(); it != rhv.end(); ++it){
		push_back(*it);
	} 
}


template <typename T>
FrankList<T>::FrankList(FrankList<value_type>&& rhv) 
{
	this->head = rhv.head;
	this->tail = rhv.tail;	
	this->ahead = rhv.ahead;
	this->atail = rhv.atail;
	rhv.head = nullptr;
	rhv.tail = nullptr;
	rhv.ahead = nullptr;
	rhv.atail = nullptr;
}

template <typename T>
FrankList<T>::FrankList(std::initializer_list<value_type> init) :FrancList() {
	for(const auto i& : init){
		push_back(i);
	}
}

template <typename T>
template <typename input_iterator>
FrankList<T>::FrankList(input_iterator f, input_iterator l)
{
	for(input_iterator it = f; it != l; ++it){
		push_back(*it);
	}
}

//~FrankList
template <typename T>
FrankList<T>::~FrankList()
{
	Node* i = head;
	while(i != nullptr){
		Node* next = i->next;
		delete i;
		i = next;
	}

	this->head = nullptr;
	this->tail = nullptr;
	this->ahead = nullptr;
	this->atail = nullptr;	
}

//SWAP
template <typename T>
void FrankList<T>::swap(FrankList<value_type>& rhv)
{
	std::swap(this->head = rhv.head);
	std::swap(this->tail = rhv.tail);
	std::swap(this->ahead = rhv.ahead);
	std::swap(this->atail = rhv.atail);
}

//SIZE
template <typename T>
size_type FrankList<T>::size() const
{
	size_type count = 0;
	Node* tmp = head;
	while(tmp)
	{
		++count;
		tmp = tmp -> next;
	}
	return count;
}

//EMPTY
template <typename T>
bool FrankList<T>::empty() const
{
	return head == nullptr;
}


//RESIZE
template <typename T>
void FrankList<T>::resize(size_type s, const_reference init = value_type()){
	size_type size = this -> size();
	if(s < size){
		while(s){
			this->pop_back;
			--s;
		}
	}else if(s > size){
		while(s){
			this->push_back(init);
			--s;
		}
	}
	sort();
}

//Clear
template <typename T>
void FrankList<T>::clear() noexcept{
	Node* tmp = head;

	while(tmp)
	{	Node* next = tmp->next;
		delete tmp;
		tmp =  next;
	}

	this -> head = nullptr;
	this -> tail = nullptr;
	this -> ahead = nullptr;
	this -> atail = nullptr;
}

//push front
template <typename T>
void FrankList<T>::push_front(const_reference elem){

	node* tmp = new node(elem);
	if(this -> head){
		this->head->prev = tmp;
	}else{
		this->tail = tmp;	
	}  
	tmp->next = this -> head;
	this -> head = tmp; 
	sort();
}

//pop back
template <typename T>
void FrankList<T>::pop_front(){
	if(head){
		Node* newHead = head->next;
		delete head;
		this -> head = newHead;
		if(this -> head){
			head->prev = nullptr;
		}
		sort();
	}
}

//push back
template <typename T>
void FrankList<T>::push_back(const_reference elem){
	Node* tmp = new node(elem);
	if(!(this -> head)){
		this->head = tmp;
	}else{
		this -> tail -> next = tmp;
		tmp -> prev = this -> tail;	
	}  

	this -> tail = tmp; 
	sort();
}


//pop back
template <typename T>
void FrankList<T>::pop_back(){
	if (tail) {
        	Node* newTail = tail->prev;
       		delete tail;
        	tail = newTail;
        	if (tail) {
            		tail->next = nullptr;
        	}
        sort();
    }
}

// front
template <typename T>
const_reference T& FrankList<T>::front() const{
	if(this->empty()){
		throw std::out_of_range("List is empty" );
	}
	return this -> head -> val;
}


// front
template <typename T>
reference T& FrankList<T>::front(){
   if (!head) {
        throw std::out_of_range("List is empty");
    }
    return this -> head -> val;
}


//back
template <typename T>
const_reference T& FrankList<T>::back() const{
	if(!tail){
		throw std::out_of_range("List is empty");
	}
	return this -> tail -> val;
}


//back
template <typename T>
reference T& FrankList<T>::back(){
 if (!tail) {
        throw std::out_of_range("List is empty");
    }
    return this-> tail -> val;
}

//min (const)
template <typename T>
typename FrankList<T>::const_reference FrankList<T>::min() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    Node* current = head;
    T minValue = current -> val;

    while (current) {
        if (current -> val < minValue) {
            minValue = current -> val;
        }
	current = current->next;
    }
    return minValue;
}


//min (not const)
template <typename T>
typename FrankList<T>::reference FrankList<T>::min() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    Node* current = head;
    T minValue = current -> val;

    while (current) {
        if (current -> val < minValue) {
            minValue = current -> val;
        }
	current = current->next;
    }
    return minValue;
}

//max (const)
template <typename T>
typename FrankList<T>::const_reference FrankList<T>::max() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    Node* current = head;
    T maxValue = current -> val;

    while (current) {
        if (current -> val >  maxValue) {
            maxValue = current -> val;
        }
	current = current->next;
    }
    return maxValue;
}


//max (not const)
template <typename T>
typename FrankList<T>::reference FrankList<T>::max(){
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    Node* current = head;
    T maxValue = current -> val;

    while (current) {
        if (current -> val >  maxValue) {
            maxValue = current -> val;
        }
	current = current->next;
    }
    return maxValue;
}


//operator =
template <typename T>
const FrankList<value_type>& FrankList<T>::operator=(const FrankList<value_type>& rhv){

}



//sa link list a u ++ptr nety poxel a petq 
#endif //_FRANKLIST_HPP__
