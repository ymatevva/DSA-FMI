#include <iostream>
#include "Priority_queue.hpp"

int main()
{
    PQ<int> pq;

    pq.push(3);
    pq.push(10);
    pq.push(0);

    std::cout << pq.peek();
}