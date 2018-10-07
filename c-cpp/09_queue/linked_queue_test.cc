#include <iostream>
#include "linked_queue.hpp"

int main() {
    auto do_traverse = [&](auto item){ std::cout << item << ' '; };

    LinkedQueue<int> linked_queue_1;
    linked_queue_1.enqueue(1);
    linked_queue_1.enqueue(2);
    linked_queue_1.enqueue(3);
    linked_queue_1.traverse(do_traverse);
    std::cout << std::endl;

    LinkedQueue<int> linked_queue_2(linked_queue_1);  // copy constructor
    linked_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    LinkedQueue<int> linked_queue_3(std::move(linked_queue_2));  // move constructor
    linked_queue_3.traverse(do_traverse);
    std::cout << std::endl;
    linked_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << linked_queue_3.head() << std::endl;
    linked_queue_3.dequeue();
    std::cout << linked_queue_3.head() << std::endl;
    linked_queue_3.dequeue();
    std::cout << linked_queue_3.head() << std::endl;
    linked_queue_3.dequeue();
    // std::cout << linked_queue_3.head() << std::endl;  // throw
    // linked_queue_3.dequeue();  // throw

    LinkedQueue<int> linked_queue_4;
    linked_queue_4 = linked_queue_1;  // copy assignment
    linked_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    LinkedQueue<int> linked_queue_5;
    linked_queue_5 = std::move(linked_queue_4);  // move assignment
    linked_queue_5.traverse(do_traverse);
    std::cout << std::endl;
    linked_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << linked_queue_5.head() << std::endl;
    linked_queue_5.dequeue();
    std::cout << linked_queue_5.head() << std::endl;
    linked_queue_5.dequeue();
    std::cout << linked_queue_5.head() << std::endl;
    linked_queue_5.dequeue();
    // std::cout << linked_queue_5.head() << std::endl;  // throw
    // linked_queue_5.dequeue();  // throw

    return 0;
}
