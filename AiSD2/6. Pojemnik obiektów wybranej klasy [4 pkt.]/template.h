#pragma once
#include <iostream>
using namespace std;
template<class T>

class Container {
private:
	T array[6];
	int counter = 0;
public:
	Container();
	Container(T array);
	void add(T obj);
	void remove(int index);
	int getCounter();
	T* getArray();
	void swapIndexes(int idx1, int idx2);
};

template<class T> Container<T>::Container(){}

template<class T> Container<T>::Container(T array): array(array) {}

template<class T> void Container<T>::add(T obj) {
	if (counter > 5) 
		return;

	array[counter] = obj;
	counter++;
}

template<class T> void Container<T>::remove(int index) {
	if (index >= counter) 
		return;

	array[index] = array[counter - 1];
	counter--;
}

template<class T> void Container<T>::swapIndexes(int idx1, int idx2) {
	swap(array[idx1], array[idx2]);
}

template<class T> int Container<T>::getCounter() {
	return counter;
}

template<class T> T* Container<T>::getArray() {
	return array;
}