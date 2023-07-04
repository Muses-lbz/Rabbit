//2. 两数相加
//给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
//请你将两个数相加，并以相同形式返回一个表示和的链表。
//你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
//示例 1：
//输入：l1 = [2,4,3], l2 = [5,6,4]
//输出：[7,0,8]
//解释：342 + 465 = 807.

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0); // 创建一个虚拟头节点作为结果链表的起始节点
        ListNode* curr = dummyHead; // 当前节点指针，用于遍历结果链表
        int carry = 0; // 进位值，初始为0

        // 遍历两个链表，直到两个链表都为空且没有进位
        while (l1 || l2 || carry) {
            int sum = carry; // 当前位置的数字之和，初始为进位值
            if (l1) {
                sum += l1->val; // 将l1链表当前节点的值加到sum上
                l1 = l1->next; // l1链表指针后移
            }
            if (l2) {
                sum += l2->val; // 将l2链表当前节点的值加到sum上
                l2 = l2->next; // l2链表指针后移
            }

            carry = sum / 10; // 计算进位值
            curr->next = new ListNode(sum % 10); // 创建新节点存储相加结果的个位数
            curr = curr->next; // 更新当前节点指针

            // 更新 l1 和 l2 的指针
            // 如果链表l1或l2还未遍历完，则继续移动指针；否则指针保持不变
        }

        return dummyHead->next; // 返回结果链表的头节点，即去除虚拟头节点后的第一个节点
    }
};

// 创建链表的辅助函数
ListNode* createList(int arr[], int n) {
    ListNode* dummyHead = new ListNode(0); // 创建一个虚拟头节点
    ListNode* curr = dummyHead; // 当前节点指针
    for (int i = 0; i < n; i++) {
        curr->next = new ListNode(arr[i]); // 创建新节点并将其连接到当前节点后面
        curr = curr->next; // 更新当前节点指针，指向新节点
    }
    return dummyHead->next; // 返回去除虚拟头节点后的第一个节点
}

// 打印链表的函数
void printList(ListNode* head) {
    ListNode* curr = head; // 当前节点指针
    while (curr) { // 遍历链表，直到当前节点为空
        cout << curr->val << " "; // 输出当前节点的值
        curr = curr->next; // 移动到下一个节点
    }
    cout << endl;
}

int main() {
    Solution obj;

    int arr1[] = { 2, 4, 3 };
    int arr2[] = { 5, 6, 4 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // 创建链表 l1 和 l2
    ListNode* l1 = createList(arr1, n1);
    ListNode* l2 = createList(arr2, n2);

    // 将链表相加并获取结果链表
    ListNode* result = obj.addTwoNumbers(l1, l2);

    // 将结果链表逆序输出
    printList(result);

    // 释放内存
    ListNode* curr = nullptr;
    while (result) {
        curr = result;
        result = result->next;
        delete curr;
    }

    return 0;
}
