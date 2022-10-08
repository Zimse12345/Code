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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],s,x,y;

int ct(int id){
	int r=s-a[id];
	int res=0;
	if(a[id]<x)res+=x-a[id];
	if(r<y)res+=y-r;
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
	sort(a+1,a+n+1);
	m=read();
	while(m--){
		x=read(),y=read();
		int L=1,R=n,c=0,ans=0;
		while(L<=R){
			int M=(L+R)>>1ll;
			if(a[M]>=x)c=M,R=M-1;
			else L=M+1;
		}
		if(c)ans=min(ct(c),ct(max(1ll,c-1)));
		else ans=ct(n);
		printf("%lld\n",ans);
	}
	return 0;
}

