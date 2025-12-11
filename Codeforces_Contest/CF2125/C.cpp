#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,l,r;

int f(int x){
    int s=x;
    s-=x/2+x/3+x/5+x/7;
    s+=x/6+x/10+x/14+x/15+x/21+x/35;
    s-=x/30+x/42+x/70+x/105;
    s+=x/210;
    return s;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>l>>r;
        printf("%lld\n",f(r)-f(l-1));
    }
    return 0;
}


