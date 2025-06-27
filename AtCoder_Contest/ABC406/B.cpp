#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,k,num=1,lim=1;

signed main(){
    cin>>n>>k;
    while(k--)lim*=10;
    while(n--){
        int x=0;
        cin>>x;
        if(lim/num<x){
            num=1;
        }
        else{
            num*=x;
            if(num>=lim)num=1;
        }
    }
    printf("%lld\n",num);
    return 0;
}


