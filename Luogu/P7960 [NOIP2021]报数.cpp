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
inline void write(int x)
{
    if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9) 
		write(x/10);
    putchar(x%10+'0');
}

const int N=1e7+100,Mod=998244353,INF=1e9+7;
int T,n,pr[N],prime[N],t,nx[N],tag[N];

int main(){
	T=read();
	for(int i=2;i<N;i++){
		if(pr[i]==0)pr[i]=i,prime[++t]=i;
		for(int j=1;j<=t&&i*prime[j]<=N;j++){
			pr[i*prime[j]]=prime[j];
			if(pr[i]==prime[j])break;
		}
	}
	for(int i=1;i<N;i++){
		if(!tag[i]){
			int v=i;
			while(v){
				if(v%10==7){tag[i]=1;break;}
				v/=10;
			}
		}
		if(tag[i]){
			for(int j=1;i*prime[j]<N&&j<=t;j++)tag[i*prime[j]]=1;
		}
	}
	for(int i=N-1,j=N;i>=0;i--){
		if(!tag[i])nx[i]=j,j=i;
		else nx[i]=-1;
	}
	while(T--){
		write(nx[read()]);
		putchar('\n');
	}
	return 0;
}

