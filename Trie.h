//
// Created by Katie He on 4/13/25.
//

#ifndef WORD_HUNT_SOLVER_TRIE_H
#define WORD_HUNT_SOLVER_TRIE_H

#include <vector>
#include <string>
#include <locale>
#include <codecvt>
using namespace std;

class Trie
{
    struct TrieNode
    {
        vector<TrieNode*> children;
        bool isWord;

        TrieNode() : isWord(false), children(26, nullptr) {}
    };
    TrieNode* root;

public:
    Trie() : root(new TrieNode()) {}

    bool insert(const string& word)
    {
        for (const char c : word) {
            if (!isalpha(c)) {
                return false;
            }
        }
        if(search(word))
            return false;
        TrieNode* current = root;
        for(char c : word)
        {
            int i = tolower(c) - 'a';
            if(current->children[i] == nullptr)
            {
                current->children[i] = new TrieNode();
            }
            current = current->children[i];
        }
        current->isWord = true;
        return true;
    }

    bool search(const string& word)
    {
        TrieNode* current = root;
        for(char c : word)
        {
            int i = tolower(c) - 'a';
            if(current->children[i] == nullptr)
            {
                return false;
            }
            current = current->children[i];
        }
        return current->isWord;
    }

   bool prefix(const string& prefix)
    {
        TrieNode* current = root;
        for(char c : prefix)
        {
            int i = tolower(c) - 'a';
            if(current->children[i] == nullptr)
            {
                return false;
            }
            current = current->children[i];
        }
        return true;
    }

    ~Trie()
    {
        deleteTrie(root);
    }

    void deleteTrie(TrieNode* node)
    {
        if (!node) return;
        for (int i = 0; i < 26; i++) {
            deleteTrie(node->children[i]);
        }
        delete node;
    }
};

#endif //WORD_HUNT_SOLVER_TRIE_H
