//228. 汇总区间
//给定一个  无重复元素 的 有序 整数数组 nums 。
//返回 恰好覆盖数组中所有数字 的 最小有序 区间范围列表 。也就是说，nums 的每个元素都恰好被某个区间范围所覆盖，并且不存在属于某个范围但不属于 nums 的数字 x 。
//列表中的每个区间范围 [a,b] 应该按如下格式输出：
//  "a->b" ，如果 a != b
//  "a" ，如果 a == b
 
//示例 1：
//输入：nums = [0,1,2,4,5,7]
//输出：["0->2","4->5","7"]
//解释：区间范围是：
//[0,2] --> "0->2"
//[4,5] --> "4->5"
//[7,7] --> "7"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int n = nums.size();

        for (int i = 0; i < n; ) {
            int start = nums[i];
            int end = start;

            // 找到当前区间的结束位置
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
                end = nums[i];
            }

            // 将区间加入到结果中
            if (start == end) {
                result.push_back(to_string(start));
            }
            else {
                result.push_back(to_string(start) + "->" + to_string(end));
            }

            i++; // 移动到下一个潜在的区间起始位置
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums = { 0, 1, 2, 4, 5, 7 };
    vector<string> ranges = solution.summaryRanges(nums);

    // 打印结果
    for (const string& range : ranges) {
        cout << range << " ";
    }

    return 0;
}
