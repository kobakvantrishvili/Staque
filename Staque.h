#pragma once
#include <iostream>
#ifndef STAQUE
#define STAQUE

using namespace std;
typedef int num;

class Staque {
private:

	class Node {
	public:
		num value;
		num order;
		Node * nextNode;

		//Node constructor
		Node(num number, Node * link = NULL);
	};

	Node* Front;
	Node* Back;

public:

	//Constructor
	Staque();

	//Copy constructor
	Staque(const Staque & Original);

	//Destructor
	~Staque();

	//Checks If List Is Empty
	bool empty() const;

	//Returns Top Node
	num top() const;

	//Returns Bottom Node
	num bottom() const;

	//Add Node
	void Add(num number);

	//Remove Node/Nodes
	void remove(int num, int num_odd = 0, int num_even = 0);

	//Display List
	void display(ostream & out) const;

	//Assignment Operator Overlod
	const Staque & operator=(const Staque& first);

	//Check amount of values
	int amount();

};
#endif