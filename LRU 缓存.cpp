//146. LRU 缓存
//请你设计并实现一个满足  LRU (最近最少使用) 缓存 约束的数据结构。

//  实现 LRUCache 类：
// -LRUCache(int capacity) 以 正整数 作为容量 capacity 初始化 LRU 缓存
// -int get(int key) 如果关键字 key 存在于缓存中，则返回关键字的值，否则返回 -1 。
// -void put(int key, int value) 如果关键字 key 已经存在，则变更其数据值 value ；如果不存在，则向缓存中插入该组 key-value 。
//    如果插入操作导致关键字数量超过 capacity ，则应该 逐出 最久未使用的关键字。
//函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。

//示例：
//输入
//["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
//[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
//输出
//[null, null, null, 1, null, -1, null, -1, 3, 4]
//解释
//LRUCache lRUCache = new LRUCache(2);
//lRUCache.put(1, 1); // 缓存是 {1=1}
//lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
//lRUCache.get(1);    // 返回 1
//lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
//lRUCache.get(2);    // 返回 -1 (未找到)
//lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
//lRUCache.get(1);    // 返回 -1 (未找到)
//lRUCache.get(3);    // 返回 3
//lRUCache.get(4);    // 返回 4

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    struct ListNode {
        int key;
        int value;
        ListNode* prev;
        ListNode* next;
        ListNode(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    LRUCache(int capacity) {
        capacity_ = capacity;
        head_ = new ListNode(-1, -1);
        tail_ = new ListNode(-1, -1);
        head_->next = tail_;
        tail_->prev = head_;
    }

    int get(int key) {
        if (cache_.find(key) != cache_.end()) {
            // 移动访问的节点到链表头部
            ListNode* node = cache_[key];
            moveToHead(node);
            return node->value;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache_.find(key) != cache_.end()) {
            // 更新已存在的节点的值，并移动到链表头部
            ListNode* node = cache_[key];
            node->value = value;
            moveToHead(node);
        }
        else {
            if (cache_.size() >= capacity_) {
                // 移除链表尾部的节点（最久未使用的）
                ListNode* tailNode = tail_->prev;
                removeFromList(tailNode);
                cache_.erase(tailNode->key);
                delete tailNode;
            }
            // 创建新节点，并添加到链表头部
            ListNode* newNode = new ListNode(key, value);
            addToFront(newNode);
            cache_[key] = newNode;
        }
    }

    ~LRUCache() {
        // 释放链表和哈希表的内存
        ListNode* node = head_->next;
        while (node != tail_) {
            ListNode* temp = node;
            node = node->next;
            delete temp;
        }
        delete head_;
        delete tail_;
    }

private:
    int capacity_;
    unordered_map<int, ListNode*> cache_;
    ListNode* head_;
    ListNode* tail_;

    void moveToHead(ListNode* node) {
        // 从链表中移除节点
        removeFromList(node);
        // 添加到链表头部
        addToFront(node);
    }

    void removeFromList(ListNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void addToFront(ListNode* node) {
        node->next = head_->next;
        head_->next->prev = node;
        head_->next = node;
        node->prev = head_;
    }
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(1, 1);
    lRUCache.put(2, 2);
    cout << lRUCache.get(1) << endl; // 返回 1
    lRUCache.put(3, 3); // 移除键 2
    cout << lRUCache.get(2) << endl; // 返回 -1
    lRUCache.put(4, 4); // 移除键 1
    cout << lRUCache.get(1) << endl; // 返回 -1
    cout << lRUCache.get(3) << endl; // 返回 3
    cout << lRUCache.get(4) << endl; // 返回 4

    return 0;
}
