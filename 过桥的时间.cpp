//2532. 过桥的时间
//共有 k 位工人计划将 n 个箱子从旧仓库移动到新仓库。给你两个整数 n 和 k，以及一个二维整数数组 time ，数组的大小为 k x 4 ，
//其中 time[i] = [leftToRighti, pickOldi, rightToLefti, putNewi] 。
//一条河将两座仓库分隔，只能通过一座桥通行。旧仓库位于河的右岸，新仓库在河的左岸。开始时，所有 k 位工人都在桥的左侧等待。为了移动这些箱子，第 i 位工人（下标从 0 开始）可以：
//  从左岸（新仓库）跨过桥到右岸（旧仓库），用时 leftToRighti 分钟。
//  从旧仓库选择一个箱子，并返回到桥边，用时 pickOldi 分钟。不同工人可以同时搬起所选的箱子。
//  从右岸（旧仓库）跨过桥到左岸（新仓库），用时 rightToLefti 分钟。
//  将箱子放入新仓库，并返回到桥边，用时 putNewi 分钟。不同工人可以同时放下所选的箱子。

//如果满足下面任一条件，则认为工人 i 的 效率低于 工人 j ：
//  leftToRighti + rightToLefti > leftToRightj + rightToLeftj
//  leftToRighti + rightToLefti == leftToRightj + rightToLeftj 且 i > j

//工人通过桥时需要遵循以下规则：
//  如果工人 x 到达桥边时，工人 y 正在过桥，那么工人 x 需要在桥边等待。
// 如果没有正在过桥的工人，那么在桥右边等待的工人可以先过桥。如果同时有多个工人在右边等待，那么 效率最低 的工人会先过桥。
// 如果没有正在过桥的工人，且桥右边也没有在等待的工人，同时旧仓库还剩下至少一个箱子需要搬运，此时在桥左边的工人可以过桥。如果同时有多个工人在左边等待，那么 效率最低 的工人会先过桥。

//所有 n 个盒子都需要放入新仓库，请你返回最后一个搬运箱子的工人 到达河左岸 的时间。

//示例 1：
//输入：n = 1, k = 3, time = [[1,1,2,1],[1,1,3,1],[1,1,4,1]]
//输出：6
//解释：
//从 0 到 1 ：工人 2 从左岸过桥到达右岸。
//从 1 到 2 ：工人 2 从旧仓库搬起一个箱子。
//从 2 到 6 ：工人 2 从右岸过桥到达左岸。
//从 6 到 7 ：工人 2 将箱子放入新仓库。
//整个过程在 7 分钟后结束。因为问题关注的是最后一个工人到达左岸的时间，所以返回 6 。

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <climits>

using namespace std;

class Solution {
public:
    // 定义函数，计算最后一个盒子通过的时间
    int findCrossingTime(int n, int k, vector<vector<int>>& time) {
        // 定义等待队列的比较函数，按照等待时间和编号进行排序
        auto wait_priority_cmp = [&](int x, int y) {
            int time_x = time[x][0] + time[x][2];  // x号盒子的等待时间和通过时间之和
            int time_y = time[y][0] + time[y][2];  // y号盒子的等待时间和通过时间之和
            return time_x != time_y ? time_x < time_y : x < y;  // 如果等待时间和通过时间之和不相等，按照较小的时间排序；如果相等，则按照较小的编号排序
        };

        // 定义左侧等待队列和右侧等待队列，使用优先队列，并根据上述比较函数进行排序
        priority_queue<int, vector<int>, decltype(wait_priority_cmp)> wait_left(wait_priority_cmp), wait_right(wait_priority_cmp);

        // 定义左侧工作队列和右侧工作队列，使用优先队列，按照通过时间进行排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> work_left, work_right;

        int remain = n;  // 剩余未通过的盒子数量
        int cur_time = 0;  // 当前时间

        // 将最开始的k个盒子加入左侧等待队列
        for (int i = 0; i < k; i++) {
            wait_left.push(i);
        }

        // 当还有剩余盒子未通过或者右侧工作队列和右侧等待队列不为空时进行循环
        while (remain > 0 || !work_right.empty() || !wait_right.empty()) {
            // 将左侧工作队列中已通过的盒子放回左侧等待队列
            while (!work_left.empty() && work_left.top().first <= cur_time) {
                wait_left.push(work_left.top().second);
                work_left.pop();
            }

            // 将右侧工作队列中已通过的盒子放回右侧等待队列
            while (!work_right.empty() && work_right.top().first <= cur_time) {
                wait_right.push(work_right.top().second);
                work_right.pop();
            }

            // 如果右侧等待队列不为空，选择通过时间最小的盒子通过，并将其加入左侧工作队列
            if (!wait_right.empty()) {
                int id = wait_right.top();  // 取出通过时间最小的盒子的编号
                wait_right.pop();  // 从右侧等待队列中移除该盒子
                cur_time += time[id][2];  // 更新当前时间为通过时间
                work_left.push(make_pair(cur_time + time[id][3], id));  // 将该盒子加入左侧工作队列，通过时间为当前时间加上工作时间
            }
            // 如果还有剩余盒子未通过，并且左侧等待队列不为空，选择等待时间最小的盒子通过，并将其加入右侧工作队列
            else if (remain > 0 && !wait_left.empty()) {
                int id = wait_left.top();  // 取出等待时间最小的盒子的编号
                wait_left.pop();  // 从左侧等待队列中移除该盒子
                cur_time += time[id][0];  // 更新当前时间为等待时间
                work_right.push(make_pair(cur_time + time[id][1], id));  // 将该盒子加入右侧工作队列，通过时间为当前时间加上工作时间
                remain--;  // 剩余未通过的盒子数量减1
            }
            // 如果没有盒子通过，需要等待下一个盒子的通过时间
            else {
                int next_time = INT_MAX;
                if (!work_left.empty()) {
                    next_time = min(next_time, work_left.top().first);  // 获取左侧工作队列中通过时间最小的盒子的通过时间
                }
                if (!work_right.empty()) {
                    next_time = min(next_time, work_right.top().first);  // 获取右侧工作队列中通过时间最小的盒子的通过时间
                }
                if (next_time != INT_MAX) {
                    cur_time = max(next_time, cur_time);  // 更新当前时间为下一个盒子通过时间和当前时间中的较大值
                }
            }
        }
        return cur_time;  // 返回最后一个盒子通过的时间
    }
};

