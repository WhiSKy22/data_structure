#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

class List
{
public:
	List();
	~List();
	// create a list according to the inputs from the terminal
	void create();
	// return the size of a list
	int size();
	// search for the ith node in the list, return a pointer to the node at the ith position, the range of pos is 1,2,бнбн,size
	Node* find_pos(const int& pos);
	// insert value at the specific position, the range of pos is 1,2,бнбн,size
	void insert(const int& value, const int& pos);
	// check whether a list is empty or not
	bool empty();
	// delete the node at the specific position, the range of pos is 1,2,бнбн,size
	void delete_node(const int& pos);
	// 	delete the whole list
	void delete_list();
	// get the value of the specific position
	int get_value(const int& pos);
	// get the position of the specific value
	int get_position(const int& value);
	// print the list
	void print();

private:

	Node* head;
};