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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];
map<int,int> m;

signed main(){
	T=read();
	while(T--){
		n=read(),m.clear();
		int ans=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			a[i]=read(),sum+=a[i];
			if(!m.count(a[i]))m[a[i]]=1;
			else ++m[a[i]];
		}
		double k=double(sum)/double(n);
		sort(a+1,a+n+1);
		if((sum*2)%n!=0){
			printf("0\n");
			continue;
		}
		int p=0;
		for(int i=1;i<=n;i++){
			//(a+b)=k*2
			int b=(sum*2)/n-a[i];
			if(m.count(b))ans+=m[b];
			if(a[i]==b)++p;
		}
		printf("%lld\n",ans/2-p/2);
	}
	return 0;
}

