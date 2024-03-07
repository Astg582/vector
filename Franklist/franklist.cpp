#ifndef _FRANKLIST_CPP__
#define _FRANKLIST_CPP_

#include <iostream>
#include "franklist.hpp"
#include <stdexcept>
#include <cassert>

namespace vhuk
{
	


//operator << out
template <typename T>
std::ostream& vhuk::operator<<(std::ostream& out, const FrankList<T>& rhv)
{
    out << "~[ ";
    for (auto it = rhv.begin(); it != rhv.end(); ++it) {
        out << *it << " ";
    }
    out << " ]~";
    return out;
}

//Node
template <typename T>
vhuk::FrankList<T>::Node::Node()
	: val(T()), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr)
{}

//~FrankList
template <typename T>
vhuk::FrankList<T>::~FrankList()
{
	this->clear();
}

//Node (val)
template <typename T>
vhuk::FrankList<T>::Node::Node(T val)
    : val(val), next(nullptr), prev(nullptr), asc(nullptr), desc(nullptr)
{}


//Construcors Franclist
template <typename T>
vhuk::FrankList<T>::FrankList() {
	this->head = nullptr;
	this->tail = nullptr;
	this->ahead = nullptr;
	this->htail = nullptr;	
}



template <typename T>
vhuk::FrankList<T>::FrankList(size_type size) : vhuk::FrankList<T>::FrankList() {
    for(int i = 0; i != size; ++i) {
        push_back(T());
    }
}

template <typename T>
vhuk::FrankList<T>::FrankList(size_type size, const_reference init) : vhuk::FrankList<T>::FrancList() {

	for(int i = 0; i != size; ++i){
		push_back (init);
	}
}

template <typename T>
vhuk::FrankList<T>::FrankList(const FrankList<value_type>& rhv) : vhuk::FrankList<T>::FrancList() 
{
	for(auto it = rhv.begin(); it != rhv.end(); ++it){
		push_back(*it);
	} 
}


template <typename T>
vhuk::FrankList<T>::FrankList(FrankList<value_type>&& rhv) 

	: head(rhv.head) 
	, tail(rhv.tail) 	
	, ahead(rhv.ahead) 
	, atail(rhv.atail) 
{
	rhv.head = nullptr;
	rhv.tail = nullptr;
	rhv.ahead = nullptr;
	rhv.atail = nullptr;
}

template <typename T>
vhuk::FrankList<T>::FrankList(std::initializer_list<value_type> init) : vhuk::FrankList<T>::FrancList() {
	for(const auto& i : init){
		push_back(i);
	}
}

template <typename T>
template <typename input_iterator>
vhuk::FrankList<T>::FrankList(input_iterator f, input_iterator l) : vhuk::FrankList<T>::FrancList()
{
	for(input_iterator it = f; it != l; ++it){
		push_back(*it);
	}
}



//SWAP
template <typename T>
void vhuk::FrankList<T>::swap(FrankList<value_type>& rhv)
{
	std::swap(this->head = rhv.head);
	std::swap(this->tail = rhv.tail);
	std::swap(this->ahead = rhv.ahead);
	std::swap(this->atail = rhv.atail);
}

//SIZE
template <typename T>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::size() const
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
bool vhuk::FrankList<T>::empty() const
{
	return this->head == nullptr;
}


