#include <iostream>

int sort(int *arr, int start, int end)
{
    if (end == start + 1) {
        std::cout << arr[end] << std::endl;
        return arr[end];
    }

    int mid = (start + end) / 2;
    if (arr[mid] > arr[start]) {
        return sort(arr, mid, end);
    } else {
        return sort(arr, start, mid);
    }
}

int sort2(int *arr, int length)
{
    if (arr == NULL) {
        throw;
    }
    int start = 0;
    int end = length - 1;
    int mid = 0;
    while (arr[end] <= arr[start]) {
        if (end == start + 1) {
            return arr[end];
        }

        mid = (start + end) / 2;
        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
            int small = arr[start]; 
            for (int i = start + 1; i < length; i++) {
                if (arr[i] < small) {
                    small = arr[i];
                }
            }
            return small;
        }

        if (arr[start] >= arr[mid]) {
            end = mid;
        } else {
            start = mid;
        }
    }

    return arr[mid];
}


int main(void) {

        //int arr[] = {3,4,5,6,-1,1,2};
        int arr[] = {1,1,1,0,1,1};
        //int a = sort(arr, 0, sizeof(arr) / sizeof(int) - 1);
        int a = sort2(arr, sizeof(arr) / sizeof(int));

        std::cout << a << std::endl; 

        //std::cout << sort(arr, 0, sizeof(arr) / sizeof(int) - 1) << std::endl;


        return 0;

}
