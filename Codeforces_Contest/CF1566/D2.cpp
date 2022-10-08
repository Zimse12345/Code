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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=300+7,Mod=998244353,INF=1e9+7;
int T,n,m,a[N][N],q[N*N];
int t[N][N],cnt[N];

struct p{
	int v,num;
	p(int v=0,int num=0):v(v),num(num){};
	bool operator <(const p& A)const{if(v==A.v)return num<A.num;return v<A.v;}
}s[N*N],ss[N*N];

int id(int x,int y){
	return (x-1)*m+y;
}

signed main(){
	T=read();
	while(T--){
		n=read(),m=read();
		int c=0,ans=0;
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			a[i][j]=read(),t[i][j]=0,++c,cnt[i]=0;
			s[c]=p(a[i][j],c);
		}
		sort(s+1,s+c+1);
		for(int i=1;i<=c;){
			int j=i;
			while(j<c&&s[i].v==s[j+1].v)++j;
			int x1=1+(i-1)/m,y1=1+(i-1)%m;
			int x2=1+(j-1)/m,y2=1+(j-1)%m;
			if(x1==x2){
				for(int k=y1;k<=y2;k++)ss[id(x1,k)]=s[id(x1,y1+y2-k)];
				i=j+1;
				continue;
			}
			if(x1<x2){
				for(int k=y1;k<=m;k++)ss[id(x1,k)]=s[id(x1,y1+m-k)];
				++x1,y1=1;
			}
			while(x1<x2){
				for(int k=1;k<=m;k++)ss[id(x1,k)]=s[id(x1,m-k+1)];
				++x1;
			}
			for(int k=y1;k<=y2;k++)ss[id(x1,k)]=s[id(x1,y1+y2-k)];
			i=j+1;
		}
		for(int i=1;i<=c;i++)q[ss[i].num]=i;
		
		for(int i=1;i<=c;i++){
			int k=q[i];
			int x=1+(k-1)/m,y=1+(k-1)%m;
			for(int j=1;j<y;j++)ans+=t[x][j];
			t[x][y]=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}
