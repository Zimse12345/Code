#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
#include <cstdlib>
#include <ctime>

#define ll long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,q,vis[N],dep[N],fa[N],p[N],pc,hev[N],cnt[N],tp[N];
int v[N<<2],val[N<<2],tag[N<<2],_L[N<<2],_R[N<<2],len[N<<2];
vector<int> g[N],ch[N];

void dfs1(int u,int d){
	vis[u]=1,dep[u]=d,cnt[u]=1;
	for(int i=0,v;i<int(g[u].size());i++){
		v=g[u][i];
		if(!vis[v]){
			dfs1(v,d+1),cnt[u]+=cnt[v];
			ch[u].push_back(v),fa[v]=u;
		}
	}
	return;
}

void dfs2(int u,int t){
	p[u]=++pc,tp[u]=t;
//	printf("[p[%d] = %d]\n",u,p[u]);
	for(int i=0,v;i<int(ch[u].size());i++){
		v=ch[u][i];
		if(cnt[v]>cnt[hev[u]])hev[u]=v;
	}
	if(hev[u])dfs2(hev[u],t);
	for(int i=0,v;i<int(ch[u].size());i++){
		v=ch[u][i];
		if(v!=hev[u])dfs2(v,v);
	}
	return;
}

void pushup(int id){
	if(_L[id]==_R[id])return;
	int Lid=id<<1,Rid=(id<<1)|1;
	val[id]=val[Lid]+val[Rid];
	if(v[_R[Lid]]==v[_L[Rid]])++val[id];
	return;
}

void pushdown(int id){
	if(_L[id]==_R[id]){
		if(tag[id])v[_L[id]]=tag[id],tag[id]=0;
		return;
	}
	if(tag[id]){
		v[_L[id]]=v[_R[id]]=tag[id];
		val[id]=len[id]-1;
		tag[id<<1]=tag[(id<<1)|1]=tag[id],tag[id]=0;
	}
	return;
}

void build(int L,int R,int id){
	_L[id]=L,_R[id]=R,len[id]=R-L+1;
	val[id]=tag[id]=0;
	if(L!=R){
		int M=(L+R)>>1;
		build(L,M,id<<1),build(M+1,R,(id<<1)|1);
	}
	return;
}

void chg(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(l<=L&&R<=r)tag[id]=x;
	else{
		int M=(L+R)>>1;
		if(l<=M)chg(L,M,id<<1,l,r,x);
		if(r>M)chg(M+1,R,(id<<1)|1,l,r,x);
		pushdown(id<<1),pushdown((id<<1)|1);
		pushup(id);
	}
	return;
}

int query(int L,int R,int id,int l,int r){
	pushdown(id);
	if(l<=L&&R<=r){
//		printf("{%d %d %d}\n",L,R,val[id]);
		return val[id];
	}
	int res=0;
	int M=(L+R)>>1;
	if(l<=M)res+=query(L,M,id<<1,l,r);
	if(r>M)res+=query(M+1,R,(id<<1)|1,l,r);
	pushdown(id<<1),pushdown((id<<1)|1);
	if(l<=M&&r>M&&v[_R[id<<1]]==v[_L[(id<<1)|1]])++res;//printf("*{%d %d}\n",v[_R[id<<1]],v[_L[(id<<1)|1]]);
//	printf("{%d %d %d}\n",L,R,res);
	return res;
}

void up(int L,int R,int id,int x){
	pushdown(id);
	if(L!=R){
		int M=(L+R)>>1;
		if(x<=M)up(L,M,id<<1,x);
		else up(M+1,R,(id<<1)|1,x);
	}
	return;
}

signed main(){
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	T=read();
	while(T--){
		n=read(),q=read(),pc=0;
		for(int i=1;i<=n;i++)g[i].resize(0),ch[i].resize(0),vis[i]=fa[i]=cnt[i]=tp[i]=dep[i]=hev[i]=0,v[i]=i;
		for(int i=1,u,v;i<n;i++)u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
		dfs1(1,1),dfs2(1,1),build(1,n,1);
		for(int i=1,op,a,b;i<=q;i++){
			op=read(),a=read(),b=read();
			if(op==1){
				while(tp[a]!=tp[b]){
					if(dep[tp[a]]>=dep[tp[b]]){
						int A=tp[a];
//						printf("chg(%d %d %d)\n",A,a,n+i);
						chg(1,n,1,p[A],p[a],n+i),a=fa[A];
					}
					else{
						int B=tp[b];
//						printf("chg(%d %d %d)\n",B,b,n+i);
						chg(1,n,1,p[B],p[b],n+i),b=fa[B];
					}
				}
				int k1=a,k2=b;
				if(dep[b]<dep[a])k1=b,k2=a;
				
//				printf("chg-(%d %d %d)\n",k1,k2,n+i);
				chg(1,n,1,p[k1],p[k2],n+i);
			}
			else{
				int ans=0;
				while(tp[a]!=tp[b]){
					if(dep[tp[a]]>=dep[tp[b]]){
						int A=tp[a];
//						printf("query(%d %d)\n",A,a);
						ans+=query(1,n,1,p[A],p[a]);
						up(1,n,1,p[A]),up(1,n,1,p[fa[A]]);
//						printf("[%d %d %d %d]\n",A,fa[A],v[A],v[fa[A]]);
						if(A!=1&&v[p[A]]==v[p[fa[A]]])++ans;
						a=fa[A];
					}
					else{
						int B=tp[b];
//						printf("query(%d %d)\n",B,b);
						ans+=query(1,n,1,p[B],p[b]);
						up(1,n,1,p[B]),up(1,n,1,p[fa[B]]);
//						printf("[%d %d %d %d]\n",B,fa[B],v[B],v[fa[B]]);
						if(B!=1&&v[p[B]]==v[p[fa[B]]])++ans;
						b=fa[B];
					}
				}
				int k1=a,k2=b;
				if(dep[b]<dep[a])k1=b,k2=a;
				
//				printf("query-(%d %d)\n",k1,k2);
				ans+=query(1,n,1,p[k1],p[k2]);
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}
