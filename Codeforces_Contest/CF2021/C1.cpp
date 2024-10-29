#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,q,a[N],b[N],p[N];

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>q;
        for(int i=1;i<=n;i++)cin>>a[i],p[a[i]]=i;
        for(int i=1;i<=m;i++)cin>>b[i];
        int t=0,tag=0;
        for(int i=1;i<=m;i++){
            if(p[b[i]]>t+1){
                tag=1;
                break;
            }
            t=max(t,p[b[i]]);
        }
        if(tag)printf("TIDAK\n");
        else printf("YA\n");
    }
    return 0;
}


