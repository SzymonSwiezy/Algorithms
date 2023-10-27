#include <iostream>
#include <map>
#include <string>

class Union{
private:
    std::map<int, int> unionMap;
public:
    void createUnion(int element1, int element2);
    bool connected(int element1, int element2);
    void createTable(std::vector<int>);
    void printTable(void);
};

int main(void)
{
    Union un;
    std::vector<int> table = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    un.createTable(table);
    un.printTable();
    un.createUnion(4, 3);
    un.createUnion(3, 8);
    un.createUnion(6, 5);
    un.createUnion(9, 4);
    un.createUnion(2, 1);

    std::cout << un.connected(0, 7) << "\n" << un.connected(8, 9) << "\n";
    
    return 0;
}

bool Union::connected(int element1, int element2)
{
        bool rV = false;
        if( this->unionMap[element1] == this->unionMap[element2] ) rV = true;
        return rV;
}

void Union::printTable()
{
    std::map <int, int> :: iterator itr;
    itr = this->unionMap.begin();
    for(; itr != this->unionMap.end() ; ++itr)
    {
        std::cout << itr->first << "\t" << itr->second << std::endl;
    }
    
}

void Union::createTable(std::vector<int> table)
{
    size_t len = table.size();
    for(int idx = 0; idx < len ; idx++)
    {
        this->unionMap.insert(std::pair <int, int> (table[idx], idx));
    }
}

void Union::createUnion(int element1, int element2)
{
    int id1 = this->unionMap[element1];
    for (auto iterator : this->unionMap)
    {
        if(iterator.second == id1)
        {
            this->unionMap[iterator.first] = this->unionMap[element2];
        }
    }
}
