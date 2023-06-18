#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:

    int countPaths(vector<vector<int>>& grid) {
    
        int mod = int(1e9+7);
        int h =  grid.size();
        int w = grid[0].size();

        vector<vector<int>> cells;
        for (int i = 0; i<h; ++i) {
            for (int j = 0; j<w; ++j) {
                cells.push_back({grid[i][j],i,j});
            }
        }
        sort(cells.begin(),cells.end());

        vector<int> row(w,1);
        vector<vector<int>> pathsFormCell(h,row);

        int i;
        int j;
        int count = 0;

        for (int k = cells.size()-1; k>=0; --k) {

            i = cells[k][1];
            j = cells[k][2];

            if (i != 0 && grid[i-1][j] > grid[i][j]) {
                pathsFormCell[i][j] += pathsFormCell[i-1][j];
                pathsFormCell[i][j] %= mod;
            }
            if (i != h-1 && grid[i+1][j] > grid[i][j]) {
                pathsFormCell[i][j] += pathsFormCell[i+1][j];
                pathsFormCell[i][j] %= mod;
            }
            if (j != 0 && grid[i][j-1] > grid[i][j]) {
                pathsFormCell[i][j] += pathsFormCell[i][j-1];
                pathsFormCell[i][j] %= mod;
            }
            if (j != w-1 && grid[i][j+1] > grid[i][j]) {
                pathsFormCell[i][j] += pathsFormCell[i][j+1];
                pathsFormCell[i][j] %= mod;
            }
            count += pathsFormCell[i][j];
            count %= mod;
        }
        return count;
    }
};

int main() {
    Solution* s = new Solution;
    vector<vector<int>> grid = {{1,2},{3,4}};
    cout << s->countPaths(grid) << endl;
}