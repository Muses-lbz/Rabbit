//142. 环形链表 II
//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//如果 pos 是 -1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。

 #include <iostream>

using namespace std;

// 单链表的定义
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: 找到相遇点（如果有环的话）
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break; // 找到相遇点
        }

        // 如果链表中不存在环，返回 nullptr
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }

        // Step 2: 找到环的入口点
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow; // 返回环的入口点
    }
};

// 从数组创建链表的工具函数
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

// 打印链表的工具函数
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }
    cout << endl;
}

int main() {
    int arr[] = { 3, 2, 0, -4 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // 创建一个带环的链表
    ListNode* head = createLinkedList(arr, n);
    ListNode* tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    tail->next = head->next; // 创建一个环

    // 使用 Solution 类来找到环的入口点
    Solution solution;
    ListNode* entrance = solution.detectCycle(head);

    if (entrance != nullptr) {
        cout << "环的入口点: " << entrance->val << endl;
    }
    else {
        cout << "链表中没有环." << endl;
    }

    return 0;
}
