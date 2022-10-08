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

const int N=4e6+7,Mod=998244353,INF=1e9+7;
int n,a[N],f[N],ans=INF,tr[N];
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}
bool operator < (const node& A)const{return x<A.x;}}p[N],v[N];

inline void ub(int& x){x+=(x&(-x));return;}
inline void db(int& x){x-=(x&(-x));return;}
inline void add(int x){for(;x<=n;ub(x))++tr[x];return;}
inline int sum(int x){int res=0;for(;x;db(x))res+=tr[x];return res;}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),p[i]=node(a[i],i);
	for(int i=1;i<=n;i++)f[i]=read(),v[i]=node(f[i],i);
	sort(p+1,p+n+1);
	sort(v+1,v+n+1);
	if(f[1]==1){
		printf("1\n");
		return 0;
	}
	for(int i=1,l=n,r=1,j=1;i<=n;i++){
		while(j<=n&&v[j].x<=i)add(v[j].y),++j;
		l=min(l,p[i].y),r=max(r,p[i].y);
		if(p[i+1].y<l||r<p[i+1].y){
			int L=r-l+1,R;
			if(p[i+1].y<l)R=n-p[i+1].y;
			else R=p[i+1].y-1;
			while(L!=R){
				int M=(L+R)>>1;
				if(sum(M)-sum(L-1)>0)R=M;
				else L=M+1;
			}
			if(sum(R)-sum(L-1)>0)ans=min(ans,R);
		}
	}
	if(ans==INF)ans=0;
	printf("%d\n",ans);
	return 0;
}

