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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,ans;
int s[N];

struct node{
	int w,id;
	node(int w=0,int id=0):w(w),id(id){};
	bool operator < (const node& A)const{return w<A.w;} 
}e[N];

int query(){
	printf("? ");
	for(int i=1;i<=m;i++)printf("%c",'0'+s[i]);
	printf("\n");
	fflush(stdout);
	return read();
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++){
		s[i]=1;
		e[i]=node(query(),i);
		s[i]=0;
	}
	for(int i=1;i<=m;i++)s[i]=1;
	int mx=query();
	sort(e+1,e+m+1);
	for(int i=m;i>=2;i--){
		s[e[i].id]=0;
		int k=query();
		if(k+e[i].w==mx)s[e[i].id]=1,ans+=e[i].w;
		else mx=k;
	}
	ans+=e[1].w;
	printf("! %d\n",ans);
	fflush(stdout);
	return 0;
}

