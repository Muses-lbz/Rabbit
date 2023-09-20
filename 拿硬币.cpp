//LCP 06. 拿硬币
//桌上有 n 堆力扣币，每堆的数量保存在数组 coins 中。我们每次可以选择任意一堆，拿走其中的一枚或者两枚，求拿完所有力扣币的最少次数。

//示例 1：
//输入：[4,2,1]
//输出：4
//解释：第一堆力扣币最少需要拿 2 次，第二堆最少需要拿 1 次，第三堆最少需要拿 1 次，总共 4 次即可拿完。

//示例 2：
//输入：[2,3,10]
//输出：8

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCount(vector<int>& coins) {
        int minCount = 0;
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] % 2 == 0) {
                minCount += coins[i] / 2; // 如果硬币数量为偶数，每次拿2枚
            }
            else {
                minCount += (coins[i] + 1) / 2; // 如果硬币数量为奇数，拿1枚后剩下的是偶数，每次拿2枚
            }
        }
        return minCount;
    }
};

int main() {
    Solution solution;
    vector<int> coins = { 4, 2, 1 };
    int result = solution.minCount(coins);
    std::cout << "最少需要拿的次数为: " << result << std::endl;
    return 0;
}
