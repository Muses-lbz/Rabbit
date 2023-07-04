//1. 两数之和
//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。
//示例 1：
//输入：nums = [2,7,11,15], target = 9
//输出：[0,1]
//解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> numMap;  // 创建一个哈希表，用于存储数组元素和对应的索引

        // 遍历数组元素
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];  // 计算目标值与当前元素的差值

            // 检查哈希表中是否存在与当前元素配对的数字
            // 如果存在，则找到了符合条件的两个数，将它们的索引存入结果数组
            if (numMap.count(complement) && numMap[complement] != i) {
                result.push_back(i);
                result.push_back(numMap[complement]);
                break;
            }

            // 将当前元素及其索引存储到哈希表中
            numMap[nums[i]] = i;
        }

        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    vector<int> indices = obj.twoSum(nums, target);

    cout << "Indices: ";
    for (int i = 0; i < indices.size(); i++) {
        cout << indices[i] << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}
