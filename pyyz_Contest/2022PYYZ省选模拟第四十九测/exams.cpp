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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int n,L[N],R[N];
double p[N],pre[N],val[N],ppre[N];

signed main(){
	n=read();
	for(int i=1;i<=n;i++){
		L[i]=read(),R[i]=read();
		p[L[i]]+=1.0/double(R[i]-L[i]);
		p[R[i]]-=1.0/double(R[i]-L[i]);
	}
	for(int i=1;i<N;i++)p[i]+=p[i-1],pre[i]=pre[i-1]+p[i];
	for(int i=0;i<N;i++)val[i]=(pre[N-1]-pre[i])+p[i]/2;
	for(int i=1;i<N;i++)ppre[i]=ppre[i-1]+val[i];
	for(int i=1;i<=n;i++){
		printf("%.8lf\n",0.5+(ppre[R[i]-1]-ppre[L[i]-1])/double(R[i]-L[i]));
	}
	return 0;
}

