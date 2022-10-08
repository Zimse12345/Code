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

const int N=2e5+7,Mod=998244353;
int n,sz,last,f[N];
ll ans;
char s[N];
struct node{
	int len,link;
	map<int,int> nxt;
}t[N];
inline int F(int id){return t[id].len-t[t[id].link].len;}

void ins(int c){
	int cur=++sz;
	t[cur].len=t[last].len+1;
	int p=last;
	while(p!=-1&&!t[p].nxt[c])t[p].nxt[c]=cur,p=t[p].link;
	if(p==-1)t[cur].link=0,ans+=F(cur);
	else{
		int q=t[p].nxt[c];
		if(t[q].len==t[p].len+1)t[cur].link=q,ans+=F(cur);
		else{
			int clone=++sz;
			t[clone]=t[q],t[clone].len=t[p].len+1,ans+=F(clone);
			while(p!=-1&&t[p].nxt[c]==q)t[p].nxt[c]=clone,p=t[p].link;
			ans-=F(q);
			t[q].link=t[cur].link=clone;
			ans+=F(q)+F(cur);
		}
	}
	last=cur;
	return;
}

signed main(){
	t[0].link=-1;
	n=read();
	while(n--){
		ins(read());
		printf("%lld\n",ans);
	}
	return 0;
}

