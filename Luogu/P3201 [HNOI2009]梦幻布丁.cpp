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

#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,m,a[N],t,v[N]; 
int sum[N*4];
set<int> s[N];

void build(int L,int R,int id){
	if(L==R)sum[id]=1;
	else{
		int M=(L+R)>>1;
		build(L,M,Lid),build(M+1,R,Rid);
		sum[id]=sum[Lid]+sum[Rid]-(a[M]==a[M+1]?1:0);
	}
	return;
}

void update(int L,int R,int id,int p,int x){
	if(L==R)a[L]=x;
	else{
		int M=(L+R)>>1;
		if(p<=M)update(L,M,Lid,p,x);
		else update(M+1,R,Rid,p,x);
		sum[id]=sum[Lid]+sum[Rid]-(a[M]==a[M+1]?1:0);
	}
	return;
}

int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read(),s[a[i]].insert(i);
	for(int i=0;i<N;i++)v[i]=i;
	build(1,n,1);
	for(int i=1,op,x,y;i<=m;i++){
		op=read();
		if(op==1){
			int X=read(),Y=read();
			x=v[X],y=v[Y];
			if(x==y)continue;
			if(s[x].size()<s[y].size()){
				while(s[x].size()){
					t=*s[x].begin();
					update(1,n,1,t,y),s[x].erase(t),s[y].insert(t);
				}
			}
			else{
				while(s[y].size()){
					t=*s[y].begin();
					update(1,n,1,t,x),s[y].erase(t),s[x].insert(t);
				}
				swap(v[X],v[Y]);
			}
		}
		else printf("%d\n",sum[1]);
	}
	return 0;
}
