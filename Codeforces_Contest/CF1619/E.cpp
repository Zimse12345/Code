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

const int N=4e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],t[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),++t[a[i]];
		priority_queue<int> Q;
		while(Q.size())Q.pop();
		
		for(int i=0,c=0;i<=n;i++){
			if(c==-1){
				printf("-1 ");
				continue;
			}
			printf("%lld ",c+t[i]);
			if(!t[i]){
				if(!Q.size())c=-1;
				else{
					int p=Q.top();
					Q.pop(),c+=i-p;
				}
			}
			while(t[i]>1)--t[i],Q.push(i);
		}
		for(int i=1;i<=n;i++)t[a[i]]=0;
		printf("\n");
	}
	return 0;
}

