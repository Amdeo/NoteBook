#pragma once

//定义一个结构体
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
	//头插法
	void insert_head(int data);
	//尾插法
	void insert_tail(int data);
	//删除结点
	bool delete_node(int pos);
	//选择排序
	void select_sort();

	//打印链表
	void display();

private:
	ListNode* phead;	//头结点指针
	int isize;	//链表的大小
};

