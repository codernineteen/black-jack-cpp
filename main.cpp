#include <iostream>
#include <fstream>
#include <string>

void printASCII()
{
    std::string line = "";
    std::ifstream inFile;
    inFile.open("cards.txt");
    if(inFile.is_open())
    {
        while(getline(inFile,line))
        {
            if(line == "n")
            {
                std::cout << "seperation here" << std::endl;
            }
            std::cout << line << std::endl;
        }
    }
    else
    {
        std::cout << "Can't open file" << std::endl;
    }
    inFile.close();

}


int main()
{
    printASCII();
    return 0;
}
