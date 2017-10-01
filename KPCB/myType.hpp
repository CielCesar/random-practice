#include <iostream>


template<typename Data>
class myType {
public:
	myType(const Data & d): data(d) {}

	Data const data;
};