//Напишите эффективный алгоритм, который ищет целевое значение в целочисленной матрице размера m x n.Эта матрица обладает следующими свойствами :
//Целые числа в каждой строке сортируются слева направо.
//Первое целое число каждой строки больше, чем последнее целое число предыдущей строки.

#include <iostream>
#include <vector>


class Solution {
public:
    static bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {


        int row_size = matrix.size();
        int col_size = matrix.at(0).size();
        int hole_size = row_size * col_size;

        int lo = 0;
        int right = hole_size-1;
        
        while (lo <= right) {

            int pivot = (right + lo) / 2;

            if (matrix[pivot / col_size][pivot % col_size] < target) {

                lo = pivot + 1;

            }

            else if (matrix[pivot / col_size][pivot % col_size] > target) {

                right = pivot - 1;

            }
            else {
                return true;
            }
        }
        return false;


    }
};

int main()
{
    int n = 3;
    int m = 3;
    std::vector < std::vector <int> > vec(n, std::vector <int>(m)); // Объявление вектора на n строк по m элементов 

    int filler = 0;
    for (int i = 0; i < n; i++)     // Цикл, который идёт по строкам
        for (int j = 0; j < m; j++) // Цикл, который идёт по элементам
        {
            vec[i][j] = filler;
            ++filler;           
        }
   
    int num1 = 5;
    int num2 = 9;

    if (Solution::searchMatrix(vec, num1) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }

    if (Solution::searchMatrix(vec, num2) == false) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
    
}

