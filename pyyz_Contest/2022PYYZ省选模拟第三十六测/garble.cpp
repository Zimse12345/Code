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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,len[N],ans;
char s[N][N];
struct node{
	int l,r,z;
	node(int l=0,int r=0,int z=0):l(l),r(r),z(z){}
}p[N*N];
int tot;
int hd[N*N],nxt[N*N],to[N*N],ec,f[N*N];
void add(int u,int v){
	nxt[++ec]=hd[u],hd[u]=ec,to[ec]=v;
	return;
}

void dp(int u){
	if(f[u])return;
	f[u]=1;
	for(int i=hd[u];i;i=nxt[i])dp(to[i]),f[u]=max(f[u],f[to[i]]+1);
//	printf("f[%d]=%d\n",u,f[u]);
	return;
}

signed main(){
//	freopen("garble3.in","r",stdin);
//	freopen("d.out","w",stdout);
	T=read();
	while(T--){
		n=read(),tot=ans=ec=0;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1),len[i]=strlen(s[i]+1);
			for(int l=1;l<=len[i];l++){
				for(int r=l;r<=len[i];r++)p[++tot]=node(l,r,i);
			}
		}
		for(int i=1;i<=tot;i++){
			for(int j=1;j<=tot;j++)if(i^j){
				//i -> j
				if(p[i].r-p[i].l<p[j].r-p[j].l)continue;
				if(p[i].r-p[i].l==p[j].r-p[j].l&&(p[i].z>p[j].z||(p[i].z==p[j].z&&p[i].l>p[j].l)))continue;
				int S=p[j].r-p[j].l+1;
				int tag=0;
				for(int L=p[i].l;L+S-1<=p[i].r;L++){
					int tg=1;
					for(int m=0;m<S;m++)if(s[p[i].z][L+m]!=s[p[j].z][p[j].l+m]){tg=0;break;}
					if(tg){
						tag=1;
						break;
					}
				}
				if(tag){
					add(i,j);
//					printf("node(%d %d %d) -> node(%d %d %d)\n",
//					p[i].l,p[i].r,p[i].z,p[j].l,p[j].r,p[j].z);
				}
			}
		}
		for(int i=1;i<=tot;i++)dp(i),ans=max(ans,f[i]);
		printf("%d\n",ans);
		for(int i=1;i<=tot;i++)hd[i]=f[i]=0;
		for(int i=1;i<=ec;i++)nxt[i]=to[i]=0;
	}
	return 0;
}

