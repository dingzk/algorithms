#include <iostream>
#include <vector>
#include <string.h>

int find_path(const char *matrix, int i, int j, int rows, int cols, const char *target, int pos, int *hit, std::vector<int> &path) {
    if (i < 0 || j < 0 || i >= rows || j >= cols) {
        return 0;
    }
    if (*(matrix + i * cols + j) == *(target + pos++) && !hit[i *cols + j]) {
        hit[i * cols + j] = 1;
        path.push_back(i * cols + j);
        //if (strlen(target) == path.size()) {
        if (pos == strlen(target)) {
            std::cout << "find path : " << std::endl;
            return 1;
        } else {
            // up,down,left,right
            int haspath = find_path(matrix, i - 1, j, rows, cols, target, pos, hit, path) ||
                  find_path(matrix, i + 1, j, rows, cols, target, pos, hit, path) ||
                  find_path(matrix, i, j - 1, rows, cols, target, pos, hit, path) ||
                  find_path(matrix, i, j + 1, rows, cols, target, pos, hit, path);

            // rollback
            if (!haspath) {
                hit[i * cols + j] = 0;
                --pos;
                path.pop_back();
            }

            return haspath;
        }
    }

    return 0;
}

int find(const char *matrix, int rows, int cols, const char *target) {
   if (matrix == NULL || rows == 0 || cols == 0 || target == NULL) {
        return 0;
    } 
    int *hit = new int[rows * cols];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int *hit = new int[rows * cols];
            memset(hit, 0, sizeof(int) * rows * cols);
            std::vector<int> path;
            int pos = 0;
            if (find_path(matrix, i, j, rows, cols, target, pos, hit, path)) {
                std::cout << "path: " << std::endl; 
                for (auto iter : path) {
                    std::cout << iter << " " << std::endl; 
                }
                return 1;
            }
        }
    }

    delete[] hit;

    return 0;
}



int main(void)
{
   const char matrix[] = {'a', 'b', 't', 'g',
                          'c', 'f', 'c', 's',
                          'j', 'd', 'e', 'h'
                            };
   const char target[] = {'b', 'f', 'c', 'e'};

   std::cout << find(matrix, 3, 4, target) << std::endl;

    return 0;
}
