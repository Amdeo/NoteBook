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
