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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,ch[N][30],tot=1,t;
char s[N],ans[N];

void dfs(int u,int tag){
	while(ch[u][26]--)ans[++t]='P';
	int p=0;
	for(int i=0;i<26;i++)if(ch[ch[u][i]][27]>ch[ch[u][p]][27])p=i;
	for(int i=0;i<26;i++)if(ch[u][i]){
		if(i==p&&tag)continue;
		ans[++t]='a'+i,dfs(ch[u][i],0);
	}
	if(tag&&ch[u][p])ans[++t]='a'+p,dfs(ch[u][p],1);
	if(!tag)ans[++t]='-';
	return;
}

signed main(){
	n=read();
	for(int i=1,m;i<=n;i++){
		scanf("%s",s+1),m=strlen(s+1);
		int id=1;
		for(int j=1;j<=m;j++){
			if(!ch[id][s[j]-'a'])ch[id][s[j]-'a']=++tot;
			id=ch[id][s[j]-'a'];
			ch[id][27]=max(ch[id][27],m-j+1);
		}
		ch[id][26]++;
	}
	dfs(1,1);
	printf("%d\n",t);
	for(int i=1;i<=t;i++)printf("%c\n",ans[i]);
	return 0;
}

