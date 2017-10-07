#include "sort.h"
#include <iostream>
#include <cstdlib>

void selection_sort(int* array, int l, int r){
// Implement here!

}

void bubble_sort(int* array, int l, int r){
// Implement here!
}

void insertion_sort(int* array, int l, int r){
// Implement here!
	int temp;
	for (int i = l; i <= r; i++) {
		for (int j = i; j>l; j--) {
			if (array[j] < array[j - 1]) {
				swap(array, j, j - 1);
			}
			else {
				break;
			}
		}

	}
}



void merge_sort(int* array, int l, int r){
// Implement here!
	if (l != r){
		int half = (l + r) / 2;
		merge_sort(array, l, half);
		merge_sort(array, half + 1, r);
		//merge
		merge(array, l, r, half);
		debug(array, l, r);
	}
}

void merge(int* array, int l, int r, int half) {
		int* left_arr = new int[half - l + 1+1];
		int* right_arr = new int[r - half+1];
		for (int i = 0; i < half - l + 1; i++) {
			left_arr[i] = array[l + i];
		}
		left_arr[half - l + 1] = INT_MAX;
		for (int i = 0; i < r - half + 1; i++) {
			right_arr[i] = array[half + 1 + i];
		}
		right_arr[r - half] = INT_MAX;
		
		int L_ptr = 0;
		int R_ptr = 0;
		for (int i = l; i < r + 1; i++) {
			if (left_arr[L_ptr] < right_arr[R_ptr]) {
				array[i] = left_arr[L_ptr++];
			}
			else {
				array[i] = right_arr[R_ptr++];
			}
		}

		delete[] left_arr;
		delete[] right_arr;
}

void quick_sort(int* array, int l, int r){
// Implement here!
	if (l != r) {
		int small = l;
		int pivot = r;
		int eqbig = r - 1;
		while (1) {
			while (array[small] < array[pivot]) {
				small++;
			}
			while (array[eqbig] >= array[pivot]) {
				eqbig--;
			}
			if (small < eqbig) {
				swap(array, small, eqbig);
			}
			else {
				break;
			}
		}

	}
}

void heap_sort(int* array, int size){
// Implement here!  
}

void stooge_sort(int* array, int l, int r){
// Implement here!
}

void radix_sort(int* array, int l, int r, int d){
//implement here!
}


void swap(int* array, int i, int j) {
	int temp = array[j]; //swap
	array[j] = array[i];
	array[i] = temp;
}

void debug(int* array, int l, int r) {
	for (int k = l; k<=r; k++) {
	std::cout << array[k] << " ";
	}
	std::cout<<std::endl;
}