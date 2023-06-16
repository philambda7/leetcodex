#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numOfWays(vector<int>& nums) {
        //initialize binomialTable;
        int n = nums.size();
        binomialTable = {};
        for (int i = 1; i<n+2; ++i) {
            binomialTable.push_back(vector<int>(i,-1));
        }

        return actualNumOfWays(nums)-1;
    }

private:
    vector<vector<int>> binomialTable;


    int binomialCoefficients(int n, int k) {
        if (binomialTable[n][k] != -1) return binomialTable[n][k];
        
        if (k == 0 || k == n) binomialTable[n][k] = 1;
        else binomialTable[n][k] = (binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k))%(int(1e9+7));

        return binomialTable[n][k];
    }   

    int actualNumOfWays(vector<int>& nums){
        if (nums.size() <= 1) {
            return 1;
        }
        int root = nums[0];
        vector<int> left = {};
        
        vector<int> right = {};
        for (int e: nums) {
            if (e < root) {
                left.push_back(e);
            }
            else if (e > root) {
                right.push_back(e);
            }
        }
        long long a = actualNumOfWays(left);
        long long b = actualNumOfWays(right);
        long long c = binomialCoefficients(nums.size()-1,left.size());
        long long ans = (a*b)%int(1e9+7);
        ans = (ans*c)%int(1e9+7);
        return int(ans); 
    }
};

int main() {
    Solution* s = new Solution;
    vector<int> v = {3,4,5,1,2};
    cout << s->numOfWays(v) << endl;
}