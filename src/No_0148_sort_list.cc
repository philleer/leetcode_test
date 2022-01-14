/******************************************************************************
 * The source is part of my C++ solution for leetcode problems.
 *
 * All of the codes can pass leetcode online judge, while also compiled and ran
 * on the offline machine
 * ============================================================================
 * //////////// Apple clang 13.0.0 (clang-1300.0.29.30) when on mac ///////////
 * /////////////////           G++5.4.0 when on Linux           ///////////////
 * ============================================================================
 * If any question, feel free to create an issue or Pull Request
 * @phillee<< phillee2016@163.com >>
 ******************************************************************************
 */
/**
 *=============================================================================
 * @Description : Solution for leetcode problem 0148
 * @Author      : phillee (email: phillee2016@163.com)
 * @Date        : 2022-01-10
 * @LICENSE     : Copyright (c) philleer 2022. All Rights Reserved.
 *=============================================================================
 */
#include <stdio.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "ioutils.h"

/**
 * Definition for singly-linked list.
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void trimLeftTrailingSpaces(std::string &input);
void trimRightTrailingSpaces(std::string &input);
std::vector<int> stringToIntegerVector(std::string input);
ListNode* stringToListNode(std::string input);
std::string listNodeToString(ListNode* node);

class Solution {
public:
	// 148. Sort List
	/*=====================================================================
	 * Description: Given the head of a linked list, return the list after
	 *  sorting it in ascending order.
	 *
	 * Example:
	 *  Input: head = [4,2,1,3]
	 *	Output: [1,2,3,4]
	 *
	 *  Input: head = [-1,5,3,4,0]
	 *	Output: [-1,0,3,4,5]
	 *
	 *  Input: head = []
	 *  Output: []
	 *
	 * Constraints:
	 *  The number of nodes in the list is in the range [0, 5 * 10^4].
	 *  -10^5 <= Node.val <= 10^5
	 *
	 * Follow up:
	 *	Can you sort the linked list in O(n logn) time and O(1) memory
	 *	(i.e. constant space)?
	 *=====================================================================
	 */
	void swap(int &i, int &j)
	{
		if (i!=j)
		{
			int tmp = i;
			i = j;
			j = tmp;
		}
	}

	ListNode* sortList(ListNode* head) {
		if (nullptr==head)
			return head;

		ListNode *dummyHead = new ListNode(-1, head);
		ListNode *curNode = dummyHead;
		
		int len = 0;
		for (; (curNode=curNode->next)!=nullptr; len++)
			;

		int inner_cnt = 0;
		while (--len>=0)
		{
			curNode = dummyHead;
			ListNode *nextNode = curNode->next;

			inner_cnt = 0;
			while (inner_cnt<len+1 && nullptr!=(curNode = curNode->next) && nullptr!=(nextNode=nextNode->next))
			{
				if (curNode->val>nextNode->val)
				{
					swap(curNode->val, nextNode->val);
				}
				++inner_cnt;
			}
		}

		return dummyHead->next;
	}


	// ListNode *qSort(ListNode* head, int left, int right)
	// {
	// 	ListNode *dummyHead = head;
	// 	if (left>=right)
	// 	{
	// 		return nullptr;
	// 	}

	// 	swap(head, left, left+(right-left)/2);
	// 	int last = left;

	// 	for (int i=left+1; i<=right; i++)
	// 	{
	// 		if ()
	// 		{
	// 			swap(head, ++last, i);
	// 		}
	// 	}
	// 	swap(head, last, left);
	// 	qSort(head, left, last-1);
	// 	qSort(head, last+1, right);
	// }

	// ListNode* quicksortList(ListNode* head) {
	// 	if (nullptr==head)
	// 		return head;

	// 	ListNode *dummyHead = new ListNode(-1, head);
	// 	ListNode *curNode = dummyHead;
		
	// 	int len = 0;
	// 	for (; (curNode=curNode->next)!=nullptr; len++)
	// 		;

	// 	qSort(dummyHead, 0, len);

	// 	return dummyHead->next;
	// }
};

int main(int argc, char *argv[])
{
	std::string line;
	std::cout << "[Please input the data, seperate with space]" << std::endl;
	std::cout << "[like [3,30,34,5,9], note left/right bracket and comma!]" << std::endl;
	while (std::getline(std::cin, line)) {
		ListNode* head = stringToListNode(line);
		std::cout << "The input list is:"
			<< listNodeToString(head) << std::endl;

		ListNode* res = Solution().sortList(head);
		std::cout << "The processed result is : "
			<< listNodeToString(res) << std::endl;
	}

	return 0;
}

void trimLeftTrailingSpaces(std::string &input) {
	input.erase(input.begin(), std::find_if(input.begin(), input.end(),
		[](int ch) { return !isspace(ch); }
	));
}

void trimRightTrailingSpaces(std::string &input) {
	input.erase(std::find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
	}).base(), input.end());
}

std::vector<int> stringToIntegerVector(std::string input) {
	std::vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	std::stringstream ss;
	ss.str(input);
	std::string item;
	char delim = ',';
	while (std::getline(ss, item, delim)) {
		output.push_back(std::stoi(item));
	}
	return output;
}

ListNode* stringToListNode(std::string input) {
	// Generate list from the input
	std::vector<int> list = stringToIntegerVector(input);

	// Now convert that list into linked list
	ListNode* dummyRoot = new ListNode(0);
	ListNode* ptr = dummyRoot;
	for(int item : list) {
		ptr->next = new ListNode(item);
		ptr = ptr->next;
	}
	ptr = dummyRoot->next;
	delete dummyRoot;
	return ptr;
}

std::string listNodeToString(ListNode* node) {
	if (node == nullptr) return "[]";

	std::string result;
	while (node) {
		result += std::to_string(node->val) + ", ";
		node = node->next;
	}
	return "[" + result.substr(0, result.length() - 2) + "]";
}