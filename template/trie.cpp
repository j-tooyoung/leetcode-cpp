//
// Created by tooyoung on 2021/2/16.
//


#include "bits/stdc++.h"
using namespace std;
//const static int size = ;
int trie[100][26];
bool end1[100];
int tot = 1;

void insert(char* str){
    int len = strlen(str);
    int p = 1;
    for (int i = 0; i < len; ++i) {
        int ch = str[i] - 'a';
        if (trie[p][ch] == 0) {
            trie[p][ch] = ++tot;
            p = trie[p][ch];
        }

    }
    end1[p] = true;
}


bool search(char *str) {
    int len = strlen(str);
    int p = 1;
    for (int i = 0; i < len; ++i) {
        int ch = str[i] - 'a';
        if (trie[p][ch] == 0) {
            return false;
        }
        p = trie[p][ch];

    }
    return end1[p];
}