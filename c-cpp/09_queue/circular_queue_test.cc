#include <iostream>
#include "circular_queue.hpp"

int main() {
    auto do_traverse = [&](auto item){ std::cout << item << ' '; };

    CircularQueue<int> circular_queue_1(4);
    circular_queue_1.enqueue(1);
    circular_queue_1.enqueue(2);
    circular_queue_1.enqueue(3);
    // circular_queue_1.enqueue(4);  // throw
    circular_queue_1.traverse(do_traverse);
    std::cout << std::endl;

    CircularQueue<int> circular_queue_2(circular_queue_1);  // copy constructor
    circular_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    CircularQueue<int> circular_queue_3(std::move(circular_queue_2));  // move constructor
    circular_queue_3.traverse(do_traverse);
    std::cout << std::endl;
    circular_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << circular_queue_3.head() << std::endl;
    circular_queue_3.dequeue();
    std::cout << circular_queue_3.head() << std::endl;
    circular_queue_3.dequeue();
    std::cout << circular_queue_3.head() << std::endl;
    circular_queue_3.dequeue();
    // std::cout << circular_queue_3.head() << std::endl;  // throw
    // circular_queue_3.dequeue();  // throw

    CircularQueue<int> circular_queue_4(1);
    circular_queue_4 = circular_queue_1;  // copy assignment
    circular_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    CircularQueue<int> circular_queue_5(100);
    circular_queue_5 = std::move(circular_queue_4);  // move assignment
    circular_queue_5.traverse(do_traverse);
    std::cout << std::endl;
    circular_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << circular_queue_5.head() << std::endl;
    circular_queue_5.dequeue();
    std::cout << circular_queue_5.head() << std::endl;
    circular_queue_5.dequeue();
    std::cout << circular_queue_5.head() << std::endl;
    circular_queue_5.dequeue();
    // std::cout << circular_queue_5.head() << std::endl;  // throw
    // circular_queue_5.dequeue();  // throw

    for (size_t i = 0; i != 4; ++i) {
        circular_queue_1.dequeue();
        circular_queue_1.enqueue(i + 4);
        circular_queue_1.traverse(do_traverse);
        std::cout << std::endl;
    }
    return 0;
}
