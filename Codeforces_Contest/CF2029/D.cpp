#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m;
int U[N],V[N],t[N];
int ans,A[N],B[N],C[N];

signed main(){
    cin>>T;
    while(T--){
        ans=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++)t[i]=0;
        for(int i=1;i<=m;i++){
            cin>>U[i]>>V[i];
            if(V[i]<U[i])swap(U[i],V[i]);
        }
        for(int i=1;i<=m;i++)if(U[i]==1)t[V[i]]=1;
        for(int i=1;i<=m;i++)if(U[i]!=1){
            ++ans;
            A[ans]=U[i],B[ans]=V[i],C[ans]=1;
            t[U[i]]^=1,t[V[i]]^=1;
        }
        int p=0;
        for(int i=2;i<=n;i++)if(t[i])p=i;
        if(p){
            for(int i=2;i<=n;i++)if(!t[i]){
                ++ans;
                A[ans]=i,B[ans]=p,C[ans]=1;
                p=i;
            }
        }
        printf("%d\n",ans);
        for(int i=1;i<=ans;i++)printf("%d %d %d\n",A[i],B[i],C[i]);
    }
    return 0;
}


