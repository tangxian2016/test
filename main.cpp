#include <iostream>
#include "function.h"
#include <Windows.h>
using namespace std;

#define N 10000

//int main()
//{
//	string str="-+1";
//	int m=myAtoi(str); 
//	cout<<m<<endl;
//	return 0;
//}
DWORD WINAPI Fun1(LPVOID lpParameter);  

DWORD WINAPI Fun2(LPVOID lpParameter);  


void Longadd(char *s1,char *s2)
{
	int len1=strlen(s1);
	int len2=strlen(s2);
	int a[N]={0};
	int b[N]={0};
	for (int i=0;i<len1;i++)
		a[i]=s1[len1-1-i]-'0'; //字符转化为整数
	for (int i=0;i<len2;i++)
		b[i]=s2[len2-1-i]-'0';
	int len=(len1>len2 ? len1:len2);
	for (int i=0;i<len;i++)
	{
		a[i]+=b[i];
		if (a[i]>=10)
		{
			a[i+1]+=a[i]/10;
			a[i]=a[i]%10;
		}
	}
	if (a[len])
		cout<<a[len];
	for (int i=len-1;i>=0;i--)
		cout<<a[i];
	cout<<endl;
}


int index = 0;  
int tickets = 100;   //全局变量tickets用来表示销售的剩余票数  
//int main()
//{  
//	HANDLE hThread1;  
//	HANDLE hThread2;  
//	//创建线程  
//	hThread1 = CreateThread(NULL,0,Fun1,NULL,0,NULL);  
//	//4个参数的意思分别为：使线程使用默认的安全性、让新线程采用与调用线程一样的栈大小、指定线程的入口函数地址、  
//	//线程创建标记，0表示让线程一旦创立就运行、新线程的ID，不需要的话为null  
//	hThread2 = CreateThread(NULL,0,Fun2,NULL,0,NULL);  
//	CloseHandle(hThread1);  //调用CloseHandle将此线程的句柄关闭，关闭句柄时，系统会递减该线程内核对象的使用计数。  
//	CloseHandle(hThread2);  
//	//Sleep(4000); //让线程暂停运行4s  
//	system("pause");  
//	return 0;  
//}  

//线程1入口函数  
DWORD WINAPI Fun1(LPVOID lpParameter)  
{  
	while (TRUE)  
	{  
		if (tickets > 0)  
		{  
			//Sleep(1);  
			cout<<"thread1 sell ticket : "<<tickets--<<endl;  
		}  
		else  
		{  
			break;  
		}  
	} 

	char *s1="12345667";
	char *s2="683902";
	Longadd(s1,s2);

	return 0;  
}  

//线程2的入口函数  
DWORD WINAPI Fun2(LPVOID lpParameter)  
{  
	while (TRUE)  
	{  


		if (tickets > 0)  
		{  
		//	Sleep(1);  
			cout<<"thread2 sell ticket : "<<tickets--<<endl;  
		}  
		else  
		{  
			break;  
		}  
	}  

	char *s1="1";
	char *s2="2";
	Longadd(s1,s2);

	return 0;  
}  
