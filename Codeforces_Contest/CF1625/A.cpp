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
 
int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
 
const int N=1e3+7,Mod=1e9+7,INF=1e9+7;
inline void yes(){printf("YES\n");return;}
inline void no(){printf("NO\n");return;}
int T,n,a[N],k,c[N];
 
signed main(){
	T=read();
	while(T--){
		n=read(),k=read();
		for(int i=0;i<k;i++)c[i]=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
			for(int j=0;j<k;j++){
				if(a[i]&(1<<j))++c[j];
			}
		}
		int ans=0;
		for(int i=0;i<k;i++)if(c[i]>n/2)ans|=(1<<i);
		printf("%d\n",ans);
	}
	return 0;
}

