#include <iostream>


int partion(int *arr, int start, int end) 
{

    int tmp;
  /*
    int mid = start + (end - start) / 2;  
    tmp = arr[end];
    arr[end] = arr[mid];
    arr[mid] = tmp;
  */  
    int small = start - 1;
    for (int i = start; i < end; i++) {
        if (arr[i] < arr[end]) {
            small ++;
            if (i != small) {
                tmp = arr[i];
                arr[i] = arr[small];
                arr[small] = tmp;
            }
        }  
    }
    
    small++;
    tmp = arr[small];
    arr[small] = arr[end];
    arr[end] = tmp;
    
    return small;
}

void quick_sort(int *arr, int start, int end)
{

    // TODO 注意边界条件
    if (arr == NULL || start >= end) {
        return;
    }

    int index = partion(arr, start, end);

    // TODO 不需要把index位置的数据继续传下去，以免判断麻烦
    quick_sort(arr, start, index - 1);

    quick_sort(arr, index + 1, end);

}

#define N 12

int main(void) {

   int arr[N] = {8, 7, 5, 4, 1, 2, 3, 9, 0, 6, 6, 6};

   quick_sort(arr, 0, N -1);

   for (int i = 0; i < N; i++) {
        std::cout << arr[i] << std::endl;
   }

    return 0;
}
