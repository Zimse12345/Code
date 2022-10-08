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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=2e5,Mod=998244353,INF=1e9+7;
int n,m,b[N],ans;

int main(){
	n=read(),m=read();
	ans=n;
	for(int i=1,u,v;i<=m;i++){
		u=read(),v=read();
		if(v<u){
			if(!b[v])--ans;
			++b[v];
		}
		if(u<v){
			if(!b[u])--ans;
			++b[u];
		}
	}
	int q=read();
	while(q--){
		int ty=read();
		if(ty==3)printf("%d\n",ans);
		if(ty==1){
			int u,v;
			u=read(),v=read();
			if(v<u){
				if(!b[v])--ans;
				++b[v];
			}
			if(u<v){
				if(!b[u])--ans;
				++b[u];
			}
		}
		if(ty==2){
			int u,v;
			u=read(),v=read();
			if(v<u){
				if(b[v]==1)++ans;
				--b[v];
			}
			if(u<v){
				if(b[u]==1)++ans;
				--b[u];
			}
		}
	}
	return 0;
}

