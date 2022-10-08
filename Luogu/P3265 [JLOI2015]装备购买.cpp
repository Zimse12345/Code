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

const int N=5e2+7,Mod=998244353,INF=1e9+7;
int n,m,ans,cnt;
struct vec{int c;double v[N];}a[N],d[N];
bool cmp(const vec& A,const vec& B){return A.c<B.c;}

void mul(vec& A,double B){for(int i=1;i<=m;i++)A.v[i]*=B;return;}
void add(vec& A,vec B){for(int i=1;i<=m;i++)A.v[i]+=B.v[i];return;}

bool check(vec x){
	for(int i=1;i<=m;i++)if(abs(x.v[i])>1e-6){
		if(!d[i].c){
			d[i]=x,d[i].c=1;
			return true;
		}
		double p=x.v[i]/d[i].v[i];
		vec y=d[i];
		mul(y,-p),add(x,y);
	}
	return false;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)a[i].v[j]=read();
	for(int i=1;i<=n;i++)a[i].c=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)if(check(a[i]))ans+=a[i].c,++cnt;
	printf("%d %d\n",cnt,ans);
	return 0;
}

