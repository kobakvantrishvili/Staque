#include "Staque.h"

Staque::Node::Node(num number, Node* next)
{
	value = number;
	nextNode = next;
	order = -1;
}

Staque::Staque()
:Front(NULL), Back(NULL)
{
}

Staque::Staque(const Staque & original)
{
	Front = Back = NULL;
	if (original.empty() != true)
	{
		Front = new Staque::Node(original.top()); //copies first node
		Front->order = original.Front->order;

		Staque::Node* curr = Front,
					* origNext = original.Front->nextNode;

		while (origNext != NULL) {
			curr->nextNode = new Staque::Node(origNext->value);
			curr = curr->nextNode;
			curr->order = origNext->order;
			origNext = origNext->nextNode;
		}
		Back = curr;
	}
}

Staque::~Staque()
{
	if (!empty()) {
		Staque::Node* prev = Front,
					* curr;

		while (prev != NULL) {
			curr = prev->nextNode;
			delete prev;
			prev = curr;
		}
	}
}

bool Staque::empty() const
{
	return (Front == NULL);
}

num Staque::top() const
{
	if (!empty())
		return (Front->value);
	else
		cout << "List is Empty!" << endl;
}

num Staque::bottom() const
{
	if(!empty())
		return (Back->value);
	else
		cout << "List is Empty!" << endl;
}

void Staque::Add(num number)
{
	if (empty()) {
		Front = Back = new Staque::Node(number);
		Front->order = 0;
	}
	else if(number % 2 == 1)
	{
		Staque::Node* ptr = new Staque::Node(number);
		if (Front->order > Back->order)
			ptr->order = Front->order + 1;
		else
			ptr->order = Back->order + 1;
		Back->nextNode = ptr;
		Back = ptr;
	}
	else {
		Staque::Node* ptr = new Staque::Node(number);
		if (Front->order > Back->order)
			ptr->order = Front->order + 1;
		else
			ptr->order = Back->order + 1;
		ptr->nextNode = Front;
		Front = ptr;
	}

}

void Staque::remove(int num, int num_odd, int num_even)
{
	Staque::Node* ptr = NULL,
				* temp = NULL;
	if (empty())
		cerr << "List is empty, can't remove any value\n";
	else if (num_odd == 0 && num_even == 0) {
		//LIFO Principle independet of even and odd numbers
		cout << "Removing values in LIFO order..." << endl;
		for (int i = 0; i < num; i++) {
			if (Front->order > Back->order) {
				ptr = Front;
				Front = Front->nextNode;
				cout << "value " << ptr->value << " removed" << endl;
				delete ptr;
			}
			else if (Front->order < Back->order) {
				ptr = Front,
				temp = Back;
				while (ptr->nextNode != Back) {
					ptr = ptr->nextNode;
				}
				Back = ptr;
				Back->nextNode = NULL;
				cout << "value " << temp->value << " removed" << endl;
				delete temp;
			}
			else {
				break;
			}
		}
	}
	else {
		//Remove X number of evens from the Front and then remove Y number of odds from the Back (depends on input)
		for (int i = 0; i < num_even; i++) {
			if (Front->order != 0) { //First element is not removed
				ptr = Front;
				Front = Front->nextNode;
				cout << "value " << ptr->value << " removed" << endl;
				delete ptr;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < num_odd; i++) {
			if (Back->order != 0) { //First element is not removed
				ptr = Front,
				temp = Back;
				while (ptr->nextNode != Back) {
					ptr = ptr->nextNode;
				}
				Back = ptr;
				Back->nextNode = NULL;
				cout << "value " << temp->value << " removed" << endl;
				delete temp;
			}
			else
			{
				break;
			}
		}
	}
}

void Staque::display(ostream & out) const
{
	if (!empty()) {
		cout << "---------";
		Staque::Node* curr = Front;

		while (curr != NULL) {
			cout << "--";
			curr = curr->nextNode;
		}

		cout << endl;
		curr = Front;
		cout << "values : ";

		while(curr != NULL) {
			cout << curr->value << " ";
			curr = curr->nextNode;
		}

		cout << endl;
		curr = Front;
		cout << "order  : ";

		while (curr != NULL) {
			cout << curr->order << " ";
			curr = curr->nextNode;
		}

		cout<<"\n"<< endl;
	}
}

const Staque& Staque::operator=(const Staque & orig)
{
	if (this != &orig) {
		this->~Staque();
		if (orig.empty()) {
			Front = NULL;
			Back = NULL;
		}
		else {
			Front = Back = new Staque::Node(orig.top()); //copies first node
			Front->order = orig.Front->order;

			Staque::Node* origNext = orig.Front->nextNode;
			while (origNext != NULL) {
				Back->nextNode = new Staque::Node(origNext->value);
				Back = Back->nextNode;
				Back->order = origNext->order;
				origNext = origNext->nextNode;
			}
		}
	}
	return *this;
}

int Staque::amount()
{
	int i = 0;
	Staque::Node* curr = Front;
	while (curr != NULL) {
		i++;
		curr = curr->nextNode;
	}
	return i;
}
