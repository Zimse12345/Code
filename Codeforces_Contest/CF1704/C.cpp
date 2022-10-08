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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int c=0;
		for(int i=1;i<=m;i++)a[i]=read();
		sort(a+1,a+m+1);
		a[m+1]=a[1]+n;
		for(int i=1;i<=m;i++)if(a[i+1]-a[i]>1)b[++c]=a[i+1]-a[i]-1;
		sort(b+1,b+c+1);
		int ans=0,t=0;
		for(int i=c;i>=1;i--){
			b[i]-=t*2;
			if(b[i]>0&&b[i]<=2)++ans,++t;
			else if(b[i]>2)ans+=b[i]-1,t+=2;
		}
		printf("%d\n",n-ans);
	}
	return 0;
}

