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
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,k,a[N];
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
	bool operator < (const node& A)const{return x<A.x;}
}b[N];

signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read(),b[i]=node(a[i]+i,i);
		sort(b+1,b+n+1);
		for(int i=n;i>=n-k+1;i--)a[b[i].y]=0;
		int sum=0;
		for(int i=1,s=0;i<=n;i++){
			if(a[i])sum+=a[i]+s;
			else ++s;
		}
		printf("%lld\n",sum);
	}
	return 0;
}

