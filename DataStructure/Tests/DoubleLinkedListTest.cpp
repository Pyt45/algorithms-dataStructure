#include "../List/DoubleLinkedList.hpp"
#include <string>

int main() {
    nds::DoubleLinkedList<int> dl;
    nds::DoubleLinkedList<int> dl1;

    std::cout << "==== push back test ====\n";

    dl.push_back(1);
    dl.push_back(2);
    dl.push_back(3);
    dl.push_back(4);
    dl.traverse_forward();
    std::cout << "==== push back test ====\n";
    dl1.push_front(1);
    dl1.push_front(2);
    dl1.push_front(3);
    dl1.push_front(4);

    dl1.traverse_forward();
}