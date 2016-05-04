#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

void random(int num) {
	srand(time(NULL));
	int n=rand()%100+1;
	bool guess=false;
	while(!guess) {
		if(num==n) {
			cout<<"You guessed!"<<endl;
			guess=true;
		}
		if(num>n) {
			cout<<"It's less than you think! Try again!"<<endl;
			char newGuess[333];
			fgets(newGuess, 333, stdin);
			num=atoi(newGuess);
		}
		if(num<n) {
			cout<<"It's more than you think! Try again!"<<endl;
			char newGuess[333];
			fgets(newGuess, 333, stdin);
			num=atoi(newGuess);
		}
	}
	return;
}

int main(int argc, char *argv[]) {
  /*if (argc != 2) {
    std::cout << "Please retry"<< std::endl;
    return -1;
  }
  int n = atoi(argv[1]);*/
  int n=1;
  random(n);
  return 0;
}
