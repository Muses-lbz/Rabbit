//LCP 50. 宝石补给
//欢迎各位勇者来到力扣新手村，在开始试炼之前，请各位勇者先进行「宝石补给」。
//每位勇者初始都拥有一些能量宝石， gem[i] 表示第 i 位勇者的宝石数量。现在这些勇者们进行了一系列的赠送，
//operations[j] = [x, y] 表示在第 j 次的赠送中 第 x 位勇者将自己一半的宝石（需向下取整）赠送给第 y 位勇者。
//在完成所有的赠送后，请找到拥有最多宝石的勇者和拥有最少宝石的勇者，并返回他们二者的宝石数量之差。
//注意：
//赠送将按顺序逐步进行。

//示例 1：
//输入：gem = [3,1,2], operations = [[0,2],[2,1],[2,0]]
//输出：2

#include <iostream>
#include <vector>

class Solution {
public:
    int giveGem(std::vector<int>& gem, std::vector<std::vector<int>>& operations) {
        int n = gem.size();

        for (const std::vector<int>& op : operations) {
            int giver = op[0];
            int receiver = op[1];
            int amount = gem[giver] / 2;

            gem[giver] -= amount;
            gem[receiver] += amount;
        }

        int maxGem = gem[0];
        int minGem = gem[0];

        for (int i = 1; i < n; ++i) {
            if (gem[i] > maxGem) {
                maxGem = gem[i];
            }
            if (gem[i] < minGem) {
                minGem = gem[i];
            }
        }

        return maxGem - minGem;
    }
};

int main() {
    // 输入数据
    std::vector<int> gem = { 3, 1, 2 };
    std::vector<std::vector<int>> operations = { {0, 2}, {2, 1}, {2, 0} };

    // 创建解决方案对象
    Solution solution;

    // 调用函数计算宝石差值
    int difference = solution.giveGem(gem, operations);

    // 输出结果
    std::cout << "拥有最多宝石的勇者和拥有最少宝石的勇者宝石数量之差是: " << difference << std::endl;

    return 0;
}
