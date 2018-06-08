#include <smart_array.hpp>
#include <iostream>
#include <new>
#include <cstdio>
#include <cassert>

bool Smart_array::set_element(unsigned int i, int v)
{
	if(is_out(i)) {
		return false;
	}
        // YM: overkill
	int* c = m_array + i;  
	assert(NULL != c);
	*(c) = v;
	return true;
}

int Smart_array::get_element(unsigned int i)
{
	if(is_out(i)) {
		std::cout << m_out_message << std::endl;
		return m_default_value;
	}
	int* c = m_array + i;
	assert(NULL != c);
	return *c;
};

const int Smart_array::get_size() const
{
	return m_size;
}

int Smart_array::get_size()
{
	return m_size;
}

void Smart_array::resize(unsigned int n)
{
	try {
		int *v = new int [n];
		move(m_array, v, m_size, n);
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
                //exit 1;
	}
}

bool Smart_array::is_out(unsigned int n)
{
	if(m_size <= n) {
		return true;
	}
	return false;
}

bool Smart_array::is_out(unsigned int n) const
{
	if(m_size <= n) {
		return true;
	}
	return false;
}

bool Smart_array::init()
{
	int* c = NULL;
	for (int i = 0; i < m_size; ++i) {
		c = (m_array + i);
		assert(NULL != c);
		*c = m_default_value;
	}
}

void Smart_array::move(int* f, int* t, unsigned int n_f, unsigned int n_t){
	int i = 0;
	while(!is_out(i) && i < n_t) {
		*(t + i) = *(f + i);
		++i;
	}
	for(int i = 0; i < (n_t - n_f ); ++i){
		*(t + i) = m_default_value;
	}
	if(m_array) {
		delete[] m_array;
	}
	m_array = t;
	m_size = n_t;
}

void Smart_array::print_array()
{
	for(int i = 0; i < m_size; ++i) {
		std::cout << get_element(i) << "; " ;
	}
	std::cout<<std::endl;
}


bool Smart_array::swap(unsigned int i, unsigned int j)
{
	if(is_out(j) || is_out(i)) {
		return false;
	}
	int temp = 0;
	temp = *(m_array + i);
	*(m_array + i) = *(m_array + j);
	*(m_array + j) = temp;
	return true;
}

Smart_array::Smart_array(unsigned int n, int d)
{
	m_size = n;
	m_default_value = d;
	std::cout << "constructor called" << std::endl;
	try {
		std::cout << "initializing array"<< std::endl;
		m_array = nullptr;
		m_array = new int [m_size];
		std::cout << "done" << std::endl;
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
	init();
};

Smart_array::Smart_array(const Smart_array &s) 
{
	std::cout << "copy constructor called" << std::endl;
	m_size = s.m_size;
	m_default_value = s.m_default_value;
	try {	
		std::cout << "making an array"<< s.m_size <<std::endl;
		int* a ;
		a = new int [m_size];
		std::cout << "made"<<std::endl;
		std::cout << m_array; 
		move(s.m_array, a, s.m_size, m_size);
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}

}

Smart_array& Smart_array::operator=(const Smart_array& s)
{
	std::cout << "assignment operator called" << std::endl;
	try{
		if (this != &s) {
			delete[] m_array;
			m_size = s.m_size;
			m_default_value = s.m_default_value;
			m_array = nullptr;
			m_array = new int[s.m_size];
		}
		move(s.m_array, m_array, s.m_size,m_size);
	}
	catch (std::bad_alloc& e) {
		std::cout << e.what() << std::endl;
	}
	return *this;    
}

const int& Smart_array::operator[](unsigned int i) const
{
	if(is_out(i)){
		return m_default_value;
	}
	return m_array[i];
}

int& Smart_array::operator[](unsigned int i)
{
	if(is_out(i)){
		return m_default_value;
	}
	return m_array[i];
}
std::ostream& operator<<(std::ostream& os, const Smart_array& s)  
{  
	for(int i =0; i < s.get_size(); ++i){
		os << s[i] << ", ";
	}
	os << std::endl;
	return os;  
}  

Smart_array::~Smart_array()
{
	std::cout << "destructor called" << std::endl;
	assert(m_array);
	free(m_array);
}
