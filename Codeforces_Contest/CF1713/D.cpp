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

inline int query(int x,int y){
	printf("? %d %d\n",x+1,y+1);
	fflush(stdout);
	return read();
}

int sol(int L,int R){
	if(L==R)return L;
	int len=R-L+1;
	while(len>=4)len/=4;
	if(len==2){
		int M=(L+R)/2;
		int a=sol(L,M),b=sol(M+1,R);
		int p=query(a,b);
		return p==1?a:b;
	}
	int M=(L+R)/2;
	int LM=(L+M)/2,RM=(M+1+R)/2;
	int a=sol(L,LM),b=sol(LM+1,M),c=sol(M+1,RM),d=sol(RM+1,R);
	int p=query(a,c);
	if(!p){
		p=query(b,d);
		return p==1?b:d;
	}
	if(p==1){
		p=query(a,d);
		return p==1?a:d;
	}
	p=query(b,c);
	return p==1?b:c;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		printf("! %d\n",sol(0,(1<<n)-1)+1);
		fflush(stdout);
	}
	return 0;
}

