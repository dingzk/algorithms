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



int main(void) {

        int arr[] = {3,4,5,6,-1,1,2};
        int a = sort(arr, 0, sizeof(arr) / sizeof(int) - 1);

        std::cout << a << std::endl; 

        //std::cout << sort(arr, 0, sizeof(arr) / sizeof(int) - 1) << std::endl;


        return 0;

}
