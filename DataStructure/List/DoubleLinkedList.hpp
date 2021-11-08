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
		public:
			typedef T value_type;
			typedef size_t size_type;
			typedef Node<T>* __pointer;
			typedef typename Alloc::template rebind< Node<T> >::other __node_allocator;
		private:
			__node_allocator __alloc;
			size_type __size;
			__pointer __head;
			__pointer __tail;
		public:
			DoubleLinkedList() {
				__head = __tail = nullptr;
				__size = 0;
			}
			~DoubleLinkedList() {}
			void push_back(const T& val) {
				__pointer node = __alloc.allocate(1);
				__alloc.construct(node, val);
				if (node) {
					if (__head == nullptr) {
						__head = __tail = node;
						__size++;
					}
				}
			}
			void push_front(const T& val) {}
			void traverse_forward() {
				__pointer tmp = __head;
				while (tmp) {
					std::cout << tmp->__data << std::endl;
					tmp = tmp->__next;
				}
			}
			void traverse_backward() {
				__pointer tmp = __tail;
				while (tmp) {
					std::cout << tmp->__data << std::endl;
					tmp = tmp->__prev;
				}
			}
			__pointer find(const T& val);
			void destory_node(const T& val);
			size_type size() const {
				return __size;
			}
	};
}