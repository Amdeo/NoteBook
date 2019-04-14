#include <iostream>
#include "Linklist.h"
int main()
{
	Linklist temp;
	/*temp.insert_head(1);
	temp.insert_tail(2);
	temp.display();
	temp.delete_node(2);
	temp.display()*/
	temp.insert_tail(5);
	temp.insert_tail(4);
	temp.insert_tail(3);
	temp.insert_tail(2);
	temp.insert_tail(1);
	temp.select_sort();
	temp.display();
}