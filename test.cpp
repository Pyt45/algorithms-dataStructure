#include <iostream>
#include <vector>
#include <forward_list>
#include <iterator>
#include <memory>
#include <list>
#include <thread>
#include <regex>
#include "./DataStructure/Matrix/Matrix.hpp"

typedef std::allocator<int> alloc;

template <class Iter>
void advanced_helper(Iter& p, int n, std::random_access_iterator_tag) {
    p += n;
}

template <class Iter>
void advanced_helper(Iter& p, int n, std::forward_iterator_tag) {
    if (n > 0)
        while (n--) ++p;
    else if (n < 0)
        while (n++) --p;
}

template <class Iter>
void advanced(Iter& p, int n) {
    advanced_helper(p, n, typename std::iterator_traits<Iter>::iterator_category{});
}

template <class Iter>
typename std::iterator_traits<Iter>::value_type read(Iter p, int n) {
    return p[n];
}

template<class Iter>
void __move(Iter& p, int n, std::bidirectional_iterator_tag) {
    if (n > 0)
        while (n--) ++p;
    else if (n < 0) 
        while (n++) --p;
}

template<class Iter>
void __move(Iter &p, int n, std::random_access_iterator_tag) {
    p += n;
}

template <class Iter>
void move(Iter& p, int n) {
    __move(p, n, typename std::iterator_traits<Iter>::iterator_category{});
}

void generic_algorithms() {
    alloc al;
    int arr1[] = { 1, 2, 3, 4, 5, 6 };
    std::vector<int> v(arr1, arr1 + 6);
    std::vector<int>::iterator it = v.begin();
    // advanced(it, 3);
    move(it, 3);

    std::cout << *it << std::endl;
    std::list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);
    l.push_back(5);
    l.push_back(6);

    std::list<int>::iterator t = l.begin();
    move(t, 3);
    std::cout << *t << std::endl;
    int *arr = al.allocate(5);
    for (int i = 0; i < 5; i++)
        al.construct(&arr[i], i);
    for (int i = 0; i < 5; i++)
        std::cout << arr[i] << std::endl;
    std::cout << "Not Error\n";
    std::cout << read(arr, 3) << std::endl;
}
/*
Regex:
    * 0 or more
    + 1 or more
    ? 0 or 1
    {n} exactly n
    {n, m} between n and m inclusive
    {n,} at least n
    \d numbers
    \w characters
    | alternative (or)
    $ end of line
    ^ start of line
    () grouping
    [] select area of characters
*/
void test_regex() {
    std::string s = "NJ01234-7895o";
    std::string s1 = "ABC";
    std::regex r{ R"((\w{2})(\d{5})(-\d{4})(\w{1}){1,})" };
    //std::regex r{ R"(^A*B+C?$)" };
    std::smatch rst;
    std::regex_match(s, rst, r);
    std::cout << rst[0] << std::endl;
    std::cout << rst[1] << std::endl;
    std::cout << rst[2] << std::endl;
    std::cout << rst[3] << std::endl;
    //std::cout << rst[4] << std::endl;
}
int main() {
    nds::Matrix<int, 3, 3> m;
    m.insert(0, 0, 0);
    m.insert(0, 1, 1);
    m.insert(0, 2, 2);

    m.insert(1, 0, 3);
    m.insert(1, 1, 4);
    m.insert(1, 2, 5);

    m.insert(2, 0, 6);
    m.insert(2, 1, 7);
    m.insert(2, 2, 8);
    m.print_matrix();
}