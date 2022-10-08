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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,m,x[N],y[N],ans=INF;
char s[N][N];

int sol(int S){
	if(!S)return 1;
	int res=0;
	for(int i=0;i<n*m;i++)if(S&(1<<i)){
		for(int j=i+1;j<n*m;j++)if(S&(1<<j)){
			if(x[i]==x[j]||y[i]==y[j])res+=sol(S^(1<<i)^(1<<j));
		}
		break;
	}
	return res;
}

signed main(){
	n=read(),m=read();
	int k=0,S=0;
	for(int i=1;i<=n;i++){
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++){
			x[k]=i,y[k]=j;
			if(s[i][j]=='#')S^=(1<<k);
			++k;
		}
	}
	for(int i=0;i<(1<<(n*m));i++)if((S&i)==S)if(sol(i)==1){
		int tot=0;
		for(int j=0;j<n*m;j++)if((!(S&(1<<j)))&&(i&(1<<j)))++tot;
		ans=min(ans,tot);
	}
	if(ans==INF)ans=-1; 
	printf("%d\n",ans);
	return 0;
}

