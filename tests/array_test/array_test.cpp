#include <smart_array.hpp>
#include "assert.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdio.h>

const char* log_path = "../../test_results.txt"

void test_constructor
{
	FILE* pFile;
	pFile = fopen(log_path, "w");
	Smart_array s(6);
	int size = s.get_size();
	assert (6 == size);
	if (pFile != NULL) {
	    fputs ("constructor with given size - pass", pFile);
	}
	
	int e == s.get_element(2);
	assert (2 == e)
	if (pFile != NULL) {
	    fputs ( "user gets 0 for empty cell - pass", pFile);
	}
	fclose (pFile);
}


