#include<iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int weightValue;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int num):weightValue(num),left(nullptr),right(nullptr){}
};
struct cmp{
    bool operator()(TreeNode* a,TreeNode* b){
        return a->weightValue>b->weightValue;
    }
};

void del(TreeNode* r){
    if(!r) return;
    del(r->left);
    del(r->right);
    delete r;
}
int main(){
    int n;
    cin>>n;
    priority_queue<TreeNode* , vector<TreeNode*>,cmp> Q;
    while(n--) {
        
        int fre;
        cin>>fre;
        TreeNode *p=new TreeNode (fre);
        Q.push(p);
    }
    while(Q.size()>1){
        TreeNode *p1=Q.top();
        Q.pop();
        TreeNode *p2=Q.top();
        Q.pop();
        TreeNode *p=new TreeNode (p1->weightValue+p2->weightValue);
        p->left=p1;
        p->right=p2;
        Q.push(p);
    }
    TreeNode * root = Q.top();
    queue<TreeNode*> ans;
    int step=0;
    int play=0;
    ans.push(root);
    while(!ans.empty()){
        int siz=ans.size();
        while(siz--){
            TreeNode *p=ans.front();
            ans.pop();
            if(!p->left&&!p->right) play+=p->weightValue*step;
            if(p->left){
                ans.push(p->left);
            }
            if(p->right){
                ans.push(p->right);
            }
        }
        step++;
    }
    cout<<play<<endl;
    del(root);
}