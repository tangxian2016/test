
#include "function.h"
#include <vld.h>
#include <string>
#include <list>
#include <algorithm>
#include <queue>
#include <math.h>
#include <iomanip> 

//从尾到头打印链表
void PrintListReversingly (ListNode *pHead)
{
	stack<ListNode *> nodes;
	ListNode *pNode=pHead;
	if (pHead==NULL)
	{
		return;
	}
	else
	{
		while(pNode!=NULL)
		{
			nodes.push(pNode);
			pNode=pNode->next;
		}
		while(!nodes.empty())
		{
			ListNode *p=nodes.top();
			int m=p->value;
			cout<<m<<endl;
			nodes.pop();
		}
	}
}

//二叉树的镜像

void MirroRecursively(BinaryTreeNode* pRoot)
{
	if (pRoot==NULL)
	{
		return;
	}
	if (pRoot->left==NULL && pRoot->right==NULL)
	{
		return;
	}
	BinaryTreeNode* temp=pRoot->left;
	pRoot->left=pRoot->right;
	pRoot->right=temp;
	if(pRoot->left)
	{
		MirroRecursively(pRoot->left);
	}
	if(pRoot->right)
	{
		MirroRecursively(pRoot->right);
	}
}

//树的子结构
bool DosHasSubtree(BinaryTreeNode*pRoot1,BinaryTreeNode*pRoot2);
void SubTree(BinaryTreeNode* pRoot1,BinaryTreeNode* pRoot2)
{
	bool result=false;
	if (pRoot1!=NULL && pRoot2!=NULL)
	{
		if (pRoot1->m_value==pRoot2->m_value)
		{
			result=DosHasSubtree(pRoot1,pRoot2);
		}
		if (!result)
		{
			SubTree(pRoot1->left,pRoot2);
		}
		if (!result)
		{
			SubTree(pRoot1->right,pRoot2);
		}
	}
	
}
bool DosHasSubtree(BinaryTreeNode*pRoot1,BinaryTreeNode*pRoot2)
{
	if (pRoot1==NULL)
	{
		return false;
	}
	if (pRoot2==NULL)
	{
		return true;
	}
	if (pRoot1->m_value!=pRoot2->m_value)
	{
		return false;
	}
	return DosHasSubtree(pRoot1->left,pRoot2->left) && DosHasSubtree(pRoot1->right,pRoot2->right);
}

void PrintFromTopToBottom(BinaryTreeNode* pRoot)//广度优先遍历
{
	if (pRoot==NULL)
	{
		return;
	}
	deque<BinaryTreeNode*> dequeTreeNode;//队列
	dequeTreeNode.push_back(pRoot);
	while(dequeTreeNode.size())
	{
		BinaryTreeNode* pNode=dequeTreeNode.front();
		cout<<pNode->m_value<<endl;
		dequeTreeNode.pop_front();

		if (pNode->left)
		{
			dequeTreeNode.push_back(pNode->left);
		}
		if (pNode->right)
		{
			dequeTreeNode.push_back(pNode->right);
		}
	}
}


void FindPath(BinaryTreeNode* pRoot,int expectedSum,vector<int> path,int currentSum);
void FindPath(BinaryTreeNode* pRoot,int expectedSum)
{
	if (pRoot==NULL)
	{
		return;
	}
	vector<int> path;
	int currentSum=0;
	FindPath(pRoot,expectedSum,path,currentSum);
}

void FindPath(BinaryTreeNode* pRoot,int expectedSum,vector<int> path,int currentSum)
{
	if (pRoot==NULL)
	{
		return;
	}
	currentSum+=pRoot->m_value;
	path.push_back(pRoot->m_value);

	bool isLeaf=((pRoot->left==NULL) && (pRoot->right==NULL));
	if (currentSum==expectedSum && isLeaf)
	{
		vector<int> ::iterator iter=path.begin();
		for (;iter!=path.end();iter++)
		{
			cout<<(*iter)<<endl;
		}
	}
	if (pRoot->left!=NULL)
	{
		FindPath(pRoot->left,expectedSum,path,currentSum);
	}
	if (pRoot->right!=NULL)
	{
		FindPath(pRoot->right,expectedSum,path,currentSum);
	}
	path.pop_back();
}

void Permutation(char *str,char *begin)
{
	if (str!=NULL)
	{
		return;
	}
	if (*begin!='\0')
	{
		for (char *pch=begin;*pch!='\0';pch++)
		{
			char temp=*begin;
			*begin=*pch;
			*pch=temp;

			Permutation(str,begin+1);

			temp=*pch;
			*pch=*begin;
			*begin=temp;
		}
	}
	else
	{
		for (int i=0;i<strlen(str);i++)
		{
			cout<<str[i]<<" ";
		}
		cout<<endl;

	}
}

void Pailie(int *a,int index,int len)
{
	if (a==NULL||index>len)

	{
		return;
	}
	if (index==len)
	{
		for (int i=0;i<len;i++)
		{
			cout<<a[i]<<endl;
		}
	}
	else
	{
		for (int i=index;i<len;i++)
		{
			int temp=a[i];
			a[i]=a[index];
			a[index]=temp;

			Pailie(a,index+1,len);
            
			temp=a[i];
			a[i]=a[index];
			a[index]=temp;

		}
	}
}


void permutation(int *a,int index,int len)
{
	if (a==NULL && index>len)
	{
		return;
	}
	if (index==len)
	{
		for (int i=0;i<len;i++)
		{
			cout<<a[i];
		}
	}
	else
	{
		for (int i=index;i<len;i++)
		{
			int temp=a[index];
			a[index]=a[i];
			a[i]=temp;

			permutation(a,index+1,len);

			temp=a[i];
			a[i]=a[index];
			a[index]=temp;
		}
	}
}

//字符串中取m个字符构成的所有组合
void FindCombine(char *str,vector<char> &vec,int m)
{
	if (str==NULL || m>strlen(str) || m<0)
	{
		return;
	}
	if (*str!='\0'&&m>0)
	{
		vec.push_back(*str);
		FindCombine(str+1,vec,m-1);
		vec.pop_back();
		FindCombine(str+1,vec,m);
	}
	if (m==0)
	{
		for (vector<char>::iterator iter=vec.begin();iter!=vec.end();iter++)
		{
			cout<<(*iter)<<endl;
		}
	}
}

void Combine(char *str,vector<char> &vec,int m)
{
	if (*str!='\0'&& m>0)
	{
		vec.push_back(*str);
		Combine(str+1,vec,m-1);
		vec.pop_back();
		Combine(str+1,vec,m);
	}
	if(m==0)
	{
		for (vector<char> ::iterator it=vec.begin();it!=vec.end();it++)
		{
			cout<<(*it)<<endl;
		}
	}
}

int * BubbleSort(int *a,int len)
{
	for (int i=0;i<len;i++)
	{
		for (int j=len-1;j>=i;j--)
		{
			if (a[j]<a[j-1])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;

			}
			
		}
	}
	//int *p=new int[len/2];
	int *p=a;
	int m=0;
	for(int i=0;i<len;i++)
	{

		p[m++]=a[i];
	
		i++;
	}
	/*for (int i=0;i<len/2;i++)
	{
		cout<<p[i]<<endl;
	}
	delete p;*/
	return p;
}



//int main()
//{
//	int a[]={3,5,1,5,9,10,2,6};
//	int *q=BubbleSort(a,8);
//	//int *p=new int[8/2];
//	//int m=0;
//	//for(int i=0;i<8;i=i+2)
//	//{
//
//	//	p[m++]=a[i];
//	//}
//	for (int i=0;i<4;i++)
//	{
//		cout<<q[i]<<endl;
//	}
//	//delete p;
//	return 0;


//}



