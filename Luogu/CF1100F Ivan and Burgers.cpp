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

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,q,a[N],ans[N],d[N],pos[N];
struct node{
	int x,y,id;
	node(int x=0,int y=0,int id=0):x(x),y(y),id(id){}
	bool operator < (const node& A)const{return y<A.y;}
}b[N];

void ins(int x,int y){
	for(int i=25;i>=0;i--)if(x&(1<<i)){
		if(!d[i]){
			d[i]=x,pos[i]=y;
			return;
		}
		if(pos[i]<y)swap(pos[i],y),swap(d[i],x);
		x^=d[i];
	}
	return;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	q=read();
	for(int i=1,x,y;i<=q;i++)x=read(),y=read(),b[i]=node(x,y,i);
	sort(b+1,b+q+1);
	for(int i=1,j=1,x,y,s;i<=q;i++){
		x=b[i].x,y=b[i].y,s=0;
		while(j<=y)ins(a[j],j),++j;
		for(int i=25;i>=0;i--)if(x<=pos[i]&&(s^d[i])>s)s^=d[i];
		ans[b[i].id]=s;
	}
	for(int i=1;i<=q;i++)printf("%d\n",ans[i]);
	return 0;
}

