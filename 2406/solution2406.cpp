#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
    int minGroups(std::vector<std::vector<int>>& intervals)
    {
        std::vector<int> lefts = {};
        std::vector<int> rights = {};
        for (std::vector<int> interval : intervals)
        {
            lefts.push_back(interval[0]);
            rights.push_back(interval[1]);
        }

        std::sort(lefts.begin(), lefts.end());
        std::sort(rights.begin(), rights.end());

        auto rights_p = rights.begin();

        int count = 0;
        for (int left : lefts)
        {
            if (left > *rights_p)
            {
                ++rights_p;
            }
            else
            {
                ++count;
            }
        }
        return count;
    }
};

int main(int argc, char const* argv[])
{
    std::vector<std::vector<int>> x = {{1,3},{5,6},{8,10},{11,13}};
    std::cout << Solution().minGroups(x) << "\n";
}
