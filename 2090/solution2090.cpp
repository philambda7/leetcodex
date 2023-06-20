#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        long long sum = 0;
        for (int i = 0; i< nums.size(); ++i) {
            sum += nums[i];
            if (i >= 2*k) {
                nums[i-k] = sum / (2*k+1);
                sum -= nums[i-2*k];
            }
        }
        for (int i = 0; i<k; ++i) {
            nums[i] = -1;
            nums[nums.size()-1-i] = -1;
        }
        return nums;
    }
};

int main() {
    vector<int> nums = {7,4,3,9,1,8,5,2,6};
    int k = 3;
    Solution* s = new Solution();
    nums = s->getAverages(nums,k);
    for (int n: nums) {
        cout << n << " ";
    }
}