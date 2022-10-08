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
int T,n,f[N][6];

int main(){
	T=read();
	while(T--){
		n=read();
		int tag=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=5;j++)f[i][j]=read();
			
		}for(int a=1;a<=5;a++)for(int b=a+1;b<=5;b++){
				int c1=0,c2=0,c3=0;
				for(int i=1;i<=n;i++){
					if(f[i][a]&&f[i][b])++c2;
					else if(f[i][a])++c1;
					else if(f[i][b])++c3;
				}
				if(c1<n/2)c2-=n/2-c1;
				if(c3<n/2)c2-=n/2-c3;
				//printf("[%d %d %d %d %d]\n",a,b,c1,c3,c2);
				if(c2>=0)tag=1;
			}
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
