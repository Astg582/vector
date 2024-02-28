#ifndef _FRANKLIST_HPP__
#define _FRANKLIST_HPP__

using namespace vhuk;

template <typename T>
std::ostream& FrankList::operator<<(std::ostream& out, const FrankList<T>& rhv)
{
	return out << rhv;
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

//sa link kist a u ++ptr nety poxel a petq 
#endif //_FRANKLIST_HPP__
