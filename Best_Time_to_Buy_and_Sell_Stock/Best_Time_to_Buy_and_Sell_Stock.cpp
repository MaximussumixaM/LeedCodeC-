//Вам дан массив цен, где цены[i] — цена данной акции на i - й день.
//Вы хотите максимизировать свою прибыль, выбрав один день для покупки одной акции и выбрав другой день в будущем для продажи этой акции.
//Верните максимальную прибыль, которую вы можете получить от этой сделки.Если вы не можете получить никакой прибыли, верните 0.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int maxProfit(vector<int>& prices) {

        //int min_prev = pow(10,4);
        int min_prev = INT_MAX;
        int max_dif = 0;
        for (size_t i = 0; i < prices.size(); ++i) {

            if (prices[i] - min_prev > max_dif) {

                max_dif = prices[i] - min_prev;
            }

            if (prices[i] < min_prev) {
            
                min_prev = prices[i];
            }        
        }

        return max_dif;
    }
};


int main()
{
    vector<int> prices = { 7,1,5,3,6,4 };

    if (Solution::maxProfit(prices) == 5) {
        std::cout << "Test comlete" << std::endl;
    }
    else {

        std::cout << "Test denied" << std::endl;
    }
    
}
