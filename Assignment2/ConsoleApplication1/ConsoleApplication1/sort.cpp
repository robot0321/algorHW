#include "sort.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include <Windows.h>
#include <fstream>
#include <iomanip>
#include <cmath>

#define largest_digit 5

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

int partition(int* array, int l, int r) {
	int small_left = l;
	int pivot = r;
	int eqbig = r - 1;
	while (small_left != eqbig) {
		if (array[small_left]<array[pivot]) {
			small_left++;
		}
		else if (array[eqbig] >= array[pivot]) {
			eqbig--;
		}
		else {
			swap(array, small_left, eqbig);
		}
	}
	if (array[small_left]>array[pivot]) {
		swap(array, small_left, pivot);
	}
	return small_left;
}

void quick_sort(int* array, int l, int r){
// Implement here!
	if (l < r) {
		int next_root = partition(array, l, r);
		//debug(array, l, r);
		quick_sort(array, l, next_root);
		quick_sort(array, next_root +1, r);
	}
}

void max_heapify(int* array, int size, int root_idx){
	int left_idx = 2*root_idx;
    int right_idx = 2*root_idx+1;
    int largest_idx;
    if(left_idx<=size && array[left_idx-1]>array[root_idx-1]){
        largest_idx = left_idx;
    }else{
        largest_idx = root_idx;
    }
    if(right_idx<=size && array[right_idx-1] > array[largest_idx-1]){
        largest_idx = right_idx;
    }
    if(largest_idx!=root_idx){
        swap(array, largest_idx-1, root_idx-1);
        max_heapify(array, size, largest_idx);
    }
}

void build_max_heap(int* array, int size){
	//build_max_heap(array, )
	for(int i=size/2; i>=1; i--){
        max_heapify(array, size, i);
        //debug(array, 0, size-1);
	}
}

void heap_sort(int* array, int size){
// Implement here!
	build_max_heap(array, size);
	for(int i=size-1;i>=1;i--){
		swap(array, 0, i);
		max_heapify(array, i, 1);
		//debug(array, 0, i);
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
		//debug(array, l, r);
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
		//debug(array, l, r);
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

/*
typedef void (*fptr)(int*, int, int);
std::ofstream myfile;

void test(int size, int iter_num){

    myfile.precision(15);

    int* array = new int [size];
    int* buff_arr = new int [size];
    std::cout<<"##With size: "<<size<<std::endl;
    LARGE_INTEGER freq, start_time, end_time;
    uint64_t elapsed;

    QueryPerformanceFrequency(&freq);

    for(int iter=1; iter<=iter_num; iter++){
        srand(time(NULL));


        std::cout<<"Try #"<<iter<<": ";
        for(int i=0;i<size;i++){
            array[i] = rand() % int(pow(10,largest_digit));
            buff_arr[i] = array[i];
            //std::cout<<array[i]<<" ";
        }
        //std::cout<<std::endl;

        char* func_name[8] = {"insertion_sort",
                                "merge_sort",
                                "quick_sort",
                                "selection_sort",
                                "bubble_sort",
                                "stooge_sort",
                                "heap_sort",
                                "radix_sort"};
        const fptr func_array[6] = {&insertion_sort,
                                &merge_sort,
                                &quick_sort,
                                &selection_sort,
                                &bubble_sort,
                                &stooge_sort};

        for(int k=0;k<6;k++){
			if (size <= 1000 || k != 5) {
				if (size <= 10000 || k != 0) {
					if (size <= 10000 || k != 4) {
						if (size <= 10000 || k != 3) {
							std::cout << func_name[k] << ": ";
							QueryPerformanceCounter(&start_time);
							func_array[k](array, 0, size - 1);
							QueryPerformanceCounter(&end_time);
							elapsed = end_time.QuadPart - start_time.QuadPart;
							printf("%.15f usec / ", double(elapsed) / double(freq.QuadPart));
							//std::cout<< (end_time - start_time) / CLOCKS_PER_SEC << " sec / ";
							is_sorted(array, size);
							myfile << double(elapsed) / double(freq.QuadPart) << " ";
							for (int i = 0; i < size; i++) {
								array[i] = buff_arr[i];
							}
						}else{
							myfile << 0 << " ";
						}

					}
					else {
						myfile << 0 << " ";
					}
				}
				else {
					myfile << 0 << " ";
				}
			}
			else {
				myfile << 0 << " ";
			}
        }

        std::cout<<func_name[6]<<": ";
        QueryPerformanceCounter(&start_time);
        heap_sort(array, size);
        QueryPerformanceCounter(&end_time);
        elapsed = end_time.QuadPart - start_time.QuadPart;
        printf("%.15f usec / ", double(elapsed)/double(freq.QuadPart));
        is_sorted(array,size);
        myfile << double(elapsed)/double(freq.QuadPart)<< " ";

        for(int i=0;i<size;i++){
            array[i] = buff_arr[i];
        }

        std::cout<<func_name[7]<<": ";
        QueryPerformanceCounter(&start_time);
        radix_sort(array, 0, size-1, largest_digit);
        QueryPerformanceCounter(&end_time);
        elapsed = end_time.QuadPart - start_time.QuadPart;
        printf("%.15f usec / ", double(elapsed)/double(freq.QuadPart));
        is_sorted(array,size);

        myfile << double(elapsed)/double(freq.QuadPart) <<std::endl;

        //*********************************************
        //insertion_sort(array, 0, size-1);
        //merge_sort(array, 0, size-1);
        //quick_sort(array, 0, size-1); // 맘에 안듬
        //heap_sort(array, size); // 구현x
        //selection_sort(array, 0, size-1);
        //bubble_sort(array, 0, size-1);
        //stooge_sort(array, 0, size-1);
        //radix_sort(array, 0, size-1, 5);
        //**********************************************
    }


    delete[] array;
    delete[] buff_arr;
}

int main(){
    myfile.open("example.txt");
	int data_size[] = { 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000, 100000, 200000, 500000, 1000000, 10000000, 100000000};
    for(int i=0; i<sizeof(data_size)/sizeof(int); i++){
        test(data_size[i],5);
    }
    myfile.close();
    return 0;
}

*/