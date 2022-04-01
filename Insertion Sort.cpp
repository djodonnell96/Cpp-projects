#include <iostream>
#include <iomanip>

int* insertionSort(int[],int);

int main() {
  int A[5] = {1,2,3,4,5};
  int B[5] = insertionSort(A,5);
  
  for(int x = 0; x < 5; ++x)
  {
    std::cout << A[x] << " ";
  }
  std::endl;
  
  for(int x = 0; x < 5; ++x)
  {
    std::cout << B[x] << " ";
  }
  std::endl;
  
  system("pause");
  return 0;
}
void insertionSort(int *A, int size)
{
  for(int j = 2; j < size; ++j)
  {
    int key = *(A + j);
    int i = j - 1;
    while(i > 0 && *( A + j) < key)
    {
      *(A + (j - 1)) = *(A + j);
      i -= 1;
    }
    *(A(i-1)) = key;
  }
}
