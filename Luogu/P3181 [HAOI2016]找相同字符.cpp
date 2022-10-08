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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e5+7,SZ=26,INF=1e9+7;
char s[N],ss[N];
int n1,n2,pre,tot,f[N],ans,cnt[N];

struct node{
	int len,link,to[SZ];
}t[N];
vector<int> ch[N];

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1,cnt[tot]=1;
	while(p!=-1&&!t[p].to[c])t[p].to[c]=id,p=t[p].link;
	if(p!=-1){
		int q=t[p].to[c];
		if(t[q].len==t[p].len+1)t[id].link=q;
		else{
			int cp=++tot;t[cp]=t[q],t[cp].len=t[p].len+1;
			while(p!=-1&&t[p].to[c]==q)t[p].to[c]=cp,p=t[p].link;
			t[q].link=t[id].link=cp; 
		}
	}
	pre=id;
	return;
}

void dfs(int u){
	for(unsigned i=0;i<ch[u].size();i++)dfs(ch[u][i]),cnt[u]+=cnt[ch[u][i]];
	return;
}

void dfs2(int u,int sum){
	f[u]=sum;
	if(u)sum+=(t[u].len-t[t[u].link].len)*cnt[u];
	for(unsigned i=0;i<ch[u].size();i++)dfs2(ch[u][i],sum);
	return;
}

signed main(){
	t[0].link=-1;
	scanf("%s %s",s+1,ss+1);
	n1=strlen(s+1),n2=strlen(ss+1);
	for(int i=1;i<=n1;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
	dfs(0);
	dfs2(0,0);
	for(int i=1,p=0,l=0,c;i<=n2;i++){
		c=ss[i]-'a';
		while(p!=-1&&!t[p].to[c])p=t[p].link;
		if(p==-1)p=0,l=0;
		else l=min(t[p].len,l)+1,p=t[p].to[c];
		if(p)ans+=f[p]+(l-t[t[p].link].len)*cnt[p];
	}
	printf("%lld\n",ans);
	return 0;
}

