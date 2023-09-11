//630. 课程表 III
//这里有 n 门不同的在线课程，按从 1 到 n 编号。给你一个数组 courses ，
//其中 courses[i] = [durationi, lastDayi] 表示第 i 门课将会 持续 上 durationi 天课，并且必须在不晚于 lastDayi 的时候完成。
//你的学期从第 1 天开始。且不能同时修读两门及两门以上的课程。
//返回你最多可以修读的课程数目。

//示例 1：
//输入：courses = [[100, 200], [200, 1300], [1000, 1250], [2000, 3200]]
//输出：3
//解释：
//这里一共有 4 门课程，但是你最多可以修 3 门：
//首先，修第 1 门课，耗费 100 天，在第 100 天完成，在第 101 天开始下门课。
//第二，修第 3 门课，耗费 1000 天，在第 1100 天完成，在第 1101 天开始下门课程。
//第三，修第 2 门课，耗时 200 天，在第 1300 天完成。
//第 4 门课现在不能修，因为将会在第 3300 天完成它，这已经超出了关闭日期。

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        // 首先按照课程的截止日期排序
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int current_time = 0;  // 当前的时间，从第1天开始
        priority_queue<int> taken_durations;  // 已选课程的持续时间（最大堆）
        
        for (const vector<int>& course : courses) {
            int duration = course[0];
            int end_day = course[1];
            
            if (current_time + duration <= end_day) {
                // 如果当前时间加上课程持续时间不超过截止日期，就选这门课
                current_time += duration;
                taken_durations.push(duration);
            } else if (!taken_durations.empty() && taken_durations.top() > duration) {
                // 如果已选的课程中存在持续时间更长的课程，就替换掉它
                current_time -= taken_durations.top();
                taken_durations.pop();
                current_time += duration;
                taken_durations.push(duration);
            }
        }
        
        return taken_durations.size();
    }
};

int main() {
    // 示例输入
    vector<vector<int>> courses = {{100, 200}, {200, 1300}, {1000, 1250}, {2000, 3200}};
    
    Solution solution;
    int result = solution.scheduleCourse(courses);
    
    // 输出结果
    cout << "最多可以修读的课程数目：" << result << endl;
    
    return 0;
}
