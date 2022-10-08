#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx")
#pragma GCC optimize("inline")
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
#include <bitset>

#define ll long long
#define ull unsigned long long

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const unsigned N=512;
bitset<N> p[N],a[N],b,e;
char s[N][N],t[N][N];
unsigned n,m,q,H,W;
unsigned ans,ax,ay;

signed main(){
	n=read(),m=read();
	for(unsigned i=1;i<=n;i++){
		scanf("%s",s[i]);
		for(unsigned j=0;j<m;j++)p[i][j]=(s[i][j]=='G'?1:0);
	}
	int q=read();
	while(q--){
		ans=0,ax=1,ay=0;
		for(unsigned i=0;i<N;i++)e[i]=0;
		H=read(),W=read();
		for(unsigned i=0;i<W;i++)e[i]=1;
		for(unsigned i=1;i<=H;i++){
			scanf("%s",t[i]);
			for(unsigned j=0;j<W;j++)a[i][j]=(t[i][j]=='G'?1:0);
		}
		for(unsigned A=1;A+H-1<=n;A++){
			for(unsigned B=0;B+W-1<m;B++){
				unsigned sum=0;
				for(unsigned c=1;c<=H;c++){
					b=(a[c]^(p[A+c-1]>>B))&e;
					sum+=W-b.count();
				}
				if(sum>ans||(sum==ans&&(A<ax||(A==ax&&B<ay))))ans=sum,ax=A,ay=B;
			}
		}
		++ay;
		printf("%u %u\n",ax,ay);
	}
	return 0;
}

