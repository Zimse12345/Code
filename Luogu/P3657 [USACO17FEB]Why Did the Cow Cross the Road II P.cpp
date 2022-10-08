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
int n,a[N],b[N],pos[N];
int mx[N],s[N],t;

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return;}
inline void upt(int x,int t){for(;x<=n;ub(x))mx[x]=max(mx[x],t);return;}
inline int qmax(int x){int res=0;for(;x;db(x))res=max(res,mx[x]);return res;}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read(),pos[b[i]]=i;
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=a[i]-4;j<=a[i]+4;j++)if(1<=j&&j<=n)s[++t]=pos[j];
		sort(s+1,s+t+1);
		for(int j=t;j>=1;j--){
			int p=qmax(s[j]-1);
			upt(s[j],p+1);
		}
	}
	printf("%d\n",qmax(n));
	return 0;
}

