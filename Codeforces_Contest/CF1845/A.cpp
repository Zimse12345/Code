#include <bits/stdc++.h>
using namespace std;
const int N=1.01e6;
int T,n,k,x,ans[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>x;
        if(x==1&&k==1){
            printf("NO\n");
            continue;
        }
        int v=1,tot=0;
        if(x==1)++v;
        while(n>=v)ans[++tot]=v,n-=v;
        ans[tot]+=n;
        if(ans[tot]>k||ans[tot]==x){
            printf("NO\n");
            continue;
        }
        printf("YES\n%d\n",tot);
        for(int i=1;i<=tot;i++)printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}



