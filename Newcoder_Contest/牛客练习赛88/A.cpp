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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=5e6+7,Mod=998244353,INF=1e9+7;
int T,V,I,n,ans[N];

signed main(){
	T=read();
	while(T--){
		V=read(),I=read(),n=min(I+V,read());
		for(int i=1;i<=n;i++){
			ans[i]=0;
			if(V)--V,ans[i]=5;
			else --I,ans[i]=1;
		}
		for(int i=1;i<=n&&I;i++){
			if(ans[i]==5){
				if(I>=3)ans[i]+=3,I-=3;
				else ans[i]+=I,I=0;
			}
			else{
				if(I>=2)ans[i]+=2,I-=2;
				else ans[i]+=I,I=0;
			}
		}
		for(int i=1;i<=n;i++)printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}