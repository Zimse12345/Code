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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2048,Mod=998244353,INF=1e9+7;
int n,m,len,tot1[N],ch[N*N][2],tag[N*N],tot,mi[N],suf[N],ans;
char s[N][N],t[N][N];

void dfs(int u,int sum,int d,int f){
	if(!tag[u]){
		sum+=suf[d];
		ans=min(ans,sum);
		return;
	}
	if(d>len)return;
	tag[0]=0;
	dfs(ch[u][0],sum+tot1[d],d+1,0),dfs(ch[u][1],sum+n-tot1[d],d+1,1);
	return;
}

signed main(){
	n=read(),m=read(),len=read(),ans=INF;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=len;j++)if(s[i][j]=='1')++tot1[j];
	}
	for(int i=len;i>=1;i--){
		mi[i]=min(tot1[i],n-tot1[i]);
		suf[i]=suf[i+1]+mi[i];
	}
	tag[0]=1;
	for(int i=1;i<=m;i++){
		scanf("%s",t[i]+1);
		int pos=0;
		for(int j=1,p;j<=len;j++){
			p=t[i][j]-'0';
			if(!ch[pos][p])ch[pos][p]=++tot;
			pos=ch[pos][p],tag[pos]=1;
		}
	}
	dfs(0,0,1,-1);
	printf("%d\n",ans);
	return 0;
}

