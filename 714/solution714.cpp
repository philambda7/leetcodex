#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
   

        int maxProfit(vector<int>& prices, int fee) {
            int n = prices.size();
            vector<int> hold(n,0);
            vector<int> free(n,0);
            hold[0] = -prices[0]-fee;
            for(int i=1;i<n;i++){
                hold[i] = max(hold[i-1],free[i-1]-prices[i]-fee);
                free[i] = max(free[i-1],hold[i-1]+prices[i]);
            }
            return free[n-1];
        }

 
};

int main() {
    Solution sol;
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << sol.maxProfit(prices, fee) << endl;
    return 0;
}