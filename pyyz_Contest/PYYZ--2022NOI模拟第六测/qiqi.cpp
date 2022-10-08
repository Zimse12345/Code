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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,q,ch[N][26],fa[N],tot,ed[N],ans,c0[N],c1[N];
char s[1024][11000];

void dfs(int u){
	for(int i=0;i<26;i++)if(ch[u][i]){
		dfs(ch[u][i]);
		c0[u]+=c0[ch[u][i]];
		c1[u]+=c1[ch[u][i]];
	}
	if(u){
		ans+=min(c0[u],c1[u]);
	}
	return;
}

signed main(){
//	freopen("qiqi2.in","r",stdin);
//	freopen("qiqi.out","w",stdout);
	
	n=read(),q=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		int len=strlen(s[i]+1),pos=0;
		for(int j=len;j>=1;j--){
			if(!ch[pos][s[i][j]-'a']){
				ch[pos][s[i][j]-'a']=++tot;
				fa[tot]=pos;
			}
			pos=ch[pos][s[i][j]-'a'];
		}
		ed[i]=pos;
	}
	while(q--){
		ans=0;
		int l0=read(),r0=read(),l1=read(),r1=read();
		for(int i=l0;i<=r0;i++)++c0[ed[i]];
		for(int i=l1;i<=r1;i++)++c1[ed[i]];
		dfs(0);
		for(int i=1;i<=tot;i++)c0[i]=c1[i]=0;
		printf("%d\n",ans);
	}
	return 0;
}

