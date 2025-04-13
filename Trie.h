//
// Created by Katie He on 4/13/25.
//

#ifndef WORD_HUNT_SOLVER_TRIE_H
#define WORD_HUNT_SOLVER_TRIE_H

#include <vector>
#include <string>
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
        if(search(word))
            return false;
        TrieNode* current = root;
        for(char c : word)
        {
            int i = c - 'a';
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
            int i = c - 'a';
            if(current->children[i] == nullptr)
            {
                return false;
            }
            current = current->children[i];
        }
        return current->isWord;
    }

    vector<string> prefixHelper(TrieNode* root, const string& prefix)
    {
        vector<string> ret;
        if(root->isWord)
        {
            ret.push_back(prefix);
        }
        for(int i = 0; i < 26; ++i)
        {
            if(root->children[i] != nullptr)
            {
                char c = 'a' + i;
                vector<string> v = prefixHelper(root->children[i], prefix + c);
                ret.insert(ret.end(), v.begin(), v.end());
            }
        }
        return ret;
    }

    vector<string> prefix(const string& prefix)
    {
        TrieNode* current = root;
        for(char c : prefix)
        {
            int i = c - 'a';
            if(current->children[i] == nullptr)
            {
                vector<string> hi;
                return hi;
            }
            current = current->children[i];
        }
        return prefixHelper(current, prefix);
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
