// Basic algorithms
#include <iostream>
using namespace std;

int main() {
  int bubbleSort(int[]);
  int binarySearch(int[],int);
  int linearSearch(int[],int);
  void randomizeArr()
  int findSize(int[]);
  void selectionSort(int[]);
  
  return 0;
}
int bubbleSort(int arr[]){
  bool swap;
  int temp,
      size = findSize(arr);
  
  do
  {
    swap = false;
    for (int x = 0; x < (size - 1); x++) {
      if (arr[x] < arr[x+1])
      {
        temp = arr[x];
        arr[x] = arr[x+1];
        arr[x+1] = temp;
        swap = true;
      }
    }
  } while (swap == true);
}
int binarySearch(int arr[], int target){
  int lIndex = 0;
  int NUM_ELEMENTS = findSize(arr);
  int rIndex = NUM_ELEMENTS - 1;
  bool found = false;
  int position = -1;
  
  while (!(found == true) && lIndex <= rIndex){
    int mIndex = (lIndex + rIndex) / 2;
    if (arr[mIndex] == target)
    {
      position = middle;
      found = true;
    } else if (arr[mIndex] > target){
      rIndex = middle - 1;
    } else {
      lIndex = middle + 1;
    }
  }
  return position;
}
int linearSearch(int arr[], int target){
  bool found = false;
  int position = -1;
  int index = 0;
  const int NUM_ELEMENTS = findSize(arr);
  
  while (found == false && index < NUM_ELEMENTS)
  {
    if (arr[index] == target)
    {
      position = index;
      found = true;
    }
    index++;
  }
  return position;
}
void randomizeArr(int arr[]){
  int size = findSize(arr);
  
  for (int x = 0; x < size; x++){
    int newVal = rand() % 100;
    arr[x] = newVal;
  }
}
int findSize(int arr[]){
  int size = 0;
  for (int val : arr){
    size++;
  }
  return size;
}
void selectionSort(int arr[]) {
  int size = findSize(Arr),
      startScan,
      minIndex,
      minVal;
      
  for(startScan = 0; startScan < (size - 1); startScan++) {
    minIndex = startScan;
    minValue = arr[startScan];
    
    for (int index = (startScan + 1); index < size; index++) {
      if (arr[index] < minValue)
      {
        minValue = arr[index];
        minIndex = index;
      }
    }
    arr[minIndex] = arr[startScan];
    arr[startScan] = minVal;
  }
}