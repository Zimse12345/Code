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

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int T,n,a[N],b[N],t[N],u,v;

bool win(int x,int y){
	if(x+1==y)return 1;
	if(x==3&&y==1)return 1;
	return 0;
}

int main(){
	T=read();
	while(T--){
		n=read();
		int c=0,c1=0,c2=0;
		for(int i=1;i<=n*2;i++)a[i]=read(),t[i]=0;
		for(int i=1;i<=n*2;i++){
			b[i]=read();
			if(!win(a[i],b[i]))t[i]=1,++c;
		}
		for(int i=1;i<=n*2&&c+2<=n*2;i++)if(t[i]==0)t[i]=2,c+=2;
		for(int i=1;i<=n*2&&c<n*2;i++)if(t[i]==1)t[i]=2,++c;
		for(int i=1;i<=n*2;i++)if(t[i]){
			if(t[i]==1){
				if(c1<c2){++c1;a[i]=b[i]-1;if(a[i]==0)a[i]=3;}
				else{++c2;b[i]=a[i]+1;if(b[i]==4)b[i]=1;}
			}
			else{
				u=a[i]+1;if(u==4)u=1;
				v=u+1;if(v==4)v=1;
				if(v==b[i]){
					u=a[i]-1;if(u==0)u=3;
					v=u+1;if(v==4)v=1;
				}
				a[i]=u,b[i]=v;
			}
		}
		
		printf("%d\n",n*2);
		for(int i=1;i<=n*2;i++)printf("%d ",a[i]);
		printf("\n");
		for(int i=1;i<=n*2;i++)printf("%d ",b[i]);
		printf("\n");
	}
	return 0;
}
