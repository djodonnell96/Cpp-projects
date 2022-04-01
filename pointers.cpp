#include <iostream>
#include <cctype>

void printVal(const int&);
void printVal(const int*);
int* allocateIntArr(int);
void sortScores(int&);

int main() {
  int val1 = 1,
      val2 = 2,
      size;
  int *intArr(nullptr);
  
  std::cout << "Value 1: " << val1 << std::endl;
  std::cout << "Value 2: " << val2 << std::endl;
  system("pause");
  
  std::cout << "Printing via use of passing by reference: ";
  std::cout << "Value 1 passed by reference at address " << &val1 << ": " << printVal(val1);
  std::cout << "Value 1 passed by pointer at address " << &val1 << ": " << printVal(&val1);
  system("pause");
  
  std::cout << "Value 2 passed by reference at address " << &val2 << ": " << printVal(val2);
  std::cout << "Value 2 passed as a pointer at address " << &val2 << ": " << printVal(&val2);
  
  system("pause");
  
  std::cout << "What size should the integer array be? ";
  std::cin >> size;
  std::cout << "Allocating space..." << std::endl;
  intArr = allocateIntArr(size);
  std::cout << "Address of the first element in the array: " << intArr << std::endl;
  std::cout << "Size of the array: " << sizeOf(intArr) << std::endl;
  system("pause");
  
  std::cout << "Clearing used space..." << std::endl;
  delete[] intArr;
  delete val1, val2,size;
  system("pause");
  
  /*--------------------------------------------------------------------------------------------*/
  char testScores1;
  std::cout << "Would you like to execute the Test Scores 1 program? (Y/N) " << std::endl;
  std::cin >> testScores1;
  testScores1 = tolower(testScores1);
  // Data validation loop to avoid the stream freaking out
  while (testScores1 != 'n' || testScores1 != 'y')
  {
    std::cout << "Invalid input, enter another value: ";
    std::cin >> testScores
    std::cout << std::endl << std::endl;
    testScores; = tolower(testScores1);
  }
  
  // Test scores 1
  int numScores;
  int *testScoresPtr(nullptr);
  auto testInput;
  
  std::cout << "How many test scores atr there?";
  std::cin >> testInput;
  while (!(std::isdigit(testInput)))
  {
    std::cout << "Input is not a numeric digit, please enter another value: ";
    std::cin >> testInput;
  }
  numScores = testInput;
  
  testScoresPtr(allocateIntArr(numScores));
  
  std::cout << "Sorting scores..." << std::endl;
  
  return 0;
}
void printVal(const int &val)
{
  std::cout << val << std::endl;
}
void printVal(const int *val)
{
  std::cout << *val << std::endl;
}
int* allocateIntArr(int size)
{
  int *arr(new int(size));
  return arr;
}
void sortScores(int &scores[])
{
  
}