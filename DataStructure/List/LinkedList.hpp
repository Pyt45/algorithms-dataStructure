#pragma once

#include <iostream>
#include <memory>

namespace nds {
	template<class T>
	class Node {
		public:
			typedef T value_type;
		public:
			value_type	__data;
			Node*		__next;
			Node(): __next(nullptr), __data() {}
			Node(value_type data): __next(nullptr), __data(data) {}
			Node(const Node& rhs) {
				*this = rhs;
			}
			Node& operator=(const Node& rhs) {
				if (this != &rhs) {
					this->__data = rhs.__data;
					this->__next = rhs.__next;
				}
				return *this;
			}
			~Node() {}
	};
	template< class T, class Alloc = std::allocator<T> >
	class LinkedList {
		public:
			typedef T value_type;
			typedef Node<T>* iterator;
			typedef Node<T>* __pointer;
			typedef typename Alloc::template rebind < Node<T> >::other __node_allocator;
			typedef size_t size_type;
		private:
			__node_allocator __alloc;
			__pointer __root;
			size_type __size;
		public:
			LinkedList() {
				__root = nullptr;
				__size = 0;
			}
			~LinkedList() {
				__pointer tmp = __root;
				__pointer next;
				while (tmp) {
					next = tmp->__next;
					__alloc.destroy(tmp);
					__alloc.deallocate(tmp, 1);
					tmp = next;
				}
			}
			void push_front(const T& val) {
				__pointer node = __alloc.allocate(1);
				__alloc.construct(node, val);
				if (node) {
					if (__root == nullptr) {
						__root = node;
						__size = 1;
					} else {;
						node->__next = __root;
						__root = node;
						__size++;
					}
				}
			}
			void traverse_node() {
				__pointer tmp = __root;
				while (tmp) {
					std::cout << tmp->__data << std::endl;
					tmp = tmp->__next;
				}
			}
			void push_back(const T& val) {
				__pointer node = __alloc.allocate(1);
				__alloc.construct(node, val);
				if (node) {
					if (__root == nullptr) {
						__root = node;
						__size = 1;
					} else {
						__pointer tmp = __root;
						while (tmp && tmp->__next)
							tmp = tmp->__next;
						tmp->__next = node;
						__size++;
					}
				}
			}
			__pointer find(const T& val) {
				__pointer tmp = __root;
				while (tmp && tmp->__data != val)
					tmp = tmp->__next;
				return tmp;
			}
			void destroy_node(const T& val) {
				__pointer node_to_del = find(val);
				if (node_to_del) {
					if (node_to_del == __root) {
						__root = node_to_del->__next;
						__alloc.destroy(node_to_del);
						__alloc.deallocate(node_to_del, 1);
						__size--;
					}
					else {
						__pointer tmp = __root;
						while (tmp && tmp->__next != node_to_del) {
							tmp = tmp->__next;
						}
						if (node_to_del->__next) {
							tmp->__next = node_to_del->__next;
							__alloc.destroy(node_to_del);
							__alloc.deallocate(node_to_del, 1);
						}
						else {
							__alloc.destroy(node_to_del);
							__alloc.deallocate(node_to_del, 1);
							tmp->__next = nullptr;
						}
						__size--;
					}
				}
			}
			size_type size() const {
				return __size;
			}
	};
}