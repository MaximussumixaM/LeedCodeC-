//Существует целочисленный массив nums, отсортированный в порядке возрастания(с различными значениями).

//Перед тем, как быть переданным вашей функции, nums, возможно,
//вращается с неизвестным опорным индексом k(1 <= k < nums.length), так что результирующий массив 
//равен[nums[k], nums[k + 1], ..., nums[n - 1], nums[0], nums[1], ..., nums[k - 1]](с индексом 0).Например, [0, 1, 2, 4, 5, 6, 7] 
//может быть повернут с поворотным индексом 3 и станет[4, 5, 6, 7, 0, 1, 2].

 //   Учитывая массив nums после возможного поворота и целочисленную цель, вернуть индекс цели, если он находится в nums, или - 1, если он не в nums.

//    Вы должны написать алгоритм со сложностью выполнения O(leftg n).
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    static int search(vector<int>& nums, int target) {

        int n = nums.size();
        int left = 0, right = n - 1;
        if (target > nums[n - 1]) {
            while (left < right) {
                int pivot = left + (right - left + 1) / 2;
                if (nums[pivot] > target || nums[pivot] <= nums[n - 1])
                    right = pivot - 1;
                else left = pivot;
            }
        }
        else {
            while (left < right) {
                int pivot = left + (right - left) / 2;
                if (nums[pivot] > nums[n - 1] || nums[pivot] < target)
                    left = pivot + 1;
                else right = pivot;
            }
        }
        return nums[left] == target ? left : -1;
        

    }
};

int main()
{

    std::vector<int> vec = { 4, 5, 6, 1, 2, 3 };
    int num1 = 2;
    int num2 = 9;

    if (Solution::search(vec, num1) == 4) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }

    if (Solution::search(vec, num2) == -1) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
    
}
