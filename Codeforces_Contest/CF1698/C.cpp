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
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		int tag=1;
		if(a[1]!=-a[n])tag=0;
		for(int i=2;i<n;i++)if(a[i]!=0)tag=0;
		if(tag){
			printf("YES\n");
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++)if(a[i]!=0)++cnt;
		if(cnt<=1)printf("YES\n");
		else{
			if(n<=4){
				tag=1;
				for(int i=1;i<=n;i++){
					for(int j=i+1;j<=n;j++){
						for(int k=j+1;k<=n;k++){
							int s=a[i]+a[j]+a[k];
							int vis=0;
							for(int p=1;p<=n;p++)if(a[p]==s)vis=1;
							if(!vis)tag=0;
						}
					}
				}
				if(tag)printf("YES\n");
				else printf("NO\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}

