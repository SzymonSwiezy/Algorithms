/*
 * MIN Heap implementation
 */
#include <iostream>
#define HEAPSIZE 10
class MinHeap
{
private:
    int* array;
    int heapSize;
    int maxSize;
public:
    MinHeap();
    MinHeap(int N);
    
    void insertKey(int key);
    int extractMin();
    void minHeapify(int index);
    int parentNode(int index);
    void deleteKey(int index);
    void decreaseKey(int index, int value = INT_MIN);
    
    int leftNode(int index);
    int rightNode(int index);
    bool linearSearch(int val);
    void print();
    int heapDepth();
    
};

MinHeap::MinHeap()
{
    this->array = new int(HEAPSIZE);
    this->heapSize = HEAPSIZE;
    this->maxSize = HEAPSIZE;
}
MinHeap::MinHeap(int N)
{
    this->array = new int[N];
    this->heapSize = 0;
    this->maxSize = N;
}

bool MinHeap::linearSearch(int val)
{
    bool rV = false;
    int index = this->heapSize;
    
    while(--index)
    {
        if(this->array[index] == val)
        {
            rV = true;
            break;
        }
        
    }
    return rV;
}

void MinHeap::minHeapify(int index)
{
    int leftindex = this->leftNode(index);
    int rightindex = this->rightNode(index);
    int smallest = index;
    
    if((leftindex < this->heapSize) && (this->array[leftindex]) < this->array[smallest]) smallest = leftindex;
    if((rightindex < this->heapSize) && (this->array[rightindex]) < this->array[smallest]) smallest = rightindex;
    if(smallest != index)
    {
        std::swap(this->array[smallest], this->array[index]);
        minHeapify(smallest);
    }
}

void MinHeap::insertKey(int key)
{
    if(this->maxSize == this->heapSize) return;
    
    this->heapSize++;
    int index = this->heapSize-1;
    this->array[index] = key;
    
    while((index != 0) && (this->array[this->parentNode(index)] > key))
    {
        std::swap(this->array[this->parentNode(index)], this->array[index]);
        index = this->parentNode(index);
    }
}

void MinHeap::decreaseKey(int index, int value)
{
    this->array[index] = value;
    while((index != 0) && (this->array[this->parentNode(index)] > this->array[index]))
    {
        std::swap(this->array[this->parentNode(index)], this->array[index]);
        index = this->parentNode(index);
    }
}

void MinHeap::deleteKey(int index)
{
    this->decreaseKey(index, -1);
    this->extractMin();
}

int MinHeap::extractMin()
{
    int rV = 0;
    if(this->heapSize == 0)
    {
        rV = INT_MAX;
    }
    else if(this->heapSize == 1)
    {
        this->heapSize--;
        rV = this->array[0];
    }

    rV = this->array[0];
    this->array[0] = this->array[this->heapSize - 1];
    this->heapSize--;
    minHeapify(0);

    return rV;
}

void MinHeap::print()
{
    for(size_t index = 0; index < this->heapSize; index++)
    {
        std::cout << this->array[index] << '\n';
    }
}

int MinHeap::parentNode(int index)
{
    return (index-1)/2;
}

int MinHeap::leftNode(int index)
{
    return (index*2)+1;
}

int MinHeap::rightNode(int index)
{
    return (index*2)+2;
}

int main(int argc, const char * argv[])
{
    MinHeap heap(10);
    
    heap.insertKey(5);
    heap.insertKey(8);
    heap.insertKey(7);
    heap.insertKey(3);
    heap.insertKey(5);
    heap.insertKey(8);
    heap.insertKey(7);
    heap.insertKey(3);
    
    heap.print();
    std::cout<< "\n~~~~~~~~~~~~ MIN ~~~~~~~~~~~~\n" << heap.extractMin() << "\n~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    heap.print();
    
    std::cout<< "\n~~~~~~~~~~~~ DELETE KEY ~~~~~~~~~~~~\n";
    heap.deleteKey(5);
    heap.print();

    


    return 0;
}
