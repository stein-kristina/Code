#include <bits/stdc++.h>
using namespace std;
#define N 1145
//采取一种折半搜索的方法，数组一分为2，前半部分为A，看A能组成多少子集，

int total, n, m; // n数组总长度，total是数组总和
vector<unordered_set<int>> q;

// 从前半部分选 cnt 个数放到 A 能构成的 sum 的集合
void dfs1(vector<int> &a, int idx, int sum, int cnt)
{
  if (idx == m)
  {
    q[cnt].insert(sum);
    return;
  }
  dfs1(a, idx + 1, sum, cnt);
  dfs1(a, idx + 1, sum + a[idx], cnt + 1);
}

// 从后半部分选 cnt 个数放到 A 能构成的 sum
bool dfs2(vector<int> &a, int idx, int sum, int cnt)
{
  //q是存数数组
  if (idx == n)
  {
    for (int c = 0; c <= m; c++)
    {
      // sum * (x + y) = n * (sum(x) + sum(y))
      if (c + cnt == 0 || c + cnt == n || total * (c + cnt) % n != 0)
      {//对应A空集，B空集,不能整除
        continue;
      }
      int target = (total * (c + cnt) / n ) - sum;//算出sum(x)
      if (q[c].find(target) != q[c].end())//在里面找sum(x)
      {
        return true;
      }
    }
    return false;
  }
  return dfs2(a, idx + 1, sum, cnt) || dfs2(a, idx + 1, sum + a[idx], cnt + 1);
}

bool splitArraySameAverage(vector<int> &a)
{
  if (a.size() == 1)
  {
    return false;
  }
  // avg(A) == avg(B)
  // 设 A 为 sizeA， B 为 size2 (n - sizeA)
  //    那么 sum(A) / size1 == sum(B) / size2 == sum - sum(B) / size(B)
  //    sum * sizeA = n * sum(A)

  //    sum * (x + y) = n * (sum(x) + sum(y))
  // 折半枚举

  // 枚举 size1 的大小看此时的 sum 能否满足上式
  n = a.size();
  m = n / 2;
  q.resize(m + 1);
  total = accumulate(a.begin(), a.end(), 0);
  dfs1(a, 0, 0, 0);
  return dfs2(a, m, 0, 0);
}

int main()
{
  vector<vector<int>> a = {{1, 2, 2, 3, 5}, {3, 2, 3, 4, 4}, {2, 4, 5, 3, 1}, {6, 7, 1, 4, 5}, {5, 1, 1, 2, 4}};
  vector<int> b = {5, 3, 11, 19, 2};
  cout << splitArraySameAverage(b);

  system("pause");
  return 0;
}
