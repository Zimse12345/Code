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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e7+7,Mod=998244353,INF=1e9+7;
int T,prime[N],cnt,pr[N],phi[N],P;

void pre(){
	for(int i=2;i<N;i++){
		if(!pr[i])prime[++cnt]=i,pr[i]=i;
		for(int j=1;j<=cnt&&i*prime[j]<N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	phi[1]=1;
	for(int i=3;i<N;i++){
		int c=pr[i],p=i,v=1;
		while(pr[p]==c)p/=c,v*=c;
		phi[i]=phi[p]*(v-v/c);
	}
	return;
}

int qp(ll x,ll k,ll p){
	ll res=1ll;
	while(k){
		if(k&1ll)res=(res*x)%p;
		k/=2ll,x=(x*x)%p;
	}
	return res;
}

int f(int p){
	if(p<=2)return 0;
	int k=f(phi[p])+phi[p];
	return qp(2,k,p);
}

int main(){
	pre(),T=read();
	while(T--){
		P=read();
		printf("%d\n",f(P));
	}
	return 0;
}
