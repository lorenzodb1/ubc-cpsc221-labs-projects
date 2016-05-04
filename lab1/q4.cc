#include <string>
#include <fstream>
#include <cstdlib> // for atoi
#include <iostream>
// prototype 

using namespace std;

//void moveDisks(int n, const char* FROM, const char* VIA, const char* TO);

void moveDisks(int n, string first, string second, string third) {
	if(n==1) {
		cout<<"Move disk from "<<first<<" to "<<third<<endl;
	}
	else {
		moveDisks(n-1, first, third, second);
		moveDisks(1, first, second, third);
		moveDisks(n-1, second, first, third);
	}
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " number_of_disks" << std::endl;
    return -1;
  }
  int n = atoi(argv[1]);
  moveDisks(n, "peg A", "peg B", "peg C");
  return 0;
}
// put your moveDisks() function here #include <cstdlib>

