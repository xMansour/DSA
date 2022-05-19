#include <iostream>
#include "Node.cpp"
#include "Queue.cpp"

using namespace std;

int main()
{
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.display();
    queue.dequeue();
    queue.dequeue();
    queue.display();
    cout << "COUNT: " << queue.count() << "\n";
    cout << "Found: " << queue.isFound(5) << "\n";
    queue.clear();
    queue.display();
}