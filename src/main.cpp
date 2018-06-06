#include <smart_array.hpp>
#include <iostream>
#include <new>

void quick_sort(Smart_array& s, int left, int right);
/**
 *@brief The main function for battleship program
 * 
 * The fucntion creates a playing area, fills it with random layout of ships, and profides the user to play.
 *@return return 0 - success, return 1 - fail with message "cant allocate memory..." 
 *@authors Galust Betkhemyan, Sevak Sahakyan
 *@date 25.05.2018
 */
int main(){
	Smart_array s(10,0);
	s.set_element(2,9);
	s.set_element(0,6);
	s.print_array();
        std::cout << "Sorting" << std::endl;
	quick_sort(s,0,s.get_size()-1);	
	s.print_array();
        std::cout << "new Smart_array declared" << std::endl;
        Smart_array b(10,0);
        std::cout << "assignment op called" << std::endl;
        b = s;
//      b.print_array();
//	Smart_array b = s;
//	b.resize(40);
//	b.set_element(39,80);
//	b.print_array();
	return 0;
}


void quick_sort(Smart_array& s, int left, int right)
{
	int i = left;
	int j = right;
	int m = (int) (left + right)/2;
	int pivot = s.get_element(m);

	while (i < j){
		while (s.get_element(i) < pivot) {
			++i;
		}
		while (s.get_element(j) > pivot) {
			--j;
		}
		if (i <= j){
			s.swap(i, j);
			++i;
			--j;
		}
	}
	if (left < j) {
		quick_sort (s, left , j);
	}
	if (i < right) {
		quick_sort ( s, i, right);
	}
}
