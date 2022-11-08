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
using namespace std;

typedef struct _TreeNode{
    int val;
    _TreeNode* left;
    _TreeNode* right;
    _TreeNode(int num):val(num),left(nullptr),right(nullptr){}
    _TreeNode() : val(0), left(nullptr), right(nullptr) {}
    _TreeNode(int x, _TreeNode *left, _TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;
struct Node{
    int v,cost;
    Node(int a,int b):v(a),cost(b){}
    bool operator<(const Node& t)const{
        return cost>t.cost;
    }
    bool operator<=(const Node& t)const{
        return cost<=t.cost;
    }
    const Node& operator=(const Node& a){
        v=a.v;cost=a.cost;
        return *this;
    }
};

int main(){
    //priority_queue<Node> q;
    int t,temp;
    cin>>t;
    while(t--){
        int m;
        cin>>m;
        priority_queue<Node> ver[m];
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                cin>>temp;
                if(i==j) continue;
                ver[i].push(Node(j,temp));
            }
        }
        vector<bool> vis(m,false);
        vis[0]=1;
        vector<int> nv;
        int ans=0;
        nv.push_back(0);
        while(nv.size()<m){
            Node temp(-1,70000);
            for(auto i:nv){
                while(!ver[i].empty()&&vis[ver[i].top().v]==1){
                    ver[i].pop();
                }
                if(!ver[i].empty()) temp=(temp<=ver[i].top())?temp:ver[i].top();
            }
            nv.push_back(temp.v);ans+=temp.cost;vis[temp.v]=1;
        }
        cout<<ans;
        getchar();
        return 0;
    }
}