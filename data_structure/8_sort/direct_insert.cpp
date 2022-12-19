#include <random>
#include <bits/stdc++.h>

using namespace std;
// 折半插入排序
void insertsort(vector<int> &arr)
{
  int n = arr.size();
  int pivot; // 哨兵
  for (int i = 1; i < n; i++)
  {
    pivot = arr[i];
    int pos = lower_bound(arr.begin(), arr.begin() + i, pivot) - arr.begin();
    for (int j = i; j > pos; j--)
    {
      arr[j] = arr[j - 1];
    }
    arr[pos] = pivot;
  }
}
void hier_sort(vector<int> & arr){
  int n = arr.size();
  int pivot;
  for(int dk = n/2 ; dk >= 1 ;dk = dk/2){
    for(int i = dk ;i < n ;i++){
      if(arr[i] < arr[i-dk]){//选取一定间隔
        pivot = arr[i];
        int j;
        for(j = i-dk; j >=0 && pivot < arr[j] ; j-=dk){
          arr[j+dk] = arr[j];
        }
        arr[j+dk] = pivot;
      }
    }
  }
}
int main()
{
  vector<int> a = {49, 38, 65, 97, 76, 13, 27, 19};
  hier_sort(a);
  for (auto &i : a)
  {
    cout << i << ' ';
  }
  system("pause");
  return 0;
}