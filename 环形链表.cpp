//141. 环形链表
//给你一个链表的头节点 head ，判断链表中是否有环。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 
//为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。
//  注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。
//如果链表中存在环 ，则返回 true 。 否则，返回 false 。

#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)
            return false;

        ListNode* slow = head; // 慢指针
        ListNode* fast = head->next; // 快指针

        while (slow != fast) {
            if (!fast || !fast->next) {
                // 如果快指针或者快指针的下一个节点为 NULL，说明链表没有环
                return false;
            }
            slow = slow->next; // 慢指针前进一步
            fast = fast->next->next; // 快指针前进两步
        }

        // 如果能跳出循环，则说明链表有环
        return true;
    }
};

int main() {
    // 创建链表示例，并测试是否有环
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next; // 构造一个有环的链表

    Solution solution;
    if (solution.hasCycle(head)) {
        std::cout << "链表中存在环。" << std::endl;
    }
    else {
        std::cout << "链表中不存在环。" << std::endl;
    }

    return 0;
}
