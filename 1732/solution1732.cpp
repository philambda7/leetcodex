#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int maximum = 0;
        for (int x: gain) {
            altitude += x;
            if (altitude > maximum) maximum = altitude;    
            }
        return maximum;
    }
};

int main() {
    Solution* s = new Solution;
    vector<int> gain = {-5,1,5,0,-7};
    cout << s->largestAltitude(gain);
}