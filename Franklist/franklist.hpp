#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

namespace vhuk{

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

	: this->head(rhv.head) 
	, this->tail(rhv.tail) 	
	, this->ahead(rhv.ahead) 
	, this->atail(rhv.atail) 
{
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
FrankList<T>::FrankList(input_iterator f, input_iterator l) :FrancList()
{
	for(input_iterator it = f; it != l; ++it){
		push_back(*it);
	}
}

//~FrankList
template <typename T>
FrankList<T>::~FrankList()
{
	this->clear();
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
typename FrankList<T>::size_type FrankList<T>::size() const
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
	return this->head == nullptr;
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
		while(s - size){
			this->push_back(init);
			--s;
		}
	}
	put_in_sorted_order(this->head);
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

	put_in_sorted_order(head);
}

//pop back
template <typename T>
void FrankList<T>::pop_front() {
    if (!this->head) {
        throw std::invalid_argument("List is empty");
    }

    if (this->head) {
        if (this->head->asc) {
            this->head->asc->desc = this->head->desc;
        }
        if (this->head->desc) {
            this->head->desc->asc = this->head->asc;
        }

        Node* newHead = this->head->next;
        delete this->head;
        this->head = newHead;

        if (this->head) {
            this->head->prev = nullptr;
        }
    }
}


//push back
template <typename T>
void FrankList<T>::push_back(const_reference elem){
	Node* tmp = new Node(elem);
	if(!(this -> head)){
		this->head = tmp;
	}else{
		this -> tail -> next = tmp;
		tmp -> prev = this -> tail;	
	}  

	this -> tail = tmp; 
	put_in_sorted_order(tail);
}


//pop back
template <typename T>
void FrankList<T>::pop_back(){
	if (!this->head) {
        	throw std::invalid_argument("List is empty");
	}

	if (tail) {
	 if (this->head->asc) {
            this->head->asc->desc = this->head->desc;
        }
        if (this->head->desc) {
            this->head->desc->asc = this->head->asc;
        }
       
 	Node* newTail = tail->prev;
       		delete tail;
        	tail = newTail;
        	if (tail) {
            		tail->next = nullptr;
        	}
    }
}

// front
template <typename T>
typename FrankList<T>::const_reference T& FrankList<T>::front() const{
	if(this->empty()){
		throw std::out_of_range("List is empty" );
	}
	return this -> head -> val;
}


// front
template <typename T>
typename FrankList<T>::reference T& FrankList<T>::front(){
   if (!head) {
        throw std::out_of_range("List is empty");
    }
    return this -> head -> val;
}


//back
template <typename T>
typename FrankList<T>::const_reference T& FrankList<T>::back() const{
	if(!tail){
		throw std::out_of_range("List is empty");
	}
	return this -> tail -> val;
}


//back
template <typename T>
typename FrankList<T>::reference T& FrankList<T>::back(){
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

    return this -> atail -> val;
}


//min (not const)
template <typename T>
typename FrankList<T>::reference FrankList<T>::min() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> ahead -> val;
}

//max (const)
template <typename T>
typename FrankList<T>::const_reference FrankList<T>::max() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> ateal -> val;
}


//max (not const)
template <typename T>
typename FrankList<T>::reference FrankList<T>::max(){
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> atail -> val;
}


//operator = (copy)
template <typename T>
const FrankList<value_type>& FrankList<T>::operator=(const FrankList<value_type>& rhv){

	if(this == &rhv){
		return *this;
	}

	this -> clear();

	for(auto it = rhv.begin(); it != rhv.end(); ++it){
		push_back(*it);
	}
	return *this; 
}

//operator = (accign)
template <typename T>
const FrankList<value_type>& FrankList<T>::operator=(FrankList<value_type>&& rhv){
	if(this == &rhv){
		return *this;
	}
	
	this->clear();

	this->head = rhv.head;
	this->tail = rhv.tail;	
	this->ahead = rhv.ahead;
	this->atail = rhv.atail;
	rhv.head = nullptr;
	rhv.tail = nullptr;
	rhv.ahead = nullptr;
	rhv.atail = nullptr;
	return *this;
}


//operator = (initial)
template <typename T>
const FrankList<value_type>& FrankList<T>::operator=(std::initializer_list<value_type> init) {

	this->clear();

	for (const auto& value : init) {
        	push_back(value);
	}

	return *this;
}


//operator ==
template <typename T>
bool FrankList<T>::operator==(const FrankList<value_type>& rhv) const{
	if(this->size() != rhv.size()){
		return false;
	}

	auto it1 = this->begin();
	auto it2 = rhv.begin();

	while(it1 != this->end() && it2 !=rhv.end()){
		if(*it1 != *it2){
			return false;
		} 
		++it1;
		++it2;
	} 
	return (it1 == this->end() && it2 == rhv.end());
}

//operator !=
template <typename T>
bool FrankList<T>::operator!=(const FrankList<value_type>& rhv) const {
	return !(*this == rhv);
}

