#include <iostream>
#include <fstream>
#include <vector>

bool LoadFile(std::string fileName, std::vector<uint32_t>& arr)
{
  std::fstream file(fileName);
  std::string line;
  bool rV = false;
  
  if(file.is_open())
  {
    while(getline(file, line))
      {
        arr.push_back(stoi(line));
      }
    rV = true;
    file.close();
  }
  return rV;
}

uint32_t Merge(std::vector<uint32_t>& arr, uint32_t low, uint32_t middle, uint32_t high)
{

  uint32_t left = low, right = middle + 1, cnt = 0;
  std::vector<uint32_t> temp;
  while(left <= middle && right <= high)
    {
      if(arr[left] < arr[right])
      {
        temp.push_back(arr[left]);
        left++;
      }
      else
      {
        temp.push_back(arr[right]);
        cnt += (middle - left + 1); 
        right++;
      }
    }
  while(left <= middle)
    {
      temp.push_back(arr[left]);
      left++;
    }
  while(right <= high)
    {
      temp.push_back(arr[right]);
      right++;
    }

  for(size_t idx = low; idx <= high; idx++)
    {
        arr[idx] = temp[idx - low];
    }
  return cnt;
}

uint32_t MergeSort(std::vector<uint32_t>& arr, uint32_t left, uint32_t right)
{
  uint32_t cnt = 0;
  if(left >= right) return cnt;
  uint32_t middle = (right + left)/2;
  cnt += MergeSort(arr, left, middle);
  cnt += MergeSort(arr, middle+1, right);
  cnt += Merge(arr, left, middle, right);
  return cnt;
}

uint32_t NumberOfInversions(std::vector<uint32_t>& arr, uint32_t arrSize)
{
  return MergeSort(arr, 0, arrSize - 1);
}

int main() 
{
  std::vector<uint32_t> intArray;

  if(LoadFile("IntArray.txt", intArray))
  {
    std::cout << NumberOfInversions( intArray, intArray.size());
  }

}