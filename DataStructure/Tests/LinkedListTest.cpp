#include "../List/LinkedList.hpp"
#include <string>

template<class T>
void push_back_test(const T val[], size_t N) {
	nds::LinkedList<T> l;
	for (size_t i = 0; i < N; i++)
		l.push_back(val[i]);
	l.traverse_node();
}

template<class T>
void push_front_test(const T val[], size_t N) {
	nds::LinkedList<T> l;
	for (size_t i = 0; i < N; i++)
		l.push_front(val[i]);
	l.traverse_node();
}

template<class T>
void delete_test(const T val[], size_t N) {
	nds::LinkedList<T> *l = new nds::LinkedList<T>();
	for (size_t i = 0; i < N; i++)
		l->push_back(val[i]);
	l->traverse_node();
	delete l;
	std::cout << "size of list: " << l->size() << std::endl;
}

auto main() -> int{
	std::cout << "==== push back test ====\n";
	int arr[] = {1, 2, 3, 4, 5};
    push_back_test<int>(arr, sizeof(arr) / sizeof(int));
	std::cout << "==== push front test ====\n";
	std::string arr1[] = {"a", "b", "c", "d", "e", "f"};
	push_front_test<std::string>(arr1, sizeof(arr1) / sizeof(std::string));
	std::cout << "==== delete test ====\n";
	delete_test<std::string>(arr1, sizeof(arr1) / sizeof(std::string));
	return 0;
}