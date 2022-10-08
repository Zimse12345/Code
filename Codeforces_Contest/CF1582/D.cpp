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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		if(n%2==0){
			for(int i=1;i<=n;i+=2)b[i]=-a[i+1],b[i+1]=a[i];
			for(int i=1;i<=n;i++)printf("%lld ",b[i]);
			printf("\n");
		}
		else{
			n-=3;
			for(int i=1;i<=n;i+=2)b[i]=-a[i+1],b[i+1]=a[i];
			if(a[n+1]!=a[n+2]&&a[n+2]!=a[n+3]&&a[n+1]!=a[n+3])b[n+1]=a[n+2]-a[n+3],b[n+2]=a[n+3]-a[n+1],b[n+3]=a[n+1]-a[n+2];
			else if(a[n+1]==a[n+2]&&a[n+2]==a[n+3])b[n+1]=2,b[n+2]=-1,b[n+3]=-1;
			else if(a[n+1]==a[n+2]){
				int tag=1;
				if(abs(a[n+3])<2)a[n+3]*=2,tag=2;
				b[n+1]=a[n+3]/2,b[n+2]=b[n+1];
				if(a[n+3]%2!=0){
					if(a[n+3]<0)--b[n+2];
					else ++b[n+2];
				}
				b[n+3]=-tag*a[n+1];
			}
			else if(a[n+2]==a[n+3]){
				int t=a[n+3];a[n+3]=a[n+1],a[n+1]=t;
				int tag=1;
				if(abs(a[n+3])<2)a[n+3]*=2,tag=2;
				b[n+1]=a[n+3]/2,b[n+2]=b[n+1];
				if(a[n+3]%2!=0){
					if(a[n+3]<0)--b[n+2];
					else ++b[n+2];
				}
				b[n+3]=-tag*a[n+1];
				t=b[n+3];b[n+3]=b[n+1],b[n+1]=t;
			}
			else if(a[n+1]==a[n+3]){
				int t=a[n+3];a[n+3]=a[n+2],a[n+2]=t;
				int tag=1;
				if(abs(a[n+3])<2)a[n+3]*=2,tag=2;
				b[n+1]=a[n+3]/2,b[n+2]=b[n+1];
				if(a[n+3]%2!=0){
					if(a[n+3]<0)--b[n+2];
					else ++b[n+2];
				}
				b[n+3]=-tag*a[n+1];
				t=b[n+3];b[n+3]=b[n+2],b[n+2]=t;
			}
			for(int i=1;i<=n+3;i++)printf("%lld ",b[i]);
			printf("\n");
		}
	}
	return 0;
}
