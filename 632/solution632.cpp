#include <algorithm>
#include <iostream>
#include <ostream>
#include <vector>

class Solution
{
public:
    std::vector<int> smallestRange(std::vector<std::vector<int>>& nums)
    {
        std::vector<std::pair<int, int>> nums_n_groups = {};
        for (int group = 0; group < nums.size(); ++group)
        {
            for (int n : nums[group])
            {
                nums_n_groups.push_back({n, group});
            }
        }
        std::sort(nums_n_groups.begin(), nums_n_groups.end());

        int start_ptr = 0;
        int end_ptr = -1;

        std::vector<int> seen(nums.size(), 0);
        int amount_of_seen = 0;

        int min_length = (--nums_n_groups.end())->first - nums_n_groups.begin()->first + 1;
        int best_start = 0;
        int best_end = 0;

        while (end_ptr == -1 || end_ptr < nums_n_groups.size())
        {
            if (amount_of_seen < nums.size())
            {
                ++end_ptr;
                if (end_ptr==nums_n_groups.size())
                {
                    break;
                }
                const int cur_group = nums_n_groups[end_ptr].second;
                if (seen[cur_group] == 0)
                {
                    ++amount_of_seen;
                }
                ++seen[cur_group];
                if (amount_of_seen == nums.size())
                {
                    if (nums_n_groups[end_ptr].first - nums_n_groups[start_ptr].first < min_length)
                    {
                        best_start = nums_n_groups[start_ptr].first;
                        best_end = nums_n_groups[end_ptr].first ;
                        min_length = best_end - best_start;
                    }
                }
            }
            else
            {
                const int cur_group = nums_n_groups[start_ptr].second;
                if (seen[cur_group] == 1)
                {
                    --amount_of_seen;
                    if (nums_n_groups[end_ptr].first - nums_n_groups[start_ptr].first < min_length)
                    {
                        best_start = nums_n_groups[start_ptr].first;
                        best_end = nums_n_groups[end_ptr].first ;
                        min_length = best_end - best_start;
                    }
                }
                --seen[cur_group];
                ++start_ptr;
            }
        }
        return {best_start, best_end};
    }
};


int main()
{
    std::vector<std::vector<int>> nums = {{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};
    std::cout << Solution().smallestRange(nums)[0] << Solution().smallestRange(nums)[1] << std::endl;
    return 0;
}