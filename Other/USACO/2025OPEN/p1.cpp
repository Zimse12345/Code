#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,m,n,lx[N],ly[N],rx[N],ry[N];
int deg[N];
int mn[N*4],ans[N];
vector<int> g[N];
queue<int> q;

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

void build(int id,int L,int R,int x){
    mn[id]=x;
    if(L!=R)build(Lid,L,M,x),build(Rid,M+1,R,x);
    return;
}

void update(int id,int L,int R,int x,int y){
    mn[id]=min(mn[id],y);
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y);
        else update(Rid,M+1,R,x,y);
    }
    return;
}

int query(int id,int L,int R,int l,int r){
    if(r<L||R<l)return 1e9;
    if(l<=L&&r>=R)return mn[id];
    return min(query(Lid,L,M,l,r),query(Rid,M+1,R,l,r));
}

signed main(){
    cin>>T>>m;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>lx[i]>>ly[i]>>rx[i]>>ry[i];
            g[i].resize(0),deg[i]=0;
        }
        if(m==1){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)if(i!=j){
                    if(lx[j]<=rx[i]&&ly[j]<=ry[i]){
                        g[j].push_back(i);
                        ++deg[i];
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(!deg[i])q.push(i);
            }
            while(!q.empty()){
                int x=q.front();
                q.pop();
                printf("%d ",x);
                for(unsigned i=0;i<g[x].size();i++){
                    int y=g[x][i];
                    --deg[y];
                    if(!deg[y])q.push(y);
                }
            }
            printf("\n");
        }
        else{
            build(1,1,n*2,n*2+1);
            for(int i=n;i>=1;i--){
                if(query(1,1,n*2,1,rx[i])<=ry[i])ans[i]=0;
                else ans[i]=1;
                update(1,1,n*2,lx[i],ly[i]);
            }
            for(int i=1;i<=n;i++)printf("%d",ans[i]);
//            for(int i=1;i<=n;i++){
//                int tag=1;
//                for(int j=i+1;j<=n;j++){
//                    if(lx[j]<=rx[i]&&ly[j]<=ry[i]){
//                        tag=0;
//                        break;
//                    }
//                }
//                printf("%d",tag);
//            }
            printf("\n");
        }
    }
    return 0;
}


