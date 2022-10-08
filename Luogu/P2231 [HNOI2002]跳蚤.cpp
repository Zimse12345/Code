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
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,p[N],t;

int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=res*x;
		x=x*x,k/=2;
	}
	return res;
}

signed main(){
	n=read(),m=read();
	int ans=qp(m,n);
	int s=m;
	for(int i=2;i*i<=1e8;i++){
		if(s%i==0){
			p[++t]=i;
			while(s%i==0)s/=i;
		}
	}
	if(s>1)p[++t]=s;
	for(int i=1;i<(1ll<<t);i++){
		int tot=0,k=1;
		for(int j=0;j<t;j++)if(i&(1<<j))++tot,k*=p[j+1];
		int c=qp(m/k,n);
		if(tot%2==1)ans-=c;
		else ans+=c;
	}
	write(ans),putchar(10);
	return 0;
}

