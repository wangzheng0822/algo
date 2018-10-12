#include <iostream>
#include "dynamic_array_queue.hpp"

int main() {
    auto do_traverse = [&](auto item){ std::cout << item << ' '; };

    DynamicArrayQueue<int> dynamic_array_queue_1(3);
    dynamic_array_queue_1.enqueue(1);
    dynamic_array_queue_1.enqueue(2);
    dynamic_array_queue_1.enqueue(3);
    // dynamic_array_queue_1.enqueue(4);  // throw
    dynamic_array_queue_1.traverse(do_traverse);
    std::cout << std::endl;

    DynamicArrayQueue<int> dynamic_array_queue_2(dynamic_array_queue_1);  // copy constructor
    dynamic_array_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    DynamicArrayQueue<int> dynamic_array_queue_3(std::move(dynamic_array_queue_2));  // move constructor
    dynamic_array_queue_3.traverse(do_traverse);
    std::cout << std::endl;
    dynamic_array_queue_2.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << dynamic_array_queue_3.head() << std::endl;
    dynamic_array_queue_3.dequeue();
    std::cout << dynamic_array_queue_3.head() << std::endl;
    dynamic_array_queue_3.dequeue();
    std::cout << dynamic_array_queue_3.head() << std::endl;
    dynamic_array_queue_3.dequeue();
    // std::cout << dynamic_array_queue_3.head() << std::endl;  // throw
    // dynamic_array_queue_3.dequeue();  // throw

    DynamicArrayQueue<int> dynamic_array_queue_4(1);
    dynamic_array_queue_4 = dynamic_array_queue_1;  // copy assignment
    dynamic_array_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    DynamicArrayQueue<int> dynamic_array_queue_5(100);
    dynamic_array_queue_5 = std::move(dynamic_array_queue_4);  // move assignment
    dynamic_array_queue_5.traverse(do_traverse);
    std::cout << std::endl;
    dynamic_array_queue_4.traverse(do_traverse);
    std::cout << std::endl;

    std::cout << dynamic_array_queue_5.head() << std::endl;
    dynamic_array_queue_5.dequeue();
    std::cout << dynamic_array_queue_5.head() << std::endl;
    dynamic_array_queue_5.dequeue();
    std::cout << dynamic_array_queue_5.head() << std::endl;
    dynamic_array_queue_5.dequeue();
    // std::cout << dynamic_array_queue_5.head() << std::endl;  // throw
    // dynamic_array_queue_5.dequeue();  // throw

    for (size_t i = 0; i != 3; ++i) {
        dynamic_array_queue_1.dequeue();
        dynamic_array_queue_1.enqueue(i + 4);
        dynamic_array_queue_1.traverse(do_traverse);
        std::cout << std::endl;
    }
    return 0;
}
