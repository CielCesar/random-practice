#include "myHashMap.hpp"


int findIndex(char* key) {
		int i = 0;
		int sum = 0;
		while(key[i] != '\0') {
			sum += key[i];
		}
		return sum%size;
	}

bool myHashMap::set(char* key, myType<Data>* value) {

		int index = myHashMap::findIndex(key);
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

	myType<Data>* myHashMap::get(char* key) {
		int index = 0;
		while(index < size) {
			if (myVector[index].first == key) {
				return myVector[index].second;
			}
		}
		return NULL;
	}

	myType<Data>* myHashMap::todelete(char* key) {
		int index = 0;
		int flag = 0;
		while (index < size) {
			if (myVector[index].first == key) {
				myVector[index].first = NULL;
				flag = 1;
				break;
			}
		}

		if (flag == 0) {
			return NULL;
		}
		else {
			return myVector[index].second;
		}
	}

	float myHashMap::load() {
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