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

const int N=1e7+7,Mod1=998244353,Mod2=1000000007,Mod3=114514;
int T,n,s1[N],s2[N],s3[N];

int main(){
	T=read();
	for(int t=1;t<=T;t++){
		n=read();
		for(int i=1,v,h1,h2,h3;i<=n;i++){
			v=read();
			h1=((v*Mod1)%N+N)%N,h2=((v*Mod2)%N+N)%N,h3=((v*(v+1)*Mod3)%N+N)%N;
			if(s1[h1]<t||s2[h2]<t||s3[h3]<t){
				s1[h1]=t,s2[h2]=t,s3[h3]=t;
				printf("%d ",v);
			}
		}
		printf("\n");
	}
	return 0;
}
