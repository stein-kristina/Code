#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <cmath>
#include <list>
#include<algorithm>
#include <set>
using namespace std;

typedef struct _TreeNode{
    int val;
    _TreeNode* left;
    _TreeNode* right;
    _TreeNode(int num):val(num),left(nullptr),right(nullptr){}
    _TreeNode() : val(0), left(nullptr), right(nullptr) {}
    _TreeNode(int x, _TreeNode *left, _TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;


bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int,vector<int>> edge;//记录有向边
    vector<int> indegree(numCourses,0);//插入入度为0的点
    for(int i=0 ; i<prerequisites.size() ; i++){
        edge[prerequisites[i][1]].push_back(prerequisites[i][0]);//边A->B
        indegree[prerequisites[i][0]]++;
    }//统计入度
    queue<int> Q;//使用队列
    for(int i=0 ;i<numCourses ;i++){
        if(!indegree[i]){
            Q.push(i);
        }//入度为0的节点入队
    }
    int cnt = 0;//比较点的个数与入队的点数
    while(!Q.empty()){
        int p = Q.front();
        Q.pop();
        cnt++;//入队的点++
        for(auto &i : edge[p]){
            indegree[i]--;//所有与之相连的点的入度全部减一
            if(!indegree[i]){
                Q.push(i);
            }
        }
    }
    return cnt==numCourses;
}
int main(){
    vector<vector<int>> a = {{1,0}};
    cout<<canFinish(2,a);
}
//lc：802，找出度为0的，逆拓扑排序，宝
vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        vector<int> inDeg(n);
        for (int x = 0; x < n; ++x){
            for (int y : graph[x]){
                rg[y].push_back(x);
            }
            inDeg[x] = graph[x].size();
        }

        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                q.push(i);
            }
        }
        while (!q.empty()) {
            int y = q.front();
            q.pop();
            for (int x : rg[y]) {
                if (--inDeg[x] == 0) {
                    q.push(x);
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (inDeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }