// 849. 到最近的人的最大距离
//给你一个数组 seats 表示一排座位，其中 seats[i] = 1 代表有人坐在第 i 个座位上，seats[i] = 0 代表座位 i 上是空的（下标从 0 开始）。
//至少有一个空座位，且至少有一人已经坐在座位上。
//亚历克斯希望坐在一个能够使他与离他最近的人之间的距离达到最大化的座位上。
//返回他到离他最近的人的最大距离。

//示例 1：
//输入：seats = [1,0,0,0,1,0,1]
//输出：2
//解释：
//如果亚历克斯坐在第二个空位（seats[2]）上，他到离他最近的人的距离为 2 。
//如果亚历克斯坐在其它任何一个空位上，他到离他最近的人的距离为 1 。
//因此，他到离他最近的人的最大距离是 2 。 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int prevPerson = -1; // 上一个有人坐的座位的下标
        int maxDistance = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                if (prevPerson == -1) {
                    // 亚历克斯坐在第一个座位上
                    maxDistance = max(maxDistance, i);
                } else {
                    // 亚历克斯坐在两人之间的座位上
                    maxDistance = max(maxDistance, (i - prevPerson) / 2);
                }
                prevPerson = i;
            }
        }

        // 亚历克斯坐在最后一个座位上
        maxDistance = max(maxDistance, n - 1 - prevPerson);

        return maxDistance;
    }
};

int main() {
    Solution solution;
    vector<int> seats = {1, 0, 0, 0, 1, 0, 1};
    int result = solution.maxDistToClosest(seats);
    cout << "Max distance to closest person: " << result << endl;

    return 0;
}