int main() {
    int n = 1;  // 盒子的数量
    int k = 3;  // 最初放在左侧等待队列的盒子的数量
    vector<vector<int>> time = { {1, 1, 2, 1}, {1, 1, 3, 1}, {1, 1, 4, 1} };  // 盒子的等待时间和工作时间

    Solution solution;
    int lastBoxTime = solution.findCrossingTime(n, k, time);

    cout << "Last box crossing time: " << lastBoxTime << endl;

    return 0;
}


//    这段代码的目的是计算最后一个盒子通过的时间。以下是解决思路的详细说明：
//1.  首先，我们定义了一个名为`findCrossingTime`的函数，该函数接受盒子的数量`n`、最初放在左侧等待队列的盒子的数量`k`和盒子的等待时间和工作时间`time`作为输入参数，
//    并返回最后一个盒子通过的时间。
//2.  在函数内部，我们使用了多个优先队列来模拟盒子的等待队列和工作队列。
//3.  我们定义了一个等待队列的比较函数`wait_priority_cmp`，用于确定等待队列中的盒子的排序方式。排序首先根据盒子的等待时间和通过时间之和，如果相等则按照盒子的编号进行排序。
//4.  我们创建了左侧等待队列`wait_left`和右侧等待队列`wait_right`，并使用定义的比较函数进行排序。
//5.  我们创建了左侧工作队列`work_left`和右侧工作队列`work_right`，并使用`greater`函数对象进行排序，以保证通过时间最小的盒子在队列的前面。
//6.  我们初始化剩余未通过的盒子数量`remain`为`n`，当前时间`cur_time`为0。
//7.  将最初的`k`个盒子放入左侧等待队列`wait_left`中。
//8.  在一个循环中，当还有剩余盒子未通过或者右侧工作队列和右侧等待队列不为空时进行迭代。
//9.  在每次迭代中，我们首先将左侧工作队列`work_left`中已经通过的盒子放回左侧等待队列`wait_left`。
//10. 然后，我们将右侧工作队列`work_right`中已经通过的盒子放回右侧等待队列`wait_right`。
//11. 如果右侧等待队列`wait_right`不为空，表示有盒子可以通过。我们选择通过时间最小的盒子，将其从右侧等待队列中取出，更新当前时间为通过时间，并将该盒子加入左侧工作队列`work_left`。
//12. 如果还有剩余未通过的盒子并且左侧等待队列`wait_left`不为空，表示还有盒子可以等待通过。我们选择等待时间最小的盒子，将其从左侧等待队列中取出，更新当前时间为等待时间，并将该盒子加入右侧工作队列`work_right`，然后将剩余未通过的盒子数量减1。
//13. 如果没有盒子可以通过，我们需要等待下一个盒子的通过时间。我们找到下一个通过时间最小的盒子，更新当前时间为下一个盒子的通过时间。
//14. 当循环结束后，返回最后一个盒子通过的时间`cur_time`。
//    在主函数中，我们输入盒子的数量`n`、最初放在左侧等待队列的盒子的数量`k`和盒子的等待时间和工作时间`time`。
//    然后，创建`Solution`对象。调用`findCrossingTime`函数，将输入参数传递给函数，并将结果保存在`lastBoxTime`变量中。
//    最后，输出最后一个盒子通过的时间。
