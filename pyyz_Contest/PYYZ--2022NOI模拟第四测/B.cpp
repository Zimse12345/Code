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
#include <bitset>

#define int long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e4+7,Mod=998244353,INF=1e9+7;
char s[N];
int n,pre,tot;
int P,Q;
int rpos[N],top;
int gcd(int a,int b){return b?gcd(b,a%b):a;}

bitset<5100> b[N];
struct node{
	int len,link,to[26];
}t[N];
vector<int> ch[N];
vector<int> pos;

void ins(int c,int i){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1,b[id][i]=1;
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
	for(unsigned i=0;i<ch[u].size();i++){
		dfs(ch[u][i]);
		b[u]|=b[ch[u][i]];
	}
	return;
}
int T=0;
void sol(int len){
	int sz=pos.size();
	Q+=sz*sz;
	top=0;
	int tl=1;
	rpos[++top]=pos[0];
//	for(int i=pos[0]-len+1;i<=pos[0];i++)printf("%c",s[i]);
//	printf("\n");
	int sum=len,cnt=1;
	P+=sum*2-len;
//	printf("(%d)\n",sum);
	for(int i=1,pl=pos[0]-len+1;i<sz;i++){
		int l=pos[i]-len+1;
		while(tl<=top&&l>rpos[tl])--cnt,sum-=rpos[tl]-pl+1,++tl;
		sum-=cnt*(l-pl),sum+=len,++cnt;
		rpos[++top]=pos[i];
//		printf("(%d)\n",sum);
		P+=sum*2-len;
		pl=l;
	}
	return;
}

signed main(){
//	freopen("ex_string1.in","r",stdin);
	t[0].link=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a',i);
	for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
	dfs(0);
	for(int i=1;i<=tot;i++){
		pos.resize(0);
		for(int k=1;k<=n;k++)if(b[i][k])pos.push_back(k);
		for(int j=t[i].len;j>t[t[i].link].len;j--)sol(j);
	}
	int g=gcd(P,Q);P/=g,Q/=g;
	printf("%lld/%lld\n",P,Q);
	return 0;
}

