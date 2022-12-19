#include <random>
#include <bits/stdc++.h>

using namespace std;
// 简单选择排序
void selectsort(vector<int> &arr)
{
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    int min_i = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[j] < arr[min_i])
        min_i = j;
    }
    if (min_i != i)
      swap(arr[min_i], arr[i]);
  }
}
// 堆排序
void headadjust(vector<int> &arr, int r, int len)
{
  int n = len; // 最后一个点的长度
  arr[0] = arr[r];
  for (int i = 2 * r; i <= n; i *= 2)
  {
    if (i < n && arr[i] > arr[i + 1])
      i++;
    // 选择最小的儿子
    if (arr[0] <= arr[i])
      break; // 父亲小，别管了
    else
    {
      arr[r] = arr[i];
      r = i;
    }
  }
  arr[r] = arr[0];
}
void buildminheap(vector<int> &arr)
{
  int n = arr.size() - 1;
  for (int i = n / 2; i > 0; i--)
  {
    headadjust(arr, i, n);
  }
}
void heap_sort(vector<int> &arr)
{
  buildminheap(arr);
  int len = arr.size() - 1; // 最后一个元素
  for (int i = len; i > 1; i--)
  {
    cout << arr[1] << ' ';
    swap(arr[1], arr[i]);
    headadjust(arr, 1, i - 1);
  }
}
int main()
{
  vector<int> a = {49, 38, 65, 97, 76, 13, 27, 38};
  vector<int> b = {0, 49, 38, 65, 97, 76, 13, 27, 38};
  int choose;
  cin >> choose;
  if (choose)
  {
    selectsort(a);
    for (auto &i : a)
    {
      cout << i << ' ';
    }
  }
  else
  {
    int n = a.size();
    heap_sort(b);
  }

  system("pause");
  return 0;
}