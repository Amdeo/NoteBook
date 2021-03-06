#include "Linklist.h"
#include <iostream>
using namespace std;

/*
	创建头结点
*/
Linklist::Linklist()
{
	phead = new ListNode;
	phead->next = NULL;
	phead->data = 0;
	isize = 0;
}

/*
释放所有节点（包括头结点）
*/
Linklist::~Linklist()
{
	//判断链表长度
	if (isize == 0)
	{
		delete phead;
		phead = NULL;
		return;
	}
	ListNode* p = NULL;
	while (phead != NULL)
	{
		p = phead;
		phead = phead->next;
		delete(p);
	}
	p = NULL;
	phead = NULL;
}

//头插法
void Linklist::insert_head(int data)
{
	//创建结点
	ListNode* p = new ListNode;
	p->data = data;
	p->next = NULL;

	/*
	头插法，头结点指向新结点
	*/
	p->next = phead->next;
	phead->next = p;

	p = NULL;
	isize++;
	cout << "头部插入"<< data  << endl;
}

//尾插法
void Linklist::insert_tail(int data)
{
	//创建新结点
	ListNode* p = new ListNode;
	p->data = data;
	p->next = NULL;

	ListNode* q = phead;
	while (q->next != NULL)
	{
		q = q->next;
	}

	q->next = p;
	isize++;
	p = NULL;
	q = NULL;
	cout << "尾部插入" << data << endl;
}

//删除结点
bool Linklist::delete_node(int pos)
{
	//参数判断
	if (pos > isize)
	{
		cout<< "超出链表长度" <<endl;
		return false;
	}

	ListNode* p = phead;
	ListNode* target= NULL;
	//移动指针p到目标前一个结点
	for (int i = 0; i < pos -1; i++)
	{
		p = p->next; 
	}
	//q指向需要删除的结点
	target = p->next;
	//越过需要删除结点进行连接
	p->next = p->next->next;
	//删除结点
	delete target;

	p = NULL;
	target = NULL;
	//数量减1
	isize--;
	cout<<"删除第"<<pos<<"结点"<<endl;
	return true;
}

//选择排序
void Linklist::select_sort()
{
	ListNode* p = NULL, * q = NULL, *m= NULL;
	for (p = phead->next;p != NULL;p=p->next)
	{
		m = p;//将循环的结点保存
		for (q=p->next;q != NULL;q=q->next)
		{
			//从后面所有的数中找出最小的数
			if (m->data > q->data)
			{
				m = q;
			}
		}
		//最小的结点不是保存的结点，就进行交换
		if (p != m)
		{
			//交换p和m的数据
			p->data = p->data ^ m->data;
			m->data = p->data ^ m->data;
			p->data =  m->data ^ p->data;
		}
	}
}

//直接插入排序
void Linklist::insert_sort()
{
	ListNode* p = NULL, * q = NULL, * m = NULL;
	for (p = phead;p != NULL;p=p->next)
	{

	}
}

//插入排序



//打印链表(不包括头结点)
void Linklist::display()
{
	if(isize == 0)
	{
		cout<<"没有结点"<<endl;
		return;
	}
	ListNode* p = phead->next;
	while (p != NULL)
	{
		cout << p->data <<" ";
		p = p->next;
	}
	cout << "\n";
	p = NULL;
}