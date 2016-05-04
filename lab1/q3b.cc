#include <iostream>

using namespace std;

int * fill_array(int first_value, int increment) {
	int *numArray=new int [10];
	numArray[0]=first_value;
	for(int i=1; i<10; i++) {
		numArray[i]=numArray[i-1]+increment;
	}
	return numArray;
}

int main() {
	int* result;
	result=fill_array(4,2);
	for(int i=0; i<10; i++) {
		cout<<result[i]<<endl;
	}
	return 0;
}

