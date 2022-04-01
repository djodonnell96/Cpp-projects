int main() {
  const int ROWS = 10,
            COLS = 10;
            
  int arr[ROWS][COLS];
  
  /**
   * Each space in the array is filled with an integer value of the number of iterations it took to get to that position
   */
  for(int i = 0; i < ROWS; ++i)
    for(int j = 0; j < COLS; ++j)
      arr[i][j] = i + j
  
  return 0;
}
void showArray(int arr[ROWS][COLS]& arr) {
  for (int i = 0; i < ROWS; ++i)
    for (int j = 0; j < COLS; ++j)
      std::cout << arr[i][j] << " \n";
  return;
}