//struct ListNode
//{
//	int val;
//	ListNode *next;
//};
void PrintListReverse(ListNode *pHead)
{
	stack<ListNode *> st;
	ListNode *p=pHead;
	while(p!=NULL)
	{
		st.push(pHead);
		p=p->next;
	}
	while(!st.empty())
	{
		ListNode *node=st.top();
		st.pop();
		int m=node->value;
		cout<<m<<endl;
	}
}


int *LIS(int *array,int n)
{
	int *p=new int[n];
	p[0]=1;
	for (int i=1;i<n;i++)
	{
		p[i]=1;
		for (int j=0;j<i;j++)
		{
			if (array[j]<array[i])
			{
				if (p[j]+1>p[i])
				{
					p[i]=p[j]+1;
				}
			}
		}
	}
	return p;
}

int TreeDepth(BinaryTreeNode *root)
{
	if (root==NULL)
	{
		return 0;
	}
	int leftDepth=TreeDepth(root->left);
	int rightDepth=TreeDepth(root->right);

	return (leftDepth>rightDepth)?(leftDepth+1):(rightDepth+1);
}


void NumPermutation(int *a,int index,int len)
{
	if (a==NULL && index>len)
	{
		return;
	}
	if (index==len)
	{
		for(int i=0;i<len;i++)
		{
			cout<<a[i]<<endl;
		}
	}
	else
	{
		for (int i=index;i<len;i++)
		{
			int temp=a[i];
			a[i]=a[index];
			a[index]=temp;

			NumPermutation(a,index+1,len);

			temp=a[index];
			a[index]=a[i];
            a[i]=temp;
		}
	}
}

int Partiton(int *a,int low,int high)
{
	if (a==NULL)
	{
		return 0;
	}
	int key=a[low];
    while(low<high)
	{
		while(low<high && key<a[high])
		{
			high--;
		}
		int temp=a[high];
		a[high]=key;
		key=temp;

		while(low<high && key>a[low])
		{
			low++;
		}
		temp=a[high];
		a[high]=key;
		key=temp;
	}
	return low;
}

void MinK(int *a,int k,int len)
{
	if (a==NULL)
	{
		return;
	}
	int index=Partiton(a,0,len-1);
	while(index!=k-1)
	{
		if (index<k-1)
		{
			index=Partiton(a,index+1,len-1);
		}
		else if (index>k-1)
		{
			index=Partiton(a,0,index-1);
		}
	}
}



int BinarySearch(int *a,int len,int m)
{
	int low=0;int high=len-1;
	int middle
		;
	while(low<high)
	{
		middle=(low+high)/2;
		if (a[middle]>m)
		{
			high=middle-1;
		}
		else if (a[middle]<m)
		{
			low=middle+1;
		}
		else
			return middle;
	}
	return 0;
}



//Reverse digits of an integer.
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//注意翻转后溢出问题

int reverse(int x) {
	int n=x;
	if(x<0)
		n=-1*x;
	long long sum=0;
	while(n)
	{
		int i=n%10;
		n=n/10;
		sum=sum*10+i;
	}
	if(x<0 && sum>INT_MIN && sum<INT_MAX)
	{
		return (int)(-1*sum);
	}
	else if(x>=0 && sum<INT_MAX)
		return sum;
	else
		return 0;
}



//string 到 int 的转化
int myAtoi(string str) 
{
	int i=0;
	long long sum=0;
	while (str[i]!='\0'&&str[i]==' ')
	{
		i++;
	}
	int minmum=0x80000000;
	int maxmum=0x7fffffff;
	if(str[i]=='\0')
		return 0;
	int signal=1;
	if (str[i]=='+')
	{
		i++;
		signal=1;
	}
	if (str[i]=='-')
	{
		i++;
		signal=-1;
	}
	while(str[i]!='\0')
	{
		if (str[i]>='0'&&str[i]<='9')
		{
			sum=sum*10+signal*(str[i]-'0');
		}
		else
			return sum;
		if (sum>maxmum||sum<minmum)
		{
			return sum>0? maxmum:minmum;
		}
		i++;
	}
	return sum;
}

ListNode* BuildList(int m)
{
	ListNode* head=(ListNode*)malloc(sizeof(ListNode));
	head->next=NULL;
	head->value=m;
	ListNode* t=head;
	if (head)
	{
		for (int i=0;i<m;i++)
		{
			ListNode* nextnode=(ListNode*)malloc(sizeof(ListNode));
			nextnode->next=NULL;
			cin>>nextnode->value;
			head->next=nextnode;
			head=nextnode;
		}
	}
	else
	{
		cout<<"head new comes error"<<endl;
	}
	return t;
}

int length(ListNode* head)
{
	ListNode* p=head;
	int len=0;
	while(p)
	{
		len++;
		p=p->next;
	}
	return len;
}

void Push(LinkStack* s,int a)
{
	stackNode* p=(stackNode*)malloc(sizeof(stackNode));
	p->data=a;
	p->next=s->top;
	s->top=p;
	s->count++;
	free(p);
}

void Pop(LinkStack* s,int *e)
{
	*e=s->top->data;
	stackNode* p=s->top;
	p=p->next;
	free(p);
	s->count--;
}

void EnQueue(LinkQueue* Q,int e)
{
	QNode* s=(QNode*)malloc(sizeof(QNode));
	s->data=e;
	s->next=NULL;
	Q->rear->next=s;
	Q->rear=s;
	free(s);
}

void DeQueue(LinkQueue* Q,int e)
{
	QNode* p;
	p=Q->front->next;
    e=p->data;
	Q->front->next=p->next;
	if (Q->rear==p)
	{
		Q->rear=Q->front;
	}
}


int depth(BinaryTreeNode* root)
{
	if (root==NULL)
	{
		return 0;
	}

	int left=depth(root->left);
	
	int right=depth(root->right);
	
	return (left>right)? (left+1):(right+1);
	
}

//void BubbleSort(int *a,int len)
//{
//	for (int i=0;i<len;i++)
//	{
//		for (int j=len-1;j>=i;j--)
//		{
//			if (a[j]>a[j-1])
//			{
//				int temp=a[j];
//				a[j]=a[j-1];
//				a[j-1]=temp;
//			}
//			
//		}
//	}
//}

void SelectSort(int* a,int len)
{
	int i,j,min;
	for (i=0;i<len;i++)
	{
		min=i;
		for (j=i+1;j<len;j++)
		{
			if (a[min]>a[j])
			{
				min=j;
			}
		}
		if (min!=i)
		{
			int temp=a[min];
			a[min]=a[i];
			a[i]=temp;
		}
	}
}


void adjustHeap(int* arrs,int p,int len)
{
	int curParent=arrs[p];
	int child=2*p+1;
	while(child<len)
	{
		if (child+1<len && arrs[child]<arrs[child+1])
		{
			child++;
		}
		if (curParent<arrs[child])
		{
			arrs[p]=arrs[child];
			p=child;
			child=2*p+1;
		}
		else
			break;
	}
	arrs[p]=curParent;

}

struct 
{
	unsigned char a:4;//a占4位
	unsigned char b:4;
};

void swap(int *a,int x,int y)
{
	int temp=a[x];
	a[x]=a[y];
	a[y]=temp;
}

int partition(int *a,int low,int high)
{
	int key;
	key=a[low];
	while(low<high)
	{
		while(low<high && a[high]>=key)
		{
			high--;
		}
		swap(a,low,high);
		while(low<high && a[low]<=key)
		{
			low++;
		}
		swap(a,low,high);
	}
	return low;
}
void QSort(int *a,int low,int high)
{
	int key;
	if (low<high)
	{
		key=partition(a,low,high);
		QSort(a,low,key-1);
		QSort(a,key+1,high);
	}
}

