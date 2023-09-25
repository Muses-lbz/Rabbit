// 460. LFU 缓存
//请你为 最不经常使用（LFU）缓存算法设计并实现数据结构。

//实现 LFUCache 类：
//LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
//int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回 -1 。
//void put(int key, int value) - 如果键 key 已存在，则变更其值；如果键不存在，请插入键值对。当缓存达到其容量 capacity 时，则应该在插入新项之前，移除最不经常使用的项。
//在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，应该去除 最近最久未使用 的键。
//为了确定最不常使用的键，可以为缓存中的每个键维护一个 使用计数器 。使用计数最小的键是最久未使用的键。
//当一个键首次插入到缓存中时，它的使用计数器被设置为 1 (由于 put 操作)。对缓存中的键执行 get 或 put 操作，使用计数器的值将会递增。
//函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

//示例：
//输入：
//["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//输出：
//[null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//解释：
//// cnt(x) = 键 x 的使用计数
//// cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
//LFUCache lfu = new LFUCache(2);
//lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
//lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
//lfu.get(1);      // 返回 1
//                 // cache=[1,2], cnt(2)=1, cnt(1)=2
//lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
//                 // cache=[3,1], cnt(3)=1, cnt(1)=2
//lfu.get(2);      // 返回 -1（未找到）
//lfu.get(3);      // 返回 3
//                 // cache=[3,1], cnt(3)=2, cnt(1)=2
//lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
//                 // cache=[4,3], cnt(4)=1, cnt(3)=2
//lfu.get(1);      // 返回 -1（未找到）
//lfu.get(3);      // 返回 3
//                 // cache=[3,4], cnt(4)=1, cnt(3)=3
//lfu.get(4);      // 返回 4
//                 // cache=[3,4], cnt(4)=2, cnt(3)=3

#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

// 自定义结构表示缓存条目
struct Node {
    int cnt, time, key, value;

    Node(int _cnt, int _time, int _key, int _value) : cnt(_cnt), time(_time), key(_key), value(_value) {}

    // 自定义比较函数用于set中的排序
    bool operator < (const Node& rhs) const {
        return cnt == rhs.cnt ? time < rhs.time : cnt < rhs.cnt;
    }
};

class LFUCache {
    int capacity, time;
    unordered_map<int, Node> key_table; // 存储缓存的键值对
    set<Node> S; // 维护缓存的顺序
public:
    LFUCache(int _capacity) {
        capacity = _capacity;
        time = 0;
        key_table.clear();
        S.clear();
    }

    int get(int key) {
        if (capacity == 0) return -1;
        auto it = key_table.find(key);
        if (it == key_table.end()) return -1;
        Node cache = it->second;
        S.erase(cache); // 从set中删除旧缓存
        cache.cnt += 1; // 更新缓存的使用计数
        cache.time = ++time;
        S.insert(cache); // 将新缓存重新插入set中
        it->second = cache; // 更新哈希表中的缓存
        return cache.value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            if (key_table.size() == capacity) {
                key_table.erase(S.begin()->key); // 删除最不常用的缓存
                S.erase(S.begin());
            }
            Node cache = Node(1, ++time, key, value); // 创建新缓存
            key_table.insert(make_pair(key, cache)); // 插入新缓存到哈希表
            S.insert(cache); // 插入新缓存到set中
        }
        else {
            Node cache = it->second;
            S.erase(cache); // 从set中删除旧缓存
            cache.cnt += 1; // 更新缓存的使用计数
            cache.time = ++time;
            cache.value = value; // 更新缓存的值
            S.insert(cache); // 将新缓存重新插入set中
            it->second = cache; // 更新哈希表中的缓存
        }
    }
};

int main() {
    LFUCache lfu(2);
    lfu.put(1, 1);
    lfu.put(2, 2);
    cout << lfu.get(1) << endl; // 返回 1
    lfu.put(3, 3); // 去除键 2
    cout << lfu.get(2) << endl; // 返回 -1
    cout << lfu.get(3) << endl; // 返回 3
    lfu.put(4, 4); // 去除键 1
    cout << lfu.get(1) << endl; // 返回 -1
    cout << lfu.get(3) << endl; // 返回 3
    cout << lfu.get(4) << endl; // 返回 4

    return 0;
}
