#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,q,p[N],cnt[N],ans;

signed main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++)p[i]=i,cnt[i]=1;
    while(q--){
        int ty;
        cin>>ty;
        if(ty==2){
            printf("%d\n",ans);
            continue;
        }
        int x,y;
        cin>>x>>y;
        --cnt[p[x]];
        if(cnt[p[x]]==1)--ans;
        p[x]=y;
        if(cnt[p[x]]==1)++ans;
        ++cnt[p[x]];
    }
    return 0;
}


