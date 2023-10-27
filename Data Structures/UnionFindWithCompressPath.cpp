#include <iostream>

class UnionTree
{
private:
    int* parent;
    int* rank;
    int max;
    
public:
    UnionTree(int N=10);
    ~UnionTree();
    
    void unionElements(int element1, int element2);
    bool connected(int element1, int element2);
    int findRoot(int element);
    int getMaxDepth(void);
};

UnionTree::UnionTree(int N)
{
    this->parent = new int[N];
    this->rank = new int[N]{};
    this->max = 0;
    for(int idx = 0; idx < N; idx++)
    {
        this->parent[idx] = idx;
    }
}

UnionTree::~UnionTree()
{
    delete [] this->parent;
    delete [] this->rank;
}

void UnionTree::unionElements(int element1, int element2)
{
    if(findRoot(element1) != findRoot(element2))
    {
        if((this->rank[element1]) > (this->rank[element2]))
        {
            this->parent[element2] = this->parent[element1];
        }
        else if((this->rank[element2]) > (this->rank[element1]))
        {
            this->parent[element1] = this->parent[element2];
        }
        else
        {
            this->parent[element1] = this->parent[element2];
            this->rank[element2]++;
        }
    }
    return;
}

int UnionTree::findRoot(int element)
{
    int root = this->parent[element];
    if(element != root)
    {
        this->parent[element] = this->findRoot(this->parent[element]);
    }
    return root;
}

bool UnionTree::connected(int element1, int element2)
{
    return findRoot(element2) == findRoot(element1);
}

int main(int argc, const char * argv[]) {
    UnionTree unions;
    
    unions.unionElements(1, 2);
    unions.unionElements(2, 3);
    unions.unionElements(4, 5);
    unions.unionElements(6, 7);
    unions.unionElements(5, 6);
    
    std::cout << unions.connected(3, 7) << " root: " << unions.findRoot(9) << "\n";
    unions.unionElements(3, 7);
    std::cout << unions.connected(3, 7) << " root: " << unions.findRoot(9) << "\n";

}
