//21. 合并两个有序链表
//将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

//示例：
//输入：l1 = [1,2,4], l2 = [1,3,4]
//输出：[1,1,2,3,4,4]

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0); // 创建一个哑节点作为新链表的起始节点
        ListNode* current = &dummy; // 当前指针用于构建新链表

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                current->next = list1; // 将当前最小节点连接到新链表
                list1 = list1->next;   // 移动list1指针
            } else {
                current->next = list2; // 将当前最小节点连接到新链表
                list2 = list2->next;   // 移动list2指针
            }
            current = current->next;   // 移动新链表指针
        }

        // 将剩余的节点连接到新链表
        if (list1 != nullptr) {
            current->next = list1;
        } else {
            current->next = list2;
        }

        return dummy.next; // 返回新链表的头节点
    }
};

// 创建链表的辅助函数
ListNode* createList(int values[], int n) {
    if (n <= 0) {
        return nullptr;
    }
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

// 打印链表的辅助函数
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    int values1[] = {1, 3, 5};
    int values2[] = {2, 4, 6};
    ListNode* list1 = createList(values1, 3);
    ListNode* list2 = createList(values2, 3);

    Solution solution;
    ListNode* mergedList = solution.mergeTwoLists(list1, list2);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}
