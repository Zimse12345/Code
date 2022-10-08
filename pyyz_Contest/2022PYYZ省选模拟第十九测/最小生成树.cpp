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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,q,k,fa[N],cnt[N],ans;
struct edge{int a,b,c,d;edge(int a=0,int b=0,int c=0,int d=0):a(a),b(b),c(c),d(d){}
bool operator < (const edge& A)const{return c<A.c;}}e[N];
inline int F(int x){if(fa[x]!=x)fa[x]=F(fa[x]);return fa[x];}

void link(int a,int b,int c){
	++a,++b;
	int A=F(a),B=F(b);
	if(A^B){
		if(cnt[A]<cnt[B])swap(A,B);
		cnt[A]+=cnt[B],fa[B]=A,--k,ans+=c;
	}
	return;
}

signed main(){
	n=k=read(),q=read();
	for(int i=1;i<=n;i++)fa[i]=i,cnt[i]=1;
	for(int i=1,a,b,c;i<=q;i++)a=read(),b=read(),c=read(),e[i]=edge(a,b,c,n*2);
	sort(e+1,e+q+1);
	for(int i=2;i<=q;i++){
		for(int j=1;j<i;j++){
			while(e[j].c<e[i].c){
				link(e[j].a,e[j].b,e[j].c);
				e[j].a=(e[j].a+1)%n,swap(e[j].a,e[j].b),++e[j].c,--e[j].d;
				if(k==1||!e[i].d)break;
			}
			if(k==1)break;
		}
		if(k==1)break;
	}
	while(k!=1){
		for(int i=1;i<=q;i++)if(e[i].d){
			link(e[i].a,e[i].b,e[i].c);
			e[i].a=(e[i].a+1)%n,swap(e[i].a,e[i].b),++e[i].c,--e[i].d;
		}
	}
	printf("%lld\n",ans);
	return 0;
}

