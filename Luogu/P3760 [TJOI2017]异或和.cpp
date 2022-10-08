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

const int N=3e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],tr[2][N],ans;

inline void db(int& x){x-=(x&(-x));return;}
inline void ub(int& x){x+=(x&(-x));return; }
inline void add(int x,int k){++x;for(;x<N;ub(x))tr[k][x]++;return;}
inline int sum(int x,int k){++x;int res=0;for(;x;db(x))res+=tr[k][x];return res;}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=a[i-1]+read();
	for(int w=0;w<=20;w++){
		int tot=0;
		add(0,0);
		for(int i=1;i<=n;i++){
			int v=a[i]&((1<<w)-1);
			if(a[i]&(1<<w)){
				tot+=sum(v,0)+sum(N-10,1)-sum(v,1);
				add(v,1);
			}
			else{
				tot+=sum(N-10,0)-sum(v,0)+sum(v,1);
				add(v,0);
			}
		}
		for(int i=0;i<N;i++)tr[0][i]=tr[1][i]=0;
		if(tot&1)ans|=(1<<w);
	}
	printf("%lld\n",ans);
	return 0;
}

