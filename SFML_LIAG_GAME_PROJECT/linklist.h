#include<list>	
#include"defineHead.h"
struct node
{
	unsigned long data;
	node* next;
};

class linklist
{
public:
	linklist();
	void crateNode(unsigned long value);
	void insertStart(unsigned long value);
	void insertLast(unsigned long value);
	void insertPosition(int pos, unsigned long value);
	void deleteFirst();
	void deleteLast();
	void deletePosition(int pos);
	void display();
	int size();
private:
	node* head, * tail;
	int SIZE = 0;
};

