#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n,m,k,q,vis[N];
vector<int> a[N],b[N];

signed main(){
    cin>>n>>m>>k;
    for(int i=1,x,y;i<=k;i++){
        cin>>x>>y;
        a[x].push_back(i);
        b[y].push_back(i);
    }
    cin>>q;
    while(q--){
        int ty,i,ans=0;
        cin>>ty>>i;
        if(ty==1){
            for(unsigned j=0;j<a[i].size();j++){
                if(!vis[a[i][j]])++ans,vis[a[i][j]]=1;
            }
            a[i].resize(0);
        }
        else{
            for(unsigned j=0;j<b[i].size();j++){
                if(!vis[b[i][j]])++ans,vis[b[i][j]]=1;
            }
            b[i].resize(0);
        }
        printf("%d\n",ans);
    }
    return 0;
}


