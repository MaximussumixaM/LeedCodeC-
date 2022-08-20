#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {

        vector<int> ans;
        unordered_map<int, int>m;

        for (int i = 0; i < nums.size(); i++)
        {
            int val = target - nums[i];
            if (m.find(val) != m.end())
            {
                ans.push_back(m.find(val)->second);
                ans.push_back(i);
                break;
            }
            m.insert(pair<int, int>(nums[i], i));
        }
        return ans;

    }
};

int main()
{

    int target = 22;
    vector<int> vec = { 2,7,11,15 };

   
    if (Solution::twoSum(vec, target) == vector<int> {1,3}) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }


  
}
