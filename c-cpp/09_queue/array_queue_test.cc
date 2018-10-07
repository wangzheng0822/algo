#include <iostream>
#include "array_queue.hpp"

int main() {
    auto do_traverse = [&](auto item){ std::cout << item << ' '; };

    ArrayQueue<int> array_queue_1(3);
    array_queue_1.enqueue(1);
    array_queue_1.enqueue(2);
    array_queue_1.enqueue(3);
    // array_queue_1.enqueue(4);  // throw
    array_queue_1.traverse(do_traverse);
    std::cout << std::endl;

    ArrayQueue<int> array_queue_2(array_queue_1);  // copy constructor
    array_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    ArrayQueue<int> array_queue_3(std::move(array_queue_2));  // move constructor
    array_queue_3.traverse(do_traverse);
    std::cout << std::endl;
    array_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << array_queue_3.head() << std::endl;
    array_queue_3.dequeue();
    std::cout << array_queue_3.head() << std::endl;
    array_queue_3.dequeue();
    std::cout << array_queue_3.head() << std::endl;
    array_queue_3.dequeue();
    // std::cout << array_queue_3.head() << std::endl;  // throw
    // array_queue_3.dequeue();  // throw

    ArrayQueue<int> array_queue_4(1);
    array_queue_4 = array_queue_1;  // copy assignment
    array_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    ArrayQueue<int> array_queue_5(100);
    array_queue_5 = std::move(array_queue_4);  // move assignment
    array_queue_5.traverse(do_traverse);
    std::cout << std::endl;
    array_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << array_queue_5.head() << std::endl;
    array_queue_5.dequeue();
    std::cout << array_queue_5.head() << std::endl;
    array_queue_5.dequeue();
    std::cout << array_queue_5.head() << std::endl;
    array_queue_5.dequeue();
    // std::cout << array_queue_5.head() << std::endl;  // throw
    // array_queue_5.dequeue();  // throw

    return 0;
}
