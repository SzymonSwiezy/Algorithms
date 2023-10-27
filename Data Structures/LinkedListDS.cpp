#include <iostream>

struct Node
{
public:
    int data;
    Node* next;
};

class LinkedList
{
private:
    Node* node;
    int size;
    
public:
    LinkedList()
    {
        this->node = nullptr;
        this->size = 0;
    }
    
    inline bool isEmpty()
    {
        return this->node == nullptr;
    }
    
    int getSize()
    {
        return this->size;
    }
    
    void push_back(int data)
    {
        Node* oldNode = this->node;
        node = new Node;
        node->data = data;
        node->next = oldNode;
        this->size++;
    }
    
    int pop()
    {
        int data = this->node->data;
        this->node = node->next;
        this->size--;
        return data;
    }
};

class Queue
{
private:
    // Local variables
    Node* first;
    Node* last;
    int size;
    
public:
    Queue(void)
    {
        this->size = 0;
        this->first = nullptr;
        this->last = nullptr;
    }
    
    inline bool isEmpty(void)
    {
        return this->first == nullptr;
    }
    
    void enqueue(int data)
    {
        Node* oldNode = this->last;
        this->last = new Node();
        this->last->data = data;
        
        if(isEmpty()) this->first = this->last;
        else oldNode->next = this->last;
    }
    
    int dequeue(void)
    {
        int data = this->first->data;
        this->first = this->first->next;
        if(isEmpty()) this->last = nullptr;
        return data;
    }
};

int main(int argc, const char * argv[])
{
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    
    while(!list.isEmpty())
    {
        std::cout << list.pop() << "\n";
    }
    
    Queue queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.enqueue(6);
    
    while(!queue.isEmpty())
    {
        std::cout << queue.dequeue() << "\n";
    }
    

    return 0;
}
