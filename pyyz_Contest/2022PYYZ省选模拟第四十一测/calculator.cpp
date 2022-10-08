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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e6+7,INF=1e12;
int T,P,fac[N],s[1200][1200];
map<int,int> vis,mp;

inline int qp(int x,int k){
	int res=1;
	while(k){
		if(k&1ll)res=(res*x)%P;
		x=(x*x)%P,k/=2;
	}
	return res;
}

inline int inv(int x){
	return qp(x,P-2);
}

inline int C(int a,int b){
	if(b>a)return 0;
	int f1=fac[a];
	int f2=(fac[b]*fac[a-b])%P;
	return f1*inv(f2)%P;
}

int Lucas(int a,int b){
	if(b==0)return 1;
	return C(a%P,b%P)*Lucas(a/P,b/P)%P;
}

signed main(){
	T=read();
	for(int I=1;I<=T;I++){
		int ty=read(),y=read(),z=read();
		P=read();
		if(ty==1)printf("%lld\n",qp(y,z));
		else if(ty==2){
			if(P<=1000){
				int ans=INF;
				for(int i=0,t=1;i<=P;i++){
					if(t==z){ans=i;break;}
					t=t*y%P;
				}
				if(ans==INF)printf("Math Error\n");
				else printf("%lld\n",ans);
				continue;
			}
			int B=signed(ceil(sqrt(P)))+1;
			int y1000=qp(y,B),ans=INF;
			mp.clear(),vis.clear();
			for(int i=0,Y=1;i<=B;i++){
				if(!vis[Y])mp[Y]=i,vis[Y]=1;
				Y=Y*y1000%P;
			}
			int iy=inv(y);
			for(int i=0,yy=1,iyy=1,Y;i<B;i++){
				if(yy==z)ans=min(ans,i);
				Y=iyy*z%P,yy=yy*y%P,iyy=iyy*iy%P;
				if(vis[Y])ans=min(ans,mp[Y]*B+i);
			}
			if(ans==INF)printf("Math Error\n");
			else printf("%lld\n",ans);
		}
		else{
			if(y>z){
				printf("0\n");
				continue;
			}
			if(y>1000||z>1000){
				fac[0]=1;
				for(int i=1;i<P;i++)fac[i]=fac[i-1]*i%P;
				printf("%lld\n",Lucas(z,y));
				continue;
			}
			for(int i=0;i<=z;i++)for(int j=0;j<=z;j++)s[i][j]=0;
			s[0][0]=1;
			for(int i=1;i<=z;i++){
				s[i][0]=1;
				for(int j=1;j<=i;j++)s[i][j]=(s[i-1][j-1]+s[i-1][j])%P;
			}
			printf("%lld\n",s[z][y]);
		}
	}
	return 0;
}

