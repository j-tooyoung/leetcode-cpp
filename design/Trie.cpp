//
// Created by tooyoung on 2021/1/30.
//


#include "bits/stdc++.h"
using namespace std;

class Trie{
private:
    bool isEnd;
    Trie *next[26];
public:
    Trie(){
        isEnd = false;
        memset(next, 0, sizeof(next));
    }

    void insert(string word){
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                node->next[c - 'a'] = new Trie();
            }
            node = node->next[c - 'a'];
        }
        // 标志插入结束
        node->isEnd=true;
    }

    bool search(string word){
        Trie *node = this;
        for (char c : word) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix){
        Trie *node = this;
        for (char c : prefix) {
            if (node->next[c - 'a'] == NULL) {
                return false;
            }
            node = node->next[c - 'a'];
        }
        return true;
    }
};
