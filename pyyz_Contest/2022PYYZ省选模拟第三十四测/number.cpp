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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int n,k,a[N],pr[N],prime[N],tot,ans;
int num[N],sum,t[N];

vector<int> calc(int x){
	vector<int> res;
	while(x!=1){
		int y=pr[x];
		res.push_back(y);
		while(x%y==0)x/=y;
	}
	return res;
}

void add(int x){
	++num[x];
	vector<int> p=calc(x);
	int c=p.size();
	ans+=sum;
	for(int i=1,mul,z;i<(1<<c);i++){
		mul=1,z=1;
		for(int j=0;j<c;j++)if(i&(1<<j))mul*=p[j],z=-z;
		ans+=t[mul]*z;
	}
	++sum;
	for(int i=1,mul;i<(1<<c);i++){
		mul=1;
		for(int j=0;j<c;j++)if(i&(1<<j))mul*=p[j];
		++t[mul];
	}
	return;
}

void del(int x){
	if(!num[x])return;
	--num[x],--sum;
	vector<int> p=calc(x);
	int c=p.size();
	for(int i=1,mul;i<(1<<c);i++){
		mul=1;
		for(int j=0;j<c;j++)if(i&(1<<j))mul*=p[j];
		--t[mul];
	}
	ans-=sum;
	for(int i=1,mul,z;i<(1<<c);i++){
		mul=1,z=1;
		for(int j=0;j<c;j++)if(i&(1<<j))mul*=p[j],z=-z;
		ans-=t[mul]*z;
	}
	return;
}

signed main(){
//	freopen("d.in","r",stdin);
//	freopen("d.out","w",stdout);
	for(int i=2;i<N;i++){
		if(!pr[i])pr[i]=i,prime[++tot]=i;
		for(int j=1;j<=tot&&prime[j]*i<N;j++){
			pr[prime[j]*i]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	n=read(),k=read();
	while(n--){
		int op=read(),x=read();
		if(x%k!=0){
			printf("%lld\n",ans);
			continue;
		}
		x/=k;
		if(op)add(x);
		else del(x);
		printf("%lld\n",ans);
	}
	return 0;
}

