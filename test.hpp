#ifndef TEST_CPP
#define TEST_CPP
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void insertionSort(T begin, T end) {
  for(auto t = begin+1;t!=end;t++){
    auto insert = begin;//寻找插入位置
    int pivot = (*t).n;
    int index = lower_bound(begin,t,pivot)-begin;
    insert = begin + index;
    for(auto copy = t; copy!=insert;copy--){
      *copy = *(copy-1);
    }
    (*insert).n= pivot;
  }
}

#endif