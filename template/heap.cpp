//
// Created by tooyoung on 2021/2/16.
//

#include "bits/stdc++.h"
using namespace std;

int size = 100;
int heap[100];
int n;
// 大顶堆
void up(int p){
    while (p > 1) {
        if (heap[p] > heap[p / 2]) {
            swap(heap[p], heap[p / 2]);
            p /= 2;
        }else{
            break;
        }
    }
}

void down(int p) {
    int s = p * 2;
    while (s <= n) {
        if (s < n && heap[s] < heap[s + 1]) {
            s++;
        }
        if (heap[s] > heap[p]) {
            swap(heap[s], heap[p]);
            p = s, s = p * 2;
        }else{
            break;
        }
    }
}

// 将数组下标为p的节点删除
void remove(int k){
    heap[k] = heap[n--];
    up(k);
    down(k);
}

void extract(){
    heap[1] = heap[n--];
    down(1);
}

int getTop() {
    return heap[1];
}


int main () {
    return 0;
}
