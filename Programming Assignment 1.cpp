/**
  Author: Dennis ODonnell
  Project Start Date: 9.6.16
  CSC 215
  Programming Assignment 1
  Arabic numerals to Roman numberals converter
  
  @author Dennis ODonnell
  @version 1.3 9/19/16
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

std::string convert(int value);
std::string arabicToRoman(int digit, std::string low, std::string mid, std::string high);
void printVector(std::vector<std::string>);
void cmdFinalReport(int count);
void saveFinalReport(int count, std::ofstream &file);

int main() {
  // Data
  const int MINIMUM = 1,
            MAXIMUM = 3999,
            SIZE = 4;
  int value,
	  conversionCount = 0;

  std::string romNum;

  char saveFile;

  bool invalidDatatype;

  std::ofstream file;
  
  // Instructions on how to use program that will be shown at runtime
  std::cout << "PROGRAM INSTRUCTIONS\n" << "--------------------------\n";
  std::cout << "1. Any number between 1 and 3999 is valid. Anything else will be rejected.\n";
  std::cout << "2. Enter a negative number to exit the program.\n";
  system("pause");
  
  // Input with data validation
  do
  {
    std::cout << "Enter a number between 1 and 3999 to be converted (negative to exit): ";
    std::cin >> value;
	// Eliminating all unwanted situations before continuing with processing
	if (value > MAXIMUM)
		std::cout << "Invalid input, enter something lower.\n";
	else if (value < MINIMUM && value == 0)
		std::cout << "Invalid input, enter something higher\n";
	else if (value < MINIMUM)
		continue;
    else
    {
      // Where the logic will bring the process when a valid positive number has been input
      ++conversionCount;
	  romNum = convert(value);
      std::cout << "The Roman Numeral for " << value << " is: " << romNum << "\n";

    }
    } while (!(value < 0));
      
    // Final report and output
	// Data validation loop to ensure the program does not break upon something that is not a 'y' or 'b' being entered into the stream
	do 
	{
		invalidDatatype = true;
		std::cout << "\nWould you like to save the final report? (Y/N) ";
		std::cin >> saveFile;
		saveFile = tolower(saveFile);
		if (saveFile == 'y' || saveFile == 'n')
			invalidDatatype = false;
		else
			std::cout << "\nError: Invalid datatype. Please enter a Y or an N: ";
	} while (invalidDatatype);
	
    cmdFinalReport(conversionCount);
	if (saveFile == 'y')
	{
		saveFinalReport(conversionCount, file);
	}
    std::cout << std::endl;
    system("pause");
	exit(EXIT_SUCCESS);
  
    return 0;
}
/**
 * This method is meant to be an intermediate between calling a conversion on a whole number and the actual process of converting the number.
 * Essentially what it does is it takes the value and size of the number and generates it's Roman Numeral equivalent digit by digit.
 *
 * @param value The literal value to be converted
 * @param size The size of the number being passed
 */
std::string convert(int value) {
  // A vector is used to build the string part by part
  std::vector<std::string> romNumVect;
  std::string romNum;

  int thousands,
	  hundreds,
	  tens,
	  ones;

  //Extracting each digit
  thousands = value / 1000;
  value %= 1000;
  hundreds = value / 100;
  value %= 100;
  tens = value / 10;
  value %= 10;
  // Keeping this one here for clarity
  ones = value / 1;
  
  /*
	Pushing values onto the array
  */
  if (thousands != 0)
	romNumVect.push_back(arabicToRoman(thousands, "M", "M", "M"));
  if (hundreds != 0)
	romNumVect.push_back(arabicToRoman(hundreds, "C", "D", "M"));
  if (tens != 0)
    romNumVect.push_back(arabicToRoman(tens, "X", "L", "C"));
  if (ones != 0)
    romNumVect.push_back(arabicToRoman(ones, "I", "V", "X"));

  // Appending each value in the vector to the final string
  for (auto i = romNumVect.begin(); i != romNumVect.end(); ++i)
  {
	  romNum += *i;
  }
  return romNum;
}

/**
  Converts Arabic numberals to Roman numerals through the use of num%10^n returning the value at n's index place value
  e.g. when n = 1, it returns how many ones there are in a given number
  
  @param digit The digit to be converted
  @param low The low Roman Numeral term to be used
  @param mid The middle Roman Numeral term to be used
  @param high The high Roman Numeral term to be used
  @return A string in Roman Numeral that is equivalent to the digit
*/
std::string arabicToRoman(int digit, std::string low, std::string mid, std::string high) {
  std::string romanNumeral;

  if (digit == 1)
	  romanNumeral = low;
  else if (digit == 2)
	  romanNumeral = low + low;
  else if (digit == 3)
	  romanNumeral = low + low + low;
  else if (digit == 4)
	  romanNumeral = low + mid;
  else if (digit == 5)
	  romanNumeral = mid;
  else if (digit == 6)
	  romanNumeral = mid + low;
  else if (digit == 7)
	  romanNumeral = mid + low + low;
  else if (digit == 8)
	  romanNumeral = mid + low + low + low;
  else if (digit == 9)
	  romanNumeral = low + high;
  
  return romanNumeral;
}

/**
  Prints the array passed by reference in the first parameter
  
  @param arr The array to be read
  @param size The size of the array being read
*/
void printVector(std::vector<std::string> romNum) {
	for (auto i = romNum.begin(); i != romNum.end(); ++i)
	{
		std::cout << *i;
	}
}

/**
  For outputting the final report on the command line
  
  @param count The number of conversions successfully completed
*/
void cmdFinalReport(int count) {
  std::cout << std::setw(6);
  std::cout << "Final report\n";
  std::cout << "-----------------------";
  std::cout << "\nNumber of Arabic numbers converted: " << count << "\n";
}

/**
* Saves the final report to FinalReport.txt and reports to the user upon completion
*
* @param count The number of conversions
* @param file A reference to the desired file
*/
void saveFinalReport(int count, std::ofstream &file) {

	file.open("FinalReport.txt");
	if (!(file.is_open()))
	{
		std::cout << "\nThe FinalReport.txt file could not be opened, aborting...\n";
		exit(EXIT_FAILURE);
	}

	file << "\nFinal Report\n---------------\n";
	file << "Number of conversions: " << count << std::endl;

	file.close();

	std::cout << "\nFinal report saved to FinalReport.txt\n";
}