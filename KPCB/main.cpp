#include <iostream>
#include <string>
#include "myHashMap.hpp"

using namespace std;

int main() {

	myHashMap<std::string> myMap(5);

	float myLoad = myMap.load();
	cout << myLoad << endl;


	char key[] = {'a', 'b'};
	myType<string>* value = new myType<string>("cute\0");
	bool returned = myMap.set(key, value);
	cout << returned << endl;

	return 0;
}