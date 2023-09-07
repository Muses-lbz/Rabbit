//2594. 修车的最少时间
//给你一个整数数组 ranks ，表示一些机械工的 能力值 。ranksi 是第 i 位机械工的能力值。能力值为 r 的机械工可以在 r * n2 分钟内修好 n 辆车。
//同时给你一个整数 cars ，表示总共需要修理的汽车数目。
//请你返回修理所有汽车 最少 需要多少时间。
//注意：所有机械工可以同时修理汽车。

//示例 1：
//输入：ranks = [4,2,3,1], cars = 10
//输出：16
//解释：
//- 第一位机械工修 2 辆车，需要 4 * 2 * 2 = 16 分钟。
//- 第二位机械工修 2 辆车，需要 2 * 2 * 2 = 8 分钟。
//- 第三位机械工修 2 辆车，需要 3 * 2 * 2 = 12 分钟。
//- 第四位机械工修 4 辆车，需要 1 * 4 * 4 = 16 分钟。
//16 分钟是修理完所有车需要的最少时间。

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    using ll = long long;
    long long repairCars(vector<int>& ranks, int cars) {
        ll l = 1, r = 1ll * ranks[0] * cars * cars;
        auto check = [&](ll m) {
            ll cnt = 0;
            for (auto x : ranks) {
                cnt += sqrt(m / x);
            }
            return cnt >= cars;
        };
        while (l < r) {
            ll m = l + r >> 1;
            if (check(m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution solution;
    vector<int> ranks = {175, 100, 200};
    int cars = 5;
    long long result = solution.repairCars(ranks, cars);
    cout << "Minimum time to repair all cars: " << result << endl;
    return 0;
}