//operator <
template <typename T>
bool FrankList<T>::operator<(const FrankList<value_type>& rhv) const template <typename T>
{
	auto it1 = this->begin();
	auto it2 = rhv.begin();
	auto size = (this->size() <= rhv.size()) ? this->end() : rhv.end();

	while(it1 != size && it2 != size){
		if(*it1 >= *it2){
			return false;
		} 
		++it1;
		++it2;
	} 
	
	 return (it1 == size && it2 != size);
}

//operator <=
template <typename T>
bool operator<=(const FrankList<value_type>& rhv) const{
	return (*this < rhv) || (*this == rhv);
}

//operator >=
template <typename T>
bool FrankList<T>::operator>=(const FrankList<value_type>& rhv) const{
	return !(*this < rhv);
}

//operator >
template <typename T>
bool FrankList<T>::operator>(const FrankList<value_type>& rhv) const{
	return !(*this <= rhv); 
}


// iterator cbegin
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cbegin() const{
	return const_iterator(head);
}

//iterator cend
template <typename T>
typename FrankList<T>::const_iterator FrankList<T>::cend() const{
	return const_iterator(nullptr);
}

// reverse iterator crbegin
template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crbegin() const{
	 return const_reverse_iterator(tail);
}

// reverse iterator crend
template <typename T>
typename FrankList<T>::const_reverse_iterator FrankList<T>::crend() const {
    return const_reverse_iterator(head->prev);
}

// cabegin
template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::cabegin() const {
    return const_asc_iterator(atail);
}

// caend
template <typename T>
typename FrankList<T>::const_asc_iterator FrankList<T>::caend() const {
    return const_asc_iterator(atail->asc);
}

// cdbegin
template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdbegin() const {
    return const_desc_iterator(atail);
}

// cdend
template <typename T>
typename FrankList<T>::const_desc_iterator FrankList<T>::cdend() const {
    return const_desc_iterator(ahead->desc);
}


//cmbegin
template <typename T>
typename FrankList<T>::const_multi_iterator cmbegin() const{
	return const_multi_iterator(this->head);
}


//cmend
template <typename T>
typename FrankList<T>::const_multi_iterator cmend() const{
	return const_multi_iterator (this->tail->next);
}


//cmabegin
template <typename T>
typename FrankList<T>::const_multi_iterator cmabegin() const{
	return const_multi_iterator(this->ahead);
}


//cmaend
template <typename T>
typename FrankList<T>::const_multi_iterator cmaend() const{
	return const_multi_iterator(this->atail->asc);
}


//revers const multi iterator
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator cmrbegin() const{
	return const_multi_reverse_iterator(tail);
}


//cmrend
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator cmrend() const{
	return const_multi_reverse_iterator(this->head->prev);
}

//cmrdbegin
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator cmrdbegin() const{
	return const_multi_reverse_iterator(this->atail);
}

//cmrdend
template <typename T>
typename FrankList<T>::const_multi_reverse_iterator cmrdend() const{
	return const_multi_reverse_iterator(this->ahead->desc);
}


//iterator begin
template <typename T>
typename FrankList<T>::iterator begin(){
	return iterator(this->head);
}

//iterator end
template <typename T>
typename FrankList<T>::iterator end(){
	return iterator(this->teal->next);
}

//revers iterator begin
template <typename T>
typename FrankList<T>::reverse_iterator rbegin();{
	return reverse_iterator(this->teal);
}

//revers iterator end
template <typename T>
typename FrankList<T>::reverse_iterator rend(){
	return revers_iterator(this->head->prev);
}

//asc iterator abegin
template <typename T>
typename FrankList<T>::asc_iterator abegin(){
	return asc_iterator(this->ahead);
}

//asc iter end
template <typename T>
typename FrankList<T>::asc_iterator aend(){
	return asc_iterator(this->atail->asc);
}

//dbegin
template <typename T>
typename FrankList<T>::desc_iterator dbegin(){
	return desc_iterator(this->atail);
}

//dend
template <typename T>
typename FrankList<T>::desc_iterator dend(){
	return desc_iterator(this->ahead->desc);
}

//mbegin
template <typename T>
typename FrankList<T>::multi_iterator mbegin(){
	return multi_iterator(this->head);
}

//mend
template <typename T>
typename FrankList<T>::multi_iterator mend(){
	return multi_iterator(this->tail->next);
}

//revers mrbegin
template <typename T>
typename FrankList<T>::multi_reverse_iterator mrbegin(){
	return multi_reverse_iterator(this->tail);
}

//revers mrend
template <typename T>
typename FrankList::multi_reverse_iterator mrend();{
	return multi_reverse_iterator(this->head->prev);
}


//revers mrdbegin
template <typename T>
typename FrankList<T>::multi_reverse_iterator mrdbegin(){
	return multi_reverse_iterator(this->atail);
}

//revers mrdbend
template <typename T>
typename FrankList<T>::multi_reverse_iterator mrdend(){
	return multi_reverse_iterator(this->ahead->desc);
}

template <typename T>
template <typename iter> 
iter FrankList<T>::insert(iter pos, size_type size, const_reference val){

}
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>


 
}
//

}
#endif //_FRANKLIST_HPP__
