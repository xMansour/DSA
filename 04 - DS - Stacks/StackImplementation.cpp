#include <iostream>
#include "Node.cpp"
#include "Stack.cpp"
using namespace std;

int main()
{
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.display();
    cout << "POP: " << stack.pop() << "\n";
    stack.display();
    stack.push(5);
    stack.push(6);
    stack.display();
    cout << "PEEK: " << stack.peek() << "\n";
    cout << "COUNT: " << stack.count() << "\n";
    cout << "FOUND: " << stack.isFound(8) << "\n";
}