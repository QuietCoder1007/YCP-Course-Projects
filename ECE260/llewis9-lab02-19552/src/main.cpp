#include <iostream>
#include <string>
#include <stdint.h>
#include "functions.h"
using namespace std;

#define SIZE 5

int main()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #1 - Use a call to 'new' to declare and allocate an array of five integers. 
	// Use print_ptr_info(string, ptr) to print out information for the long* array.
	// print_ptr_info(string, ptr) prints the memory address in which the value for 'ptr' 
	// is stored, followed by the actual value that is stored at that address. 
	//
	cout << endl << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #1" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #1 CODE HERE
	/////////////////////////////
	long* array = new long[5];
	print_ptr_info("array*", &array);
	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #2 - Iterate over 'array' and use print_ptr_info to print out the memory 
	// address and the value of each index of the array.  Notice anything about the addresses?
	// The values stored at each address consists of unknown garbage data. 
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #2" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #2 CODE HERE
	/////////////////////////////
	for(int i = 0; i < SIZE; i++){
		print_ptr_info("array[" + to_string(i) + "]", &array[i]);
	}
	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #3 - Iterate over 'array' and initialize each element to '100 + index'.
	// You do not need to print anything during this iteration.
	// This should overwrite the garbage data that you saw in Task #2.
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #3" << endl;
	cout << "*******************************************************************************" << endl;
	cout << "* Nothing to print" << endl;
	/////////////////////////////
	// YOUR Task #3 CODE HERE
	/////////////////////////////
	for(int i = 0; i < SIZE; i++){
		array[i] = 100 + i;
	}

	/////////////////////////////
	


	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #4 - After initialization, use print_ptr_info to print out the memory 
	// address and the value of each index of the array once again (same as Task #2). 
	// The addresses should be the same as those that you saw in Task #2.
	// The values should be the values that you set in Task #3.
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #4" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #4 CODE HERE
	/////////////////////////////
	
	for(int i = 0; i < SIZE; i++){
		print_ptr_info("array[" + to_string(i) + "]", &array[i]);
	}
	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #5 - Create a new 'long* ptr' and set that pointer equal to the 'array' created 
	// in Task #1. It should now point to 'array[0]'.
	// Print out the memory address and value of 'ptr'.
	// Does that value of 'ptr' match the address of 'array[0]'?  (hint hint ... it should)
	// Next, use the '+' operator and add 3 to 'ptr'. It should now point to 'array[3]'.
	// Print out the memory address and value of 'ptr'.
	// Does that value of 'ptr' match the address of 'array[3]'?
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #5" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #5 CODE HERE
	/////////////////////////////
	long* ptr = new long;
	ptr = array;
	print_ptr_info("ptr to array[0]", &ptr);
	ptr += 3;
	print_ptr_info("ptr to array[3]", &ptr);

	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #6 - Use 'print_ptr_info()' to print out the memory address and value of 
	// 'main()', 'print_ptr_info()', and 'get_num_processors()'.
	// This one requires an unusual cast, so the first one is done for you.
	// These functions are declared in the functions.h file
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #6" << endl;
	cout << "*******************************************************************************" << endl;
	print_ptr_info("main()", (void*)&main);
	/////////////////////////////
	// YOUR Task #6 CODE HERE
	/////////////////////////////
	print_ptr_info("print_ptr_info()", (void*)&print_ptr_info);
	print_ptr_info("get_num_processors()", (void*)&get_num_processors);
	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #7 - Not all variables types consume the same amount of memory. Use the function sizeof(<type>)
	// to determine the width (in bytes) of the following variable types: bool, char, short, int, long, long long,
	// float, double, char*, int*, and long*. Use the following website to get an idea of what sizes you should expect.
	// https://www.learncpp.com/cpp-tutorial/23-variable-sizes-and-the-sizeof-operator/
	// However, keep in mind that the size of these data types may vary from machine to machine ...
	// and that's why real programmers use templated data types. It ensures portability.
	// https://www.gnu.org/software/libc/manual/html_node/Integers.html
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #7" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #7 CODE HERE
	/////////////////////////////
	std::cout << "bool:\t\t" << sizeof(bool) << " bytes\n";
    std::cout << "char:\t\t" << sizeof(char) << " bytes\n";
    std::cout << "short:\t\t" << sizeof(short) << " bytes\n";
    std::cout << "int:\t\t" << sizeof(int) << " bytes\n";
    std::cout << "long:\t\t" << sizeof(long) << " bytes\n";
    std::cout << "long long:\t" << sizeof(long long) << " bytes\n"; // C++11 only
    std::cout << "float:\t\t" << sizeof(float) << " bytes\n";
    std::cout << "double:\t\t" << sizeof(double) << " bytes\n";
    std::cout << "char*:\t\t" << sizeof(char*) << " bytes\n";
	std::cout << "int*:\t\t" << sizeof(int*) << " bytes\n";
	std::cout << "long*:\t\t" << sizeof(long*) << " bytes\n";
	

	/////////////////////////////



	////////////////////////////////////////////////////////////////////////////////////////////////////
	// TODO: Task #8 - The function get_num_processors() is defined in functions.h.
	// Use get_num_processors() to determine the number of processors on the current computer and print your
	// result.  Note that this result includes logical cores, not just physical cores. If your machine has 
	// Hyper-Threading the number of logical cores will be double that of your physical cores.
	//
	cout << endl;
	cout << "*******************************************************************************" << endl;
	cout << "Task #8" << endl;
	cout << "*******************************************************************************" << endl;
	/////////////////////////////
	// YOUR Task #8 CODE HERE
	/////////////////////////////
	cout << "Number of Processors: " << get_num_processors();

	/////////////////////////////
	
	
	cout << endl << endl;
	return 0;
}


