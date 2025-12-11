#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,a,b,k;

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>a>>b>>k;
        int g=gcd(a,b);
        a/=g,b/=g;
        if(a==b||(a<=k&&b<=k))printf("1\n");
        else printf("2\n");
    }
    return 0;
}


