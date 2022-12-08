#include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
/* 一个矩形区域的象限划分：:

       UL(1)   |    UR(0)
     ----------|-----------
       LL(2)   |    LR(3)
以下对该象限类型的枚举
*/
typedef enum
{
  UL = 0,
  UR = 1,
  LL = 2,
  LR = 3
} QuadrantEnum;

/* 矩形结构 */
typedef struct quadrect_t
{
  double left,
      top,
      right,
      bottom;
  quadrect_t(int l = 0, int t = 0, int r = 0, int b = 0) : left(l), top(t), right(r), bottom(b) {}
} quadrect_t;

/* 四叉树节点类型结构 */
typedef struct quadnode_t
{
  quadrect_t rect;           //节点所代表的矩形区域
  pair<double, double> data; //节点数据, 节点类型一般为链表，可存储多个对象
  struct quadnode_t *sub[4]; //指向节点的四个孩子
  bool haskid;               //有没有孩子
  quadnode_t(quadrect_t qt) : rect(qt), data(make_pair(-1, -1))
  {
    memset(sub, 0, sizeof(sub));
    haskid = false;
  }
} quadnode_t;

/* 四叉树类型结构 */
typedef struct quadtree_t
{
  quadnode_t *root;
  int depth; // 四叉树的深度
  quadtree_t() : root(nullptr), depth(1) {}
} quadtree_t;

void QuadInsert(pair<double, double> &data, quadnode_t *&root);
void QuadtreeBuild(quadtree_t *&root, int &t)
{
  root->root = new quadnode_t(quadrect_t(0, 10, 10, 0)); //头结点
  quadnode_t *&r = root->root;
  for (int i = 0; i < t; i++)
  {
    double a, b;
    cin >> a >> b;
    pair<double, double> data = make_pair(a, b);
    QuadInsert(data, root->root);
  }
}
int findhouse(double x, double y, quadnode_t *&root)
{
  auto &room = root->rect;
  double lrmid = (room.left + room.right) / 2;
  double ubmid = (room.bottom + room.top) / 2;
  int sel;
  quadrect_t limit;
  if (x <= lrmid)
  {
    if (y <= ubmid)
    {
      sel = LL;
      limit = quadrect_t(room.left, ubmid, lrmid, room.bottom);
    }
    else
    {
      sel = UL;
      limit = quadrect_t(room.left, room.top, lrmid, ubmid);
    }
  }
  else
  {
    if (y <= ubmid)
    {
      sel = LR;
      limit = quadrect_t(lrmid, ubmid, room.right, room.bottom);
    }
    else
    {
      sel = UR;
      limit = quadrect_t(lrmid, room.top, room.right, ubmid);
    }
  }
  return sel;
}
void QuadInsert(pair<double, double> &data, quadnode_t *&root)
{ //递归插入
  double x = data.first, y = data.second;
  if (root->haskid)
  {
    int sel =findhouse(x,y,root);
    QuadInsert(data, root->sub[sel]);
  }
  else if (root->data.first != -1)
  {
    root->haskid = true;//有孩子了
    auto &room = root->rect;
    double lrmid = (room.left + room.right) / 2;
    double ubmid = (room.bottom + room.top) / 2;
    quadrect_t limit;
    for (int i = 0; i < 4; i++)
    {
      switch (i)
      {
      case UR://UR
      {
        limit = quadrect_t(lrmid, room.top, room.right, ubmid);
        break;
      }
      case UL:
      {
        limit = quadrect_t(room.left, room.top, lrmid, ubmid);
        break;
      }
      case LL:
      {
        limit = quadrect_t(room.left, ubmid, lrmid, room.bottom);
        break;
      }
      case LR:
      {
        limit = quadrect_t(lrmid, ubmid, room.right, room.bottom);
        break;
      }
      default:
        break;
      }
      root->sub[i] = new quadnode_t(limit);
    }
    int sel = findhouse(root->data.first,root->data.second,root);
    root->sub[sel]->data = root->data;//原来root里的数据
    
    sel = findhouse(x,y,root);//插入的数据
    root->data.first = -1;
    QuadInsert(data, root->sub[sel]);
  }
  else
  { //节点数据为空
    root->data = data;
  }
}
int main()
{
  quadtree_t *root = new quadtree_t();
  int t;
  cin >> t;
  QuadtreeBuild(root, t);
  queue<quadnode_t*> Q;
  Q.push(root->root);
  while(!Q.empty()){
    int siz = Q.size();
    while(siz--){
      quadnode_t * p = Q.front();
      Q.pop();
      if(p->data.first!=-1){
        cout<<p->data.first<<' '<<p->data.second<<endl;
      }
      for(int i=0;i<4;i++){
        if(p->sub[i]){
          Q.push(p->sub[i]);
        }
      }
    }
  }
  system("pause");
  return 0;
}
