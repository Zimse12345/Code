#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,a[N];
struct node{
    int nd,to;
    node(int nd=0,int to=0):nd(nd),to(to){}
    bool operator < (const node& _)const{return nd<_.nd;}
}b[N];
map<int,int> vis;

signed main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>=n-i+1)b[i]=node(a[i]-(n-i+1),a[i]-(n-i+1)+(i-1));
            else b[i]=node(0,0);
        }
        vis.clear();
        vis[0]=1;
        sort(b+1,b+n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            if(vis[b[i].nd])vis[b[i].to]=1,ans=max(ans,b[i].to);
        }
        printf("%lld\n",n+ans);
    }
    return 0;
}


