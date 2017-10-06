#include <iostream>
#include <ctime> // time
#include <cstdlib> //  srand, rand
#include <math.h> // pow
#include "sort.h"

int main(){
	int size = 10;
	int* array = new int [size];
	
	srand(time(NULL));  // random seed
	
	float start_time, end_time;
	start_time=clock();  // start time
	for (int i=0;i<size;i++){
		array[i]=rand();  //random number generation
		std::cout<<array[i]<<" ";
	}
	std::cout << std::endl; std::cout << std::endl;
	start_time = clock();  // start time
	merge_sort(array, 0, size-1);
	end_time=clock();  // end time
	for (int i = 0; i<size; i++) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
	std::cout << (end_time - start_time) / CLOCKS_PER_SEC << std::endl;

	int a = 0;
	std::cin >> a;

	
	
	delete [] array;
	
	int* array2 = new int[size];	//array for radix sort
	int d = 5;
	srand(time(NULL));
	for (int i=0;i<size;i++){
		array2[i] = rand() % ((int)pow(10,d));	//integer of at most d digits
		std::cout<<array2[i]<<std::endl;
	}
	
	delete [] array2;

	return 0;
}
