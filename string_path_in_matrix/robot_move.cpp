#include <iostream>
#include <stdlib.h>

int sum_matrix(int i, int j) {
    int sum = 0;
    while (i > 0) {
        sum += i % 10;
        i = i / 10;
    }
    while (j > 0) {
        sum += j % 10;
        j = j / 10;
    }

    return sum;
}

int robot_move(int *matrix, int rows, int cols, int i, int j, int *visited, int sum) {
    int count = 0;
     if (matrix == NULL || rows <= 0 || cols <= 0 || i >= rows || j >= cols || i < 0 || j < 0) {
        return count;
    }

    if (sum_matrix(i, j) <= sum && *(visited + i*cols + j) != 1) {
        std::cout << i << " " << j << std::endl;
        *(visited + i*cols + j) = 1;

        count = 1 + robot_move(matrix, rows, cols, i -1, j, visited, sum) +
                      robot_move(matrix, rows, cols, i +1, j, visited, sum) +
                      robot_move(matrix, rows, cols, i, j -1, visited, sum) +
                      robot_move(matrix, rows, cols, i, j +1, visited, sum);
    }

    return count;
}


int main(void) {

    int matrix[] = {1, 2, 3, 4, 5,
                    1, 2, 3, 4, 5,
                    1, 2, 3, 4, 5};
    int rows = 3;
    int cols = 5;
    int *visited = (int *)calloc(cols * rows, sizeof(int));

    std::cout << robot_move(matrix, rows, cols, 0, 0, visited, 4) << std::endl;

    free(visited);
    return 0;
}
