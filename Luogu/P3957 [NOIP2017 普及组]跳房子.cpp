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

const int N=1e6+7,Mod=998244353,INF=1e14+7;
int n,d,k,x[N],s[N],f[N];
int q[N],l,t1,t2;

bool check(int L,int R){
	if(L<1)L=1;
	for(int i=0;i<=n;i++)f[i]=0;
	l=-1,t1=1,t2=0;
	int res=0;
	for(int i=1;i<=n;i++){
		while(l+1<i&&x[i]-x[l+1]>=L){
			if(f[l+1]==-INF){
				++l;
				continue;
			}
			while(t1<=t2&&f[l+1]>=f[q[t2]])--t2;
			q[++t2]=++l;
		}
		while(t1<=t2&&x[i]-x[q[t1]]>R)++t1;
		if(t2<t1)f[i]=-INF;
		else f[i]=s[i]+f[q[t1]];
		res=max(res,f[i]);
	}
	if(res>=k)return true;
	else return false;
}

signed main(){
	n=read(),d=read(),k=read();
	for(int i=1;i<=n;i++)x[i]=read(),s[i]=read();
	int L=0,R=x[n],ans=-1;
	while(L<=R){
		int M=(L+R)>>1;
		if(check(d-M,d+M))R=M-1,ans=M;
		else L=M+1;
	}
	printf("%lld\n",ans);
	return 0;
}
