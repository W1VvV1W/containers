/**
* @author - Duzhinsky D.E. ( github - W1VvV1W )
* @date 14.02.2018
* @license - MIT
*/

#ifndef CONTAINER_LINKED_LIST
#define CONTAINER_LINKED_LIST

#include <stdexcept>
#include <initializer_list>

#include <stdint.h>

template<class T>
class LinkedList {

	struct Element
	{
		Element* prev = nullptr;
		Element* next = nullptr;
		T content = nullptr;

		Element() {}
		Element(Element* prev_argument,
				Element* next_argument,
				T& content_argument)
				    : prev(prev_argument),
				      next(next_argument),
				      content(content_argument)
				    {}
	};

	Element* begin = nullptr;
	Element* end = nullptr;
	uint64_t list_size;


public:
	LinkedList() {}
	LinkedList(LinkedList& rhs) { *this = rhs; }
	LinkedList(std::initializer_list<T> init);
	virtual ~LinkedList() { clear(); }

	void clear() noexcept;
	uint64_t size() const noexcept { return list_size; }
	bool empty() const noexcept { return !list_size; }

	void push_front(T& rhs);
	void push_front(const T&& rhs);
	void push_back(T& rhs);
	void push_back(const T&& rhs);
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

    LinkedList& operator=(LinkedList& rhs);
    T operator[](uint64_t index);

};

template<class T>
LinkedList<T>::LinkedList(std::initializer_list<T> init) {
    list_size = init.size();
    for(int i = 0; i < list_size; ++i)
        push_back(*(init.begin()+i));
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& rhs) {
    list_size = rhs.list_size;
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
void LinkedList<T>::push_front(T& rhs) {
    Element* new_element(nullptr, begin, rhs);
    begin = new_element;
    ++list_size;
}

template<class T>
void LinkedList<T>::push_front(const T&& rhs) {
    Element* new_element(nullptr, begin, rhs);
    begin = new_element;
    ++list_size;
}


template<class T>
void LinkedList<T>::push_back(const T&& rhs) {
    Element* new_element(end, nullptr, rhs);
    end = new_element;
    ++list_size;
}

template<class T>
T LinkedList<T>::pop_front() {
    T result = begin->content;
    Element* buff_begin = begin;
    begin->next->prev = nullptr;
    begin = begin->next;
    delete buff_begin;
    return result;
}

template<class T>
T LinkedList<T>::pop_back() {
    T result = end->content;
    Element* buff_end = end;
    end->prev->next = nullptr;
    end = end->prev;
    delete buff_end;
    return result;
}

#endif
