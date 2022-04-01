// Arrays 
// Dennis ODonnell
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
  // Names 
  int names[20];
  
  for (int x = 0; x < SIZE; x++){
    cout << "Enter a name: ";
    cin >> names[x];
  }
  
  for (string name : names){
    cout << name << endl;
  }
  
  // Copying arrays
  int numberArray1[100];
  int numberArray2[100];
  
  // Filling array1
  for (int x = 0; x < 100; x++){
    numberArray1[x] = x;
  }
  
  // Copying to array 2
  for (int y = 0; y < 100; x++){
    int temp = numberArray1[x];
    numberArray2[x] = temp;
  }
  int count = 0;
  // Alt copying (might work)
  for (int num : numberArray1){
    numberArray2[count] = num;
  }
  //Anotha one
  for (int z = 0; z < 100; z++){
    numberArray2[z] = numberArray1[z];
  }
  
  // Parallel arrays
  const int NUM_EMPLOYEES = 10;
  int employeeArr[NUM_EMPLOYEES];
  double employeePay[NUM_EMPLOYEES];
  
  // Input employees name and pay
  for (int x = 0; x < NUM_EMPLOYEES; x++){
    cout << "Add employee's name: ";
    cin >> employeeArr[x];
    cout << "Add employee's pay: ";
    cin >> employeePay;
  }
  
  cout << "Employee's name\t\tWeekly Gross Pay" << endl 
          << "--------------------------------------------" << endl;
  
  for (int y = 0; y < NUM_EMPLOYEES; y++){
    cout << employeeAtt[y] << "\t\t" << enployeePAy[y];
  }
  
  // Rainfall statistics
  double doubleMin(int[]);
  double doubleMax(int[]);
  
  const int MONTHS = 12;
  double monthlyRainTbl[MONTHS];
  double rainfall; // temp double for checking valid input
  double min, max;
  
  for (int currentMonth = 0; currentMonth < MONTHS; currentMonth++){
    do
    {
      cout << "Enter month " << currentMonth << "'s rainfall";
      cin >> rainfall;
      if (rainfall < 0)
        cout << "Invalid input" << endl;
    } while (rainfall < 0);
    monthlyRainTbl[currentMonth] = rainfall;
  }
  
  min = doubleMin(monthlyRainTbl);
  max = doubleMax(monthlyRainTbl);
  
  cout << "The smallest amount of rainfall was " << min << " inches." << endl;
  cout << "The largest amount of rainfall was " << max << " inches." << endl;
  
  // Basic array number analysis
  int sum(int[]);
  double avg(int[]);
  int min(int[]);
  int max(int[]);
  int findSize(int[]);
  
  const int SIZE = 20;
  ifstream inputFileStr;
  int fileNumArr[SIZE];
  string filename;
  int sum, avg, min, max;
  
  cout << "Please enter the filename" << endl;
  cin >> filename;
  
  inputFileStr.open(filename);
  
  for (int x = 0; x < SIZE; x++){
    cin >> fileNumArr[x];
  }
  
  sum = sum(fileNumArr);
  avg = avg(fileNameArr);
  
  min = min(fileNameArr);
  max = max(fileNameArr);
  
  cout << "Max: " << max << "\t" << "Min: " << min << endl
    "Total: " << total << "\t" << "Average: " << average;
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
int max(int arr[]){
  int max = arr[0];
  for(int val : arr){
    if (val > max)
      max = val;
  }
  return max;
}
int min(int arr[]){
  int min = arr[0];
  for(int val : arr){
    if (val < min)
      min = val;
  }
  return min;
}
int sum (int arr[]){
  int sum = 0;
  for (int val : arr){
    sum += val;
  }
  return sum;
}
int avg(int arr[]){
  int sum = sum(arr);
  int size = findSize(arr);
  double avg = static_type(double)sum / static_type(double)size;
  return avg;
}
int findSize(int arr[]){
  int size = 0;
  for (int val : arr){
    size++;
  }
  return size;
}
double doubleMin(int arr[]) {
  double min = arr[0];
  int index = 0;
  for (double val : arr) {
    if (val < min)
      min = val;
  }
  return min;
}
double doubleMax(int arr[]) {
  double max = arr[0];
  int index = 0;
  for (double val : arr) {
    if (val > max)
      max = val;
  }
  return max;
}