void ReorderOddEven(int *data,int len)
{
	if (data==NULL || len==0)
	{
		return ;
	}
	int *begin=data;
	int *end=data+len-1;
	while(begin<end)
	{
		while(begin<end && (*begin &0x1)!=0)
		{
			begin++;
		}
		while(begin<end && (*end & 0x1)==0)
		{
			end--;
		}

		if (begin<end)
		{
			int temp=*begin;
			*begin=*end;
			*end=temp;
		}
	}
}

ListNode* merge(ListNode* pHead1,ListNode* pHead2)
{
	if (pHead1==NULL)
	{
		return pHead2;
	}
	if (pHead2==NULL)
	{
		return pHead1;
	}
	ListNode* pHead;
	if (pHead1->value<pHead2->value)
	{
		pHead=pHead1;
		pHead->next=merge(pHead1->next,pHead2);
	}
	else
	{
		pHead=pHead2;
		pHead->next=merge(pHead1,pHead2->next);
	}
	return pHead;
}

//int *LIS(int *array,int n)
//{
//	int *p=new int[n];
//	p[0]=1;
//	for (int i=1;i<n;i++)
//	{
//		p[i]=1;
//		for (int j=0;j<i;j++)
//		{
//			if (array[j]<array[i] && p[j]>p[i]-1)
//			{
//				p[i]=p[j]+1;
//			}
//		}
//	}
//	return p;
//}

int search(int *data,int n,int key)
{
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if (key<data[mid])
		{
			high=mid-1;
		}
		if (key>data[mid])
		{
			low=mid+1;
		}
		else
			return mid;
	}
	return 0;
}

char* GetMemory(char *p)
{
	p=(char *)malloc(100);
	return p;
}
//int main()
//{
//	char *str=NULL;
//	str=GetMemory(str);
//	strcpy(str,"Hello World");
//	return 0;
//}

//struct  
//{
//	char a;
//	int no;
//	short b;
//}s;

char *memcpy( char * strDest, const char * strSrc, size_t n) 
{
	if (strSrc==NULL)
	{
		return NULL;
	}
	char *s=strDest;
	for (size_t i=0;i<n;i++)
	{
		*strDest=*strSrc;
		strSrc++;
		strDest++;
	}
	return s;
}

void f()
{
	int *p=new int(0x12345678);
	printf("p=%08x, ",p);
}

//int main()
//{
//	//cout<<sizeof(s)<<endl;//12
//	char *a="whludnals";
//	char *s=(char *)malloc(sizeof(char)*4);
//	s=memcpy(s,a,4);
//	printf(s);
//	free(s);
//	//f();
//}

//合并两个有序链表，返回合并后的链表
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode *p=new ListNode(0);
	ListNode *head=p;
	while (l1!=NULL||l2!=NULL)
	{
		ListNode *cur=NULL;
		if (l1==NULL)
		{
			cur=l2;
			l2=l2->next;
		}
		else if (l2==NULL)
		{
			cur=l1;
			l1=l1->next;
		}
		else if (l1->value<l2->value)
		{
			cur=l1;
			l1=l1->next;
		}
		else
		{
			cur=l2;
			l2=l2->next;
		}
		p->next=cur;
		p=p->next;
	}
	return head->next;//注意这里不能是返回p->next,因为p不再是合并后的头结点了
}




char a[30],b[30];
int lena,lenb;
int LCS(int i,int j)
{
	if(i>=lena || j>=lenb)
		return 0;
	if(a[i]==b[j])
		return 1+LCS(i+1,j+1);
	else
		return LCS(i+1,j)>LCS(i,j+1)? LCS(i+1,j):LCS(i,j+1);
}


char num[501][501]; ///记录中间结果的数组
int flag[501][501];    ///标记数组，用于标识下标的走向，构造出公共子序列
int LCS(char *a,char *b)
{
	int i,j;
	for(i=1;i<=strlen(a);i++)
	{
		for(j=1;j<=strlen(b);j++)
		{
			if(a[i-1]==b[j-1])   ///注意这里的下标是i-1与j-1
			{
				num[i][j]=num[i-1][j-1]+1;
				flag[i][j]=1;  ///斜向下标记
			}
			else if(num[i][j-1]>num[i-1][j])
			{
				num[i][j]=num[i][j-1];
				flag[i][j]=2;  ///向右标记
			}
			else
			{
				num[i][j]=num[i-1][j];
				flag[i][j]=3;  ///向下标记
			}
		}
	}
	return num[strlen(a)][strlen(b)];
}


void getLCS(char *a,char *b)
{

	char res[500];
	memset(res,0,sizeof(res));
	int i=strlen(a);
	int j=strlen(b);
	int k=0;    ///用于保存结果的数组标志位
	while(i>0 && j>0)
	{
		if(flag[i][j]==1)   ///如果是斜向下标记
		{
			res[k]=a[i-1];
			k++;
			i--;
			j--;
		}
		else if(flag[i][j]==2)  ///如果是斜向右标记
			j--;
		else if(flag[i][j]==3)  ///如果是斜向下标记
			i--;
	}

	for(i=k-1;i>=0;i--)
		cout<<res[i];
	cout<<endl;
}


//int main()
//{
//	/*strcpy(a,"ABCBDAB");
//	strcpy(b,"BDCABA");
//	lena=strlen(a);
//	lenb=strlen(b);
//	printf("%d\n",LCS(0,0));*/
//
//	char *a="ABCBDAB";
//	char *b="BDCABA";
//	memset(num,0,sizeof(num));
//	memset(flag,0,sizeof(flag));
//	int len=LCS(a,b);
//	cout<<len<<endl;
//	getLCS(a,b);
//	return 0;
//}

bool Find(int *matrix,int rows,int columns,int number)
{
	bool found=false;
	if (matrix!=NULL&&rows>0 && columns>0)
	{
		int row=0;
		int column=columns-1;
		while(row<=rows && column>=0)
		{
			if (matrix[row*columns+column]>number)
			{
				column--;
			}
			else if (matrix[row*columns+column]<number)
			{
				row++;
			}
			else
			{
				found=true;
				break;
			}
				
		}
	}
	return found;
}

void ReplaceBlank(char string[],int len)
{
	int i=0;
	int numOfBlank=0;
	while(string[i]!='\0')
	{
		if(string[i]==' ')
		{
			numOfBlank++;
		}
		i++;
	}
	int originLength=len;
	int newLength=originLength+2*numOfBlank;
	int indexOfOrigin=originLength-1;
	int indexOfNew=newLength-1;
	while(indexOfOrigin>=0&&indexOfNew>indexOfOrigin)
	{
		if (string[indexOfOrigin]==' ')
		{
			string[indexOfNew--]='0';
			string[indexOfNew--]='2';
			string[indexOfNew--]='%';
		}
		else
		{
			string[indexOfNew--]=string[indexOfOrigin];
		}
		indexOfOrigin--;

	}

}

//void PrintListReversingly(ListNode* pHead)
//{
//	stack<ListNode*> node;
//	ListNode* pNode=pHead;
//	while(pNode!=NULL)
//	{
//		node.push(pNode);
//		pNode=pNode->next;
//	}
//	while(!node.empty())
//	{
//		pNode=node.top();
//		node.pop();
//		cout<<pNode->value<<endl;
//	}
//}

