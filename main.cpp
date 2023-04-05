#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

int main() 
{
    std::ifstream file("data.csv");
    //Array to hold all first values
    std::string firstvalues[8];

    //Checks if File is valid
    if (!file.is_open()) 
    {
        std::cerr << "Failed to open file.\n";
        return 1;
    }
  
    std::string line;
    // Reads and discard the first line as it is not needed
    std::getline(file, line);

    // Keeps track of array storage in while loop
    int i = 0;
  
    // Reads all Lines after the first line and sets them into array
    while (std::getline(file, line)) 
    {
        std::stringstream ss(line);
        std::string value;

        // Read the first value from each line
        std::getline(ss, value, ',');

        // Converts Data into Integer
        // int actValue = stoi(value);
        
        // Adds Data to Array
        firstvalues[i] = value;
        i++;
    }
  
    // Close file
    file.close();
  
    for(i = 0; i < 8;i++)
    {  
        std::string print = firstvalues[i];
        std::cout << print << std::endl;
    }
    

    return 0;
}
