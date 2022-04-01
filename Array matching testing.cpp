#include <iostream>
#include <stdlib.h>

void initalizeArray(int &arr, int size);
void initalizeArrayRand(int &arr, int size, int low = 0, int high = 10);
int findDistance(int &refArr, int &genArr, int size);
void manipArr(int &refArr, int size, int low = 0, int high = 10);
void printArr(int &arr, int size);

int main() {
  int *refArr = nullptr,
      *genArr = nullptr,
      distance;
    
  const int SIZE = 5,
            LOW_RAND = 0,
            HIGH_RAND = 10;
            
  refArr = new int[SIZE][SIZE];
  genArr = new int[SIZE][SIZE];
  
  initalizeArrayRand(refArr, SIZE);
  intializeArray(genArr, SIZE);
  
  distance = findDistance(refArr, genArr);
  
  while (distance != 0)
  {
    manipArr(genArr, SIZE);
    distance = findDistance(refArr, genArr);
  }
  
  std::cout << "Array 1: " << printArr(refArr, SIZE) << std::endl;
  std::cout << "Array 2: " << printArr(genArr, SIZE) << std::endl;
  
  delete[] refArr;
  delete[] genArr;
  
  system("pause");
  return 0;
}

/**
 * Initalizes an array to be filled with all ones
 *
 * @param arr Array to be referenced to when initalizing
 * @param size Size of the array
 */
void initalizeArray(int &arr, int size) {
  // Making the range play nice with rand()
  int range = high - low;
  
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j){
      arr[i][j] = std::rand() % range + low;
    }
  }
}

/**
 * Initalizes an array to be filled with random numbers from low to high
 *
 * @param arr Array to be referenced to when initalizing
 * @param size Size of the array
 * @param low Low end of the desired random numbers
 * @param high High end of the desired random numbers
 */
void initalizeArrayRand(int &arr, int size, int low = 0, int high = 10) {
  // Making the range play nice with rand()
  int range = high - low;
  
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j){
      arr[i][j] = std::rand() % range + low;
    }
  }
}
/**
 * Finds the number of different elements between a reference array and a seperate array
 * @param refArr Array to be referred to as 'correct'
 * @param genArr Array that will be compared to the reference array
 * @return distance Integer value of the number of elements that are 'off'
 */
int findDistance(int &refArr, int &genArr, int size) {
   int distance = 0;
   
   for (int i = 0; i < size; ++i)
   {
     for (int j = 0; j < size; ++j)
     {
       if (refArr[i][j] != genArr[i][j])
        ++distance;
     }
   }
   
   return distance;
 }
/**
  * Manipulates a given number of elements in a given array to a random number in a given range
  *
  * @param refArr the array referenced in this operation
  * @param size Size of the given array (This squared if 2D, cubed if 3D and so on)
  * @param lowRange Low end of the range desired (inclusive)
  * #param highRange High end of the range desired (inclusive)
  */
void manipArr(int &refArr, int size, int low = 0, int high = 10) {
   const int MAX_PERCENT = 100;
   // The chance any given element will be changed
   double percentChange = static_type(double)numElements / static_type(double)size;
   int range = highRange - lowRange;
   
   for (int element : refArr)
   {
     if (std::rand() % MAX_PERCENT + 1 <= percentChange)
      element = std::rand() % range + highRange;
   }
 }
/**
  * Prints a given array to the command prompt
  *
  * @param arr Array to be printed
  * @param size Size of the array, squared if 2D, cubed if 3D and so on
  */
void printArr(int &arr, int size) {
  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      std::cout << arr[i][j] << " ";
    }
    std::cout << std::endl;
  }
 }