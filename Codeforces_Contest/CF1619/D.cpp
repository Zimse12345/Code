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

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m;
vector< vector<int> > a,b;
vector<int> emp;

bool check(int x){
	for(int i=1;i<=m;i++)for(int j=1;j<=n;j++){
		if(a[i][j]>=x)b[i][j]=1;
		else b[i][j]=0;
	}
	for(int p=1;p<=m;p++){
		int t=0;
		for(int j=1;j<=n;j++)t+=b[p][j];
		if(t>=2){
			for(int j=1;j<=n;j++)if(!b[p][j]){
				int tg=0;
				for(int i=1;i<=m;i++)if(b[i][j])tg=1;
				if(!tg)return 0;
			}
			return 1;
		}
	}
	return 0;
}

signed main(){
	T=read();
	while(T--){
		a.resize(0),a.push_back(emp);
		b.resize(0),b.push_back(emp);
		m=read(),n=read();
		
		for(int i=1;i<=m;i++){
			a.push_back(emp),b.push_back(emp);
			a[i].push_back(0),b[i].push_back(0);
			for(int j=1;j<=n;j++)a[i].push_back(read()),b[i].push_back(0);
		}
		int L=0,R=1e9,ans=0;
		while(L<=R){
			int M=(L+R)>>1;
			if(check(M))ans=M,L=M+1;
			else R=M-1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

