#include <iostream>
#include <vector>
#include "myType.hpp"

template<typename Data>
class myHashMap {

protected:
	std::vector<std::pair<char*, myType<Data>* > > myVector;

	int size;

public:

	//helper functions
	int findIndex(char* key) {
		int i = 0;
		int sum = 0;
		while(key[i] != '\0') {
			sum += key[i];
			i++;
		}
		return sum%size;
	}

	// requirement functions
	myHashMap(int passIn_size) {
		char* myChar = NULL;
		myType<Data>* theValue = NULL;
		myVector.push_back(std::make_pair(myChar, theValue));
		myVector.resize(passIn_size*2);
		size = myVector.size();
		int index = 0;
		while(index < size) {
			myVector[index].first = NULL;
			myVector[index].second = NULL;
			index++;
			std::cout << "enter" << std::endl;
		}

		
	}

bool set(char* key, myType<Data>* value) {

		int index = findIndex(key);

		std::cout << key<<std::endl;
		
		int starting = index;
		while (myVector[index].first != NULL && index + 1 < size) {
			std::cout << myVector[index].first << std::endl;;

			if (myVector[index].first == key) {
				std::cout << "fsdf";
				return false;
			}
			index++;
			
		}
		if (myVector[index].first != NULL) {
			index = 0;
		}
		else {
			myVector[index] = make_pair(key, value);
		}

		while(index + 1 < size && myVector[index].first != NULL & index != starting) {
			if (myVector[index].first == key) {
				std::cout << "fsdf232323";
				return false;
			}
			index++;
			
		}
		if (myVector[index].first != NULL) {
			std::cout << "fsdfjklklmk";
			return false;
		}
		else {
			myVector[index] = make_pair(key, value);
		}

		return true;

	}

	myType<Data>* get(char* key) {
		int index = 0;
		while(index < size) {
			if (myVector[index].first == key) {
				return myVector[index].second;
			}
		}
		return NULL;
	}

	myType<Data>* todelete(char* key) {
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

	float load() {
		int index = 0;
		int load = 0;
		while(index < size) {
			if(myVector[index].first != NULL) {
				load++;
			}
			index++;
		}
		std::cout << "load is " << load << std::endl;
		std::cout << "size is " << size << std::endl;
		return (float)(load/size);
	}
};

