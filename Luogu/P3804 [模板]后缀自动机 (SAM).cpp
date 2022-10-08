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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353;
int n,sz,last,f[N];
ll ans;
char s[N];
struct node{
	int len,link,cnt,nxt[26];
}t[N];
vector<int> ch[N];

void ins(int c){
	int cur=++sz;
	t[cur].len=t[last].len+1,t[cur].cnt=1;
	int p=last;
	while(p!=-1&&!t[p].nxt[c])t[p].nxt[c]=cur,p=t[p].link;
	if(p==-1)t[cur].link=0;
	else{
		int q=t[p].nxt[c];
		if(t[q].len==t[p].len+1)t[cur].link=q;
		else{
			int clone=++sz;
			t[clone]=t[q],t[clone].len=t[p].len+1,t[clone].cnt=0;
			while(p!=-1&&t[p].nxt[c]==q)t[p].nxt[c]=clone,p=t[p].link;
			t[q].link=t[cur].link=clone;
		}
	}
	last=cur;
	return;
}

void dfs(int id){
	for(unsigned i=0;i<ch[id].size();i++){
		dfs(ch[id][i]);
		t[id].cnt+=t[ch[id][i]].cnt;
	}
	if(t[id].cnt>1)ans=max(ans,1ll*t[id].cnt*t[id].len);
	return;
}

signed main(){
	t[0].link=-1;
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=sz;i++)ch[t[i].link].push_back(i);
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}

