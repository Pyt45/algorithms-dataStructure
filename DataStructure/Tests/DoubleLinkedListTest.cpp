#include "../List/DoubleLinkedList.hpp"
#include <string>

int main() {
    nds::DoubleLinkedList<int> dl;

    dl.push_back(1);
    dl.push_back(2);
    dl.push_back(3);
    dl.push_back(4);
    dl.traverse_forward();
}