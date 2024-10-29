#include <bits/stdc++.h>
using namespace std;

const int N=1500;
int L,S,n,G[N][N],X[N],Y[N];

struct edge{
    int u,v,w;
    edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
    bool operator < (const edge& _)const{return w<_.w;}
}e[N*N];
int p[N],m,c[N],ans,mx;

vector<int> g[N*N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& _)const{return x>_.x;}
};
priority_queue<node> q;
int vis[N*N],dis[N*N];

int id(int x,int y){
    return x*(L*3+S+2)+y;
}

void Dij(){
	for(int i=0;i<N*N;i++)dis[i]=1e9;
	int s=id(L*2,L*2);
	dis[s]=0,q.push(node(0,s));
	while(!q.empty()){
		int u=q.top().y;
		q.pop();
		if(vis[u]++)continue;
		for(unsigned i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				q.push(node(dis[v],v));
			}
		}
	}
	return;
}

int gcd(int x,int y){
    return y?gcd(y,x%y):x;
}

int _abs(int x){
    return x<0?-x:x;
}

int F(int x){
    if(p[x]!=x)p[x]=F(p[x]);
    return p[x];
}

signed main(){
    cin>>L>>S>>n;
    for(int x=0;x<=L;x++){
        for(int y=0;y<=L;y++)G[x][y]=gcd(x,y);
    }
    for(int i=0;i<=L*3+S;i++){
        for(int j=0;j<=L*3+S;j++){
            for(int x=0;x<=L;x++){
                for(int y=0;y<=L;y++)if(x*x+y*y<=L*L&&G[x][y]==1){
                    if(i+x<=L*3+S&&j+y<=L*3+S){
                        g[id(i,j)].push_back(id(i+x,j+y));
                        g[id(i+x,j+y)].push_back(id(i,j));
                    }
                    if(i+x<=L*3+S&&j-y>=0){
                        g[id(i,j)].push_back(id(i+x,j-y));
                        g[id(i+x,j-y)].push_back(id(i,j));
                    }
                }
            }
        }
    }
    Dij();
    for(int i=1;i<=n;i++){
        cin>>X[i]>>Y[i];
        p[i]=i,c[i]=1;
        for(int j=1;j<i;j++){
            int dx=_abs(X[i]-X[j]),dy=_abs(Y[i]-Y[j]);
            e[++m]=edge(i,j,dis[id(L*2+dx,L*2+dy)]);
        }
    }
    mx=1;
    sort(e+1,e+m+1);
    for(int i=1;i<=m;i++){
        if(mx*2>=n)break;
        int u=F(e[i].u),v=F(e[i].v);
        if(u!=v){
            ans=e[i].w;
            p[u]=v;
            c[v]+=c[u];
            mx=max(mx,c[v]);
        }
    }
    printf("%d\n",ans);
    return 0;
}


