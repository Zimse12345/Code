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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e6+7,INF=1e9;
int n,l,r,k,T,s[N];

signed main(){
	T=read();
	while(T--){
		n=read(),l=read(),r=read(),k=read();
		int t=0;
		for(int i=1,a;i<=n;i++){
			a=read();
			if(l<=a&&a<=r)s[++t]=a;
		}
		if(!t){
			printf("0\n");
			continue;
		}
		sort(s+1,s+t+1);
		int ans=0;
		for(int i=1;i<=t;i++){
			if(s[i]<=k)k-=s[i],++ans;
			else break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
