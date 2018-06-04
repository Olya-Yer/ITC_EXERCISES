#include <smart_array.hpp>
#include <iostream>
#include <new>
#include <cstdio>
#include <cassert>

Smart_array::Smart_array(unsigned int n)
{
	try {
		this->m_array = new float(n);	
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
	this->m_size = n;
	this->init();
};

Smart_array::Smart_array(const Smart_array &s) 
{
	try {
		this->m_array = new float(s.m_size);
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
	this->m_size = s.m_size;
	this->move(s.m_array, this->m_array, s.m_size, this->m_size);
}

bool Smart_array::set_element(int i, int v)
{
	if(this->is_out(i)) {
		return false;
	}
	*(this->m_array + i) = (float) v;
}

int Smart_array::get_element(int i)
{
	if(this->is_out(i)) {
		std::cout << this->m_out_message << std::endl;
		return 0;
	}
	else if (this->is_empty(i)){
		return this->m_empty_return;
	}
	return (int)  *(this->m_array + i);
};

int Smart_array::get_size()
{
	return this->m_size;
}

bool Smart_array::is_empty(int i){
	if(this->is_out(i)){
		return false;
	}
	float* c = (this->m_array + i);
	if(*c == this->m_default_value) {
		return true;
	}
	return false;
}
void Smart_array::resize(unsigned int n)
{
	try {
		float *v = NULL; 
		v = new float(n);
		this->move(this->m_array, v, this->m_size, n);
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
}
bool Smart_array::is_out(unsigned int n)
{
	if(this->m_size <= n) {
		return true;
	}
	return false;
}

bool Smart_array::init(){
	float* c = NULL;
	for (int i = 0; i < this->m_size; ++i) {
		c = (this->m_array + i);
		assert(NULL != c);
		*c = this->m_default_value;
	}
}

void Smart_array::move(float* f, float* t, int n_f, int n_t){
	int i = 0;
	while(!this->is_out(i) && i < n_t) {
		*(t + i) = *(f + i);
		++i;
	}
	for(int i = 0; i < (n_t - n_f ); ++i){
		*(t + i) = this->m_default_value;
	}
	if(this->m_array) {
		delete this->m_array;
	}
	this->m_array = t;
	this->m_size = n_t;
}

void Smart_array::print_array()
{
	for(int i = 0; i < this->m_size; ++i) {
		if(this->is_empty(i)){	
			std::cout << "empty" << "; " ;
			continue;
		}
		std::cout << this->get_element(i) << "; " ;
	}
	std::cout<<std::endl;
}
