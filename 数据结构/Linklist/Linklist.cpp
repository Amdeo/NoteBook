#include "Linklist.h"
#include <iostream>
using namespace std;

/*
	����ͷ���
*/
Linklist::Linklist()
{
	phead = new ListNode;
	phead->next = NULL;
	phead->data = 0;
	isize = 0;
}

/*
�ͷ����нڵ㣨����ͷ��㣩
*/
Linklist::~Linklist()
{
	//�ж�������
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
