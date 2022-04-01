#include <iostream>

int* generateLotto();
bool compareArr(int[],int[],int);

int main()
{
  const int SIZE = 5;
  
  int *answerKey,
      *userNums = new int[SIZE];
      
  bool answer;
      
  std::cout << "Enter 5 digits: ";
  for(int x = 0; x < 5; ++X)
    std::cin >> *(userNums + x);
    
  std::cout << "Evaluating numbers..." << std::endl;
  
  answerKey = generateLotto();
  
  answer = compareArr(userNums, answerKey, SIZE);
  
  if(answer)
    std::cout << "Congradulations! You have won the lottery!";
  else
    std::cout << "You lost! Game over!";
    
  system("pause");
  return 0;
}
int* generateLotto()
{
  int *ptr = new int[5];
  
  for(int pos = 0; pos < 5; ++pos)
  {
    *(ptr + pos) = rand() % 9;
  }
  
  return ptr;
}
bool compareArr(int arr1[], int arr2[], int size)
{
  for(int pos = 0; pos < size; ++pos)
    if(arr1[pos] != arr2[pos])
      return false;
  return true;
}