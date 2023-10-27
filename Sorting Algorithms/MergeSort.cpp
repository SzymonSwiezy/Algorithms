#include <iostream>
#include <vector>

void merge(std::vector<int> &tab, int first, int middleIdx, int last)
{
    std::vector<int> tempTable;
    int left = first;
    int right = middleIdx+1;
    
    while(left <= middleIdx && right<=last)
    {
        if(tab[left]>tab[right])
        {
            tempTable.push_back(tab[right]);
            right++;
        }
        else
        {
            tempTable.push_back(tab[left]);
            left++;
        }
    }

    while(right<=last)
    {
        tempTable.push_back(tab[right]);
        right++;
    }
    while(left <= middleIdx)
    {
        tempTable.push_back(tab[left]);
        left++;
    }

    
    for(int idx = first; idx <= last; idx++)
    {
        tab[idx] = tempTable[idx-first];
    }
    
}

void mergeSort(std::vector<int> &tab, int first, int last )
{
    if(first >= last) return;
    int middleIdx = (first+last)/2;
    mergeSort(tab, first, middleIdx);
    mergeSort(tab,middleIdx+1, last);
    merge(tab, first, middleIdx, last);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> tab{1, 2, 5 ,2, 6, 2, 4, 9, 8, 5};
    size_t tableSize = tab.size();
    mergeSort(tab, 0 , tableSize-1);
    
    for(int idx = 0; idx < tableSize; idx++){
        std::cout << tab[idx] << "\n";
    }
    
    return 0;
}
