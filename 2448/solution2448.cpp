#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        map<int,vector<int>> valute2idx = {};
        for (int i = 0; i< nums.size(); ++i) {
            if (valute2idx.find(nums[i]) == valute2idx.end()) {
                valute2idx[nums[i]] = {i};
            }
            else {
                valute2idx[nums[i]].push_back(i);
            }
        }

        long long ans = 0;

        auto top = valute2idx.rbegin();
        int topValue = top->first;
        long long topCost = 0;
        for (int x: top->second) {
            topCost += cost[x];
        }

        auto bottom = valute2idx.begin();
        int bottomValue = bottom->first;
        long long bottomCost = 0;
        for (int x: bottom->second) {
            bottomCost += cost[x];
        } 

        while (topValue != bottomValue) {
            if (topCost<bottomCost) {
                ++top;
                ans += (topValue-(top->first))*topCost;
                for (int x: top->second) {
                    topCost += cost[x];
                }
                topValue = top->first;
            }
            else {
                ++bottom;
                ans += ((bottom->first)-bottomValue)*bottomCost;
                for (int x: bottom->second) {
                    bottomCost += cost[x];
                }
                bottomValue = bottom->first;
            }
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> nums = {2,2,2,2,2};
    vector<int> cost = {4,2,8,1,3};
    cout << s->minCost(nums,cost) << endl;
}

