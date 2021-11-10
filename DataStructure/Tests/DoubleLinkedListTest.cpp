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
    dl.push_back(5);
    //dl.unlink_node(1);
    //dl.unlink_node(2);
    //dl.unlink_node(3);
    //dl.unlink_node(4);
    //dl.unlink_node(5);
    dl.traverse_forward();
    // 1 2 3 4 5
    /*std::cout << "==== push back test ====\n";
    dl1.push_front(1);
    dl1.push_front(2);
    dl1.push_front(3);
    dl1.push_front(4);

    dl1.traverse_forward();*/
}