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
#include <queue>

#include "Trie.h"

using namespace std;

vector<string>& bfs(const vector<vector<char>>& grid) {

}

int main() {
    ifstream myReadFile("words.txt");
    string line;
    Trie tree;
    if(myReadFile.is_open())
    {
        while (getline(myReadFile, line)) {
            //cout << line << endl;
            if (line[0] == '#') {
            } else {
                if (line.size() > 2) {
                    tree.insert(line);
                }
            }
        }
    }

    myReadFile.close();

    cout << "Input size of square grid: " << endl;
    int size;
    cin >> size;
    vector<vector<char>> grid;
    cout << "Please enter grid: " << endl;

    for (int i = 0; i < size; i++) {
        string characters = "";
        cin >> characters;
        vector<char> row;
        for (int j = 0; j < characters.size(); j++) {
            row.push_back(characters[j]);
        }
        grid.push_back(row);
    }

    //test
}