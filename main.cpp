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
		a[i]=s1[len1-1-i]-'0'; //�ַ�ת��Ϊ����
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
int tickets = 100;   //ȫ�ֱ���tickets������ʾ���۵�ʣ��Ʊ��  
//int main()
//{  
//	HANDLE hThread1;  
//	HANDLE hThread2;  
//	//�����߳�  
//	hThread1 = CreateThread(NULL,0,Fun1,NULL,0,NULL);  
//	//4����������˼�ֱ�Ϊ��ʹ�߳�ʹ��Ĭ�ϵİ�ȫ�ԡ������̲߳���������߳�һ����ջ��С��ָ���̵߳���ں�����ַ��  
//	//�̴߳�����ǣ�0��ʾ���߳�һ�����������С����̵߳�ID������Ҫ�Ļ�Ϊnull  
//	hThread2 = CreateThread(NULL,0,Fun2,NULL,0,NULL);  
//	CloseHandle(hThread1);  //����CloseHandle�����̵߳ľ���رգ��رվ��ʱ��ϵͳ��ݼ����߳��ں˶����ʹ�ü�����  
//	CloseHandle(hThread2);  
//	//Sleep(4000); //���߳���ͣ����4s  
//	system("pause");  
//	return 0;  
//}  

//�߳�1��ں���  
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

//�߳�2����ں���  
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
