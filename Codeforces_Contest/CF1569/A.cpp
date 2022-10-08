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

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();break;}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=2e5+7,Mod=998244353,INF=1e9+7;
int T,n;
char s[N];

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		int L=-1,R=-1;
		for(int i=1;i<=n;i++)for(int j=i;j<=n;j++){
			int A=0,B=0;
			for(int k=i;k<=j;k++){
				if(s[k]=='a')++A;
				else ++B;
			}
			if(A==B&&j-i>R-L)L=i,R=j;
		}
		printf("%d %d\n",L,R);
	}
	return 0;
}
