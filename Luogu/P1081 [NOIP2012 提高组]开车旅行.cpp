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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}
struct node{int x,y;node(int x=0,int y=0):x(x),y(y){}bool operator < (const node& A)const{return x<A.x;};};
inline double c(node p){if(p.y==0)return 1e15;return double(p.x)/double(p.y);}

const int N=1e5+7,Mod=998244353,INF=1e15;
int n,x0,m,h[N],nxtA[N],nxtB[N],f[N][20],disA[N][17],disB[N][17];
set<node> city;

node query(int s,int x){
	node res=node(0,0);
	for(int i=16;i>=0;i--){
		int to=f[s][i];
		if(!to)continue;
		if(x<disA[s][i]+disB[s][i])continue;
		res.x+=disA[s][i],res.y+=disB[s][i];
		x-=disA[s][i]+disB[s][i],s=to;
	}
	return res;
}

signed main(){
	n=read();
	for(int i=1;i<=n;i++)h[i]=read();
	city.insert(node(INF,0)),city.insert(node(INF+1,0)),city.insert(node(-INF,0)),city.insert(node(-INF-1,0));
	for(int i=n;i>=1;i--){
		city.insert(node(h[i],i));
		set<node>::iterator p=city.lower_bound(node(h[i],i));
		int c[4],m1=0,m2=0;
		p--,c[0]=(*p).y,p--,c[1]=(*p).y;
		p++,p++,p++,c[2]=(*p).y,p++,c[3]=(*p).y;
		for(int j=0;j<4;j++)if(c[j]){
			if(m1==0||abs(h[i]-h[m1])>abs(h[i]-h[c[j]])||(abs(h[i]-h[m1])==abs(h[i]-h[c[j]])&&h[c[j]]<h[m1]))m2=m1,m1=c[j];
			else if(m2==0||abs(h[i]-h[m2])>abs(h[i]-h[c[j]])||(abs(h[i]-h[m2])==abs(h[i]-h[c[j]])&&h[c[j]]<h[m2]))m2=c[j];
		}
		nxtA[i]=m2,nxtB[i]=m1;
		f[i][0]=nxtA[i],disA[i][0]=abs(h[i]-h[nxtA[i]]);
		f[i][1]=nxtB[nxtA[i]],disA[i][1]=disA[i][0],disB[i][1]=abs(h[nxtA[i]]-h[nxtB[nxtA[i]]]);
	}
	for(int j=2;j<=16;j++){
		for(int i=1;i<=n;i++){
			f[i][j]=f[f[i][j-1]][j-1];
			disA[i][j]=disA[i][j-1]+disA[f[i][j-1]][j-1];
			disB[i][j]=disB[i][j-1]+disB[f[i][j-1]][j-1];
		}
	}
	x0=read();
	node ans0=query(1,x0);
	int Ans=1;
	for(int i=2;i<=n;i++){
		node p=query(i,x0);
		double k1=c(ans0),k2=c(p);
		if(fabs(k1-k2)<1e-9&&h[i]>h[Ans])Ans=i,ans0=p;
		else if(k2<k1)Ans=i,ans0=p;
	}
	printf("%lld\n",Ans);
	m=read();
	for(int i=1,x,s;i<=m;i++){
		s=read(),x=read();
		node ans=query(s,x);
		printf("%lld %lld\n",ans.x,ans.y);
	}
	return 0;
}
