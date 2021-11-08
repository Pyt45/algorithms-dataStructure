#pragma once

#include <iostream>
#include <memory>

namespace nds {
	template<class T>
	class Node {
		public:
			T		__data;
			Node	*__prev;
			Node	*__next;
		public:
			Node(): __data(), __prev(nullptr), __next(nullptr) {}
			Node(const T& data): __data(data), __prev(nullptr), __next(nullptr) {}
			Node(const Node& rhs) {
				*this = rhs;
			}
			Node& operator==(const Node& rhs) {
				if (this != &rhs) {
					this->__data = rhs.__data;
					this->__prev = rhs.__prev;
					this->__next = rhs.__next;
				}
				return *this;
			}
			~Node() {}
	};
	template < class T, class Alloc = std::allocator<T> >
	class DoubleLinkedList {
		
	};
}