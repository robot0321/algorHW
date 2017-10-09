#include "selection.h"
#include "sort.h"
#include <iostream>
#include <Windows.h>

int array_selection(int* array, int l, int r, int k){
// Implement here!
	int length = r - l + 1;
	if (length < k) {
		std::cout << "No k-th elements" << std::endl;
		return 0;
	}
	int* k_arr = new int[k];
	for (int i = 0; i < k; i++) {
		k_arr[i] = array[l+i];
		insertion_sort(k_arr, 0, i);
	}
	debug(k_arr, 0, k - 1);
	for (int i = k; i < length; i++) {
		if (array[l + i] < k_arr[k - 1]) {
			k_arr[k - 1] = array[l + i];
			insertion_sort(k_arr, 0, k - 1);
			debug(k_arr, 0, k - 1);
		}
	}
	
	int result = k_arr[k - 1];
	delete[] k_arr;

	return result;
}

int heap_selection(int* array, int l, int r, int k){
// Implement here!
	int length = r - l + 1;
	if (length < k) {
		std::cout << "No k-th elements" << std::endl;
		return 0;
	}
	int* k_arr = new int[k];
	for (int i = 0; i < k; i++) {
		k_arr[i] = array[l + i];
	}
	build_max_heap(k_arr, k);
	debug(k_arr, 0, k - 1);
	for (int i = k; i < length; i++) {
		if (array[l + i] < k_arr[0]) {
			k_arr[0] = array[l + i];
			max_heapify(k_arr, k, 1);
			debug(k_arr, 0, k - 1);
		}
	}

	int result = k_arr[0];
	delete[] k_arr;

	return result;
}

int quick_selection(int* array, int l, int r, int k){
// Implement here!
	if (l == r) {
		return array[l];
	}
	debug(array, l, r);
	int pivot_idx = partition(array, l, r);
	int pivot_pos = pivot_idx - l + 1;
	if (k == pivot_pos) {
		return array[pivot_idx];
	}
	else if (k < pivot_pos) {
		return quick_selection(array, l, pivot_idx - 1, k);
	}
	else {
		return quick_selection(array, pivot_idx + 1, r, k - pivot_pos);
	}
}

int linear_selection(int* array, int l, int r, int k){
// Implement here!
	int length = r - l + 1;
	int group_num = length / 7 + 1;
	int* median_arr = new int[group_num];
	for (int i = 0; i < group_num; i++) {
		insertion_sort(array, 7 * i, 7 * i + 6);
		median_arr[i] = array[7 * i + 3];
	}
	



	delete[] median_arr;

	return 0;
}

typedef int (*FP)(int*, int, int, int);

int main() {
	int arr[] = { 3, 2, 1, 6, 13, 5, 12, 15, 11, 10, 4, 9 };
	int k_th_num;
	int size = 12;
	int k = 8;
	
	const FP func_ptr[4] = { &array_selection,
							 &heap_selection,
							 &quick_selection,
							 &linear_selection};

	for (int i = 0; i < 4; i++) {
		k_th_num = func_ptr[i](arr, 0, size - 1, k);
		std::cout << k_th_num << std::endl;
	}
	
	int a;
	std::cin >> a;

	return 0;
}