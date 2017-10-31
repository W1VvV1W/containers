#include "vector.h"
#include <iostream>

using namespace containers;

template<class T>
void outarr(vector<T>& v) {
	std::cout << "------------" << std::endl;
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << std::endl;
	for(int i = 0; i < v.capacity(); ++i)
		std::cout << v[i] << "\t";
	std::cout << std::endl << "------------" << std::endl;
}

int main() {
	vector<int> test(4);

	test.push_back(1);
	test.push_back(3);
	test.insert(4, 5);
	outarr<int>(test);

	std::cout << test.pop_back() << std::endl;
	outarr<int>(test);

	test.erase(1);
	outarr<int>(test);

	test[1] = 8;
	outarr<int>(test);

	vector<int> test2 = {1, 7, 8, 2, 43};
	outarr<int>(test2);

	test2.reserve(10);
	outarr<int>(test2);

	test2.erase(2,5);
	outarr<int>(test2);

	test2 = {1, 7, 9, 3};
	outarr<int>(test2);
	return 0;
}
