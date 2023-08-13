//88. 合并两个有序数组
//给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
//请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
//注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。

//示例 1：
//输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
//输出：[1,2,2,3,5,6]
//解释：需要合并 [1,2,3] 和 [2,5,6] 。
//合并结果是 [1,2,2,3,5,6] ，其中斜体加粗标注的为 nums1 中的元素。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;  // nums1 的指针
        int j = n - 1;  // nums2 的指针
        int idx = m + n - 1;  // 合并后数组的指针

        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[idx] = nums1[i];  // 把较大的元素放入合并后的数组
                i--;  // 移动 nums1 指针
            }
            else {
                nums1[idx] = nums2[j];  // 把较大的元素放入合并后的数组
                j--;  // 移动 nums2 指针
            }
            idx--;  // 移动合并后数组的指针
        }

        // 如果 nums2 中还有剩余元素
        while (j >= 0) {
            nums1[idx] = nums2[j];  // 把剩余的 nums2 元素放入合并后的数组
            j--;  // 移动 nums2 指针
            idx--;  // 移动合并后数组的指针
        }
    }
};

int main() {
    Solution solution;

    vector<int> nums1 = { 1, 2, 3, 0, 0, 0 };
    vector<int> nums2 = { 8, 8, 8 };
    int m = 3;
    int n = 3;

    solution.merge(nums1, m, nums2, n);

    cout << "合并后的数组: ";
    for (int num : nums1) {
        cout << num << " ";
    }

    return 0;
}
