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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,Mod=1e9;
map<int,int> A;
int n,ans=1,tag;

void addA(int x){
	++A[x];
	return;
}

void addB(int x){
	if(A[x]){
		--A[x],ans=ans*x;
		if(ans>Mod)ans%=Mod,tag=1;
	}
	return;
}

signed main(){
	n=read();
	for(int i=1,v,x;i<=n;i++){
		x=v=read();
		for(int j=2;j*j<=x;j++)while(v%j==0)addA(j),v/=j;
		if(v>1)addA(v);
	}
	n=read();
	for(int i=1,v,x;i<=n;i++){
		x=v=read();
		for(int j=2;j*j<=x;j++)while(v%j==0)addB(j),v/=j;
		if(v>1)addB(v);
	}
	if(tag)printf("%09lld\n",ans);
	else printf("%lld\n",ans);
	return 0;
}
