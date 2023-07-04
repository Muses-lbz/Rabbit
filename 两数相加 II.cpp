//445. 两数相加 II
//给你两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
//你可以假设除了数字0之外，这两个数字都不会以零开头。
//示例1:
//输入：l1 = [7,2,4,3], l2 = [5,6,4]
//输出：[7,8,0,7]

#include <iostream>
#include <vector>

using namespace std;

struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution 
{
public:
	// 反转链表的函数
	ListNode* reverseList(ListNode* head)
	{
		ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr)
		{
			ListNode* next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		return prev;
	}
	// 将两个链表相加的函数
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		l1 = reverseList(l1);
		l2 = reverseList(l2);
		ListNode* dummyHead = new ListNode(0); // 创建一个虚拟头节点
		ListNode* curr = dummyHead; // 当前节点指针
		int carry = 0; // 进位值

		while (l1 || l2 || carry) 
		{
			int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry; // 当前位置的数字之和
			carry = sum / 10; // 计算进位值
			curr->next = new ListNode(sum % 10); // 创建新节点存储相加结果的个位数
			curr = curr->next; // 更新当前节点指针

			// 更新 l1 和 l2 的指针
			if (l1) l1 = l1->next;
			if (l2) l2 = l2->next;
		}

		return reverseList(dummyHead->next); // 返回结果链表的头节点
	}
};

// 打印链表的函数
void printList(ListNode* head) 
{
	ListNode* curr = head;
	while (curr) 
	{
		cout << curr->val << " ";
		curr = curr->next;
	}
	cout << endl;
}


int main()
{
	Solution obj;

	// 创建链表 l1: 7->2->4->3
	ListNode* l1 = new ListNode(7);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(4);
	l1->next->next->next = new ListNode(3);

	// 创建链表 l2: 5->6->4
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);

	// 将两个链表相加
	ListNode* result = obj.addTwoNumbers(l1, l2);

	// 打印结果链表
	cout << "Result: ";
	printList(result);

	// 释放内存
	ListNode* curr = nullptr;
	while (result) 
	{
		curr = result;
		result = result->next;
		delete curr;
	}

	return 0;
}
