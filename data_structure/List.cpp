#include<iostream>
#include"Node.h"
#include"List.h"
using namespace std;

List::List()
{
	head = new Node(0);
}

void List::create()
{
	int temp;
	cout << "input some integers to the list(input a letter to finish)" << endl;
	while (cin >> temp)
	{
		Node* p = new Node(temp);
		p->next = head->next;
		head->next = p;
		cout << "new_node_data = " << p->data << endl;
	}
}

int List::size()
{
	int size = 0;
	Node* p = head;
	while (p->next)
	{
		size++;
		p = p->next;
	}
	return size;
}

bool List::empty()
{
	return ((bool)head->next) == NULL;
}

void List::print()
{
	if (empty() == true)
	{
		cout << "list is empty" << endl;
	}
	else
	{
		Node* p = head->next;
		while (p)
		{
			cout << p->data;
			p = p->next;
		}
		cout << endl;
	}
}

Node* List::find_pos(const int& pos)
{
	if (pos > this->size() || pos < 0 || this->empty() == true)
	{
		cout << "Finding failed." << endl;
		return NULL;
	}
	else
	{
		Node* p = head;
		int temp = 0;
		while (temp < pos)
		{
			p = p->next;
			temp++;
		}
		return p;
	}
}

void List::insert(const int& value, const int& pos)
{
	if (pos > this->size() || pos <= 0 || this->empty() == true)
	{
		cout << "Insertion failed." << endl;
	}
	else
	{
		Node* p = new Node(value);
		Node* prior = this->find_pos(pos - 1);
		p->next = prior->next;
		prior->next = p;
	}
}

void List::delete_node(const int& pos)
{
	if (pos < 1 || pos > this->size())
	{
		cout << "Index out of bounds." << endl;
	}
	else
	{
		Node* p = this->find_pos(pos - 1);
		Node* q = p->next->next;
		delete p->next;
		p->next = q;
	}
}

void List::delete_list()
{
	Node* p;
	while (head->next != NULL)
	{
		this->delete_node(1);
	}
}

int List::get_value(const int& pos)
{
	if (pos > this->size() || pos < 1)
	{
		cout << "Index out of bounds." << endl;
		return 0;
	}
	else
	{
		Node* p = this->find_pos(pos);
		return p->data;
	}
}

int List::get_position(const int& value)
{
	if (this->empty())
	{
		cout << "This list is empty." << endl;
		return 0;
	}
	else
	{
		Node* p = head->next;
		int temp = 1;
		while (p && p->data != value)
		{
			p = p->next;
			temp++;
		}
		if (p == NULL)
		{
			cout << "Value not found." << endl;
			return 0;
		}
		else
		{
			return temp;
		}
	}
}

List::~List()
{
	this->delete_list();
	delete head;
}
