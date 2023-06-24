#include <bits/stdc++.h>
#define gc getchar
using namespace std;

int read(){int x=0,y=1;char c=gc();while(c<48||57<c){if(c==45)
y=-1;c=gc();}while(47<c&&c<58)x=x*10+c-48,c=gc();return x*y;}

const int V=5.01e5,INF=1e9;
vector<int> pos[V];
int X[V],Y[V],sum[V*4][2],mn[V*4][2],mx[V*4][2];

#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

inline void update(int id,int L,int R,int x,int y,int t){
    sum[id][t]+=y;
    if(L==R)mn[id][t]+=y,mx[id][t]+=y;
    if(L!=R){
        if(x<=M)update(Lid,L,M,x,y,t);
        if(x>M)update(Rid,M+1,R,x,y,t);
        mn[id][t]=min(mn[Lid][t],sum[Lid][t]+mn[Rid][t]);
        mx[id][t]=max(mx[Lid][t],sum[Lid][t]+mx[Rid][t]);
    }
    return;
}

inline int query(int id,int L,int R,int l,int r,int t){
    if(r<l)return 0;
    if(l<=L&&r>=R)return sum[id][t];
    if(r<L||R<l)return 0;
    return query(Lid,L,M,l,r,t)+query(Rid,M+1,R,l,r,t);
}

inline int qmin(int id,int L,int R,int l,int r,int t){
    if(l<=L&&r>=R)return mn[id][t];
    if(r<L||R<l)return INF;
    return min(qmin(Lid,L,M,l,r,t),qmin(Rid,M+1,R,l,r,t)+sum[Lid][t]);
}

inline int qmax(int id,int L,int R,int l,int r,int t){
    if(l<=L&&r>=R)return mx[id][t];
    if(r<L||R<l)return -INF;
    return max(qmax(Lid,L,M,l,r,t),qmax(Rid,M+1,R,l,r,t)+sum[Lid][t]);
}

int sequence(int N, std::vector<int> A){
    int ans=0;
    for(int i=0;i<N;i++){
        pos[A[i]].push_back(i);
    }
    for(int i=0;i<N;i++)update(1,0,N-1,i,1,0),update(1,0,N-1,i,1,1);
    for(int i=1;i<=N;i++)if(pos[i].size()){
        for(unsigned j=0;j<pos[i].size();j++)update(1,0,N-1,pos[i][j],-2,0);
        for(int x=0,p0=0,p1=0;x<pos[i].size();x++){
            p0=max(p0,x),p1=max(p1,x);
            int pmx=max(qmax(1,0,N-1,0,pos[i][x]-1,0),0),pmn=min(qmin(1,0,N-1,0,pos[i][x]-1,1),0);
            while(p0<pos[i].size()&&pmx>=qmin(1,0,N-1,pos[i][p0],N-1,0))++p0;
            while(p1<pos[i].size()&&pmn<=qmax(1,0,N-1,pos[i][p1],N-1,1))++p1;
            ans=max(ans,min(p0,p1)-x);
        }
        for(unsigned j=0;j<pos[i].size();j++)update(1,0,N-1,pos[i][j],-2,1);
    }
    return ans;
}

int main(){
    int n=read();
    vector<int> a;
    for(int i=1;i<=n;i++)a.push_back(read());
    printf("%d\n",sequence(n,a));
    return 0;
}
