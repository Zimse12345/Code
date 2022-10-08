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

const int N=1e5+7,SZ=128,INF=1e9+7;
int n,m,q,s[N],cnt,inb[N],ans;

struct Block{
	int l,r,tag,stk[150],top;
	double k(int i){return double(1)/i;}
	double b(int i){return double(s[i])/i;}
	void build(){
		if(tag)for(int i=l;i<=r;i++)s[i]+=tag;
		tag=top=0;
		for(int i=l;i<=r;i++){
			while(top>1){
				double mid1=(b(stk[top])-b(stk[top-1]))/(k(stk[top-1])-k(stk[top]));
				double mid2=(b(i)-b(stk[top-1]))/(k(stk[top-1])-k(i));
				if(mid2>=mid1)--top;
				else break;
			}
			stk[++top]=i;
		}
		return;
	}
	void ins(int k){
		tag+=k;
		return;
	}
	int query(){
		while(top>1){
			double mid=(b(stk[top])-b(stk[top-1]))/(k(stk[top-1])-k(stk[top]));
			if(mid<=double(tag))--top;
			else break;
		}
		return int(ceil(k(stk[top])*double(tag)+b(stk[top])));
	}
}b[1000];

signed main(){
//	freopen("computer_sample.in","r",stdin);
//	freopen("B.out","w",stdout);
	n=read(),m=read(),q=read();
	while(m--)s[read()]++;
	for(int i=2;i<=n;i++)s[i]+=s[i-1];
	while(++cnt){
		b[cnt].l=b[cnt-1].r+1;
		b[cnt].r=min(b[cnt].l+SZ,n);
		for(int i=b[cnt].l;i<=b[cnt].r;i++)inb[i]=cnt;
		b[cnt].build();
		ans=max(ans,b[cnt].query());
		if(b[cnt].r==n)break;
	}
	printf("%d\n",ans);
	while(q--){
		int k=read(),v=read();
		for(int i=v;i<=b[inb[v]].r;i++)s[i]+=k;
		b[inb[v]].build();
		ans=max(ans,b[inb[v]].query());
		for(int i=inb[v]+1;i<=cnt;i++)b[i].ins(k),ans=max(ans,b[i].query());
		printf("%d\n",ans);
	}
	return 0;
}

