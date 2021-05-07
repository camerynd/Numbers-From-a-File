#include <iostream>
#include <fstream>//library to use fstream objects
using namespace std;
//function prototypes
void error_message(ifstream&);
void find_values(ifstream&, int&, int&, int&);
void display_results(int&, int&, int&);
//main function
int main()
{   
    //create ifstream object to read from a file
    ifstream inFile;
    //declaring variables
    int number = 0,
        sumOfNumbers = 0,
        numberOfNumbers = 0;
    //open text file using ifstream object
    inFile.open("Random.txt");
    //calling functions
    error_message(inFile);
    find_values(inFile, number, sumOfNumbers, numberOfNumbers);
    //close text file using fstream object
    inFile.close();
    //call function to display results 
    display_results(number, sumOfNumbers, numberOfNumbers);
    return 0;
}
//function to display error message if there is an issue opening file
void error_message(ifstream& file)
{
    if(file.fail())//detects failiure opening file
    {
        cout << "Error opening file." << endl;
        exit(1);//ends program if file won't open
    }
}
//function to store values from the file to variables
void find_values(ifstream& file, int& num, int& sumNum, int& numNum)
{
    while(!file.eof())//detects when the file has ended
    {
        file >> num;//draws values from file and stores in num
        sumNum += num;
        numNum++;
    }
}
//function to display results
void display_results(int& num, int& sumNum, int& numNum)
{
    cout << "The number of values in this file is ";
    cout << numNum << endl;
    cout << "The sum of the values in this file is ";
    cout << sumNum << endl;
    cout << "The average of the numbers in this file is ";
    cout << sumNum / numNum << endl;
}
