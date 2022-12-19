#include<iostream>
#include<climits>
#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
 struct linkNode {
     int val;
     linkNode *next;
     linkNode(int x) : val(x), next(nullptr) {}
 };

linkNode *getIntersectionNode(linkNode *headA, linkNode *headB){
  linkNode* p1 = headA,*p2 =headB;
  while(p1&&p2){
    if(p1==p2) return p1;
    if(p1->next) p1=p1->next;
    else p1 = headB;
    if(p2->next) p2=p2->next;
    else p2 = headA;
  }
  return nullptr;
}

#define MAXN 1000
#define MAXL 100
#define random(x) (rand()%x)



linkNode* initList(int n) {
    linkNode* pre = nullptr;
    linkNode* h = nullptr;
    int t;
    for (int i = 0; i < n; i++) {
        cin >> t;
        linkNode* tmp = new linkNode(t);
        if (i == 0) {
            pre = tmp;
            h = pre;
        } else {
            pre->next = tmp;
            pre = pre->next;
        }
    }
    return h;
}

int main(int argc, const char * argv[]) {
    vector<int> a = {1,2,3};
    cout<<lower_bound(a.begin(),a.end(),4)-a.begin();
    system("pause");
}
