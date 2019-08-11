#ifndef CONTAINER_VECTOR
#define CONTAINER_VECTOR

#include <iostream>
#include <initializer_list>

namespace containers {

template<class T>
class vector {

private:
	T* array = 0;
	int vector_size = 0;
	int vector_capacity = 0;

public:
	vector() {}
	vector(std::initializer_list<T> init);
	vector(int capacity);
	vector(vector& other);
	~vector() { delete[] array; }

	int size();
	int capacity();
	void reserve(int capacity);

	void push_back(const T& value);
	void push_back(T&& value);
	void insert(int pos, const T& value);
	void insert(int pos, T&& value);
	
	T& front();
	T& back();
	T* data();
	T& pop_back();

	void clear();
	void erase(int pos);

	void operator=(std::initializer_list<T> init);
	T& operator[](int index);
	bool operator==(vector<T>& rhs);
	bool operator!=(vector<T>& rhs);
};

}

#include "vector.cpp"

#endif
