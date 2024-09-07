#include <iostream>
#include "Staque.h"
using namespace std;

int main() {

	num n, odd, even;
	char c;
	Staque List;

	//Creating a Linked Staque List
	cout << "Please insert an integer in range 1 - 9:" << endl;
	do
	{
		while (1) {
			cin >> n;
			if (cin.fail() || n < 1 || n > 9) {
				cin.clear(); //Clears Error flags so user can enter new input 
				cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
				cout << "Please insert a valid number" << endl;
			}
			else{
				List.Add(n); 
				break;
			}
		}
		cout << "Want to insert more? [Y/N]" << endl;
		while (1) {
			cin >> c;
			if (c == 'y' || c == 'Y' ) {
				cout << "Please insert a natural number:" << endl;
				break;
			}
			else if(c == 'n' || c == 'N') {
				break;
			}
			else {
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Please insert a valid answer ---- [Y/N]?" << endl;
			}
		}
	} while (c != 'n' && c != 'N');

	//Displaying all the values
	List.display(cout);
	
	cout << "how many numbers should be removed from the list?"<<endl;
	while (1) {
		cin >> n;
		if (cin.fail() || n < 0 || n >= List.amount()) {
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number in range 0 - " << List.amount() - 1 <<":" << endl;
		}
		else {
			break;
		}
	}
	cout << "how many of those numbers should be odd or even?" << endl;
	cout << "odd :"<<endl;
	while (1) {
		cin >> odd;
		if (cin.fail() || odd > n || odd < 0) {
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number in range 0 - " << n << ":" << endl;
		}
		else {
			break;
		}
	}
	cout<<"even :" << endl;
	while (1) {
		cin >> even;
		if (cin.fail() || odd + even > n || even < 0) {
			cin.clear(); //Clears Error flags so user can enter new input 
			cin.ignore(10000, '\n'); //Ignores input stream up to 10000 characters 
			cout << "Please insert a valid number in range 0 - " << n - odd << ":" << endl;
		}
		else {
			break;
		}
	}

	List.remove(n, odd, even);
	List.display(cout);


	//TESTING ASSIGNMENT OPERATOR AND COPY CONSTRUCTOR
	cout << endl;
	Staque Test1;
	Test1.Add(1);
	Test1.Add(3);
	Test1.Add(2);
	Test1.Add(4);
	Test1.Add(6);
	Test1.Add(8);
	Test1.Add(9);
	cout << "original list :" << endl;
	Test1.display(cout);

	cout << "Copied List :" << endl;
	Staque Test2(Test1); //Copy constructor test
	Test2.display(cout);

	Staque Test3;
	Test3.Add(8);
	Test3.Add(1);
	Test3.Add(5);
	Test3.Add(7);
	Test3.Add(3);
	cout << "original list :" << endl;
	Test3.display(cout);

	cout << "Assigned List :" << endl;
	Test3 = Test1; // assignment opperator test
	Test3.display(cout);

}

