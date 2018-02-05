#ifndef CONTAINER_STACK
#define CONTAINER_STACK

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
	uint64_t stack_size = 0;
	int64_t max_size = -1;

public:
	Stack() {}
	Stack(int64_t max_size_arg) : max_size(max_size_arg) {}
	Stack(Stack& other);
	~Stack() { clear(); }

	void clear();
	void set_max_size(int64_t max_size_arg)
		{ max_size = max_size_arg; }
	uint64_t size() const noexcept { return stack_size; }
	bool empty() const noexcept { return !stack_size; }
	bool completed() const noexcept { return max_size != -1 &&stack_size >= max_size; }

	void swap(Stack<T>& other);

	void push(T& element) noexcept(false);
	void push(T&& element) noexcept(false);
	T& pop() noexcept(false);
	T& top() const;
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
	int64_t buffer_size = stack_size;
	int64_t buffer_max_size = max_size;

	root = other.root;
	stack_size = other.stack_size;
	max_size = other.max_size;

	other.root = buffer_root;
	other.stack_size = buffer_size;
	other.max_size = buffer_max_size;
}

template<class T>
void Stack<T>::push(T& element) {
	if(completed())
		throw std::overflow_error("The maximum stack size is reached!");
	Element* new_element = new Element(element, root);
	root = new_element;
	++stack_size;
}

template<class T>
void Stack<T>::push(T&& element) {
    if(completed())
        throw std::overflow_error("The maximum stack size is reached!");
    Element* new_element = new Element(element, root);
    root = new_element;
    ++stack_size;
}

template<class T>
T& Stack<T>::pop() noexcept(false) {
	if(empty()) throw std::length_error("No stack elements!");
	T result = root->element;
	Element* prev_root = root;
	root = root->next_element;
	delete prev_root;
	--stack_size;
	return result;
}

template<class T>
T& Stack<T>::top() const {
    if(empty()) throw std::length_error("No stack elements");
	return root->element;
}

#endif

