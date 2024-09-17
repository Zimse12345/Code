#include <bits/stdc++.h>
using namespace std;

const int N=1505;
int T,l,n,m,a[N],b[N][N],V;
struct node{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
    bool operator < (const node& _)const{
        if(x==_.x)return y<_.y;
        return x>_.x;
    }
};
vector<node> p[N*N];
int tag[N][N];

bool ck(int x,int y){
    int t=-1,mx=0;
    bool res=false;
    for(unsigned i=0;i<p[x].size();i++){
        while(t+1<int(p[y].size())&&p[y][t+1].x>p[x][i].x){
            ++t;
            if(V!=tag[p[y][t].x][p[y][t].y])mx=max(mx,p[y][t].y);
        }
        if(mx<=p[x][i].y){
            res=true;
        }
        else tag[p[x][i].x][p[x][i].y]=V+1;
    }
    ++V;
    return res;
}

signed main(){
    cin>>T;
    V=1;
    while(T--){
        V+=2;
        cin>>l>>n>>m;
        for(int i=1;i<=l;i++)cin>>a[i];
        for(int i=1;i<=n*m;i++)p[i].resize(0);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>b[i][j];
                p[b[i][j]].push_back(node(i,j));
            }
        }
        for(int i=1;i<=n*m;i++)if(p[i].size()){
            sort(p[i].begin(),p[i].end());
        }
        while(l&&!p[a[l]].size())--l;
        int win=l;
        for(int i=l;i>=1;i--){
            if(win==i-1||ck(a[i-1],a[i])||!p[a[i]].size())win=i-1;
            else win=i-2,++V;
        }
        if(win%2==0)printf("N\n");
        else printf("T\n");
    }
    return 0;
}


