#include<iostream>
#include <stdlib.h>
using namespace std;
#define MaxSize 6
typedef int KeyType;
//˳��ṹ�洢����
typedef struct{
	int r[MaxSize+1];
	int length;
}SqList;
//��Ԫ�ؽ���
void swap(SqList &L,int i,int j)
{
	int temp=L.r[i];
	L.r[i]=L.r[j];
	L.r[j]=temp;
}
//**********************�����㷨******************

//******************��������***************
//ֱ�Ӳ�������
SqList InsertSort(SqList L)
{
	for(int i=2;i<L.length;i++)
	{
		if(L.r[i]<L.r[i-1])
		{
			L.r[0]=L.r[i];//�����ڱ�
			for(int j=i-1;L.r[j]>L.r[0];j--)
				L.r[j+1]=L.r[j];
			L.r[j+1]=L.r[0];
		}
	}
	return L;
}
//�۰��������
void BInsertSort(SqList &L)
{
	int low,high;
	int m;
	for(int i=2;i<L.length;i++)
	{
		L.r[0]=L.r[i];
		low=1;high=i-1;
		while(low<=high)
		{
			m=(low+high)/2;
			if(L.r[0]<L.r[m])
				high=m-1;
			else low=m+1;
		}
		for(int j=i-1;j>=low;j--)L.r[j+1]=L.r[j];
		L.r[high+1]=L.r[0];
	}
}
//ϣ������
void ShellPass(SqList &L,int d)
{
	for(int i=d+1;i<L.length;i++)
		if(L.r[i]<L.r[i-d])
		{
			L.r[0]=L.r[i];
			int j=i-d;
			do{
				L.r[j+d]=L.r[j];
				j=j-d;
			}while(j>0&&L.r[0]<L.r[j]);
			L.r[j+d]=L.r[0];
		}
}
void ShellSortNoGuard(SqList &L)
{
	int inc=L.length;
	do{inc=inc/3+1;ShellPass(L,inc);}
	while(inc>1);
}
//********************��������***********************
//ð������(�Ż����)
void BubbleSort(SqList &L)
{
	bool flag=true;
	for(int i=1;flag&&i<L.length;i++)
	{
		flag=false;
		for(int j=L.length-1;j>i;j--)
		if(L.r[j]<L.r[j-1])
		{
			swap(L,j,j-1);
				flag=true;
		}
	}
}
//��������
void QuickSort(SqList &L,int left,int right)
{
	if(left<right)
	{
		int low=left;
		int high=right;
		int key=L.r[low];
		while(low<high)
		{
			while(low<high&&L.r[high]>key){high--;}
			L.r[low]=L.r[high];
			while(low<high&&L.r[low]<key){low++;}
			L.r[high]=L.r[low];
		}
		L.r[low]=key;
		QuickSort(L,left,low-1);
		QuickSort(L,low+1,right);
	}
}
//**********************ѡ������************************
void SelectSort(SqList &L)
{
	for(int i=1;i<L.length-1;i++)
	{
		int min=i;
		for(int j=i+1;j<L.length;j++)
		{
			if(L.r[j]<L.r[min])
				min=j;
		}
		if(i!=min)
		swap(L,i,min);
	}
}
void main()
{
	SqList L={{0,21,3,14,15,4,18},7};
	//L=InsertSort(L);
	//BInsertSort(L);
	//ShellSortNoGuard(L);
	//BubbleSort(L);
	//QuickSort(L,1,6);
	SelectSort(L);
	for(int i=1;i<L.length;i++)
	{
		cout<<L.r[i]<<endl;
	}
}