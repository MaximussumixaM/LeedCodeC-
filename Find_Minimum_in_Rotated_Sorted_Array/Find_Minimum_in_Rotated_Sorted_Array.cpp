//Предположим, что массив длины n, отсортированный в порядке возрастания, вращается от 1 до n раз.Например, массив numleft = [0, 1, 2, 4, 5, 6, 7] может стать следующим :

//[4, 5, 6, 7, 0, 1, 2] , если он был повернут 4 раза.
//[0, 1, 2, 4, 5, 6, 7], если он был повернут 7 раз.
//Обратите внимание, что поворот массива[a[0], a[1], a[2], ..., a[n - 1]] 1 раз приводит к массиву[a[n - 1], a[0], а[1], а[2], ..., а[n - 2]].

//Учитывая число уникальных элементов отсортированного повернутого массива, вернуть минимальный элемент этого массива.

//Вы должны написать алгоритм, который работает за время O(log n).
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1; // getting first and last index
        int pivot = left + (right - left) / 2; // getting pivot index

        while (left < right) {  // if left == right then loop will break
            if (nums[0] <= nums[pivot]) { // comparing 0th-index value with pivot one because array is sorted till maximum element 
//like: [3 4 5 1 2] so 5 is maximun and getting minimum value just after that index
                left = pivot + 1;  // this is index just after the maximum element
            }
            else if (nums[0] > nums[pivot]) { // same but opposite condition
                right = pivot;  // here we are not doint right = pivot - 1 because
// suppose if you reach your minimum index value then in that case we will assign that index not the previous one
            }
            pivot = left + (right - left) / 2; // updating the pivot
        }

        // not we got our pivot element so wre will compare with the 0th index value because that will bre the minimum for the left part of the sorted elements
        if (nums[left] < nums[0]) {
            return nums[left];
        }

        return nums[0];
    }
};

int main()
{

    std::vector<int> vec = { 3,4, 5, 6, 1, 2 };
    int num1 = 2;
    int num2 = 9;

    if (Solution::findMin(vec) == 1) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }


}

