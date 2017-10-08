#include "sort.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

void selection_sort(int* array, int l, int r){
// Implement here!
	for(int i=l; i<=r;i++){
		int min = INT_MAX;
		int min_idx = 0;
		for(int j=i; j<=r; j++){
			if(min>array[j]){
				min = array[j];
				min_idx = j;
			}
		}
		swap(array, i, min_idx);
	}
}


void bubble_sort(int* array, int l, int r){
// Implement here!r 
	for(int i=r; i>=l;i--){
		for(int j=l;j<i;j++){
			if(array[j]>array[j+1]){
				swap(array, j, j+1);
			}
		}
	}
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
	//debug(array, l, i);
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
		//debug(array, l, r);
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
	if (l < r) {
		int small = l;
		int pivot = r;
		int eqbig = r - 1;
		while(small!=eqbig){
			if(array[small]<array[pivot]){
				small++;
			}else if(array[eqbig]>=array[pivot]){
				eqbig--;
			}else{
				swap(array, small, eqbig);
			}
		}
		if(array[small]>array[pivot]){
			swap(array, small, pivot);
		}
		debug(array, l, r);
		quick_sort(array, l, small);
		quick_sort(array, small+1, r);
	}
}

void tri_max(int* array, int parent, int child1, int child2){
	if(array[parent]<array[child2] || array[parent]<array[child1]){
		if(array[child1]<array[child2]){
			swap(array, parent, child2);
		}else{
			swap(array, parent, child1);
		}
	}
}

void max_heapify(int* array, int size, int root_idx){
	int child1_idx = 2*root_idx+1;
	int child2_idx = 2*root_idx+2;
	if(size>=child2_idx){
		if (array[child1_idx] > array[root_idx] || array[child2_idx] > array[root_idx]) {
			if (array[child1_idx] > array[child2_idx]) {
				swap(array, child1_idx, root_idx);
				max_heapify(array, size, child1_idx);
			}
			else {
				swap(array, child2_idx, root_idx);
				max_heapify(array, size, child2_idx);
			}
		}
	}else if(size==child1_idx){
		if (array[child1_idx] > array[root_idx]) {
			swap(array, child1_idx, root_idx);
			max_heapify(array, size, child1_idx);
		} 
	}	
}

void build_max_heap(int* array, int size){
	//build_max_heap(array, )
}

void heap_sort(int* array, int size){
// Implement here!  
	build_max_heap(array, size);
	for(int i=0;i<size-1;i++){
		swap(array, 0, size-1-i);
		max_heapify(array, size-2-i, 0);
		debug(array, 0, size-1);
	}
}

void stooge_sort(int* array, int l, int r){
// Implement here!
	if(r-l>=2){
		if(array[l]>array[r]){
			swap(array, l, r);
		}
		int p1b3 = round(l+(r-l)/3.0);
		int p2b3 = round(l+(r-l)*2/3.0);
		debug(array, l, r);
		stooge_sort(array, l, p2b3);
		stooge_sort(array, p1b3, r);
		stooge_sort(array, l, p2b3);
	}else if(r-l==1){
		if(array[l]>array[r]){
			swap(array, l, r);
		}
	}
}

int get_digit(int num, int digit){
	return int(num/pow(10,digit-1)) % 10;
}

void one_digit_sort(int* array, int l, int r, int key_digit){
	int count[10] = {};
	int cumulative_count[10] = {};
	int* buff = new int [r-l+1];
	for(int i=0; i<r-l+1;i++){
		buff[i] = array[l+i];
	}
	
	for(int i=l; i<=r; i++){
		count[get_digit(array[i], key_digit)]++;
	}
	cumulative_count[0] = count[0];
	for(int i=1; i<10; i++){
		cumulative_count[i] = count[i] + cumulative_count[i-1];
	}
	for(int i=r; i>=l; i--){
		array[l+(--cumulative_count[get_digit(buff[i], key_digit)])] = buff[i];
	}
	delete[] buff;
}

void radix_sort(int* array, int l, int r, int d){
//implement here!
//1의자리숫자가 digit=1, 10의자리 숫자가 digit=2, ... 
	for(int i=1;i<=d;i++){
		one_digit_sort(array, l, r, i);
		debug(array, l, r);
	}
}




void swap(int* array, int i, int j) {
	int temp = array[j]; //swap
	array[j] = array[i];
	array[i] = temp;
}

void debug(int* array, int l, int r) {
	std::cout<<"d:: ";
	for (int k = l; k<=r; k++) {
	std::cout << array[k] << " ";
	}
	std::cout<<std::endl;
}


void is_sorted(int* array, int size){
	int sort_flag=1;
	for(int i=0;i<size-1;i++){
		if(array[i]>array[i+1]){
			sort_flag=0;
		}
	}
	sort_flag?std::cout<<"Sorted!"<<std::endl:std::cout<<"NOT sorted"<<std::endl;
}

int main(){
	int size=10;
	int* array = new int [size];
	srand(time(NULL));
	for(int i=0;i<size;i++){
		array[i] = rand() % 100000;
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
	//call funcg
	//insertion_sort(array, 0, size-1);
	//merge_sort(array, 0, size-1);
	//quick_sort(array, 0, size-1); // 맘에 안듬
	int* a = new int[5];
	a[0] = 1;
	a[1] = 8;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;
	max_heapify(a, 5, 0);
	debug(a, 0, 4);
	delete[] a;
	
	int b;
	std::cin >> b;

	//heap_sort(array, size); // 구현x
	//selection_sort(array, 0, size-1); 
	//bubble_sort(array, 0, size-1);
	//stooge_sort(array, 0, size-1);
	//radix_sort(array, 0, size-1, 5);
	//
	for(int i=0; i<size;i++){
		std::cout<<array[i]<<" ";
	}
	std::cout<<std::endl;
	is_sorted(array, size);
}

