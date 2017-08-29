#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

void reverseString(string &toReverse) {
	string arr = toReverse;
	int count = 0;
	for (int i = toReverse.length() - 1; i > -1; i--) {
		if (toReverse[i] != '(' && toReverse[i] != ')') {
			arr[count] = toReverse[i];
		}
		else if (toReverse[i] == '(') {
			arr[count] = ')';
		}
		else if (toReverse[i] == ')') {
			arr[count] = '(';
		}

		count++;
	}
	toReverse = arr;
}

void simplifyString(string &toSimplify) {
	string first;
	string second = toSimplify;
	string third;
	string toUse = toSimplify;
	int count = 0;
	int toMinus = 0;

	//count the number of '('
	//find the '(' that need to move
	for (string::iterator it = toSimplify.begin(); it != toSimplify.end(); it++) {
		if (*it == '(' && *(it+1) == '(') {
			toMinus++;
		}
		if (*it == '(') {
			count++;
		}
	}
	count = count - toMinus;

	while(count != 0) {
		int enter = 0;
		if (second[second.find('(') + 1] == '(') {
			first += second.substr(0, second.find('('));
			second = second.substr(second.find('(') + 1, second.size());
			enter = 1;
		}

		third = second.substr(second.find(')') + 1, second.size());
		if (enter == 1) {
			second = second.substr(0, second.find(')'));
		}
		else {
			second = second.substr(1, second.find(')') - 1);
		}

		toSimplify = first + second + third;
		second = toSimplify;
		enter = 0;
		count--;
	}
	

}

//suppose the inputs are all valid
int main(){

	string readIn;
	string inUse;
	string operation;

	cout << "Enter the string: ";
	cin >> readIn;
	
	//parse into the string and operation

	//string to do the operation
	inUse = readIn.substr(0, readIn.find('/'));

	//operation string
	operation = readIn.substr(readIn.find('/') + 1, readIn.size());

	for (string::iterator it = operation.begin(); it != operation.end(); it++) {
		if (*it == 'R') {
			reverseString(inUse);
		}
		if (*it == 'S') {
			simplifyString(inUse);
		}
	}

	cout << "Final answer is " << inUse << endl;

	return 0;
}