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
#include <set>
#include <tuple>

#include "Trie.h"

using namespace std;

void dfs(set<string>& words, vector<vector<char> >& grid, int row, int col, string s, vector<vector<bool> >& visited, Trie& tree)
{
    string newString = s + grid[row][col];
    if(!tree.prefix(newString))
    {
        return;
    }
    visited[row][col] = true;
    cout << "row: " << row << " and col: " << col << endl;
    cout << "current string: " << s << endl;
    if(newString.length() >= 3 && tree.search(newString))
    {
        words.insert(newString);
    }
    int xChange[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int yChange[] = {0, 1, 1, 1, 0, -1, -1, -1};
    for(int i = 0; i < 8; ++i)
    {
        if(row + xChange[i] >= 0 && row + xChange[i] < grid.size() && col + yChange[i] >= 0 && col + yChange[i] < grid.size() && !visited[row + xChange[i]][col + yChange[i]])
        {
            dfs(words, grid, row + xChange[i], col + yChange[i], newString, visited, tree);
        }
    }

    visited[row][col] = false;
}
void bfs(set<string>& words, vector<vector<char> >& grid, int row, int col, Trie& tree)
{
    int size = grid.size();
    int xChange[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int yChange[] = {0, 1, 1, 1, 0, -1, -1, -1};

    queue<tuple<int, int, string, vector<vector<bool> > > > q;
    vector<vector<bool> > visited(size, vector<bool>(size, false));
    string s = "";
    s = s + grid[row][col];
    visited[row][col] = true;
    q.push({row, col, s, visited});

    while(!q.empty())
    {
        auto[r, c, newString, invisit] = q.front();
        q.pop();
        if(newString.length() >= 3 && tree.search(newString))
        {
            words.insert(newString);
        }
        for(int i = 0; i < 8; ++i)
        {
            if(r + xChange[i] >= 0 && r + xChange[i] < grid.size() && c + yChange[i] >= 0 && c + yChange[i] < grid.size() && !visited[r + xChange[i]][c + yChange[i]])
            {
                string newString2 = newString + grid[r + xChange[i]][c + yChange[i]];
                if(!tree.prefix(newString2))
                {
                    vector<vector<bool> > newVisited = invisit;
                    newVisited[r + xChange[i]][c + yChange[i]] = true;
                    q.push({r + xChange[i], c + yChange[i], newString2, newVisited});
                }
            }
        }
    }
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
    vector<vector<char> > grid;
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

    set<string> words;
    vector<vector<bool> > visited(size, vector<bool>(size, false));
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            dfs(words, grid, i, j, "", visited, tree);
        }
    }
    for (const string& word : words)
    {
        cout << word << endl;
    }

    set<string> words2;
    for(int i = 0; i < size; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            bfs(words2, grid, i, j, tree);
        }
    }
    for (const string& word : words2)
    {
        cout << word << endl;
    }
    //test
}