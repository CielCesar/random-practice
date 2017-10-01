#include <iostream>
#include <vector>
#include "myType.hpp"

using namespace std;

template<typename Data>
class myHashMap {

protected:
	vector<pair<char*, myType*>> myVector(1);

	int size;

public:

	//helper functions
	int findIndex(char* key) {
		int i = 0;
		int sum = 0;
		while(key[i] != NULL) {
			sum += key[i];
		}
		return sum%size;
	}






	// requirement functions
	myHashMap(int size) {
		myVector.resize(size*2);
		size = myVector.size();
	}

	bool set(char* key, myType* value) {

		int index = findIndex(key);
		int starting = index;
		while (myVector[index].first != NULL && index + 1 < size) {
			if (myVector[index].first == key) {
				return false;
			}
			index++;
		}
		if (myVector[index].first != NULL) {
			index = 0;
		}
		else {
			myVector[index] = value;
		}

		while(index + 1 < size && myVector[index].first != NULL & index != starting) {
			if (myVector[index].first == key) {
				return false;
			}
			index++;
		}
		if (myVector[index].first != NULL) {
			return false;
		}
		else {
			myVector[index] = make_pair(key, value);
		}

		return true;

	}

	myType* get(char* key) {
		int index = 0;
		while(index < size) {
			if (myVector[index].first == key) {
				return myVector[index].second;
			}
		}
		return NULL;
	}

	myType* delete(char* key) {
		int index = 0;
		myType* toReturn = NULL;
		while (index < size) {
			if (myVector[index].first == key) {
				myVector[index].first = NULL;
				toReturn = myVector[index].first;
				break;
			}
		}

		return toReturn;

	}

	float load() {
		int index = 0;
		int load = 0;
		while(index < size) {
			if(myVector[index].first != NULL) {
				load++;
			}
			index++;
		}
		return (float)(load/size);
	}
};

