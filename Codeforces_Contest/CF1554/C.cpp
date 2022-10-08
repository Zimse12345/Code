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
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,m,b[100];

signed main(){
	T=read();
	b[0]=1;
	for(int i=1;i<=50;i++)b[i]=b[i-1]<<1ll;
	while(T--){
		n=read(),m=read();
		if(m<n){
			printf("0\n");
			continue;
		}
		int s=0,y=0;
		for(int i=40;i>=0;i--){
			if((m&b[i])&&(!(n&b[i])))s|=b[i];
			if((!(m&b[i]))&&(n&b[i])){
				y=1;
				break;
			}
		}
		if(!y){
			for(int i=0;i<=40;i++){
				if((!(m&b[i]))&&(!(n&b[i]))){
					s|=b[i],y=1;
					break;
				}
				else if(s&b[i])s-=b[i];
			}
		}
		
		printf("%lld\n",s);
	}
	return 0;
}

