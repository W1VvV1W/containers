#ifndef CONTAINER_ARRAY
#define CONTAINER_ARRAY

#include <cstddef>
#include <initializer_list>
#include <algorithm>
#include <map>
#include <iostream>

template<class T>
class Array {
private:
	std::size_t arr_size = 0;
	T* array;

public:
	Array() {}

	Array(std::size_t size_a) { resize(size_a); }
	
	Array(std::initializer_list<T> init);
	Array(Array& other);

	virtual ~Array() { delete array; }

	std::size_t size() { return arr_size; }
	void resize(std::size_t size_argument);

	void push_back(T& element);
	void remove(std::size_t index);

	void merge(Array& other);
	void remove_collisions(); // FIX BUGS
	void unite(Array& other); // TODO 
	void cross(Array& other); // TODO

	T& operator[](std::size_t index);
	T& operator=(T& other) throw(int) { return other; }


};

template<class T>
Array<T>::Array(std::initializer_list<T> init) {
	resize(init.size());
	std::copy(init.begin(), init.end(), array);
}


template<class T>
Array<T>::Array(Array& other) {
	this->arr_size = other.arr_size;
	this->array = other.array;
}

template<class T>
void Array<T>::resize(std::size_t size_argument) {
	if(!arr_size) {
		arr_size = size_argument;
		array = new T[size_argument]; 
		return;
	}
	arr_size = size_argument;
	T* buffer_array = array;
	array = new T[size_argument];
	for(std::size_t i = 0; i < size_argument; ++i)
		array[i] = buffer_array[i];
	delete[] buffer_array;
}


template<class T>
void Array<T>::push_back(T& element) {
	resize(arr_size+1);
	array[arr_size] = element;
}
	

template<class T>
void Array<T>::remove(std::size_t index) {
	for(std::size_t i = index; i < arr_size-1; ++i) {
		array[i] = array[i+1];
	}
	resize(arr_size-1);
}

template<class T>
void Array<T>::merge(Array& other) {
	int last_array_size = arr_size;
	resize(arr_size + other.size());
	for(std::size_t i = last_array_size; i < arr_size; ++i) 
			array[i] = other[i - last_array_size];	
}

template<class T>
void Array<T>::remove_collisions() {
	std::map<T, bool> collisions;
	for(std::size_t i = 0; i < arr_size; ++i) {
		if(collisions[array[i]]) 
			remove(i);
		else 
			collisions[array[i]] = true;
	}

}

template<class T>
void Array<T>::unite(Array& other) {
	merge(other);
	remove_collisions();
}

template<class T>
void Array<T>::cross(Array& other) {
	std::map<T, std::size_t> collisions;
	for(std::size_t i = 0; i < arr_size; ++i) 
		++collisions[array[i]];
}

template<class T>
T& Array<T>::operator[](std::size_t index) {
	if(index > arr_size) throw 0;
	return array[index];
}

#endif 
