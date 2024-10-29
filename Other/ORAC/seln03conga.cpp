#include <bits/stdc++.h>
using namespace std;

const int N=1.01e5;
int n,k,a[N],ans[N],t,Ans[N],T,sum,vis[N];
vector<int> g[N];
vector<int> p[N];

signed main(){
    freopen("congain.txt","r",stdin);
    freopen("congaout.txt","w",stdout);
    
    cin>>n>>k;
    int L=3000,R=0;
    int l=3000,r=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>k){
            g[a[i]].push_back(i);
            L=min(L,a[i]);
            R=max(R,a[i]);
        }
        else{
            l=min(l,a[i]);
            r=max(r,a[i]);
        }
    }
    for(int i=1;i<k;i++){
        ans[++t]=i;
        if(a[i]<=a[i+1]){
            for(int j=a[i];j<=a[i+1];j++){
                for(unsigned id=0;id<g[j].size();id++){
                    ans[++t]=g[j][id];
                }
                g[j].resize(0);
            }
        }
        else{
            for(int j=a[i];j>=a[i+1];j--){
                for(unsigned id=0;id<g[j].size();id++){
                    ans[++t]=g[j][id];
                }
                g[j].resize(0);
            }
        }
    }
    ans[++t]=k;
    for(unsigned id=0;id<g[a[k]].size();id++)ans[++t]=g[a[k]][id];
    g[a[k]].resize(0);
    if(R>r){
        if(R-a[ans[1]]<=(R-r)*2&&a[ans[1]]>=a[ans[t]]){
            for(int j=R;j>r;j--){
                for(unsigned id=0;id<g[j].size();id++){
                    p[1].push_back(g[j][id]);
                }
                g[j].resize(0);
            }
        }
        else if(R-a[ans[t]]<=(R-r)*2){
            for(int j=r+1;j<=R;j++){
                for(unsigned id=0;id<g[j].size();id++){
                    p[t+1].push_back(g[j][id]);
                }
                g[j].resize(0);
            }
        }
        else{
            for(int i=1;i<=t;i++)if(a[ans[i]]==r){
                for(int j=r+1;j<=R;j++){
                    for(unsigned id=0;id<g[j].size();id++){
                        p[i].push_back(g[j][id]);
                    }
                    g[j].resize(0);
                }
            }
        }
    }
    if(L<l){
        if(a[ans[t]]-L<=(l-L)*2&&a[ans[t]]<=a[ans[1]]){
            for(int j=l-1;j>=L;j--){
                for(unsigned id=0;id<g[j].size();id++){
                    p[t+1].push_back(g[j][id]);
                }
                g[j].resize(0);
            }
        }
        else if(a[ans[1]]-L<=(l-L)*2){
            for(int j=L;j<l;j++){
                for(unsigned id=0;id<g[j].size();id++){
                    p[1].push_back(g[j][id]);
                }
                g[j].resize(0);
            }
        }
        else{
            for(int i=1;i<=t;i++)if(a[ans[i]]==l){
                for(int j=l-1;j>=L;j--){
                    for(unsigned id=0;id<g[j].size();id++){
                        p[i].push_back(g[j][id]);
                    }
                    g[j].resize(0);
                }
            }
        }
    }
    for(int i=1;i<=t+1;i++){
        for(unsigned j=0;j<p[i].size();j++)Ans[++T]=p[i][j];
        if(i<=t)Ans[++T]=ans[i];
    }
    for(int i=1;i<=T;i++)vis[Ans[i]]=1;
    for(int i=1;i<=n;i++)if(!vis[i])Ans[++T]=i;
    for(int i=1;i<T;i++){
        if(a[Ans[i]]<a[Ans[i+1]])sum+=a[Ans[i+1]]-a[Ans[i]];
        else sum+=a[Ans[i]]-a[Ans[i+1]]; 
    }
    printf("%d\n",sum);
    for(int i=1;i<=T;i++)printf("%d\n",Ans[i]);
    return 0;
}

/*
5 3
1900 1300 1500 1200 1600
*/

