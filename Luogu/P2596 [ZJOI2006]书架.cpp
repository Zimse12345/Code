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
#define Lid ch[id][0]
#define Rid ch[id][1]

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,m,rt,tot,ch[N][2],fa[N],sz[N],pos[N],val[N];
char op[100];
inline void clear(int id){Lid=Rid=fa[id]=sz[id]=pos[id]=val[id]=0;return;}
inline int gety(int id){return id==ch[fa[id]][1];}
inline void maintain(int id){sz[id]=sz[Lid]+sz[Rid]+1;return;}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int ty=gety(x);
	ch[y][ty]=ch[x][ty^1];
	if(ch[x][ty^1])fa[ch[x][ty^1]]=y;
	ch[x][ty^1]=y,fa[y]=x,fa[x]=z;
	if(z)ch[z][y==ch[z][1]]=x;
	maintain(y),maintain(x);
	return;
}

void splay(int id,int goal){
	while(fa[id]!=goal){
		int f=fa[id],gf=fa[f];
		if(gf!=goal)rotate(gety(id)==gety(f)?f:id);
		rotate(id);
	}
	if(goal==0)rt=id;
	return;
}

int kth(int k){
	int id=rt;
	while(1){
		if(sz[Lid]>=k)id=Lid;
		else if(sz[Lid]+1<k)k-=sz[Lid]+1,id=Rid;
		else return id;
	}
}

int main(){
	n=read(),m=read(),rt=1;
	for(int i=1,a;i<=n;i++){
		a=read();
		fa[i]=i-1,sz[i]=n-i+1,pos[a]=i,val[i]=a;
		if(i!=1)ch[i-1][1]=i;
	}
	for(int i=1,x,y,t;i<=m;i++){
		scanf("%s",op+1);
		if(op[1]=='T'){
			x=pos[read()];
			splay(x,0);
			if(!ch[x][0])continue;
			if(!ch[x][1])swap(ch[x][0],ch[x][1]);
			y=kth(sz[ch[x][0]]+2);
			ch[y][0]=ch[rt][0],fa[ch[rt][0]]=y,ch[rt][0]=0;
			splay(y,0);
		}
		if(op[1]=='B'){
			x=pos[read()];
			splay(x,0);
			if(!ch[x][1])continue;
			if(!ch[x][0])swap(ch[x][0],ch[x][1]);
			y=kth(sz[ch[x][0]]);
			ch[y][1]=ch[rt][1],fa[ch[rt][1]]=y,ch[rt][1]=0;
			splay(y,0);
		}
		if(op[1]=='I'){
			x=read(),t=read();
			if(t==0)continue;
			splay(pos[x],0);
			y=kth(sz[ch[pos[x]][0]]+t+1);
			int T1=val[y],T2=pos[x];
			swap(pos[x],pos[T1]);
			swap(val[T2],val[y]);
		}
		if(op[1]=='A'){
			x=pos[read()];
			splay(x,0);
			write(sz[ch[x][0]]),putchar(10);
		}
		if(op[1]=='Q'){
			x=read();
			write(val[kth(x)]),putchar(10);
		}
	}
	return 0;
}

