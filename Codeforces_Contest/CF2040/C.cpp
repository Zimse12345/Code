#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,k,t[N],ans[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        --k;
        for(int i=1;i<=n;i++)t[i]=0;
        for(int i=n-1;i>=1;i--){
            if(k&1)t[i]=1;
            k/=2;
        }
        if(k){
            printf("-1\n");
            continue;
        }
        int l=1,r=n;
        for(int i=1;i<=n;i++){
            if(t[i])ans[r--]=i;
            else ans[l++]=i;
        }
        for(int i=1;i<=n;i++)printf("%lld ",ans[i]);
        printf("\n");
    }
    return 0;
}


