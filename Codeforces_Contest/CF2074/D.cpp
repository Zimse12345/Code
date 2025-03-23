#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,m,x[N],r[N];
map<int,int> mx,vis;

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>x[i];
        mx.clear(),vis.clear();
        for(int i=1;i<=n;i++){
            cin>>r[i];
            for(int j=x[i]-r[i];j<=x[i]+r[i];j++){
                vis[j]=1;
                mx[j]=max(mx[j],r[i]*r[i]-(x[i]-j)*(x[i]-j));
            }
        }
        int ans=0;
        for(map<int,int>::iterator it=vis.begin();it!=vis.end();it++){
            int p=it->first;
            int d=mx[p];
            int s=floor(sqrt(d));
            while(s*s>d)--s;
            while((s+1)*(s+1)<=d)++s;
            ans+=s*2+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


