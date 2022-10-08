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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=1e9+7,INF=1e9+7;
int n,q,a[N],ans[N],d[N],c,_2[N];
struct query{
	int x,y,id;
	query(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	bool operator < (const query& A)const{return x<A.x;}
}s[N];

void ins(int x){
	for(int i=20;i>=0;i--)if(x&(1<<i)){
		if(!d[i]){
			d[i]=x,++c;
			return;
		}
		x^=d[i];
	}
	return;
}

bool check(int x){
	for(int i=20;i>=0;i--)if(x&(1<<i)){
		if(!d[i])return false;
		x^=d[i];
	}
	return true;
}

signed main(){
	_2[0]=1;
	for(int i=1;i<N;i++)_2[i]=(_2[i-1]*2)%Mod;
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1,x,y;i<=q;i++)x=read(),y=read(),s[i]=query(x,y,i);
	sort(s+1,s+q+1);
	for(int i=1,j=1,x,y;i<=q;i++){
		x=s[i].x,y=s[i].y;
		while(j<=x)ins(a[j++]);
		if(check(y))ans[s[i].id]=_2[x-c];
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

