void selection_sort(int* array, int l, int r);

void bubble_sort(int* array, int l, int r);

void insertion_sort(int* array, int l, int r);

void merge_sort(int* array, int l, int r);
void merge(int* array, int l, int r, int half);

int partition(int* array, int l, int r);
void quick_sort(int* array, int l, int r);

void max_heapify(int* array, int size, int root_idx);
void build_max_heap(int* array, int size);
void heap_sort(int* array,int size);

void stooge_sort(int* array, int l, int r);

int get_digit(int num, int digit);
void one_digit_sort(int* array, int l, int r, int key_digit);
void radix_sort(int* array, int l, int r, int d);

void swap(int* array, int i, int j);
void debug(int* array, int l, int r);
void is_sorted(int* array, int size);