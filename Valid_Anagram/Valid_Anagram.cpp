#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;




class Solution {
public:
    static bool isAnagram(string s, string t) {

        if (s.size() != t.size())
            return false;

        unordered_map<char, int> ana_map;

        for (size_t i = 0; i < s.size(); ++i) {
        
            ana_map[s[i]] += 1;
            ana_map[t[i]] -= 1;
        
        }

        for(auto el : ana_map){
            
            if (el.second != 0) return false;
        
        }

        return true;
    }
};

int main()
{
    string s = "anagram";
    string t = "nagaram";

    if (Solution::isAnagram(s, t) == true) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
}
