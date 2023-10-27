#include <iostream>

/* 
 Union too expensive
 takes N^2 arrau accesses to process sequence of N union commands on N objects.
*/
class QuickFindUF
{
private:
    int *id = nullptr;
    int size = 0;
public:
    QuickFindUF(int N = 0)
    {
        this->size = N;
        this->id = new int[N];
        for(int idx = 0; idx < N; idx++)
        {
            id[idx] = idx;
        }
    }
    
    bool connected(int p, int q)
    {
        return id[p] == id[q];
    }
    
    void createUnion(int p, int q)
    {
        int pid = id[p];
        int qid = id[q];
        for( int idx = 0; idx < this->size; idx++ )
        {
            if( this->id[idx] == pid )
            {
                this->id[idx] = qid;
            }
        }
    }
};

int main()
{
    QuickFindUF un(10);
    
    un.createUnion(4, 3);
    un.createUnion(3, 8);
    un.createUnion(6, 5);
    un.createUnion(9, 4);
    un.createUnion(2, 1); 

    std::cout << un.connected(0, 7) << "\n" << un.connected(8, 9) << "\n";
    
    return 0;
}
