#include <iostream>
#include <ctime>
#include <cstdlib>

int * x;
int comps;
int reg[10000];

void swap(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int randint(int a, int b) {
	return a + (rand() % (b - a + 1));
}

void quicksort(int a, int b) {
	if (a >= b) return;
	int p = randint(a,b); // pivot
	swap(x[a], x[p]);
	int m = a;
	int i;
	// in-place partition:
	for (i = a+1; i <= b; i++) {
		comps++;
		if (x[i] < x[a]) {
			swap(x[++m], x[i]);
		}
	}
	swap(x[a],x[m]);
	quicksort(a, m-1);
	quicksort(m+1, b);
}

int qc(int n) {
	if (n <= 1) return 0;
	int p=randint(1, n);
	float sum = 0.0;
	sum += n-1 + qc(p-1) + qc(n-p);
	return sum;
}

float c(int n) {
	if (n <= 1) return 0;
	float sum = 0.0;
	for (int m=1; m <= n; m++) {
		comps++;
		sum += n-1 + c(m-1) + c(n-m);
	}
	return sum / n;
}

#define NN 100000

int main(int argc, char *argv[]) {
	srand(time(0));
	int min=100000;
	int max=0;
	int a=10;
	for(int j=0; j<a; j++) {
		comps=0;
	
		// change the following code
		x = new int[NN];
		for (int i=0; i<NN; ++i) {
			x[i] = rand() % NN;
		}
		/*for (int i=0; i<NN; ++i) {
			std::cout << x[i] << " ";
		}*/
		//std::cout << std::endl;
		quicksort(0, NN-1);
		/*for (int i=0; i<NN; ++i) {
			std::cout << x[i] << " ";
		}*/
		reg[j]=comps;
		//std::cout << std::endl;
		//std::cout <<comps<< std::endl;
		if (comps<min) {
			min=comps;
		}
		if (comps>max) {
			max=comps;
		}

		delete[] x;
	}
	int sum=0;
	for (int n=0; n<a; n++) {
		sum=sum+comps;
	}
	int avg=sum/a;
	//int avg2=qc(NN);
	//int avg3=c(NN);
	std::cout << std::endl;
	std::cout <<(min)<<" < "<<(avg)<<" < "<<(max)<< std::endl;
	//std::cout <<"QC: " << (avg2) << std::endl;
	//std::cout << "C("<<NN<<"): " << (avg3) << std::endl;
	//delete[] x;
	return 0;
}

/*int main(int argc, char *argv[]) {
	srand(time(0));

	// change the following code
	x = new int[NN];
	for (int i=0; i<NN; ++i) {
		x[i] = rand() % NN;
	}
	
	quicksort(0, NN-1);
	for (int i=0; i<NN; ++i) {
		std::cout << x[i] << " ";
	}
	std::cout << std::endl;

	delete[] x;
	return 0;
}*/
