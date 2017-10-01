#include <iostream>

using namespace std;

class myList {
protected:
	struct Element{
		char* myString;
		void* theValue;
		Element* next;
	};

	Element* head;

	int size;

public:

	myList() : head(NULL), size(0) {}

	virtual ~myList() {
		Element* curr = head;
		while (curr != NULL) {
			Element* next = curr->next;
			delete(curr);
			curr = next;
		}
	}
}