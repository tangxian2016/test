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

void PrintFromTopToBottom(BinaryTreeNode* pRoot);//�������

void FindPath(BinaryTreeNode* pRoot,int expectedSum,vector<int> path,int currentSum);//�������к�Ϊĳһֵ��·��
void FindPath(BinaryTreeNode* pRoot,int expectedSum);

void Permutation(char *str,char *begin);//�ַ���ȫ����
int myAtoi(string str) ;
#endif