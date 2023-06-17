#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <set>
using namespace std;

class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {

        //remove duplicates and order arr2
        set<int> s(arr2.begin(),arr2.end());
        arr2.assign(s.begin(),s.end());
        sort(arr2.begin(),arr2.begin());

        int cost = dfse(-1,0,arr1,arr2);
        return (cost>2000)? -1 : cost;
    }

    map<pair<int,int>,int> dp;

    int dfse(int prev, int idx, vector<int>& arr1, vector<int> arr2) {
        if (dp.find({prev,idx})!=dp.end()) {
            return dp[{prev,idx}];
        }
        int cost = 2001;



        if (arr1[idx]>prev) {
            if (idx >= arr1.size()-1) {
                cost = 0;
            }
            else {
                cost = dfse(arr1[idx],idx+1,arr1,arr2);
            }
        }
     
        int a = argSmallestGreater(prev, arr2);
        if (a != -1) {
            if (idx >= arr1.size()-1) {
                cost = min(cost,1);
            }
            else {
                cost = min(cost,1+dfse(arr2[a],idx+1,arr1,arr2));
            }
        }
         
        dp[{prev,idx}] = cost;
        return cost;
    }

    int argSmallestGreater(int n, vector<int>& arr) {
        int left = 0;
        int right = arr.size()-1;
        int middle;

        while ((right-left) >1) {
            middle = (left + right)/2;
            if (n >= arr[middle]) {
                left = middle;
            }
            else {
                right = middle;
            }
        }
        for (int i = left; i<= right; ++i) {
            if (n<arr[i]) return i;
        }
        return -1; 
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> arr1 = {1,5,3,6,7};
    vector<int> arr2 = {1,3,4};
    cout << s->dfse(-1,0,arr1,arr2);
    //cout << s->argSmallestGreater(3,arr2);
}