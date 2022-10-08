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
#define Lid (id<<1)
#define Rid (Lid|1)
#define M ((L+R)/2)

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,sz,X[N],Y[N],T[N];

struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};
vector<node> addline[N],delline[N];

int mn[N*4],tag[N*4];

void pushdown(int id){
	if(tag[id]!=0){
		mn[id]+=tag[id];
		tag[Lid]+=tag[id];
		tag[Rid]+=tag[id];
		tag[id]=0;
	}
	return;
}

void update(int L,int R,int id,int l,int r,int x){
	pushdown(id);
	if(r<L||R<l)return;
	if(l<=L&&r>=R)tag[id]+=x,pushdown(id);
	else update(L,M,Lid,l,r,x),update(M+1,R,Rid,l,r,x),mn[id]=min(mn[Lid],mn[Rid]);
	return;
}

bool check(int Time){
	for(int i=1;i<=n;i++){
		if(Time<T[i])continue;
		int R=Time-T[i];
		int u=max(1,X[i]-R),v=min(sz,X[i]+R);
		int l=Y[i]-R,r=Y[i]+R;
		addline[u].push_back(node(l,r));
		delline[v].push_back(node(l,r));
	}
	int L=1,R=sz,res=0;
	for(int i=L;i<=R;i++){
		for(unsigned j=0;j<addline[i].size();j++){
			int l=addline[i][j].x,r=addline[i][j].y;
			update(L,R,1,l,r,1);
		}
		if(mn[1]==0)res=1;
		for(unsigned j=0;j<delline[i].size();j++){
			int l=delline[i][j].x,r=delline[i][j].y;
			update(L,R,1,l,r,-1);
		}
	}
	for(int i=L;i<=R;i++)addline[i].resize(0),delline[i].resize(0);
	return res;
}

signed main(){
	n=read(),sz=read();
	int mt=0;
	for(int i=1;i<=n;i++)X[i]=read(),Y[i]=read(),T[i]=read(),mt=max(mt,T[i]);
	int L=0,R=sz+mt+1,ans=0;
	while(L<=R){
		if(check(M))ans=M,L=M+1;
		else R=M-1;
	}
	printf("%d\n",ans);
	return 0;
}

