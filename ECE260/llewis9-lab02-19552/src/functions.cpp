#include "functions.h"



// print_ptr_info(string, ptr) prints the address to which 'ptr' points, and the 
// value that is stored at that address.
void print_ptr_info(string name, void* ptr) {
	ios saved_cout_flags(nullptr);
	saved_cout_flags.copyfmt(cout);

	cout.width(22);  cout << left << name.c_str();
	
	cout.width(10);  cout << "Address: ";
	cout.width(20);  cout << hex << showbase << setfill('0') << internal << setw(18) << ptr;
	
	cout.width(8);   cout << "    Value: ";
	cout << hex << showbase << setfill('0') << internal << setw(18) << *(long*)(ptr) << endl;

	cout.copyfmt(saved_cout_flags);
}



// returns the number of processors in the system
int get_num_processors() {
	unsigned num_processors = thread::hardware_concurrency();
	return num_processors;
}