//2605. 从两个数字数组里生成最小数字
//给你两个只包含 1 到 9 之间数字的数组 nums1 和 nums2 ，每个数组中的元素 互不相同 ，请你返回 最小 的数字，两个数组都 至少 包含这个数字的某个数位。

//示例 1：
//输入：nums1 = [4,1,3], nums2 = [5,7]
//输出：15
//解释：数字 15 的数位 1 在 nums1 中出现，数位 5 在 nums2 中出现。15 是我们能得到的最小数字。
//示例 2：
//输入：nums1 = [3,5,2,6], nums2 = [3,1,7]
//输出：3
//解释：数字 3 的数位 3 在两个数组中都出现了。

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    int minNumber(std::vector<int>& nums1, std::vector<int>& nums2) {
        // 定义一个 lambda 函数 same 用于找到两个数组中共有的最小数字
        auto same = [&]() -> int {
            // 使用无序集合 unordered_set 存储 nums1 中的元素，以便快速查找
            std::unordered_set<int> s(nums1.begin(), nums1.end());
            int x = 10; // 初始值设置为 10，用于记录最小公共数字
            // 遍历 nums2 中的元素
            for (int num : nums2) {
                // 如果在 s 中找到相同的元素
                if (s.count(num)) {
                    // 将它与当前最小的数字 x 进行比较，更新 x
                    x = std::min(x, num);
                }
            }
            return x == 10 ? -1 : x; // 如果 x 仍然是 10，则表示没有共有的最小数字
            };

        // 调用 same 函数，如果返回的最小公共数字不是 -1，则直接返回这个数字
        int x = same();
        if (x != -1) {
            return x;
        }

        // 找到 nums1 中的最小数字 x 和 nums2 中的最小数字 y
        int min_x = *std::min_element(nums1.begin(), nums1.end());
        int min_y = *std::min_element(nums2.begin(), nums2.end());

        // 返回 x 和 y 连接后的最小值
        return std::min(min_x * 10 + min_y, min_y * 10 + min_x);
    }
};

int main() {
    // 示例输入
    std::vector<int> nums1 = { 4, 1, 3 };
    std::vector<int> nums2 = { 5, 7 };

    // 创建 Solution 类的实例
    Solution solution;

    // 调用 minNumber 函数获取最小数字
    int result = solution.minNumber(nums1, nums2);

    // 输出结果
    std::cout << "最小数字为: " << result << std::endl;

    return 0;
}
