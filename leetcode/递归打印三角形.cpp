//
// Created by 86189 on 2022/9/24.
//

vector<string> get(int n){
    int len = 1 << n;
    vector<string> ans(len,string(""));

    if(n==1){
        ans[0]=string(" /\\ ");
        ans[1]=string("/__\\");
    }
    else{
        vector<string> prev = get(n-1);
        for(int i = 0; i < (len / 2) ;i++){
            ans[(len / 2) + i] = prev[i] + prev[i];
            for(int j = 0;j < (len / 2); j++){
                ans[i] += ' ';
            }
            ans[i] += prev[i];
        }
    }
    return ans;
}