
#include <iostream>

//#include "c_array.h"
//#include "c_stack.h"
#include "c_tree.cpp"
//#include "c_linked_list.h"

/*template<typename T>
void outarr(Array<T>& a) {
	for(int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

}*/

int main() {
	/*Array<int> a = {2, 4, 5};
	outarr(a);
	Array<int> b = {2, 4 ,5, 8, 9};
	a.remove(2);
	outarr(a);*/
	
	/*int a = 3, b = 5, c = 9;
	Stack<int> stack;
	stack.push(a);
	stack.push(b);
	stack.push(c);

	std::cout << stack.top() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.pop() << std::endl;*/

	/*LinkedList<int> list;
	list.push_back(1);
	list.push_front(2);
	list.push_back(3);

	list.pop_back();
	//std::cout << list.front() << " " << list.back();*/
	

	Tree<int> tree;
	tree.add(7);
	/*tree.add(8);
	tree.add(9);
	tree.add(10);
	tree.add(11);
	tree.add(12);
	tree.add(13);


	std::cout << tree.root->content << std::endl;

	std::cout << tree.root->left->content << std::endl;
	std::cout << tree.root->right->content << std::endl;

		std::cout << tree.root->left->left->content << std::endl;
	std::cout << tree.root->left->right->content << std::endl;

		std::cout << tree.root->right->left->content << std::endl;
	std::cout << tree.root->right->right->content << std::endl;*/
	return 0;	
}