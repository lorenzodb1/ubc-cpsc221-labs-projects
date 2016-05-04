#include <iostream>

using namespace std;

int * fill_array() {
	int *numArray=new int [10];
	for(int i=0; i<10; i++) {
		numArray[i]=i+1;
	}
	return numArray;
}

int main() {
	int* result;
	result=fill_array();
	for(int i=0; i<10; i++) {
		cout<<result[i]<<endl;
	}
	return 0;
}

