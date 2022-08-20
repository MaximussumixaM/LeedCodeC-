#include <iostream>
#include <string>
#include <vector>

//Дан массив целых чисел nums, отсортированный в порядке возрастания, 
//и целочисленная цель, напишите функцию для поиска цели в nums.
//Если цель существует, верните ее индекс.В противном случае вернуть - 1.

//You must write an algorithm with O(log n) runtime complexity.

class Solution {
public:
    static int search(std::vector<int>& nums, int target) {

        int lo = 0;
        int right = nums.size() - 1;

        int pivot = nums.size()/2;
        

        while (right >= lo) {

            pivot = (right + lo) / 2;
            if (target < nums[pivot]) {

               right = pivot-1;
              
                
            }
            else if (target > nums[pivot]) {

                lo = pivot+1;
                

            }
            else {

                return pivot;
            
            }

        }
        return -1;        

    }
};

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6};
    int num1 = 2;
    int num2 = 9;

    if (Solution::search(vec, num1) == 1) {
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
