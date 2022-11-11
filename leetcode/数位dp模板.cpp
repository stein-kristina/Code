//
// Created by 86189 on 2022/11/1.
//
#include<iostream>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

typedef struct _TreeNode{
    int weightValue;
    _TreeNode* left;
    _TreeNode* right;
    _TreeNode(int num):weightValue(num),left(nullptr),right(nullptr){}
}TreeNode;
string s;
vector<int> dp;
int numdp(int index,bool islimit,bool isNum,vector<string>& digits){
    //islimit是前面是否都是按最大填，isNum是前面填数字没有
    if(index == s.size()){
        return isNum;//如果填了数字，就是合法的
    }
    if(!islimit && isNum && dp[index]!=-1){
        //这一状态已经计算过了,去重
        return dp[index];
    }
    int max_num;
    if(islimit) max_num = s[index]-'0';
    else max_num = 9;
    int ret = 0;
    if(!isNum){
        //没有填过数字
        ret = numdp(index+1, false, false, digits);
        //那么我就可以选择跳过这位
    }

    for(auto& i:digits){
        if(i[0]-'0'>max_num){
            break;
        }
        ret += numdp(index+1, islimit&&(i[0]-'0' ==max_num), true,digits);
    }
    if(!islimit && isNum) dp[index]=ret;//在不受任何约束的条件下记录结果
    return ret;
}
int atMostNGivenDigitSet(vector<string>& digits, int n) {
    s= to_string(n);
    int m=s.size();
    dp.resize(m,-1);
    return numdp(0, true, false,digits);
}
int main(){
    vector<string> a={"1","4","9"};
    cout<<atMostNGivenDigitSet(a,1000000000);
}
