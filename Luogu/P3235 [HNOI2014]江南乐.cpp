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

const int N=1e5+7,Mod=998244353,INF=1e9+7;
int T,F,SG[N],n,a[N],x,vis[N];

int main(){
	T=read(),F=read();
	for(int i=F,r;i<N;i++){
		for(int j=2;j<=i;j=r+1){
			int t=i/j,flag=2,num=0,res=0;
            r=i/t;
            if(j==r)flag=1;
            while(num<flag) {
                num++;
                res=0;
                if((i%j)&1)res^=SG[t+1];
                if((j-i%j)&1)res^=SG[t];
                ++j,vis[res]=i;
            }
		}
		for(int j=0;j<N;j++)if(vis[j]!=i){
			SG[i]=j;
			break;
		}
	}
	while(T--){
		n=read(),x=0;
		for(int i=1;i<=n;i++)a[i]=read(),x^=SG[a[i]];
		printf("%d ",min(x,1));
	}
	return 0;
}
