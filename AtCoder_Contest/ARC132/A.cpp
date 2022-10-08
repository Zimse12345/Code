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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return y>A.y;}
};
int n,m,a[N],b[N];
node R[N],C[N];
char ans[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++)R[i]=node(i,read());
	for(int i=1;i<=n;i++)C[i]=node(i,read());
	m=read();
	sort(R+1,R+n+1),sort(C+1,C+n+1);
	for(int i=1;i<=n;i++)a[R[i].x]=i,b[C[i].x]=i;
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		if(a[x]+b[y]<=n+1)ans[i]='#';
		else ans[i]='.';
	}
	ans[m+1]='\0';
	printf("%s\n",ans+1);
	return 0;
}

