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
#include <unordered_map>
#pragma GCC optimize(2)
#pragma GCC optimize(3)

#define int long long
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int n,X,Y,mid,dx[N],dy[N],ans;
vector<pair<int, int> > p[22],q[22];

signed main(){
	n=read(),X=read(),Y=read();
	if(n==1){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;i++)dx[i]=read(),dy[i]=read();
	mid=n/2;
	for(int i=0,sz,xx,yy;i<(1<<mid);i++){
		sz=0,xx=0,yy=0;
		for(int j=0;j<mid;j++)if(i&(1<<j))++sz,xx+=dx[j+1],yy+=dy[j+1];
		p[sz].push_back({xx,yy});
	}
	for(int i=0,sz,xx,yy;i<(1<<(n-mid));i++){
		sz=0,xx=0,yy=0;
		for(int j=0;j<n-mid;j++)if(i&(1<<j))++sz,xx+=dx[j+mid+1],yy+=dy[j+mid+1];
		q[sz].push_back({X-xx,Y-yy});
	}
	for(int i=0;i<=mid+1;i++)sort(p[i].begin(),p[i].end()),sort(q[i].begin(),q[i].end());
	for(int o=1;o<=n;o++){
		ans=0;
		for(int i=0,j;i<=mid;i++){
			j=o-i;
			if(j<0)continue;
			if(j>21)continue;
			//p[i],q[j]
			
			for(unsigned k=0,kk=0,ct=0;k<signed(p[i].size());k++){
				ct = 1; 
				while((k + 1)<p[i].size() && p[i][k] == p[i][k + 1]) ++ct, ++k; 
				while(kk<signed(q[j].size())&&q[j][kk]<p[i][k])++kk;
				while(kk<signed(q[j].size())&&q[j][kk]==p[i][k])ans += ct, ++kk;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

