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

#define lc ch[u][0]
#define rc ch[u][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,cnt[N],f[N][2],g[N][2],fa[N],tag[N];
char s[N];
vector<int> ch[N];

void dfs(int u){
	if(cnt[u]==0)f[u][0]=g[u][0]=0,f[u][1]=g[u][1]=1;
	else if(cnt[u]==1){//printf("(%d %d)\n",u,lc);
		dfs(lc);
		f[u][0]=min(f[lc][0],f[lc][1]),f[u][1]=f[lc][0]+1;
		g[u][0]=max(g[lc][0],g[lc][1]),g[u][1]=g[lc][0]+1;
	}
	else{//printf("(%d %d %d)\n",u,lc,rc);
		dfs(lc),dfs(rc);
		f[u][0]=min(f[lc][0]+f[rc][1],f[lc][1]+f[rc][0]);
		f[u][1]=f[lc][0]+f[rc][0]+1;
		g[u][0]=max(g[lc][0]+g[rc][1],g[lc][1]+g[rc][0]);
		g[u][1]=g[lc][0]+g[rc][0]+1;
	}
	//printf("[%d %d %d]\n",u,f[u][0],f[u][1]);
	return;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	int p=1,m=1;
	for(int i=1;i<n;i++){
		cnt[p]=s[i]-'0';
		if(s[i]=='2'){
			ch[p].push_back(++m),fa[m]=p;
			ch[p].push_back(++m),fa[m]=p;
			tag[p]=1,p=m-1;
		}
		else if(s[i]=='1')ch[p].push_back(++m),fa[m]=p,p=m;
		else{
			while(!tag[p])p=fa[p];
			tag[p]=0,p=ch[p][1];
		}
	}
	n=m;
	dfs(1);
	printf("%d %d\n",max(g[1][0],g[1][1]),min(f[1][0],f[1][1]));
 	return 0;
}
