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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int L1,R1,L2,R2,p[N];

signed main(){
	L1=read(),R1=read(),L2=read(),R2=read();
	for(int i=2;i<=200;i++){
		p[i]=1;
		for(int j=2;j<i;j++)if(i%j==0)p[i]=0;
	}
	for(int i=L1;i<=R1;i++){
		int tag=0;
		for(int j=L2;j<=R2;j++)if(p[i+j])tag=1;
		if(tag==0){
			printf("Takahashi\n");
			return 0;
		}
	}
	printf("Aoki\n");
	return 0;
}

