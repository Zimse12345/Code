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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int h,m,n,s,t[N],tag[N],ans;

int f(int x){
	if(x>s)return x;
	t[x]^=1;
	return f(x*2+t[x]);
}

signed main(){
	h=read(),m=read(),n=read();
	s=(1<<h)-1;
	for(int i=1;i<=m;i++)tag[s+read()]=1;
	for(int i=0;i<(1<<s);i++){
		for(int j=0;j<s;j++){
			if(i&(1<<j))t[j]=1;
			else t[j]=0;
		}
		int sum=0;
		for(int j=1;j<=n;j++)sum+=tag[f(1)];
		ans=max(ans,sum);
	}
	printf("%lld\n",ans);
	return 0;
}

