#include "linklist.h"

linklist::linklist()
{
	this->head = NULL;
	this->tail = NULL;
}

void linklist::crateNode(unsigned long value)
{
	node* temp = new node;
	temp->data = value;
	temp->next = NULL;
	if (head == NULL)
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	delete temp;
}

void linklist::insertStart(unsigned long value)
{
	node* temp = new node();
	temp->data = value;
	temp->next = head;
	head = temp;
	delete temp;
}

void linklist::insertLast(unsigned long value)
{
	node* temp = new node();
	tail->next = temp;
	temp->data = value;
	temp->next = NULL;
	tail = temp;
	delete temp;
}


void linklist::insertPosition(int pos, unsigned long value)
{
	node* pre = new node();
	node* cur = new node();
	node* temp = new node();
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	temp->data = value;
	pre->next = temp;
	temp->next = cur;
	delete temp;
}

void linklist::deleteFirst()
{
	node* temp = new node();
	temp = head;
	head = head->next;
	delete temp;
}

void linklist::deleteLast()
{
	node* cur = new node();
	node* pre = new node();
	cur = head;
	while (cur->next != NULL)
	{
		pre = cur;
		cur = cur->next;
	}
	tail = pre;
	pre->next = NULL;
}

void linklist::deletePosition(int pos)
{
	node* cur = new node;
	node* pre = new node();
	cur = head;
	for (int i = 1; i < pos; i++)
	{
		pre = cur;
		cur = cur->next;
	}
	pre->next = cur->next;
}

void linklist::display()
{
	node* temp = new node;
	temp = head;
	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	delete temp;
}

int linklist::size()
{
	SIZE = 0;
	node* temp = new node();
	temp = head;
	while (temp != NULL)
	{
		SIZE++;
		temp = temp->next;
	}
	return SIZE;
	delete temp;
}
