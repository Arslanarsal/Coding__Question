#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flage = false;
    int cntEndWith = 0;
    int cntPreFix = 0;
    bool containKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void putKey(char ch, Node *key)
    {
        links[ch - 'a'] = key;
        return;
    }
    Node *getNext(char ch)
    {
        return links[ch - 'a'];
    }
    void setTrue()
    {
        flage = true;
        return;
    }
    bool isTrue()
    {
        return flage;
    }
    void increaseEnd()
    {
        cntEndWith++;
    }
    void increasePrefix()
    {
        cntPreFix++;
    }
    void reduceEnd()
    {
        cntEndWith--;
    }
    void reduceprefix()
    {
        cntPreFix--;
    }
    int getEnd()
    {
        return cntEndWith;
    }
    int getPrefix()
    {
        return cntPreFix;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        int length = word.size();
        Node *temp = root;
        for (int i = 0; i < length; i++)
        {
            if (!(temp->containKey(word[i])))
            {
                temp->putKey(word[i], new Node());
            }
            temp = temp->getNext(word[i]);
            temp->increasePrefix();
        }
        temp->setTrue();
        temp->increaseEnd();
        return;
    }

    bool search(string word)
    {
        int lenght = word.size();
        Node *temp = root;
        for (int i = 0; i < lenght; i++)
        {
            if (!(temp->containKey(word[i])))
            {
                return false;
            }
            temp = temp->getNext(word[i]);
        }
        return temp->isTrue();
    }

    int countWordEqualTo(string word)
    {
        int lenght = word.size();
        Node *temp = root;
        for (int i = 0; i < lenght; i++)
        {
            if (!(temp->containKey(word[i])))
            {
                return 0;
            }
            temp = temp->getNext(word[i]);
        }
        return temp->getEnd();
    }

    int countWordStartingWith(string word)
    {
        int lenght = word.size();
        Node *temp = root;
        for (int i = 0; i < lenght; i++)
        {
            if (!(temp->containKey(word[i])))
            {
                return 0;
            }
            temp = temp->getNext(word[i]);
        }
        return temp->getPrefix();
    }

    bool startsWith(string prefix)
    {
        int lenght = prefix.size();
        Node *temp = root;
        for (int i = 0; i < lenght; i++)
        {
            if (!(temp->containKey(prefix[i])))
            {
                return false;
            }
            temp = temp->getNext(prefix[i]);
        }
        return true;
    }

    void erase(string word)
    {
        int length = word.size();
        Node *temp = root;
        for (int i = 0; i < length; i++)
        {
            if (!(temp->containKey(word[i])))
            {
                return;
            }
            temp = temp->getNext(word[i]);
            temp->reduceprefix();
        }
        temp->reduceEnd();
        return;
    }
};

int main()
{

    return 0;
}