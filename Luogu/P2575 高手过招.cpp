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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N],b[N],t;

signed main(){
	T=read();
	while(T--){
		n=read();
		int tag=0;
		for(int i=1;i<=n;i++){
			m=read(),t=0;
			for(int j=1;j<=m;j++)a[read()]=1;
			int p=21,sg=0;
			while(1){
				int c=0;
				while(p>1&&a[p-1]==1)++c,--p;
				--p;
				b[++t]=c;
				if(p<1)break;
			}
			for(int j=1;j<=t;j++)if(!(j&1))sg^=b[j];
			tag^=sg;
			for(int j=1;j<=20;j++)a[j]=0;
		}
		if(tag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

