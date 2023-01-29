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
//#define int long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,Mod=998244353;
int n,sz,last,f[N],Cnt,bb[N],cc[N],ccnt;
ll ans;
char s[N];
struct node{
	int len,link,cnt,nxt[26];
}t[N];
vector<int> ch[N];
int pr[N],prime[N],tot,a[N];

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

void ddfs(int x,int val,int l,int r,int v){
	if(x>ccnt){
		if(l<=val&&val<=r)ans+=v;
	}
	else{
		for(int i=0;i<=cc[x];i++){
			ddfs(x+1,val,l,r,v);
			val*=bb[x];
		}
	}
	return;
}

void dfs(int id){
	for(unsigned i=0;i<ch[id].size();i++){
		dfs(ch[id][i]);
		t[id].cnt+=t[ch[id][i]].cnt;
	}
	if(id){
		int val=t[id].cnt;
		Cnt=ccnt=0;
		while(val>1)a[++Cnt]=pr[val],val/=pr[val];
		a[Cnt+1]=-1;
		for(int i=2,V=a[i-1],S=1;i<=Cnt+1;i++){
			if(a[i]!=V){
				bb[++ccnt]=V,cc[ccnt]=S;
				V=a[i],S=1;
			}
			else ++S;
		}
		ddfs(1,1,t[t[id].link].len+1,t[id].len,t[id].cnt);
		
//		for(int i=t[t[id].link].len+1;i<=t[id].len;i++)if(t[id].cnt%i==0)ans-=t[id].cnt;
	}
	return;
}

signed main(){
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	
	t[0].link=-1;
	n=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)ins(s[i]-'a');
	for(int i=1;i<=sz;i++)ch[t[i].link].push_back(i);
	dfs(0);
	printf("%lld\n",ans);
	return 0;
}

