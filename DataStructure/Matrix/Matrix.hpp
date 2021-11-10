#pragma once
#include <iostream>
#include <memory>
#include <utility>

namespace nds {
	template< class T, size_t N, size_t M, class Alloc = std::allocator<T> >
	class Matrix {
		public:
			typedef T value_type;
			typedef size_t size_type;
			typedef Alloc allocator_type;
			typedef T* pointer;
			typedef T** d_pointer;
			typedef typename Alloc::template rebind< pointer >::other __p_alloctor;
		private:
			T**				__matrix;
			allocator_type	__alloc;
			__p_alloctor	__p_alloc;
			size_type		__size;
			size_type		__cap;
		public:
			Matrix(const allocator_type& alloc = allocator_type()){
				__alloc = alloc;
				__cap = N * M;
				__matrix = static_cast<T**>(__p_alloc.allocate(N));
				for (__size = 0; __size < N; __size++) {
					__matrix[__size] = static_cast<T*>(__alloc.allocate(M));
					for (size_type j = 0; j < M; j++)
						__alloc.construct(&__matrix[__size][j], value_type());
				}
			}
			Matrix(const value_type& val) {
				__cap = N * M;
				__matrix = static_cast<T**>(__p_alloc.allocate(N));
				for (__size = 0; __size < N; __size++) {
					__matrix[__size] = static_cast<T*>(__alloc.allocate(M));
					for (size_type j = 0; j < M; j++)
						__alloc.construct(&__matrix[__size][j], val);
				}
			}
			Matrix(d_pointer mtx) {
				__cap = N * M;
				__matrix = static_cast<T**>(__p_alloc.allocate(N));
				for (__size = 0; __size < N; __size++) {
					__matrix[__size] = static_cast<T*>(__alloc.allocate(M));
					for (size_type j = 0; j < M; j++)
						__alloc.construct(&__matrix[__size][j], mtx[__size][j]);
				}
			}
			~Matrix() {
				for (size_type i = 0; i < N; i++) {
					__alloc.destroy(__matrix[i]);
					__alloc.deallocate(__matrix[i], M);
				}
				__p_alloc.deallocate(__matrix, N);
			}
			void print_matrix() {
				for (size_type i = 0; i < N; i++) {
					for (size_type j = 0; j < M; j++) {
						if (j == M - 1)
							std::cout << __matrix[i][j];
						else
							std::cout << __matrix[i][j] << " |";
					}
					if (i != N - 1)
						std::cout << "\n── ── ──\n";
				}
				std::cout << std::endl;
			}
			void insert(size_type row, size_type column, size_type val) {
				__matrix[row][column] = val;
			}
	};
}