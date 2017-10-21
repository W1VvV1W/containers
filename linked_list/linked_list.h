#ifndef CONTAINER_LINKED_LIST
#define CONTAINER_LINKED_LIST

#include <cstddef>
#include <stdexcept>

template<class T> 
class LinkedList {

	struct Element
	{
		Element* prev = nullptr;
		Element* next = nullptr;
		T* content = nullptr;

		Element() {}
		Element(Element* prev_argument,
				Element* next_argument, 
				T& contet_argument)
				    : prev(prev_argument),
				      next(next_argument)
				    { content = new T(contet_argument); }
	};

	Element* begin = nullptr;
	Element* end = nullptr;
	std::size_t max_size = -1;
	std::size_t list_size;

public:
	LinkedList() {}
	LinkedList(std::size_t max_size_argument) : max_size(max_size_argument) {}
	LinkedList(LinkedList& other);
	virtual ~LinkedList() { clear(); }

	void clear() noexcept;
	std::size_t size() const noexcept { return list_size; }
	bool empty() const noexcept { return !list_size; }

	void push_front(T other);
	void push_back(T other);
	T pop_front();
	T pop_back();

	T front() const { 
		if(empty()) throw std::length_error("List is empty!");
	 	return begin->content; 
	}
	T back() const { 
		if(empty()) throw std::length_error("List is empty!"); 
		return end->content; 
	}

};

template<class T>
LinkedList<T>::LinkedList(LinkedList& other) {
	begin = other.begin;
	end = other.end;
	max_size = other.max_size;
	list_size = other.list_size;
}

template<class T>
void LinkedList<T>::clear() noexcept {
	Element* buffer;
	while(begin != nullptr) {
		buffer = begin;
		delete begin;
		begin = buffer->next;
	}
}

template<class T>
void LinkedList<T>::push_front(T other) {

}

template<class T>
void LinkedList<T>::push_back(T other) {\

}

template<class T>
T LinkedList<T>::pop_front() {

}

template<class T>
T LinkedList<T>::pop_back() {

}

#endif
