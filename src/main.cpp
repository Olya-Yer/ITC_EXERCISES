#include <smart_array.hpp>
#include <iostream>
#include <new>
/**
 *@brief The main function for battleship program
 * 
 * The fucntion creates a playing area, fills it with random layout of ships, and profides the user to play.
 *@return return 0 - success, return 1 - fail with message "cant allocate memory..." 
 *@authors Galust Betkhemyan, Sevak Sahakyan
 *@date 25.05.2018
 */
int main(){
	unsigned int a = 5;
	Smart_array* s = new Smart_array(a);
	s->set_element(2,9);
	std::cout << s->get_element(2) << std::endl;
	s->print_array();
	Smart_array* b = s;
	b->set_element(1,6);
	b->set_element(2,2);
	b->set_element(3,10);
	b->resize(9);
	s->print_array();
	std::cout << std::endl;
	b->print_array();
	return 0;
}
