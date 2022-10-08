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

const int N=2e3+7,Mod=998244353,INF=1e9+7;
int L,R,t[N],s[N],num[N],t10[N];

void sol(int x){
	int v=x,top=0;
	t10[0]=1;
	while(v)s[++top]=v%10,num[top]=num[top-1]+s[top]*t10[top-1],v/=10;
	for(int i=0;i<10;i++){
		for(int j=top,p=0;j>=1;j--){
			if(i==0)t[i]+=max(p-1,0ll)*t10[j-1];
			else t[i]+=p*t10[j-1];
			p=p*10+s[j];
			if(i==0&&j==top)continue;
			if(s[j]>i)t[i]+=t10[j-1];
			else if(s[j]==i)t[i]+=num[j-1]+1;
		}
	}
	return;
}

signed main(){
	t10[0]=1;
	for(int i=1;i<=14;i++)t10[i]=t10[i-1]*10;
	L=read(),R=read();
	sol(L-1);
	for(int i=0;i<10;i++)t[i]=-t[i];
	sol(R);
	for(int i=0;i<10;i++)printf("%lld ",t[i]);
	printf("\n");
	return 0;
}
