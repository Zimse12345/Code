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
int T,n,m,a[N],u,v;

map<int,int> L,R;

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(!L[a[i]])L[a[i]]=i;
			R[a[i]]=i;
		}
		
		for(int i=1;i<=m;i++){
			u=read(),v=read();
			if(!L[u]||!L[v]){
				printf("No\n");
			}
			else{
				if(L[u]<R[v]){
					printf("Yes\n");
				}
				else printf("No\n");
			}
		}
		L.clear(),R.clear();
	}
	return 0;
}

