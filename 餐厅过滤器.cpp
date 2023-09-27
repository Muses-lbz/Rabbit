// 1333. 餐厅过滤器
//给你一个餐馆信息数组 restaurants，其中  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]。
//你必须使用以下三个过滤器来过滤这些餐馆信息。
//其中素食者友好过滤器 veganFriendly 的值可以为 true 或者 false，如果为 true 就意味着你应该只包括 veganFriendlyi 为 true 的餐馆，为 false 则意味着可以包括任何餐馆。
//此外，我们还有最大价格 maxPrice 和最大距离 maxDistance 两个过滤器，它们分别考虑餐厅的价格因素和距离因素的最大值。
//过滤后返回餐馆的 id，按照 rating 从高到低排序。如果 rating 相同，那么按 id 从高到低排序。
//简单起见， veganFriendlyi 和 veganFriendly 为 true 时取值为 1，为 false 时，取值为 0 。
//
//示例 1：
//输入：restaurants = [[1,4,1,40,10],[2,8,0,50,5],[3,8,1,30,4],[4,10,0,10,3],[5,1,1,15,1]], veganFriendly = 1, maxPrice = 50, maxDistance = 10
//输出：[3,1,5] 
//解释： 
//这些餐馆为：
//餐馆 1 [id=1, rating=4, veganFriendly=1, price=40, distance=10]
//餐馆 2 [id=2, rating=8, veganFriendly=0, price=50, distance=5]
//餐馆 3 [id=3, rating=8, veganFriendly=1, price=30, distance=4]
//餐馆 4 [id=4, rating=10, veganFriendly=0, price=10, distance=3]
//餐馆 5 [id=5, rating=1, veganFriendly=1, price=15, distance=1] 
//在按照 veganFriendly = 1, maxPrice = 50 和 maxDistance = 10 进行过滤后，我们得到了餐馆 3, 餐馆 1 和 餐馆 5（按评分从高到低排序）。 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        // 筛选满足条件的餐馆
        vector<vector<int>> filteredRestaurants;
        for (const vector<int>& restaurant : restaurants) {
            int id = restaurant[0];
            int rating = restaurant[1];
            int vegan = restaurant[2];
            int price = restaurant[3];
            int distance = restaurant[4];

            // 检查是否满足过滤条件
            if ((veganFriendly == 0 || vegan == veganFriendly) && price <= maxPrice && distance <= maxDistance) {
                filteredRestaurants.push_back({ id, rating });
            }
        }

        // 使用自定义比较函数排序
        sort(filteredRestaurants.begin(), filteredRestaurants.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[1] == b[1]) {
                return a[0] > b[0]; // 如果评分相同，按照id从高到低排序
            }
            return a[1] > b[1]; // 否则按照评分从高到低排序
            });

        // 提取餐馆的id
        vector<int> result;
        for (const vector<int>& restaurant : filteredRestaurants) {
            result.push_back(restaurant[0]);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // 示例输入
    vector<vector<int>> restaurants = {
        {1, 4, 1, 40, 10},
        {2, 8, 0, 50, 5},
        {3, 8, 1, 30, 4},
        {4, 10, 0, 10, 3},
        {5, 1, 1, 15, 1}
    };

    int veganFriendly = 1;
    int maxPrice = 50;
    int maxDistance = 10;

    vector<int> result = solution.filterRestaurants(restaurants, veganFriendly, maxPrice, maxDistance);

    // 输出结果
    for (int id : result) {
        cout << id << " ";
    }

    return 0;
}
