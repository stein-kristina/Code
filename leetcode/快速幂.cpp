#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll quick_pow(ll x,ll n,ll m){
	ll res = 1;
	while(n > 0){
		if(n & 1)	res = res * x % m;
		x = x * x % m;
		n >>= 1;//相当于n=n/2.详情请参考位移运算符。
	}
	return res;
} 