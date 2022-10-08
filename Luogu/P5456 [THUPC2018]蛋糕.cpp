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

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=2148473648,INF=1e9+7;
int T,a,b,c,d;
int ans[9];

signed main(){
	T=read();
	while(T--){
		a=read(),b=read(),c=read(),d=read();
		for(int i=0;i<=8;i++)ans[i]=0;
		for(int A=1;A<=3;A++){
			if(A==3&&a==1)continue;
			if(A==2&&a<=2)continue;
			for(int B=1;B<=3;B++){
				if(B==3&&b==1)continue;
				if(B==2&&b<=2)continue;
				for(int C=1;C<=3;C++){
					if(C==3&&c==1)continue;
					if(C==2&&c<=2)continue;
					for(int D=1;D<=3;D++){
						if(D==3&&d==1)continue;
						if(D==2&&d<=2)continue;
						int p=1,k=0;
						if(A==2)p*=(a-2),p%=Mod;
						if(B==2)p*=(b-2),p%=Mod;
						if(C==2)p*=(c-2),p%=Mod;
						if(D==2)p*=(d-2),p%=Mod;
						if(A==1||A==3)++k;
						if(B==1||B==3)++k;
						if(C==1||C==3)++k;
						if(D==1||D==3)++k;
						if(a==1)++k;
						if(b==1)++k;
						if(c==1)++k;
						if(d==1)++k;
						ans[k]=(ans[k]+p)%Mod;
					} 
				}
			}
		} 
		for(int i=0;i<=8;i++)printf("%lld ",ans[i]);
		printf("\n");
	}
	return 0;
}
