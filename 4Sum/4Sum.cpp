//Учитывая массив nums из n целых чисел, вернуть массив всех уникальных четверок[nums[a], nums[b], nums[c], nums[d]], таких что :

//0 <= а, б, в, d < п
  //  a, b, c и d различны.
  //  nums[a] + nums[b] + nums[c] + nums[d] == цель
  //  Вы можете вернуть ответ в любом порядке.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static vector<vector<int>> fourSum(vector<int>& nums, int target) {

        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long  ntar = (long)target - (nums[i] + nums[j]);
                int s = j + 1, e = n - 1;
                while (s < e) {
                    if (nums[s] + nums[e] == ntar) {
                        ans.push_back({ nums[i],nums[j],nums[s],nums[e] });
                        while (s < e && nums[s] == nums[s + 1]) s++;
                        while (s < e && nums[e] == nums[e - 1]) e--;
                        s++, e--;
                    }
                    else  if (nums[s] + nums[e] > ntar) {
                        e--;
                    }
                    else {
                        s++;
                    }
                }
                while (j < n - 1 && nums[j] == nums[j + 1]) j++;
            }
            while (i < n - 1 && nums[i] == nums[i + 1]) i++;
        }
        return ans;

    }
};

int main()
{

    int target = 26;
    vector<int> vec = { 2,7,11,15,5,2,23,6 };

    vector<vector<int>> test_vec;

    test_vec.push_back(vector<int> {2, 2, 7, 15});
    test_vec.push_back(vector<int> {2,6,7,11});
    

    vector<vector<int>> result = Solution::fourSum(vec, target);

    if (result == test_vec) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
    
}
