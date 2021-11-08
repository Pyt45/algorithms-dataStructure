#include "../List/DoubleLinkedList.hpp"
#include <string>

int main() {
    nds::DoubleLinkedList<int> dl;

    dl.push_back(1);
    dl.traverse_forward();
}