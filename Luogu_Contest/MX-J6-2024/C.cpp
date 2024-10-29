#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m;

inline int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        if(m%n!=0)printf("-1\n");
        else{
            int ans=0;
            while(n<m){
                int g=gcd(m/n,n);
                n*=g,++ans;
                if(g==1){
                    ans=-1;
                    break;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}


