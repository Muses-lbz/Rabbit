//24. 两两交换链表中的节点
//给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

//示例：
//输入：head = [1,2,3,4]
//输出：[2,1,4,3]

#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // 如果链表为空或只有一个节点，直接返回原链表头
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        // 新链表的头节点是原链表的第二个节点
        ListNode* newHead = head->next;
        
        // 当前节点的前一个节点，用于连接交换后的节点
        ListNode* prev = nullptr;

        // 逐对交换相邻的节点
        while (head != nullptr && head->next != nullptr) {
            ListNode* firstNode = head;         // 第一个节点
            ListNode* secondNode = head->next;  // 第二个节点

            // 进行交换
            firstNode->next = secondNode->next;
            secondNode->next = firstNode;

            // 连接交换后的节点到前一个节点
            if (prev != nullptr) {
                prev->next = secondNode;
            }

            prev = firstNode;  // 更新前一个节点为第一个节点
            head = firstNode->next;  // 更新头节点为下一组的第一个节点
        }

        return newHead;
    }
};

// Helper function to create a linked list
ListNode* createLinkedList(int arr[], int n) {
    if (n == 0) {
        return nullptr;
    }

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < n; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

// Helper function to print a linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    ListNode* head = createLinkedList(arr, n);

    Solution solution;
    ListNode* newHead = solution.swapPairs(head);

    std::cout << "Original Linked List: ";
    printLinkedList(head);

    std::cout << "Swapped Linked List: ";
    printLinkedList(newHead);

    return 0;
}
