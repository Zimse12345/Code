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

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n,a,b,ans[N];

signed main(){
	T=read();
	while(T--){
		n=read(),a=read(),b=read();
		if(abs(a-b)>1||(n==2&&a+b>0)){
			printf("-1\n");
			continue;
		}
		if(a==b){
			if(n-2<a+b){
				printf("-1\n");
				continue;
			}
			if(a==0){
				for(int i=1;i<=n;i++)printf("%d ",i);
				printf("\n");
				continue;
			}
			for(int i=1;i<=a;i++){
				ans[i*2-1]=i,ans[i*2]=n-i+1;
			}
			int p=a+1;
			for(int i=a*2+1;i<=n;i++)ans[i]=p++;
			for(int i=1;i<=n;i++)printf("%d ",ans[i]);
			printf("\n");
			continue;
		}
		int tag=0;
		if(a<b)swap(a,b),tag=1;
		if(b*2+3>n){
			printf("-1\n");
			continue;
		}
		ans[1]=1;
		for(int i=1;i<=b;i++)ans[i*2]=n-i+1,ans[i*2+1]=i+1;
		int p=n-b;
		for(int i=b*2+2;i<=n;i++)ans[i]=p--;
		
		if(tag)for(int i=1;i<=n;i++)ans[i]=n-ans[i]+1;
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}

