#include <random>
#include <bits/stdc++.h>

using namespace std;
//冒泡排序
void bubblesort(vector<int> & arr){
  int n = arr.size();
  for(int i=0 ; i<n-1;i++){
    bool flag = false;
    for(int j = n-1;j>i;j--){
      if(arr[j-1] > arr[j]){
        swap(arr[j-1],arr[j]);
        flag = true;
      }
    }
    if(!flag) return;
  }
}
void quicksort(vector<int> &arr,int low,int high){
  if(low < high){
    int pivot = arr[low];
    int l=low,r=high;
    while(l<r){
      while(l < r && arr[r] >= pivot) r--;
      arr[l] = arr[r];
      while(l < r && arr[l] <= pivot) l++;
      arr[r] = arr[l];
    }
    arr[l] = pivot;
    quicksort(arr,low,l-1);
    quicksort(arr,l+1,high);
  }
}
int main()
{
  vector<int> a = {49, 38, 65, 97, 76, 13, 27, 38};
  int choose;
  cin>>choose;
  if(choose){
    bubblesort(a);
  }
  else{
    int n = a.size();
    quicksort(a,0,n-1);
  }
  for (auto &i : a)
  {
    cout << i << ' ';
  }
  system("pause");
  return 0;
}