//42. 接雨水
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

//示例 1：
//  图略
//输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
//输出：6
//解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n <= 2) return 0;

        int left = 0, right = n - 1;
        int left_max = 0, right_max = 0;
        int trapped_water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= left_max) {
                    left_max = height[left];
                }
                else {
                    trapped_water += left_max - height[left];
                }
                left++;
            }
            else {
                if (height[right] >= right_max) {
                    right_max = height[right];
                }
                else {
                    trapped_water += right_max - height[right];
                }
                right--;
            }
        }

        return trapped_water;
    }
};

int main() {
    Solution solution;
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    int trapped_water = solution.trap(height);
    cout << "The total trapped water is: " << trapped_water << endl;

    return 0;
}
