/*
    Your Trie object will be instantiated and called as such:
    Trie* obj = new Trie();
    obj->insert(word);
    bool check2 = obj->search(word);
    bool check3 = obj->startsWith(prefix);
 */

class trienode{
    public:
    char data;
    trienode* children[26];
    bool istreminal;
    trienode(char ch)
    {
        data = ch;
        for(int i =0;i<26;i++) children[i] = NULL;
        istreminal = false;
    }
};
class Trie {

public:

    /** Initialize your data structure here. */
    trienode* root;
    Trie() {
        root = new trienode('\0');
    }

    /** Inserts a word into the trie. */
    void insertutil(trienode* root,string word)
    {
        if(word.length()==0)
        {
            root->istreminal = true;
            return;
        }
        int index = word[0] - 'a';
        trienode* child;
        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            child = new trienode(word[0]);
            root->children[index] = child;
        }
        insertutil(child,word.substr(1));
    }
    void insert(string word) {
        insertutil(root, word);
    }

    /** Returns if the word is in the trie. */
    bool searchutil(trienode* root,string word)
    {
        if(word.length()==0)
        {
            return root->istreminal;
        }
        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            return false;
        }
       return searchutil(child, word.substr(1));
    }
    bool search(string word) {
       return searchutil(root, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startswithutil(trienode* root,string prefix)
    {
        if(prefix.length()==0)
        {
            return true;
        }
        int index = prefix[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            return false;
        }
        return startswithutil(child, prefix.substr(1));
    }
    bool startsWith(string prefix) {
       return startswithutil(root, prefix);
    }
    void deleteword(trienode* root,string word)
    {
         if(word.length()==0)
        {
            root->istreminal = false;
            return;
        }
        int index = word[0]-'a';
        trienode* child;

        if(root->children[index]!=NULL)
        {
            child = root->children[index];
        }
        else{
            return false;
        }
        deleteword(child, word.substr(1));
    }
};