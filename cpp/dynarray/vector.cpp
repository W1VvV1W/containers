//DO NOT COMPILE THIS FILE!

namespace containers {

template<class T>
vector<T>::vector(std::initializer_list<T> init) {
	vector_size = init.size();
	array = new T[vector_size];
	for(int i = 0; i < vector_size; ++i)
		array[i] = *(init.begin()+i);
	vector_capacity = init.size();
}

template<class T>
vector<T>::vector(int capacity) {
	vector_capacity = capacity;
	array = new T[vector_capacity];
}

template<class T>
vector<T>::vector(vector& other) {
	vector_size = other.vector_size;
	vector_capacity = other.vector_capacity;
	array = new T[vector_capacity];
	for(int i = 0; i < vector_size; ++i)
		array[i] = other[i];
}

template<class T>
int vector<T>::size() { return vector_size; }

template<class T>
int vector<T>::capacity() { return vector_capacity; }

template<class T>
void vector<T>::reserve(int capacity) {
	if(!array) {
		array = new T[capacity];
		vector_capacity = capacity;
		return;
	}
	T* newarr = new T[capacity];
	for(int i = 0; i < vector_size; ++i)
		newarr[i] = array[i];
	vector_capacity = capacity;
	delete[] array;
	array = newarr;
}

template<class T>
void vector<T>::push_back(const T& value) {
	if(vector_capacity <= vector_size) 
		reserve(++vector_capacity);
	array[vector_size] = value;
	++vector_size;
}

template<class T>
void vector<T>::push_back(T&& value) {
	if(vector_capacity <= vector_size) 
		reserve(++vector_capacity);
	array[vector_size] = value;
	++vector_size;
}

template<class T>
void vector<T>::insert(int pos, const T& value) {
	if(pos > vector_capacity) {
		vector_size = pos;
		vector_capacity = pos;
		reserve(vector_capacity);
	}
	for(int i = vector_size; i > pos+1; --i)
		array[i] = array[i-1];
	array[pos] = value;
} 

template<class T>
void vector<T>::insert(int pos, T&& value) {
	if(pos >= vector_capacity) {
		vector_size = pos+1;
		vector_capacity = pos+1;
		reserve(vector_capacity);
	}
	for(int i = vector_size; i > pos+1; --i)
		array[i] = array[i-1];
	array[pos] = value;
}

template<class T> 
T& vector<T>::front() { return array[0]; }

template<class T>
T& vector<T>::back() { return array[vector_size-1]; }

template<class T>
T* vector<T>::data() { return array; } 

template<class T>
T& vector<T>::pop_back() {
	T& result = array[vector_size-1];
	reserve(--vector_capacity);
	--vector_size;
	return result;
}

template<class T>
void vector<T>::clear() {
	delete[] array;
	array = 0;
	vector_capacity = 0;
	vector_size = 0;
}

template<class T>
void vector<T>::erase(int pos) {
	for(int i = pos; i < vector_size-1; ++i)
		array[i] = array[i+1];
	--vector_size;
	reserve(--vector_capacity);
}

template<class T>
void vector<T>::operator=(std::initializer_list<T> init) {
	clear();
	reserve(init.size());
	vector_capacity = vector_size = init.size();
	for(int i = 0; i < vector_capacity; ++i)
		array[i] = *(init.begin() + i);
}

template<class T>
T& vector<T>::operator[](int index) {
	return array[index];
}

template<class T>
bool vector<T>::operator==(vector<T>& rhs) {
	if(size() != rhs.size()) return false;
	for(int i = 0; i < vector_size; ++i)
		if(rhs[i] != array[i]) return false;
	return true;
}

template<class T>
bool vector<T>::operator!=(vector<T>& rhs) {
	return !this==rhs;
}

} // namespace containers
