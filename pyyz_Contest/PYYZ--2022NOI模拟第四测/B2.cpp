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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,P,Q;
char s[N];
int gcd(int a,int b){return b?gcd(b,a%b):a;}

int pre,tot,cnt[N];
struct node{
	int len,link,to[26];
}t[N];
vector<int> ch[N];

void ins(int c){
	int id=++tot,p=pre;
	t[id].len=t[p].len+1,cnt[id]=1;
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
		cnt[u]+=cnt[ch[u][i]];
	}
	if(u)Q+=(t[u].len-t[t[u].link].len)*cnt[u]*cnt[u]; 
	return;
}

signed main(){
	t[0].link=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int d=1;d<=n;d++){
		for(int k=2;k*d<=n;k++){
			int p1=(k-1)*d,p2=k*d;
			if(s[p1]^s[p2])continue;
			int l=0,r=0;
			while(l+1<d&&p1-l>1&&s[p1-l-1]==s[p2-l-1])++l;
			while(p2+r<n&&s[p1+r+1]==s[p2+r+1])++r;
//			printf("[%d %d %d %d]\n",p1,p2,l,r);
			for(int i=0;i<=l;i++){
				int from=i+1-d,to=i+r+1-d;
				from=max(from,1ll);
				if(from<=to)P+=(from+to)*(to-from+1);
			}
		}
	}
	for(int i=1;i<=n;i++){
		P+=i*(i+1)/2;
	}
	
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=tot;i++)ch[t[i].link].push_back(i);
	dfs(0);
	
	int g=gcd(P,Q);P/=g,Q/=g;
	printf("%lld/%lld\n",P,Q);
	return 0;
}

