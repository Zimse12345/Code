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

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int n,m,w[N],rk[N],nrk[N];
char s[N][N];
struct p{
	int w,num;
	p(int w=0,int num=0):w(w),num(num){}
	bool operator <(const p& A)const{
		if(w==A.w)return num<A.num;
		else return w>A.w;
	}
}h[N];

int main(){
	n=read(),m=read();
	for(int i=1;i<=2*n;i++)scanf("%s",s[i]+1),rk[i]=i;
	for(int j=1;j<=m;j++){
		//for(int i=1;i<=n*2;i++)w[i]=0;
		for(int i=1;i<=n;i++){
			char a=s[rk[i*2-1]][j],b=s[rk[i*2]][j];
			if((a=='G'&&b=='C')||(a=='C'&&b=='P')||(a=='P'&&b=='G'))++w[rk[i*2-1]];
			else if(a!=b)++w[rk[i*2]];
		}
		for(int i=1;i<=2*n;i++)h[i]=p(w[i],i);
		sort(h+1,h+n*2+1);
		for(int i=1;i<=2*n;i++)rk[i]=h[i].num;
	}
	for(int i=1;i<=2*n;i++)printf("%d\n",rk[i]);
	return 0;
}

