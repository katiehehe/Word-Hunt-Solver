//
// Created by lukel on 4/12/2025.
//

#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    cout << "Hello World" << endl;
    //testing
    //read in the words from the text file and store it
    ifstream myReadFile("words.txt");
    string line;
    while (getLine(myReadFile, line))
    {
        if(line.charAt(0) == '#')
        {

        }
        else
        {

        }
    }
    //prompt user for their word search grid
    //bfs+dfs searches
    //test
}