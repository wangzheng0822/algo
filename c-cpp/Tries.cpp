#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Trie;
class TrieNode
{
private:
    char data;
    bool isTerminal;
    unordered_map<char,TrieNode*> NextLetter;
public:
    TrieNode(char ch)
    {
        data=ch;
        isTerminal=false;
    }
    friend class Trie;
};

class Trie
{
private:
    TrieNode* root;
public:
    Trie()
    {
        root=new TrieNode('\0');
    }

    void AddWord(char* Word, TrieNode* rt)
    {
        if(Word[0]=='\0')
        {
            rt->isTerminal=true;
            return;
        }
        char ch=Word[0];
        auto it=rt->NextLetter.find(ch);
        TrieNode* NewLetter;
        if(it==rt->NextLetter.end())
        {
            NewLetter=new TrieNode(ch);
            rt->NextLetter[ch]=NewLetter;
        }
        else
        {
            NewLetter=it->second;
        }
        AddWord(Word+1,NewLetter);
    }
    void AddWord(char* Word)
    {
        AddWord(Word,root);
    }

    bool Search(char* Word)
    {
        TrieNode* rt=root;
        for(int i=0;Word[i]!='\0';i++)
        {
            char ch=Word[i];
            auto it=rt->NextLetter.find(ch);
            if(it==rt->NextLetter.end()) return false;
            rt=it->second;
        }
        return rt->isTerminal;
    }

    void PrintTrie(TrieNode* rt, vector<string> &Words)
    {
        static string Word;
        Word.push_back(rt->data);
        if(rt->isTerminal)
        {
            Words.push_back(Word);
        }
        for(auto it=rt->NextLetter.begin();it!=rt->NextLetter.end();it++)
        {
            PrintTrie(it->second,Words);
        }
        Word.pop_back();
        return;
    }

    void PrintTrie()
    {
        vector<string> Words;
        PrintTrie(root,Words);
        for(auto it=Words.begin();it!=Words.end();it++)
            cout<<*it<<endl;
        return;
    }
};

int main()
{
    Trie t;
    char s1[]="Rakesh";
    char s2[]="Rajesh";
    char s3[]="Ramesh";
    char s4[]="Raju";
    char s5[]="Ravi";
    char s6[]="Suresh";
    char s7[]="Mahesh";

    t.AddWord(s1);
    t.AddWord(s2);
    t.AddWord(s3);
    t.AddWord(s4);
    t.AddWord(s5);
    t.AddWord(s6);
    t.AddWord(s7);
    //char s[]="Rajesh";
    //cout<<t.Search(s)<<endl;
    t.PrintTrie();
}
