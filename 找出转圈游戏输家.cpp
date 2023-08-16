//2682. 找出转圈游戏输家
//  n 个朋友在玩游戏。这些朋友坐成一个圈，按 顺时针方向 从 1 到 n 编号。从第 i 个朋友的位置开始顺时针移动 1 步会到达第 (i + 1) 个朋友的位置（1 <= i < n），
//而从第 n 个朋友的位置开始顺时针移动 1 步会回到第 1 个朋友的位置。

//游戏规则如下：
//第 1 个朋友接球。
//接着，第 1 个朋友将球传给距离他顺时针方向 k 步的朋友。
//然后，接球的朋友应该把球传给距离他顺时针方向 2 * k 步的朋友。
//接着，接球的朋友应该把球传给距离他顺时针方向 3 * k 步的朋友，以此类推。
//换句话说，在第 i 轮中持有球的那位朋友需要将球传递给距离他顺时针方向 i * k 步的朋友。
//当某个朋友第 2 次接到球时，游戏结束。
//在整场游戏中没有接到过球的朋友是 输家 。
//给你参与游戏的朋友数量 n 和一个整数 k ，请按升序排列返回包含所有输家编号的数组 answer 作为答案。

//示例 1：
//输入：n = 5, k = 2
//输出：[4,5]
//解释：以下为游戏进行情况：
//1）第 1 个朋友接球，第 1 个朋友将球传给距离他顺时针方向 2 步的玩家 —— 第 3 个朋友。
//2）第 3 个朋友将球传给距离他顺时针方向 4 步的玩家 —— 第 2 个朋友。
//3）第 2 个朋友将球传给距离他顺时针方向 6 步的玩家 —— 第 3 个朋友。
//4）第 3 个朋友接到两次球，游戏结束。

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        int step = 1, cur = 0;  // 初始化步数和当前持球朋友编号
        unordered_set<int> dict;  // 哈希集合，用于记录已接到球的朋友
        vector<int> res;  // 存放失败者的结果数组
        
        while (true) {
            if (dict.count(cur)) {
                break;  // 如果当前持球朋友已经接到过球，游戏结束
            } else {
                dict.emplace(cur);  // 标记当前持球朋友接到了球
                cur = (cur + step * k) % n;  // 计算下一个持球朋友的编号
                step++;  // 增加步数
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (!dict.count(i)) {
                res.emplace_back(i + 1);  // 将未接到球的朋友编号加入结果数组
            }
        }
        
        return res;
    }
};

int main() {
    Solution solution;
    int n = 5;  // 参与游戏的朋友数量
    int k = 2;  // 每次传球的步数
    vector<int> losers = solution.circularGameLosers(n, k);  // 获取输家列表
    
    cout << "输家: ";
    for (int loser : losers) {
        cout << loser << " ";
    }
    
    return 0;
}
