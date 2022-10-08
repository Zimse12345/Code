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
#define M ((L+R)>>1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,rt[N],ct=1,tot;
int v[N*8],ch[N*8][2];
stack<int> rbs;
inline int newnode(){if(rbs.empty())return ++tot;int res=rbs.top();rbs.pop();return res;}

void split(int id,int x,int& y){
	if(!id){return;}
	y=newnode();
	int c=v[ch[id][0]];
	if(x>=c)ch[y][0]=ch[id][0],ch[id][0]=0,split(ch[id][1],x-c,ch[y][1]);
	else split(ch[id][0],x,ch[y][0]);
	v[id]-=x,v[y]=x;
	return;
}

void update(int& id,int L,int R,int x,int y){
	if(!id)id=newnode();
	v[id]+=y;
	if(L^R){
		if(x<=M)update(ch[id][0],L,M,x,y);
		else update(ch[id][1],M+1,R,x,y);
	}
	return;
}

int query(int id,int L,int R,int k){
	if(L==R)return L;
	if(v[ch[id][0]]>=k)return query(ch[id][0],L,M,k);
	return query(ch[id][1],M+1,R,k-v[ch[id][0]]);
}

int qsum(int id,int L,int R,int l,int r){
	if(r<L||l>R)return 0;
	if(l<=L&&r>=R)return v[id];
	return qsum(ch[id][0],L,M,l,r)+qsum(ch[id][1],M+1,R,l,r);
}

int merge(int x,int y){
	if(!x||!y)return x^y;
	v[x]+=v[y];
	ch[x][0]=merge(ch[x][0],ch[y][0]),ch[x][1]=merge(ch[x][1],ch[y][1]);
	ch[y][0]=ch[y][1]=v[y]=0,rbs.push(y);
	return x;
}

signed main(){
	n=read(),m=read();
	for(int i=1,x;i<=n;i++)x=read(),update(rt[1],1,n,i,x);
	while(m--){
		int op=read(),p=read();
		if(op==0){
			int x=read(),y=read();
			int c1=qsum(rt[p],1,n,1,y),c2=qsum(rt[p],1,n,x,y);
			int t1,t2;
			split(rt[p],c1,t1);
			split(t1,c1-c2,t2);
			rt[++ct]=t1,rt[p]=merge(t2,rt[p]);
		}
		if(op==1){
			int t=read();
			rt[p]=merge(rt[p],rt[t]);
		}
		if(op==2){
			int x=read(),y=read();
			update(rt[p],1,n,y,x);
		}
		if(op==3){
			int x=read(),y=read();
			printf("%lld\n",qsum(rt[p],1,n,x,y));
		}
		if(op==4){
			int k=read();
			if(v[rt[p]]<k){
				printf("-1\n");
				continue;
			}
			printf("%lld\n",query(rt[p],1,n,k));
		}
	}
	return 0;
}

