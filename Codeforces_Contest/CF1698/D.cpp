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
int T,n;

void query(int l,int r){
	printf("? %d %d\n",l,r);
	fflush(stdout);
	return;
}

void answer(int x){
	printf("! %d\n",x);
	fflush(stdout);
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		int L=1,R=n;
		while(L<R){
			int M=(L+R)/2;
			query(L,M);
			int cnt=0;
			for(int i=L,x;i<=M;i++){
				x=read();
				if(L<=x&&x<=M)++cnt;
			}
			if(cnt&1)R=M;
			else L=M+1;
		}
		answer(L);
	}
	return 0;
}

