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
int n,m,u[N],v[N],w[N],nxt[N];
vector<int> g[N];

signed main(){
	n=read(),m=read();
	if(n<=7){
		int ans=INF;
		for(int i=0;i<m;i++)u[i]=read(),v[i]=read(),w[i]=read();
		for(int i=0;i<(1<<m);i++){
			int W=0,c=0,p=0,C;
			for(int j=1;j<=n;j++)g[j].clear();
			for(int j=0;j<m;j++)if(i&(1<<j)){
				W+=w[j],++c,p=u[j];
				g[u[j]].push_back(v[j]);
			}
			if(W>=0)continue;
			int tag=1;
			for(int j=1;j<=n;j++)nxt[j]=0;
			for(int j=1;j<=n;j++){
				if(signed(g[j].size())>1){tag=0;break;}
				if(signed(g[j].size())==1)nxt[j]=g[j][0];
			}
			if(!tag)continue;
			C=c;
			int q=p;
			for(;;){
				--c,q=nxt[q];
				if(q==p||!q)break;
				if(c<0)break;
			}
			if(c==0&&p==q)ans=min(ans,C);
		}
		if(ans==INF)ans=0;
		printf("%d\n",ans);
	}
	else printf("0\n");
	return 0;
}

