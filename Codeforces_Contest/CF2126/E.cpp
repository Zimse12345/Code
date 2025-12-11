#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,p[N],s[N],a[N];

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

inline int lcm(int x,int y){
    return x/gcd(x,y)*y;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>p[i];
        int tag=1;
        for(int i=1,v=0;i<=n;i++){
            cin>>s[i];
            a[i]=lcm(p[i],s[i]);
            v=gcd(v,a[i]);
            if(v!=p[i])tag=0;
        }
        for(int i=n,v=0;i>=1;i--){
            v=gcd(v,a[i]);
            if(v!=s[i])tag=0;
        }
        if(tag)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}


