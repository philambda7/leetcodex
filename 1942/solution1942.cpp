#include <algorithm>
#include <array>
#include <iostream>
#include <queue>
#include <vector>

class Solution {
public:
    static int smallestChair(std::vector<std::vector<int>>& times, int targetFriend)
    {
        std::vector<std::vector<int>> times_with_guest = {};
        times_with_guest.reserve(times.size()*3);

        for(int i = 0; i < times.size(); ++i)
        {
            times_with_guest.push_back({times[i][0], times[i][1], i});
        }
        std::sort(times_with_guest.begin(), times_with_guest.end());

        std::priority_queue<
            std::pair<int, int>,
            std::vector<std::pair<int,int>>,
            std::greater<>
        > taken_chairs = {};

        std::priority_queue<
            int,
            std::vector<int>,
            std::greater<>
        > empty_chairs = {};

        for (int i = 0; i < times.size(); ++i)
        {
            empty_chairs.push(i);
        }

        for (std::vector<int> time_with_guest : times_with_guest)
        {
            const int arrival_time = time_with_guest[0];
            const int departure_time = time_with_guest[1];
            const int guest = time_with_guest[2];

            while (!taken_chairs.empty() && taken_chairs.top().first <= arrival_time)
            {
                empty_chairs.emplace(taken_chairs.top().second);
                taken_chairs.pop();
            }

            int chair = empty_chairs.top();

            if (guest == targetFriend)
            {
                return chair;
            }

            empty_chairs.pop();

            taken_chairs.push({departure_time, chair});
        }

        return 0;
    }
};

int main()
{
    std::vector<std::vector<int>> times = {{3,40},{1,5}, {2,6}};
    std::cout << Solution().smallestChair(times, 2);
    return 1;
}
