#include <iostream>

int partition(int tab[], int startIdx, int endIdx)
{
    int pivot = tab[endIdx]; // it depends on quick sort version
    int pIndex = startIdx;
    
    for(int idx = pIndex; idx < endIdx; idx++ )
    {
        if(tab[idx]<=pivot)
        {
            std::swap(tab[idx], tab[pIndex]);
            pIndex++;
        }
    }
    std::swap(tab[endIdx], tab[pIndex]);
    return pIndex;
}

void quickSort(int tab[], int startIdx, int endIdx)
{
    if(startIdx>=endIdx) return;
    
    int partitionIdx = partition(tab, startIdx, endIdx);
    
    quickSort(tab, startIdx, partitionIdx-1);
    quickSort(tab, partitionIdx+1, endIdx);

}

int main(int argc, const char * argv[]) {
    
    int tab[] = {1, 2, 5 , 6, 4, 9, 8};
    quickSort(tab, 0, 6);
    for(int idx = 0; idx < 7; idx++){
        std::cout << tab[idx] << "\n";
    }
    return 0;
}
