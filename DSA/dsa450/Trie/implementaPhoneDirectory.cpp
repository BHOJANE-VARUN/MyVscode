#include <bits/stdc++.h>
class TrieNode
{
  public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char ch)
    {
        data = ch;
        for(int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
    } 
};
class Trie
{
  public:
    TrieNode* root;
    Trie()
    {
        root = new TrieNode('\0');
    }
    void insertUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root -> isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode* child;
        if(root -> children[index] != NULL)
        {
            child = root -> children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root -> children[index] = child;
        }
        insertUtil(child, word.substr(1));
    }
    void insertWord(string word)
    {
        insertUtil(root, word);
    }
    void printSuggestions(TrieNode* current, vector<string> &temp, string prefix)
    {
        if(current -> isTerminal)
            temp.push_back(prefix);
        for(char character = 'a'; character <= 'z'; character++)
        {
            TrieNode* next = current -> children[character - 'a'];
            if(next)
            {
                prefix.push_back(character);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    vector<vector<string>> getSuggestions(string str)
    {
        TrieNode* previous = root;
        vector<vector<string>> ans;
        string prefix = "";
        for(int i = 0; i < str.length(); i++)
        {
            char lastCharacter = str[i];
            prefix.push_back(lastCharacter);
            TrieNode* current = previous -> children[lastCharacter - 'a'];
            if(current == NULL)
                break;
            vector<string> temp;
            printSuggestions(current, temp, prefix);
            ans.push_back(temp);
            temp.clear();
            previous = current;
        }
        return ans;
    }
};
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t = new Trie();
    int size = contactList.size();
    for(int i = 0; i < size; i++)
        t -> insertWord(contactList[i]);
    return t -> getSuggestions(queryStr);
}