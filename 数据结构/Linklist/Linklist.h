#pragma once

//����һ���ṹ��
struct ListNode
{
	ListNode* next;
	int data;
};

class Linklist
{
public:
	Linklist();
	~Linklist();
	//ͷ�巨
	void insert_head(int data);
	//β�巨
	void insert_tail(int data);
	//ɾ�����
	bool delete_node(int pos);
	//ѡ������
	void select_sort();

	//��ӡ����
	void display();

private:
	ListNode* phead;	//ͷ���ָ��
	int isize;	//����Ĵ�С
};

