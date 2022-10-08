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
int T,n,a[N],b[N];
map<int,int> s;

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++){
			b[i]=read();
			while(b[i]%2==0)b[i]/=2;
			s[b[i]]++;
		}
		for(int i=1;i<=n;i++){
			a[i]=read();
			while(a[i]%2==0)a[i]/=2;
//			printf(">>> %d\n",b[i]);
		}
		int tag=1;
		sort(a+1,a+n+1);
		for(int i=n;i>=1;i--){
//			printf(" [%d]\n",a[i]);
			while(a[i]&&!s[a[i]]){
				a[i]/=2;
			}
//			printf("(%d)\n",a[i]);
			if(!a[i]){
				tag=0;
				break;
			}
			--s[a[i]];
		}
		if(tag)printf("Yes\n");
		else printf("No\n");
		for(int i=1;i<=n;i++)s[b[i]]=0;
	}
	return 0;
}

