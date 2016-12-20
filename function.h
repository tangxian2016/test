#ifndef CH_1_H
#define CH_1_H
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

struct ListNode
{
	int value;
	ListNode *next;
	ListNode(int x):value(x),next(NULL){}
};

struct BinaryTreeNode
{
	int m_value;
	BinaryTreeNode* left;
	BinaryTreeNode* right;
};

struct stackNode
{
	int data;
	stackNode* next;
};

struct LinkStack
{
	int count;
	stackNode* top;
};

struct QNode
{
	int data;
	QNode* next;
};
struct LinkQueue
{
	QNode* front;
	QNode* rear;
};


void PrintListReversingly (ListNode *pHead);

void MirroRecursively(BinaryTreeNode* pRoot);

void SubTree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2);
bool DosHasSubtree(BinaryTreeNode*pRoot1,BinaryTreeNode*pRoot2);

void PrintFromTopToBottom(BinaryTreeNode* pRoot);//按层遍历

void FindPath(BinaryTreeNode* pRoot,int expectedSum,vector<int> path,int currentSum);//二叉树中和为某一值的路径
void FindPath(BinaryTreeNode* pRoot,int expectedSum);

void Permutation(char *str,char *begin);//字符串全排列
int myAtoi(string str) ;
#endif