void Bubble_Sort(int *a,int len)
{
	for (int i=0;i<len;i++)
	{
		for (int j=len-1;j>=i;j--)
		{
			if (a[j]<a[j-1])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

//void swap(int *a,int i,int j)
//{
//	int temp=a[i];
//	a[i]=a[j];
//	a[j]=temp;
//}

int Partition(int *a,int low,int high)
{
	int key=a[low];
	while(low<high)
	{
		while(low<high && a[low]<=key)
		{
			low++;
		}
        swap(a,low,high);
		while(low<high && a[high]>=key)
		{
			high--;
		}
		swap(a,high,low);
	}
	return low;
}

//void adjustHeap(int *arrs,int p,int len)
//{
//	int curParent=arrs[p];
//    int child=2*p+1;        //左孩子
//	while(child<len)
//	{
//		if (arrs[child]<arrs[child+1])
//		{
//			child++;
//		}
//        if (arrs[child]>curParent)
//        {
//			arrs[p]=arrs[child];
//			p=child;
//			child=2*p+1;
//        }
//
//		else
//			break;
//	}
//	arrs[p]=curParent;
//
//}

//求出旋转数组的最小值
int Min(int *numbers,int len)
{
//	assert(numbers==NULL||len<=0);
	int index1=0;
	int index2=len-1;
	int indexMid=index1;
	while(numbers[index1]>=numbers[index2])
	{
		if (index2-index1==1)
		{
			indexMid=index2;
		}
		indexMid=(index1+index2)/2;
		if (numbers[indexMid]>numbers[index1])
		{
			index1=indexMid;
		}
		else if (numbers[indexMid]<numbers[index2])
		{
			index2=indexMid;
		}
	}
	return numbers[indexMid];
}

//字符串翻转
void reverse(char *pBegin,char *pEnd)
{
	if (pBegin==NULL||pEnd==NULL)
	{
		return;
	}
	while(pBegin<pEnd)
	{
		char temp=*pBegin;
		*pBegin=*pEnd;
		*pEnd=temp;
		pEnd--;
		pBegin++;
	}
}


bool IsContinuous(int *numbers,int len)
{
	sort(numbers,numbers+len);//从小到大排序
	int numOfZero=0;
	for(int i=0;i<len;i++)//统计0的个数
	{
		if (numbers[i]==0)
		{
			numOfZero++;
		}
	}
	int numOfGap=0;
	int small=numOfZero;
	int big=small+1;
	while(big<len)
	{
		if (numbers[big]==numbers[small])
		{
			return false;
		}
		numOfGap+=numbers[big]-numbers[small]-1;
		small=big;
		big=big+1;
	}
	if (numOfZero>=numOfGap)
	{
	    return true;
	}
	return false;
}


int LastRemaining(int n,int m)
{
	if (n<1||m<1)
	{
		return -1;
	}
	list<int> numbers;
	for (int i=0;i<n;i++)
	{
		numbers.push_back(i);
	}
	list<int>::iterator iter=numbers.begin();
	while(numbers.size()>1)
	{
		for (int i=0;i<m;i++)
		{
			iter++;
			if (iter==numbers.end())
			{
				iter=numbers.begin();
			}
		}
		list<int>::iterator next=iter++;
		if (next==numbers.end())
		{
			next=numbers.begin();
		}
		iter--;
		numbers.erase(iter);
		iter=next;
	}
	return *iter;
}

int addSum(int a,int b)
{
	int m=a^b;
	int jinwei=(a&b)<<1;
	int x,y;
	while(jinwei!=0)
	{
		x=m^jinwei;
		y=(m&jinwei)<<1;
		m=x;
		jinwei=y;
	}
	return m;
}



//二叉排序树中两个节点的最低公共祖先
BinaryTreeNode* LowestCommonAncestor(BinaryTreeNode* root,BinaryTreeNode* p,BinaryTreeNode* q)
{
	if (root==NULL || p==NULL || q==NULL)
	{
		return NULL;
	}
	if (p->m_value<root->m_value && q->m_value<root->m_value)
	{
		return LowestCommonAncestor(root->left,p,q);
	}
	else if (p->m_value>root->m_value && q->m_value>root->m_value)
	{
		return LowestCommonAncestor(root->right,p,q);
	}
	else
		return root;
}



//void FindMin(int money,int *coin,int n)
//{
//	int *coinNum=new int[money+1];
//	int *coinValue=new int[money+1];
//	coinNum[0]=0;
//	for (int i=1;i<=money;i++)
//	{
//		int minNum=i;
//
//		int usedMoney=0;
//		for (int j=0;j<n;j++)
//		{
//			if (i>coin[j])
//			{
//				if (coinNum[i-coin[j]]+1<minNum && (i==coin[j]||coinValue[i-coin[j]]!=0))
//				{
//					minNum=coinNum[i-coin[j]]+1;
//					usedMoney=coin[j];
//				}
//			}
//		}
//		coinNum[i]=minNum;
//		coinValue[i]=usedMoney;
//	}
//}

//int main()
//{
//	/*int a=3;
//	int b=5;
//	cout<<addSum(a,b)<<endl;*/
//	int money=30;
//	int a[]={2,4,7,8};
//	FindMin(money,a,4);
//	return 0;
//}

//int c[10][100]={0};
//
//void knap(int m,int n){
//
//	int i,j,w[10],p[10];
//	for(i=1;i<n+1;i++)
//		scanf("%d,%d",&w[i],&p[i]);
//	for(j=0;j<m+1;j++)
//		for(i=0;i<n+1;i++)
//		{
//			if(j<w[i])
//			{
//				c[i][j]=c[i-1][j];
//				continue;
//			}else if(c[i-1][j-w[i]]+p[i]>c[i-1][j])
//				c[i][j]=c[i-1][j-w[i]]+p[i];
//			else
//				c[i][j]=c[i-1][j];
//		}
//
//}            
//
//
//int main(){
//	int m,n;int i,j;
//	printf("input the max capacity and the number of the goods:\n");
//	scanf("%d,%d",&m,&n);
//	printf("Input each one(weight and value):\n");
//	knap(m,n);
//	printf("\n");
//	for(i=0;i<=n;i++)
//		for(j=0;j<=m;j++)
//		{
//			printf("%4d",c[i][j]);
//			if(m==j) printf("\n");
//		}
//}

//#define N 10000;//大数相加
//void LongAdd(char *s1,char *s2)
//{
//	if (s1==NULL ||s2==NULL)
//	{
//		return;
//	}
//	int len1=strlen(s1);
//	int len2=strlen(s2);
//	int a[N]={0};
//	int b[N]={0};
//	for (int i=0;i<len1;i++)
//		a[i]=s1[len1-1-i]-'0'; //字符转化为整数
//	for (int i=0;i<len2;i++)
//		b[i]=s2[len2-1-i]-'0';
//	int len=(len1>len2 ? len1:len2);
//	for (int i=0;i<len;i++)
//	{
//		a[i]+=b[i];
//		if (a[i]>=10)
//		{
//			a[i+1]+=a[i]/10;
//			a[i]=a[i]%10;
//		}
//	}
//	if (a[len])
//		cout<<a[len];
//	for (int i=len-1;i>=0;i--)
//		cout<<a[i];
//	cout<<endl;
//}

//void Longadd(char *s1,char *s2)
//{
//	int len1=strlen(s1);
//	int len2=strlen(s2);
//	int a[N]={0};
//	int b[N]={0};
//	for (int i=0;i<len1;i++)
//	{
//		a[i]=s1[len1-i-1]-'0';
//	}
//	for(int i=0;i<len2;i++)
//	{
//		b[i]=s2[len2-i-1]-'0';
//	}
//	int len=len1>len2?len1:len2;
//	for (int i=0;i<len;i++)
//	{
//		a[i]+=b[i];
//		if (a[i]>=10)
//		{
//			a[i+1]+=a[i]/10;
//			a[i]=a[i]%10;
//		}
//	}
//}


//#define N 10000
//void Longadd(char *s1,char *s2)
//{
//	int len1=strlen(s1);
//	int len2=strlen(s2);
//	int a[N]={0};
//	int b[N]={0};
//	for (int i=0;i<len1;i++)
//		a[i]=s1[len1-1-i]-'0'; //字符转化为整数
//	for (int i=0;i<len2;i++)
//		b[i]=s2[len2-1-i]-'0';
//	int len=(len1>len2 ? len1:len2);
//	for (int i=0;i<len;i++)
//	{
//		a[i]+=b[i];
//		if (a[i]>=10)
//		{
//			a[i+1]+=a[i]/10;
//			a[i]=a[i]%10;
//		}
//	}
//	if (a[len])
//		cout<<a[len];
//	for (int i=len-1;i>=0;i--)
//		cout<<a[i];
//	cout<<endl;
//}

void multiply(char *s1,char *s2)
{
	int len1=strlen(s1);
	int len2=strlen(s2);
	int *s=(int *)malloc(sizeof(int)*(len1+len2));
	memset(s,0,sizeof(int)*(len1+len2));
	for(int i=0;i<len1;i++)
	{
		for (int j=0;j<len2;j++)
		{
			s[i+j+1]+=(s1[i]-'0')*(s2[j]-'0');
		}
	}
	for (int i=len1+len2-1;i>=0;i--)
	{
		if (s[i]>=10)
		{
			s[i-1]+=s[i]/10;
            s[i]=s[i]%10;
		}
	}
	int i=0;
	while(s[i]==0)
		i++;
	for (;i<len2+len1;i++)
	{
		cout<<s[i];
	}
    cout<<endl;


	//int j;
	//char *c=(char *)malloc((len1+len2)*sizeof(char));
	//for(j=0;i<len1+len2;i++,j++)
	//	c[j]=s[i]+'0';
	//c[j]='\0';
	//for(int i=0;i<len1+len2;i++)
	//	cout<<c[i];
	//cout<<endl;
	//free(c);
	free(s);
}

//void multiply(const char *a,const char *b)
//{
//	int i,j,ca,cb,*s;
//	ca=strlen(a);
//	cb=strlen(b);
//	s=(int *)malloc(sizeof(int)*(ca+cb));   //分配存储空间
//	for (i=0;i<ca+cb;i++) s[i]=0;      // 初始化         
//	for (i=0;i<ca;i++)
//		for (j=0;j<cb;j++)
//			s[i+j+1]+=(a[i]-'0')*(b[j]-'0');//逐位相乘，s[0]存储最高位的进位               
//	for (i=ca+cb-1;i>=0;i--)        // 实现进位操作
//		if(s[i]>=10)
//		{
//			s[i-1]+=s[i]/10;
//			s[i]%=10;
//		}
//		char *c=(char *)malloc((ca+cb)*sizeof(char));  //分配字符数组空间比int数组省
//		i=0;
//		while(s[i]==0) i++;   // 跳过头部0元素
//		for (j=0;i<ca+cb;i++,j++) c[j]=s[i]+'0';
//		c[j]='\0';
//		for (i=0;i<ca+cb;i++) cout<<c[i];
//		cout<<endl;
//		free(s);
//		free(c);
//}


int Binary_search(int *a,int n,int key)
{
	if (a==NULL||n<0)
	{
		return 0;
	}
	int low,high,mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if (key<a[mid])
		{
		   high=mid-1;
		}
		else if (key>a[mid])
		{
			low=mid+1;
		}
		else
			return mid;
	}
	return 0;
}

int len(ListNode *pHead)
{
	ListNode *p=pHead;
	int len=0;
	while(p!=NULL)
	{
		p=pHead->next;
		len++;
	}
	return len;
}

//struct  stackNode
//{
//	int data;
//    stackNode *next;
//};
//
//struct LinkStack
//{
//    int count;
//	stackNode *top;
//};
//
//
//void push(LinkStack *s,int a)
//{
//	stackNode *p=(stackNode *)malloc(sizeof(stackNode));
//	p->data=a;
//	p->next=s->top;
//	s->top=p;
//	s->count++;
//	free(p);
//}
//
//void pop(LinkStack *s,int *e)
//{
//	*e=s->top->data;
//	stackNode *p;
//	p=s->top;
//	p=p->next;
//	free(p);
//	s->count--;
//}



//int main()
//{
//	/*char *s1="12";
//	char *s2="7";
//	multiply(s1,s2);*/
//	int *p=new int[5];
//	int a[]={1,2,3,4,5};
//	p=a;
//	return 

void bubbleSort(int *a,int len)
{
	for (int i=0;i<len;i++)
	{
		for (int j=len-1;j>=i;j--)
		{
			if (a[j]<a[j-1])
			{
				int temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

void InsertSort(int *a,int len)
{
	int j;
	for (int i=1;i<len;i++)
	{
		if (a[i]<a[i-1])
		{
			int temp=a[i];
			for(j=i-1;a[j]>temp;j--)
			{
				a[j+1]=a[j];
			}
			a[j+1]=temp;


		}
	}
}


//int partition(int *a,int low,int high)
//{
//	int key=a[low];
//	while(low<high)
//	{
//		while(low<high && a[high]>=key)
//		{
//			high--;
//		}
//		swap(a,low,high);
//		while(low<high && a[low]<key)
//		{
//			low++;
//		}
//		swap(a,low,high);
//	}
//	return low;
//}
//void QSort(int *a,int low,int high)
//{
//	int key;
//	if (low<high)
//	{
//	    key=partition(a,low,high);
//		QSort(a,low,key-1);
//		QSort(a,key+1,high);
//	}
//}

//int reverse(int a)
//{
//	int sum=0;
//	while(a>0)
//	{
//		int m=a%10;
//		sum=sum*10+m;
//		a=a/10;
//	}
//}


void FromTopToBottom(BinaryTreeNode *root)
{
	if (root==NULL)
	{
		return;
	}
	queue<BinaryTreeNode*> qu;
	qu.push(root);
	while(qu.size())
	{
		BinaryTreeNode *p=qu.front();
		qu.pop();
		cout<<p->m_value<<endl;
		if (p->left)
		{
			qu.push(p->left);
		}
		if (p->right)
		{
			qu.push(p->right);
		}
	}

}

//void InsertSort(int *a,int len)
//{
//	if (a==NULL)
//	{
//		return;
//	}
//	for (int i=1;i<len;i++)
//	{
//		if (a[i]<a[i-1])
//		{
//			int temp=a[i];
//			for (int j=i-1;a[j]>temp;j--)
//			{
//				a[j+1]=a[j];
//			}
//			a[j+1]=temp;
//		}
//	}
//}

//void Permutation(char *str,char *begin)
//{
//	if (str==NULL)
//	{
//		return;
//	}
//	if (*begin!='\0')
//	{
//		for (char *ch=begin;*ch!='\0';ch++)
//		{
//			char temp=*ch;
//			*ch=*begin;
//			*begin=temp;
//
//			Permutation(str,begin+1);
//
//			temp=*begin;
//			*begin=*ch;
//			*ch=temp;
//		}
//	}
//}



//vector<int> vec;
//sort(vec.begin(),vec.end());
//vector<int>::iterator end_unique=unique(vec.begin(),vec.end());
//vec.erase(end_unique,vec.end());


//判断一棵树是否是另一棵树的子树，子树和子结构不同
bool checkSubTree(const BinaryTreeNode* n1, const BinaryTreeNode* n2)
{  
	if( n1 == NULL && n2 == NULL )  
		return true;  

	if( n1 == NULL || n2 == NULL )  
		return false;  

	if( n1->m_value != n2->m_value )  
		return false;  

	return checkSubTree(n1->left, n2->left) && checkSubTree(n1->right, n2->right);  
}  


bool subTree(const BinaryTreeNode *n1, const BinaryTreeNode *n2)
{  
	if( n1 == NULL)
	{  
		return false; // the bigger tree is empty, so t2 is not subtree of t1  
	}  

	if( n1->m_value == n2->m_value)
	{  
		if( checkSubTree(n1, n2))  
			return true;  
	}  

	return subTree(n1->left, n2) || subTree(n2->right, n2);  
}  


//void MirroRecursively(BinaryTreeNode* pRoot)
//{
//	if (pRoot==NULL)
//	{
//		return;
//	}
//	if (pRoot->left==NULL&&pRoot->right==NULL)
//	{
//		return;
//	}
//	BinaryTreeNode* temp=pRoot->left;
//	pRoot->left=pRoot->right;
//	pRoot->right=temp;
//	if (pRoot->left)
//	{
//		MirroRecursively(pRoot->left);
//	}
//	if (pRoot->right)
//	{
//		MirroRecursively(pRoot->right);
//	}
//}

//找最小路径和
void FindPath(BinaryTreeNode* root,vector<int> &path,int cursum,int *min)
{
	cursum+=root->m_value;
	path.push_back(root->m_value);
	bool leaf=(root->left==NULL)&&(root->right==NULL);
	if (leaf)
	{
		if (*min>cursum)
		{
			*min=cursum;
		}
	}
	if (root->left)
	{
		FindPath(root->left,path,cursum,min);
	}
	if (root->right)
	{
		FindPath(root->right,path,cursum,min);
	}
	path.pop_back();
}


int FinMinPath(BinaryTreeNode *root)
{
	vector<int> vec;
	int min=10000;
	FindPath(root,vec,0,&min);
	return min;
}

int canArrangeWords(int num,char **arr)
{
	for (int i=0;i<num-1;i++)
	{
		int len=strlen(*arr);
		if (arr[i][len-1]!=arr[i+1][0])
		{

			return -1;
		}
	}
	return 1;
}


//int main()
//{
//	//int[] a = {1,2,3,4};//定义数组a[]，a0-a3的值分别为1、2、3、4
//	//int[] b = new int[]{1,2,3,4};//同上
//	char *a[4]={"abdd","dawe","emwk","kqp"};//指针数组，数组中每个元素都是指针
//	char *b[3]={"wda","aerewr","wedaf"};
//	int m=canArrangeWords(4,a);
//	int n=canArrangeWords(3,b);
//	cout<<m<<endl;
//	cout<<n<<endl;
//	return 0;
//
//}
char findTheDifference(string s, string t) 
{
	int arr1[256]={0};
	int arr2[256]={0};
	for(int i=0;i<s.length();i++)
		arr1[s[i]]++;
	for(int i=0;i<t.length();i++)
		arr2[t[i]]++;
	for(int i=0;i<256;i++)
	{
		if(arr1[i]-arr2[i]!=0)
		{
			//for(int j=0;j<t.length();j++)
			//{
			//    if(t[j]==i)
			//     return t[j];
			// }
			return i;
		}
	}
	return NULL;
}

vector<string> getGray(int n) {
	// write code here
//	int len=pow((int)2,n);
	vector<string> result;
	if(n==1)
	{
		result.push_back("0");
		result.push_back("1");
		return result;
	}
	vector<string> vec=getGray(n-1);
	for(int i=0;i<vec.size();i++)
	{
		string s="0"+vec[i];
		result.push_back(s);
	}
	for(int i=0;i<vec.size();i++)
	{
		string s="1"+vec[i];
		result.push_back(s);
	}
	return result;
}

int getValue(vector<int> gifts, int n) {
	// write code here
	sort(gifts.begin(),gifts.end());
	int begin=0;
	int end=0;
	bool flag=true;
	int mid=gifts.size()/2;
	for(int i=0;i<gifts.size();i++)
	{
		if(gifts[i]==gifts[mid] && flag)
		{
			begin=i;
			flag=false;
		}
		if(i>begin && gifts[i]!=gifts[mid]&&flag==false&&gifts[i-1]==gifts[mid])
			end=i-1;        
	}
	if(end-begin+1>=mid)
		return gifts[mid];
	return 0;
}

//int main()
//{
//	/*string a="abcd";
//	string b="abcde";
//	char m=findTheDifference(a,b);
//	cout<<m<<endl;
//	cout<<pow(2,1)<<endl;*/
//
//	/*vector<string> v=getGray(3);
//	for (int i=0;i<v.size();i++)
//	{
//		cout<<v[i]<<endl;
//	}*/
//
//	int a[]={5026,3463,5590,8864,3330,7548,826,4301,6398,1579,2137,5310,7730,6060,5211,9435,915,7943,8599,432,7306,1673,5350,5761,7426,9096,6713,8329,484,6052,3277,9491,9440,4687,1918,9532,927,5006,7146,4953,2983,6224,7544,2629,5631,3759,4809,7406,4308,1172,8237,6577,7339,8624,8329,1026,2551,9896,1720,3281,8509,2160,5135,2681,2870,7948,6565,3643,2550,5187,5811,8107,6219,5669,2152,2793,8743,750,4513,5570,5137,8043,1863,3256,8905,1565,8793,5775,3867,9276,7836,7753,3270,3245,7759,6485,5726,5751,4676,9492,878,9938,6700,9548,8642,497,6242,384,1507,6370,8971,2015,1796,8804,8620,5068,6398,1048,7741,8591,5511,1947,189,9018,71,6498,534,5406,1614,4391,1090,750,3712,5748,238,3428,7059,4013,2557,1972,3483,2899,7840,3198,1412,3030,6277,5831,1024,7802,5022,3658,8656,8109,836,9098,5496,984,8923,9548,1183,8421,4807,8611,9508,9280,2927,1196,4248,6080,5233,2267,2119,1720,4087,5637,2616,8553,5065,8576,184,8891,1027,7992,3217,8987,8760,2003,9553,3175,6166,4615,1048,8952,4524,7946,6306,9071,1817,5434,1719,2051,8103,6271,4447,7162,1225,5918,7241,5926,9376,2783,861,7090,9460,1441,2305,2365,9873,5420,9066,2486,1584,9143,6563,7049,3095,75,4498,3832,4500,6024,2489,3838,6390,9894,2618,2656,1612,1759,6927,565,531,7148,6857,1511,1801,3917,8839,5978,9783,3484,4282,1901,9503,8964,4582,8639,307,3838,5132,4148,9110,5676,1077,8840,550,8266,6673,1811,5386,946,3746,7837,2312,9583,930,6980,8379,6468,8940,2427,5491,5085,5034,7349,3101,8278,699,6835,8405,8987,1607,8011,2633,5472,7973,1018,5200,8498,9004,106,458,1325,6809,6903,2666,1680,2658,7422,7297,7438,4696,4264,9229,2790,6274,4934,6098,9653,9239,6845,1031,1722,2444,820,9828,6555,5168,9819,1883,4150,7123,5966,3589,6346,1198,714,926,5319,1199,4176,9972,771,771,600,1851,1151,8074,9863,5525,7417,8805,6596,1520,5763,8515,2615,3232,5668,3389,8484,6303,2462,3662,9687,2082,5056,7959,479,1662,4988,4674,8752,1130,3243,6725,1571,6679,5632,5625,1985,6190,9803,1196,577,136,2975,5812,5310,9764,6853,4869,1276,6628,962,6372,3436,3785,6567,7949,1198,833,8231,2482,1766,510,4463,1925,2802,6728,1985,6473,4091,1749,2337,2483,1531,4072,2740,982,6526,5816,8053,576,6252,5187,9786,5359,5093,2627,8359,2456,3358,2399,737,4681,4011,4997,9637,8941,6477,3639,4106,8816,846,867,8916,7476,5995,215,5355,4723,2994,6629,1740,213,4187,1235,2126,8613,6108,7543,7975,4271,4007,641,176,6445,919,8185,6807,7379,3035,1514,643,4903,4322,8287,733,2485,5992,6846,5869,1153};
//	vector<int> vec(a,a+485);
//	int m=getValue(vec, 485);
//	cout<<m<<endl;
//	return 0;
//}



//给定一个字符串s，你可以从中删除一些字符，使得剩下的串是一个回文串。如何删除才能使得回文串最长呢？
//输出需要删除的最少的字符个数。
//思路：求字符串和它的翻转后的字符串的最长公共子序列，再用字符串长度减去最长公共子序列的长度，就是需要删除的最少的字符个数
void LCS(string str[],int len)
{
	int num[500][500]={0};
	//   int *p=new int[len];
	for(int i=0;i<len;i++)
	{
		string rev=str[i];
		for(int j=0;j<=(int)(str[i].length())/2;j++)
		{
			char temp=str[i][j];
			str[i][j]=str[i][str[i].length()-1];
			str[i][str[i].length()-1]=temp;
		}
		for(int k=1;k<=(int)str[i].length();k++)
		{
			for(int m=1;m<=(int)rev.length();m++)
			{
				if(str[i][k]==rev[m])
					num[k][m]=num[k-1][m-1]+1;
				else if(num[k][m-1]>num[k-1][m])
					num[k][m]=num[k][m-1];
				else
					num[k][m]=num[k-1][m];
			}
		}
		// p[i]=str[i].length()-num[str[i].length()][str[i].length()];
		int result= str[i].length()-num[str[i].length()][str[i].length()];
		//int result= num[str[i].length()][str[i].length()];
		cout<<result<<endl;
	}
	//   return p;
}


int huihuan(int n,int row,int col,int first);//回环数的递归调用函数   
int arr[100][100];//保存输入n*n回环数字   
int n;//全局n   

//void main()   
//{   
//	while(1)   
//	{   
//		cin>>n;   
//		huihuan(n,0,0,1);//回环初始   
//		for(int i=0;i<n;i++)//输出回环   
//		{   
//			for(int j=0;j<n;j++)   
//				cout<<arr[i][j]<<" "; 
//			cout<<endl;   
//		}   
//	}   
//}   


int huihuan(int n,int row,int col,int first)//回环数的递归函数，每次完成一圈赋值   
{   
	int row2 = row;   
	int col2 = col;   
	for(;col<n-1;col++)//横向右输出n-1   
		arr[row][col] = first++;   
	for(;row<n-1;row++)//列向下输出n-1   
		arr[row][col] = first++;   
	for(;col>col2;col--)//横向左输出n-1   
		arr[row][col] = first++;   
	for(;row>row2;row--)//列向上输出n-1   
		arr[row][col]  = first++;          
	if(n-row>1)//没有完成，调用递归完成下一圈赋值   
	{   
		huihuan(n-1,row+1,col+1,first);   
	}   
	else  
	{   
		if(n-row==1)//n是奇数时，要单独处理中心数   
		{   
			arr[row][col]=first;   
			return 0;   
		}   
	}   
}  

//int main()
//{
//	/*string a[]={"abcda","goolge"};
//	LCS(a,2);*/
//	int n;
//	cin>>n;
//	int **a = new int* [n];
//	for(int i = 0; i < n; i++)
//		a[i] = new int [n];
//	a=snake(n);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			cout<<a[i][j];
//	return 0;
//}

int transform(char *ch)  
{  
	int mm = 0, nn = 0, i = 0, val = 0, a = 0;  
	char *pc = ch ;  

	while(*pc != '\0' )  
	{  
		//后移到个位   
		pc++;  
		nn++;  
	}  

	for(i = 1; i <= nn; i++)  
	{  
		//位循环  
		pc--;  
		a = i;  
		mm = 1;  

		while(a > 1)  
		{  
			//位权  
			mm *=26;  
			a--;  
		}  

		mm *= (*pc - 'a' +1);  
		val += mm;  
	}  

	return val;  
}  

//char * deletestr(char *p)//以下代码出错，内存访问冲突
//{
//	char *str=p;
//	int len=strlen(str);
//	int flag=0;
//	for (int j=1;j<len-1;j++)
//	{
//		if (str[j]=='*')
//		{
//			flag++;
//		}	
//	}
//	int newlen=len-flag;
//	//char *result=(char *)malloc(sizeof(char)*newlen);
//	char *result=p;//指针p指向一个常量区，result被赋值后也指向常量区，只能改变result的指向但不能改变result所指的内容
//	result[0]=str[0];
//    result[newlen-1]=str[len-1];
//	int k=1;
//	for (int i=1;i<len-1;i++)
//	{
//		if (str[i]!='*')
//		{
//			result[k++]=str[i];
//		}
//	}
//	
//	result[newlen]='\0';
//	return result;
//}



//int main()
//{
//	/*char *s="a";
//	int m=transform(s);
//	cout<<m<<endl;*/
//	char *m="*abce*d";
//	char *q=deletestr(m);
//	for (int i=0;i<strlen(q);i++)
//	{
//		cout<<q[i];
//	}
//	cout<<endl;
//	
//}



//部分公司的笔试题是空白页面，需要自己写主函数，写输入输出
//int main()
//{
//	string str;
//	getline(cin,str);
//	int len=str.length();
//	int flag=0;
//	for (int j=1;j<len-1;j++)
//	{
//		if (str[j]=='*')
//		{
//			flag++;
//		}	
//	}
//	int newlen=len-flag;
//	char *result=(char *)malloc(sizeof(char)*newlen);
//	result[0]=str[0];
//	result[newlen-1]=str[len-1];
//	int k=1;
//	for (int i=1;i<len-1;i++)
//	{
//		if (str[i]!='*')
//		{
//			result[k++]=str[i];
//		}
//	}
//	result[newlen]='\0';
//	for (int i=0;i<strlen(result);i++)
//	{
//		cout<<result[i];
//	}
//	free(result);
//	return 0;
//}


//华为笔试题，车库问题，in表示入库，out表示出库,end输入结束，capacity表示车库容量，当当前容量小于车库容量时，可以入库，输出allow，反之输出reject
//样例输入：2，in in out in end  输出：allow  allow  allow  (中间是回车)
//int main()
//{
//	vector<int> vec;
//	string a("end");
//	string b("in");
//	string c("out");
//	int capacity;
//	cin>>capacity;
//	int CurCapacity=0;
//	int sum=0;
//	bool flag=true;
//	int num=0;
//	string str;
//	do
//	{
//		getline(cin,str);
//		if (str.compare(a)!=0 && str.compare(b)==0)
//		{
//			vec.push_back(1);
//		}
//		if (str.compare(a)!=0 && str.compare(c)==0)
//		{
//			vec.push_back(-1);
//		}
//
//	}
//	while(str.compare(a)!=0);
//	
//	for (int i=0;i<vec.size();i++)
//	{
//		if (vec[i]==1)
//		{
//			for (int j=0;j<=i;j++)
//			{
//				sum+=vec[j];
//			}
//			if (sum-num<=capacity)
//			{
//				cout<<"allow"<<endl;
//				sum=0;
//			}
//			if (sum>capacity)
//			{
//				cout<<"reject"<<endl;
//				num++;
//				sum=0;
//			}
//		}
//		
//	}
//	return 0;
//}


int encode(const char *str)  
{  
	int len = 0;  
	int index = 0;  
	int factor[] = {1+25+25*25+25*25*25, 1+25+25*25, 1+25, 1};    
	while(*str)  
		index += factor[len++] * (*str++ - 'a');  
	return index + (len - 1);  
}  



//int main()
//{
//	string str;
//	getline(cin,str);
//	const char *s=str.c_str();
//    int a=encode(s);
//	cout<<a;
//	return 0;
//}

//int main()
//{
//	int a,b;
//	cin>>a>>b;
//	if ((a<1||a>2014)||(a<1||a>2014))
//	{
//		cout<<-1;
//	}
//	if (a==b)
//	{
//		cout<<1;
//	}
//
//	return 0;
//}


int f(int a,int b,int c)
{
	return 0;
}
////int main()
////{
////	return f(printf("a"),printf("b"),printf("c"));
////}



int F[40]={0};

void Test()
{
	    int temp;
	    for (int loop1=2; loop1<101; ++loop1)
		     {
			        F[loop1]=loop1;
			        for (int loop2=1; loop2<loop1;loop2++)
				         {
					             temp= (loop2>=(1+F[loop1-loop2]))?loop2:(1+F[loop1-loop2]);
					             if (F[loop1]>temp)
						                 F[loop1]=temp;
					       }
			     }
	}

//int main()
//{
//	    F[0]=0;
//	     F[1]=1;
//	     Test();
//	     cout<<F[39]<<endl;
//	     return 0;
//}

//int main()
//{
//	int rr;
//	cin>>rr;
//	int r=(int)sqrt((float)rr);
//	int sum=0;
//	int num=0;
//	for(int i=-r;i<=r;i++)
//	{
//		for (int j=0;j<=r;j++)
//		{
//			if (i*i+j*j==rr)
//			{
//				sum++;
//				if (j==0)
//				{
//					num++;
//				}
//			}
//		}
//	}
//	sum=sum*2-num;
//	cout<<sum<<endl;
//}


//inline int OddMax(int num)
//{
// 	int max_num=1;
//	if (num==1 || num==2)
//	{
//		return 1;
//	}
//	if (num%2==1)
//	{
//		return num;
//	}
//	if (num%2==0)
//	{
//		for (int i=1;i<num;i=i+2)
//		{
//			if (num%i==0&&max_num<i)
//			{
//				//if ( )
//				//{
//                    max_num=i;
//				//}
//				
//			}
//		}
//	}	
//	return max_num;
//}
//
//int main()
//{
//	int N;
//	cin>>N;
//
//	int result=0;
//	for (int i=1;i<=N;i++)
//	{
//		result+=OddMax(i);
//	}
//	cout<<result<<endl;
//	return 0;
//}

char *get_str()
{
	char str[]={"abcd"};
	return str;
}

//int main()
//{
//	string s1;
//	string s2;
//	getline(cin,s1);
//	getline(cin,s2);
//	int len=s1.length();
//	int sublen=s2.length();
//	int index=0;
//	for (int i=0;i<=len-sublen;i++)

//	{
//		string s=s1.substr(i,sublen);
//		if (s2.compare(s)==0)
//		{
//			index=i;
//			break;
//		}
//	}
//	cout<<index+1;
//	return 0;
//}

//int main()
//{
//	/*char *s=NULL;
//	s=get_str();
//	cout<<*s<<endl;*/
//	char str[]="http://www.duoyi.com";
////	cout<<sizeof(str);
//    void *p=malloc(100);
//	cout<<sizeof(p)<<endl;
//	free(p);
//
//	return 0;
//}


bool isAlpha(const char *str)
{
	int len=strlen(str);
	while(*str!='\0')
	{
		if (!((*str>='A'&&*str<='Z')||(*str>='a'&&*str<='z')))
		{
			return false;
		}
		str++;
	}
	return true;
}
//class A
//{
//public:
//	int m;
//	void print()
//	{
//		cout<<"A\n";
//	}
//};
//int main()
//{
//	A *pa=0;
//	pa->print();
//}


bool isNum(const char *str)
{
	while(*str!='\0')
	{
		if (!((*str>='0'&&*str<='9')||(*str=='.')))
		{
			return false;
		}
	}
	return true;
}




void moveString(char *str,char *begin,char *end)
{
	while(begin!=end)
	{
		char temp=*begin;
		*begin=*str;
		*str=temp;
		str++;
		begin++;
	}

}

//bool Find(int *matrix,int rows,int columns,int number)
//{
//	bool found=false;
//	if (matrix!=NULL && rows>0 && columns>0)
//	{
//		int row=0;
//		int column=columns-1;
//		while(row<rows&&column>=0)
//		{
//			if (matrix[row*columns+column]==number)
//			{
//				found=true;
//				return found;
//			}
//			else if (matrix[row*columns+column]>number)
//			{
//				column--;
//			}
//			else
//				row++;
//		}
//	}
//	return found;
//}

void ListReverse(ListNode *head)
{
	if (head==NULL)
	{
		return;
	}
	stack<ListNode *> st;
	ListNode *pNode=head;
	while(pNode!=NULL)
	{
		st.push(pNode);
		pNode=pNode->next;
	}
	while(!st.empty())
	{
		int i=0;
		pNode=st.top();
		cout<<pNode->value;
		st.pop();
	}
}


int binary_search(int *a,int n,int key)
{
	if (a==NULL || n<0)
	{
		return -1;
	}
	int low=0;
	int high=n-1;
	int mid;
	while(low<=high)
	{
		mid=low+(high-low)/2;
		if (a[mid]>key)
		{
			high=mid-1;
		}
		else if (a[mid]<key)
		{
			low=mid+1;
		}
		else
			return mid;
	}
	return 0;
}

void bubblesort(int *a,int len)
{
	int temp;

	for (int i=0;i<len;i++)
	{
		for (int j=len-1;j>=i;j--)
		{
			if (a[j]<a[j-1])
			{
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
			}
		}
	}
}

////int partition(int *a,int low,int high)
////{
////	int key;
////	key=a[low];
////	while (low<high)
////	{
////		while(low<high && a[high]>=key)
////		{
////			high--;
////		}
////		swap(a,low,high);
////		while(low<high && a[low]<=key)
////		{
////			low++;
////		}
////		swap(a,low,high);
////	}
////	return low;
////}
////void quicksort(int *a,int low,int high)
////{
////	int key;
////	if (low<high)
////	{
////		key=partition(a,low,high);
////		quicksort(a,key-+1,high);
////		quicksort(a,low,key-1);
////	}
////}


//int reverse(int a)
//{
//	int sum=0;
//	while(a>0)
//	{
//		sum+=sum*10+a%10;
//		a/=10;
//	}
//	return sum;
//}

void combine(char *a,vector<char> &vec,int m)
{
	if (a==NULL || m<0 || m>strlen(a))
	{
		return;
	}
	if (*a!='\0' && m>0)
	{
		vec.push_back(*a);
		combine(a+1,vec,m-1);
		vec.pop_back();
		combine(a+1,vec,m);
	}
	if (m==0)
	{
		for(vector<char>:: iterator it=vec.begin();it!=vec.end();it++)
		{
			cout<<(*it)<<endl;

		}
	}
}


void reorder(int *data,int len)
{
	int begin=0;
	int end=len-1;
	while(begin<end)
	{
		while((data[begin]&0x1==1) && begin<end)
		{
			begin++;
		}
		while((data[end]&0x1)==0 && begin<end)
		{
			end--;
		}
		if (begin<end)
		{
			int temp=data[begin];
			data[begin]=data[end];
			data[end]=temp;
		}
	}
}


ListNode* findKthNode(ListNode *phead,int k)
{
	if (phead==NULL || k<0)
	{
		return NULL;
	}
	ListNode *ahead=phead;
	ListNode *end=phead;
	for(int i=0;i<k-1;i++)
	{
		if (ahead->next!=NULL)
		{
			ahead=ahead->next;
		}
		else
			return NULL;
	}
	while(ahead->next!=NULL)
	{
		ahead=ahead->next;
		end=end->next;
	}
	return end;
}


int main()
{

	/*int n=0,i;
	int a[]={23,144,76522};
	for (i=0;i<3;i++)
	{
		n=n*10+a[i];
	}

	printf("%d\n",n);*/
	int a[]={1,2,3,4,5};
	reorder(a,5);
	for (int i=0;i<5;i++)
	{
		cout<<a[i];
	}
	return 0;
}