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
#include <Trie.h>

using namespace std;

int main() {
    ifstream myReadFile("words.txt");
    string line;
    Trie tree;
    if(myReadFile.is_open())
    {
        while (getline(myReadFile, line)) {
            if (line[0] == '#') {
            } else {
                tree.insert(line);
            }
        }
    }
    //prompt user for their word search grid
    //bfs+dfs searches
    //test
}