#include <iostream>
#include <deque>
#include <stack>
#include <queue>

int main(){
    // The deque is a double-ended queue
    // Both vectors and deques provide a very similar interface and can be used for similar purposes
    // but internally both work in quite different ways
    // Unlike vectors, deques are not guaranteed to store all its elements in contiguous storage locations
    // Deques are a little more complex internally than vectors, but this allows them to grow more 
    // efficiently under certain circumstances, especially with very long sequences

    // A deque can still access elements by index, however,
    // attempting to access an element by incrementing a pointer to a previous element causes
    // undefined behavior
    std::deque<int> d {1, 2, 3, 4};
    d.push_front(5);
    int* i = &d[0];
    std::cout << *(i + 2) << std::endl;
    // undefined

    // For operations that involve frequent insertion or removal of elements, 
    // at positions other than the beginning or the end, 
    // deques perform worse and have less consistent iterators and references than lists and forward lists

    // queue
    // A queue is an adapter container that overlays a deque (or another compatible type)
    // They are specifically designed to operate in a FIFO context (First In First Out), 
    // where elements are inserted into one end of the container and extracted from the other
    // Elements are pushed into the "back" of the specific container and popped from its "front"
    
    // stack 
    // A stack is also an adapter container that overlays a deque (or another compatible type)
    // Specifically designed to operate in a LIFO context (Last In First Out), where elements are inserted and 
    // extracted only from one end of the container Elements are pushed/popped 
    // from the "back" of the specific container, 
    // which is known as the top of the stack

    // priority queue
    // Priority queues are just like regular queues with one exception
    // Specifically designed such that its first element is always the greatest of the elements it contains,
    // according to some strict weak ordering criterion Elements can be inserted at any moment
    // and only the max heap element can be retrieved
    // These overlay a vector by default, instead of a deque


    // Deque
    std::deque<int> transactions {1, 2, 3, 4};

    // push front adds to the beginning of the queue
    transactions.push_front(100);
    transactions.push_front(300);
    // push backs back adds to the end of the queue
    transactions.push_back(500);
    transactions.push_back(800);

    int* i = &transactions[0];
    std::cout << *(i + 2) << std::endl;
    for (unsigned int i = 0; i < transactions.size(); i++) {
    std::cout << transactions[i] << " ";
    }
    // the output will be : 300, 100, 500 , 800
    std::cout << "\n";

    // Stack
    std::stack<int> stack;

    stack.push(100);
    stack.push(200);
    stack.push(300);
    stack.push(400);
    // there's no way to iterate over the stack
    // because the stack is an adapter container type
    while(!stack.empty()) {
      std::cout << stack.top() << " ";
      stack.pop();
    }
    // the output will be : 400, 300, 200, 100
    std::cout << "\n";


    // Queue
    std::queue<int> queue;
    queue.push(100);
    queue.push(200);
    queue.push(300);
    queue.push(400);

    while(!queue.empty()) {
      std::cout << queue.front() << " ";
      queue.pop();
    }
    // the output will be : 100, 200, 300, 400
    std::cout << "\n";

    // Priority Queue
    std::priority_queue<int> pqueue;
    pqueue.push(200);
    pqueue.push(600);
    pqueue.push(100);
    pqueue.push(400);
    pqueue.push(40);
    pqueue.push(3000);

    while(!pqueue.empty()) {
      std::cout << pqueue.top() << " ";
      pqueue.pop();
    }
    // the output will be: 3000, 600, 400, 200, 100, 40
    // it sorts itself
    std::cout << "\n";

}