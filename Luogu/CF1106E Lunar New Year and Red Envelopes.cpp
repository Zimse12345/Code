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

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=2e14;
int n,m,k,s[N],t[N],d[N],w[N],f[N][210],ans=INF;
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{if(x==A.x)return y>A.y;return x>A.x;}};
vector<node> inq[N],outq[N];
multiset<node> S;
node p[N];

signed main(){
	n=read(),m=read(),k=read();
	for(int i=1;i<=k;i++){
		s[i]=read(),t[i]=read(),d[i]=read(),w[i]=read();
		inq[s[i]].push_back(node(w[i],d[i])),outq[t[i]+1].push_back(node(w[i],d[i]));
	}
	for(int i=1;i<=n;i++){
		for(unsigned j=0;j<inq[i].size();j++)S.insert(inq[i][j]);
		for(unsigned j=0;j<outq[i].size();j++)S.erase(S.find(outq[i][j]));
		if(!S.size())p[i]=node(0,i); 
		else p[i]=*S.begin();
	}
	for(int i=0;i<=n+1;i++)for(int j=0;j<=m;j++)f[i][j]=INF;
	f[1][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			if(j<m)f[i+1][j+1]=min(f[i+1][j+1],f[i][j]);
			f[p[i].y+1][j]=min(f[p[i].y+1][j],f[i][j]+p[i].x);
		}
	}
	for(int j=0;j<=m;j++)ans=min(ans,f[n+1][j]);
	printf("%lld\n",ans);
	return 0;
}

