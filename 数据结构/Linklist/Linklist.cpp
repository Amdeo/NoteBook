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

//ͷ�巨
void Linklist::insert_head(int data)
{
	//�������
	ListNode* p = new ListNode;
	p->data = data;
	p->next = NULL;

	/*
	ͷ�巨��ͷ���ָ���½��
	*/
	p->next = phead->next;
	phead->next = p;

	p = NULL;
	isize++;
	cout << "ͷ������"<< data  << endl;
}

//β�巨
void Linklist::insert_tail(int data)
{
	//�����½��
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
	cout << "β������" << data << endl;
}

//ɾ�����
bool Linklist::delete_node(int pos)
{
	//�����ж�
	if (pos > isize)
	{
		cout<< "����������" <<endl;
		return false;
	}

	ListNode* p = phead;
	ListNode* target= NULL;
	//�ƶ�ָ��p��Ŀ��ǰһ�����
	for (int i = 0; i < pos -1; i++)
	{
		p = p->next; 
	}
	//qָ����Ҫɾ���Ľ��
	target = p->next;
	//Խ����Ҫɾ������������
	p->next = p->next->next;
	//ɾ�����
	delete target;

	p = NULL;
	target = NULL;
	//������1
	isize--;
	cout<<"ɾ����"<<pos<<"���"<<endl;
	return true;
}

//ѡ������
void Linklist::select_sort()
{
	ListNode* p = NULL, * q = NULL, *m= NULL;
	for (p = phead->next;p->next != NULL;p=p->next)
	{
		m = p;
		for (q=p->next;q != NULL;q=q->next)
		{
			if (m->data > q->data)
			{
				m = q;
			}
		}
		if (p != m)
		{
			p->data = p->data ^ m->data;
			m->data = p->data ^ m->data;
			p->data =  m->data ^ p->data;
		}
	}
}

//��ӡ����(������ͷ���)
void Linklist::display()
{
	if(isize == 0)
	{
		cout<<"û�н��"<<endl;
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