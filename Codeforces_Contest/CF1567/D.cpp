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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,s,m,n,a[N];

int main(){
	T=read();
	while(T--){
		s=read(),m=read(),n=0;
		int v=s,cnt=0;
		while(v)a[++n]=v%10,v/=10,cnt+=a[n];
		while(cnt<m){
			for(int i=2;i<=n;i++)if(a[i]){
				--a[i],a[i-1]+=10,cnt+=9;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			while(m>1&&a[i]){
				printf("%d",1);
				for(int j=1;j<i;j++)printf("0");
				printf(" ");
				--m,--a[i];
			}
			if(m==1)break;
		}
		
		int y=0;
		for(int i=n;i>=1;i--){
			if(a[i]>0)y=1; 
			if(y==1)printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}