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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,INF=1e9;
int n,m,F,s[N],q[N],a[N];
int a1[N],a2[N],t1,t2,p1,p2;

bool check(int x){
	t1=t2=0;
	int p=0;
	for(int i=1;i<=n;i++){
		if(s[i]<a[x])a1[++t1]=q[i];
		else a2[++t2]=q[i];
	}
	if(t2<m/2+1)return 0;
	sort(a1+1,a1+t1+1),sort(a2+1,a2+t2+1);
	for(int i=1;i<=m/2+1;i++)p+=a2[i];
	p1=1,p2=m/2+2;
	for(int i=1;i<=m/2;i++){
		if(p1<=t1&&(p2>t2||a1[p1]<=a2[p2]))p+=a1[p1++];
		else p+=a2[p2++];
	}
	return p<=F;
}

signed main(){
	m=read(),n=read(),F=read();
	for(int i=1;i<=n;i++)s[i]=a[i]=read(),q[i]=read();
	sort(a+1,a+n+1);
	int L=1,R=n,ans=-1;
	while(L<=R){
		int M=(L+R)/2;
		if(check(M))ans=a[M],L=M+1;
		else R=M-1;
	}
	printf("%lld\n",ans);
	return 0;
}