//RESIZE
template <typename T>
void vhuk::FrankList<T>::resize(size_type s, const_reference init){
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
void vhuk::FrankList<T>::clear() noexcept{
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
void vhuk::FrankList<T>::push_front(const_reference elem){

	Node* tmp = new Node(elem);
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
void vhuk::FrankList<T>::pop_front() {
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
void vhuk::FrankList<T>::push_back(const_reference elem){
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
void vhuk::FrankList<T>::pop_back(){
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
typename vhuk::FrankList<T>::const_reference  vhuk::FrankList<T>::front() const{
	if(this->empty()){
		throw std::out_of_range("List is empty" );
	}
	return this -> head -> val;
}


// front
template <typename T>
typename vhuk::FrankList<T>::reference  vhuk::FrankList<T>::front(){
   if (!head) {
        throw std::out_of_range("List is empty");
    }
    return this -> head -> val;
}


//back
template <typename T>
typename vhuk::FrankList<T>::const_reference  vhuk::FrankList<T>::back() const{
	if(!tail){
		throw std::out_of_range("List is empty");
	}
	return this -> tail -> val;
}


//back
template <typename T>
typename vhuk::FrankList<T>::reference  vhuk::FrankList<T>::back(){
 if (!tail) {
        throw std::out_of_range("List is empty");
    }
    return this-> tail -> val;
}

//min (const)
template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::min() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> atail -> val;
}


//min (not const)
template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::min() {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> ahead -> val;
}

//max (const)
template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::max() const {
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> ateal -> val;
}


//max (not const)
template <typename T>
typename vhuk::FrankList<T>::reference vhuk::FrankList<T>::max(){
    if (!head) {
        throw std::out_of_range("List is empty");
    }

    return this -> atail -> val;
}


//operator = (copy)
template <typename T>
const vhuk::FrankList<T>& vhuk::FrankList<T>::operator=(const FrankList<value_type>& rhv){

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
const vhuk::FrankList<T>& vhuk::FrankList<T>::operator=(FrankList<value_type>&& rhv){
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
const vhuk::FrankList<T>& vhuk::FrankList<T>::operator=(std::initializer_list<value_type> init) {

	this->clear();

	for (const auto& value : init) {
        	push_back(value);
	}

	return *this;
}


//operator ==
template <typename T>
bool vhuk::FrankList<T>::operator==(const FrankList<value_type>& rhv) const{
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
bool vhuk::FrankList<T>::operator!=(const FrankList<value_type>& rhv) const {
	return !(*this == rhv);
}

//operator <
template <typename T>
bool vhuk::FrankList<T>::operator<(const FrankList<value_type>& rhv) const
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
bool vhuk::FrankList<T>::operator<=(const FrankList<value_type>& rhv) const{
	return (*this < rhv) || (*this == rhv);
}

//operator >=
template <typename T>
bool vhuk::FrankList<T>::operator>=(const FrankList<value_type>& rhv) const{
	return !(*this < rhv);
}

//operator >
template <typename T>
bool vhuk::FrankList<T>::operator>(const FrankList<value_type>& rhv) const{
	return !(*this <= rhv); 
}


// iterator cbegin
template <typename T>
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cbegin() const{
	return const_iterator(head);
}

//iterator cend
template <typename T>
typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::cend() const{
	return const_iterator(nullptr);
}

// reverse iterator crbegin
template <typename T>
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crbegin() const{
	 return const_reverse_iterator(tail);
}

// reverse iterator crend
template <typename T>
typename vhuk::FrankList<T>::const_reverse_iterator vhuk::FrankList<T>::crend() const {
    return const_reverse_iterator(head->prev);
}

// cabegin
template <typename T>
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::cabegin() const {
    return const_asc_iterator(atail);
}

// caend
template <typename T>
typename vhuk::FrankList<T>::const_asc_iterator vhuk::FrankList<T>::caend() const {
    return const_asc_iterator(atail->asc);
}

// cdbegin
template <typename T>
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdbegin() const {
    return const_desc_iterator(atail);
}

// cdend
template <typename T>
typename vhuk::FrankList<T>::const_desc_iterator vhuk::FrankList<T>::cdend() const {
    return const_desc_iterator(ahead->desc);
}


//cmbegin
template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmbegin() const{
	return const_multi_iterator(this->head);
}


//cmend
template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmend() const{
	return const_multi_iterator (this->tail->next);
}


//cmabegin
template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmabegin() const{
	return const_multi_iterator(this->ahead);
}


//cmaend
template <typename T>
typename vhuk::FrankList<T>::const_multi_iterator vhuk::FrankList<T>::cmaend() const{
	return const_multi_iterator(this->atail->asc);
}


//revers const multi iterator
template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrbegin() const{
	return const_multi_reverse_iterator(tail);
}


//cmrend
template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrend() const{
	return const_multi_reverse_iterator(this->head->prev);
}

//cmrdbegin
template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdbegin() const{
	return const_multi_reverse_iterator(this->atail);
}

//cmrdend
template <typename T>
typename vhuk::FrankList<T>::const_multi_reverse_iterator vhuk::FrankList<T>::cmrdend() const{
	return const_multi_reverse_iterator(this->ahead->desc);
}


//iterator begin
template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::begin(){
	return iterator(this->head);
}

//iterator end
template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::end(){
	return iterator(this->teal->next);
}

//revers iterator begin
template <typename T>
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rbegin(){
	return reverse_iterator(this->teal);
}

//revers iterator end
template <typename T>
typename vhuk::FrankList<T>::reverse_iterator vhuk::FrankList<T>::rend(){
	return revers_iterator(this->head->prev);
}

//asc iterator abegin
template <typename T>
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::abegin(){
	return asc_iterator(this->ahead);
}

//asc iter end
template <typename T>
typename vhuk::FrankList<T>::asc_iterator vhuk::FrankList<T>::aend(){
	return asc_iterator(this->atail->asc);
}

//dbegin
template <typename T>
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dbegin(){
	return desc_iterator(this->atail);
}

//dend
template <typename T>
typename vhuk::FrankList<T>::desc_iterator vhuk::FrankList<T>::dend(){
	return desc_iterator(this->ahead->desc);
}

//mbegin
template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mbegin(){
	return multi_iterator(this->head);
}

//mend
template <typename T>
typename vhuk::FrankList<T>::multi_iterator vhuk::FrankList<T>::mend(){
	return multi_iterator(this->tail->next);
}

//revers mrbegin
template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrbegin(){
	return multi_reverse_iterator(this->tail);
}

//revers mrend
template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrend(){
	return multi_reverse_iterator(this->head->prev);
}


//revers mrdbegin
template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdbegin(){
	return multi_reverse_iterator(this->atail);
}

//revers mrdbend
template <typename T>
typename vhuk::FrankList<T>::multi_reverse_iterator vhuk::FrankList<T>::mrdend(){
	return multi_reverse_iterator(this->ahead->desc);
}

//iterator insert

template <typename T>
template <typename iter> 
iter vhuk::FrankList<T>::insert(iter pos, size_type size, const_reference val){
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    for (size_type i = 0; i < size; ++i) {
        pos = insert(pos, val);
    }
	return pos;
}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert(iter pos, std::initializer_list<value_type> init){
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
	for(auto i : init){
		pos = insert(pos,i);
	}
	return pos;
}

template <typename T>
template <typename iter, typename input_iterator>
iter vhuk::FrankList<T>::insert(iter pos, input_iterator f, input_iterator l){
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
	for (auto i = f; i != l; i++)
	{
		pos = insert(pos, *i);
	}
	return pos;
}


//Erase
template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::erase(iter pos){
	static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    Node* tmp = pos.ptr;
	iter it(pos);
	++it;
	if(pos.ptr == this->head) {
		pop_front();
		return it;
	}
	if(pos.ptr == this->tail){
		pop_back();
		return it;
	}
	if (tmp->prev){
		tmp->prev->next = tmp->next;
	} 
	if (tmp->next){
		tmp->next->prev = tmp->prev;
	}
	if (tmp->desc){
		tmp->desc->asc = tmp->asc;
	}
	if (tmp->asc)
	{
		tmp->asc->desc = tmp->desc;
	}
	
	delete pos.ptr;
	return it;
	
}

template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::erase(iter f, iter l){
	iter it(f);
	while (it != l){
		it = erase(it);
	}
	return it;
}

template <typename T>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::remove(const_reference val){
	size_type tmp = 0;
	iterator it = this->begin();
	while (it != this->end()){
		if (*it == val){
			it = erase(it);
			++tmp;
		}else{
			++it;
		}
		
	}
	return tmp;
 }

template <typename T>
template <typename unary_predicate>
typename vhuk::FrankList<T>::size_type vhuk::FrankList<T>::remove_if(unary_predicate func){
	size_type tmp = 0;
	iterator it = this->begin();
	while (it != this->end())
	{
		if(func(*it)){
			it = erase();
			++tmp;
		}
		else{
			++it;
		}
	}
	return tmp;
}

//revers
template <typename T>
void vhuk::FrankList<T>::reverse(){
	std::swap(this->head, this->tail);
	Node* it = head;
	while (it != nullptr){
		std::swap(it->next, it->prev );
		it = it->next;
		
	}
}


//sort
template <typename T>
void vhuk::FrankList<T>::sort(bool reversed){
	if(!ahead){
		return;
	}
	if(!reversed){
		this->head = this->ahead;
		this->tail = this->atail;
		Node* it = ahead;
		it->prev = nullptr;
		while (it){
			it->next = it->asc;
			if(it->next){
				it->next->prev = it;
			}
			it = it->next;
		}	
	} else {
			this->head = this->atail;
			this->tail = this->ahead;
			Node* it = ahead;
		it->prev = nullptr;
		while (it){
			it->next = it -> desc;
			if(it->next){
				it->next->prev = it;
			}
			it = it->next;
		}	
	}
}

//find
template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::find(const_reference elem){
	iterator it = this->begin();
	while (it != this->end() && *it != elem){
		++it;
	}
	organize_left(it.ptr);
	return iterator(it);
}

//rfind
template <typename T>
typename vhuk::FrankList<T>::iterator vhuk::FrankList<T>::rfind(const_reference elem){
	reverse_iterator it = rbegin();
	while (it != rand() && *it != elem){
		++it;
	}
	organize_right(it.ptr);
	return iterator(it);
}

//traverse
template <typename T>
template <typename unary_predicate>
void vhuk::FrankList<T>::traverse(unary_predicate func, bool sorted, bool reversed){
	if(empty()){
		return;
	}
	if (!sorted && !reversed)
	{
		for(auto it = begin(); it != end(); ++it){
			func(*it);
		}
	} else if (!sorted){
		for(auto it = rbegin(); it != rend(); ++it){
			func(*it);
		}
	} else if (!reverse) {
		for(auto it = abegin(); it != aend(); ++it){
			func(*it);
		}
	} else{
		for( auto it = dbegin(); it != dend(); ++it){
			func(*it);
		}
	}
}

//print
template <typename T>
void vhuk::FrankList<T>::print(bool sorted, bool reversed){
	if(empty()){
		std::cout << "~[ ]~";
		return;
	}
	std::cout << "~[ ";
	if (!sorted && !reversed){
		for (auto it = begin(); it != end(); ++it){
			std::cout << *it << " ";
		}	
	} else if (!sorted ){
		for (auto it = rbegin(); it != rand(); ++it){
			std::cout << *it << " ";
		}
	} else if (!reversed){
		for (auto it = abegin(); it != aend(); ++it){
			std::cout << *it << " ";
		}
	} else {
		for (auto it = dbegin(); it != dend(); ++it){
			std::cout << *it << " ";
		}
	}
	std::cout << " ]~";
}

template <typename T>
void vhuk::FrankList<T>::put_in_sorted_order(Node* ptr){
	assert(ptr != nullptr);
	if (!ahead){    // !ahead 
		ahead = ptr;
		atail = ptr;
		return;
	}
	Node* it = ahead;
	while (it->val <= ptr->val && it->asc){
		it = it->asc;
	}

	//it < ptr
	if (it->val < ptr->val){
		ptr->asc = it->asc;
		it->asc = ptr;
		ptr->desc = it;
		if (!ptr->asc){
			atail = ptr;
		}
	} else if (it->val >= ptr->val) {  // it >= ptr
		ptr->desc = it->desc;
		if(it->desc) {
			it->desc->asc = ptr;
		}else{
			ahead = ptr;
		}
		ptr->asc = it;
		it->desc = ptr;
	}
	
}

//organize_left
template <typename T>
void vhuk::FrankList<T>::organize_left(Node* ptr){
	if(empty() || ptr == head){ return; }
		Node* prev = ptr->prev;
		Node* next = ptr->next;
		if (prev){
			if(prev->prev){
				prev->prev->next = ptr;
			}
			prev->prev = ptr;
			prev->next = next;
			ptr->next = prev;
		}
		if (next){
			next->prev = prev;
		}
		if (prev == head){
			head = ptr;
		}
		if (ptr == tail) {
			tail = prev;
		}	
}


//organize_right
template <typename T>
 void vhuk::FrankList<T>::organize_right(Node* ptr){
	if(empty() || ptr == tail){ return; }
	Node* prev = ptr->prev;
	Node* next = ptr->next;
	if (prev){
		if(next->next){
			next->next->next = ptr;
		}
		next->next = ptr;
		next->prev = prev;
		ptr->next = next;
	}
	if (prev){
		prev->next = next;
	}
	if (next == tail){
		tail = ptr;
	}
	if (ptr == tail) {
		head = next;
	}	
 }


//insert def
template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert_def(iter pos, const_reference val){
	assert(pos.ptr != nullptr);
    if (pos.ptr == this->head) {
        push_front(val);
    } else {
        Node* tmp = new Node(val);
        pos.ptr->prev->next = tmp;
        tmp->prev = pos.ptr->prev;
        pos.ptr->prev = tmp;
        tmp->next = pos.ptr;
        
        put_in_sorted_order(tmp);
    }
    return pos;
}


//insert rev
template <typename T>
template <typename iter>
iter vhuk::FrankList<T>::insert_rev(iter pos, const_reference val){
	assert(pos.ptr != nullptr);
    insert_def(pos, val);
    ++pos;
    return pos;
}



//   Base Iterator   // ------------------------------------------------------------------------------------------------------------
template <typename T>
vhuk::FrankList<T>::base_iterator::base_iterator(Node* ptr) : ptr(ptr)
{}

// ==
template <typename T>
bool vhuk::FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const{
	return(this->ptr == rhv.ptr);
}

//~base iterator
template <typename T>
vhuk::FrankList<T>::base_iterator::~base_iterator(){this->ptr = nullptr;}


// !=
template <typename T>
bool vhuk::FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const {
	return this->ptr != rhv.ptr;
}


//const iterator
template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv): base_iterator(rhv){}

// R value constructor (const)
template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv) : base_iterator(rhv){
	rhv.ptr = nullptr;
}

// = copy
template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator=(const base_iterator& rhv) {
	this->ptr = rhv.ptr;
	return this;
}

// = muv
template <typename T>
 const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator=(base_iterator&& rhv) {
	this->ptr = rhv.ptr;
	rhv.ptr = nullptr;
	return this;
 }

// * deRef
template <typename T>
typename vhuk::FrankList<T>::const_reference vhuk::FrankList<T>::const_iterator::operator*() const {
		return this->ptr->val;
 }

// -> 
template <typename T>
typename vhuk::FrankList<T>::const_pointer vhuk::FrankList<T>::const_iterator::operator->() const{
	return this->ptr;
}

// ++ prefix
template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator++(){
	this->ptr = this->ptr->next;
	return *this;
}

// postfix ++ 
template <typename T>
const  typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator++(value_type) {
	const_iterator tmp(*this);
	++(*this);
	return tmp;
}

// -- prefix 
template <typename T>
const typename vhuk::FrankList<T>::const_iterator& vhuk::FrankList<T>::const_iterator::operator--(){
	this->ptr = this->ptr->next;
	return *this; 
}

// postfix --
template <typename T>
const typename vhuk::FrankList<T>::const_iterator vhuk::FrankList<T>::const_iterator::operator--(value_type) {
	const_iterator tmp = this;
	--(*this);
	return tmp;
}


// constructor
template <typename T>
vhuk::FrankList<T>::const_iterator::const_iterator(Node* ptr) : base_iterator(){}

template <typename T>
vhuk::FrankList<T>::terator::iterator(const base_iterator& rhv) : const_iterator() {}

template <typename T>
vhuk::FrankList<T>::terator::iterator(base_iterator&& rhv);
template <typename T>
template <typename T>
template <typename T>
template <typename T>
template <typename T>


 


} // namespace vhuk

#endif //_FRANKLIST_CPP_
