#ifndef CONTAINER_STACK
#define CONTAINER_STACK

#include <cstddef>
#include <initializer_list>
#include <stdexcept>

template<class T>
class Stack {

	struct Element {
		T element;
		Element* next_element;
		Element(T& element_arg, Element* next)  {
			element = element_arg;
			next_element = next;
		}
	};

	Element* root = nullptr;
	std::size_t stack_size;
	std::size_t max_size = -1;

public:
	Stack() {}
	Stack(std::size_t max_size_arg) : max_size(max_size_arg) {}
	Stack(Stack& other); 
	~Stack() { clear(); }

	void clear();
	void set_max_size(std::size_t max_size_arg) 
		{ max_size = max_size_arg; }
	std::size_t size() const noexcept { return stack_size; }
	bool empty() const noexcept { return !stack_size; }

	void swap(Stack<T>& other);

	void push(T& element);
	T pop() const noexcept;
	T top();
};


template<class T>
Stack<T>::Stack(Stack& other)  {
	root = other.root;
	stack_size = other.stack_size;
	max_size = other.max_size;
}

template<class T>
void Stack<T>::clear() {
	Element* buffer;
	while(root != nullptr) {
		buffer = root;
		root = root->next_element;
		delete buffer;
	}
}

template<class T>
void Stack<T>::swap(Stack<T>& other) {
	Element* buffer_root = root;
	std::size_t buffer_size = stack_size;
	std::size_t buffer_max_size = max_size;

	root = other.root;
	stack_size = other.stack_size;
	max_size = other.max_size;

	other.root = buffer_root; 
	other.stack_size = buffer_size;
	other.max_size = buffer_max_size;
}

template<class T>
void Stack<T>::push(T& element) {
	if(max_size != -1 &&stack_size >= max_size)
		throw std::overflow_error("The maximum stack size is reached!");
	Element* new_element = new Element(element, root);
	root = new_element;
	++stack_size;
}

template<class T>
T Stack<T>::pop() const noexcept {
	if(empty()) throw std::length_error("No stack elements!");
	T result = root->element;
	Element* prev_root = root;
	root = root->next_element;
	delete prev_root;
	//stack_size -= 1; // Компилятор запрещает декремент, фиг с ним.
	return result;
}

template<class T>
T Stack<T>::top() {
	return root->element;
}


#endif
