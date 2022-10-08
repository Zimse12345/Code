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

int read(){int qrx=0,qry=1;char qrc=' ';
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}

const int N=1e3+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

int main(){
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		int ans=0,o=1;
		while(1){
			int y=1;
			for(int i=1;i<=n;i++)if(a[i]!=i){
				y=0;
				break;
			}
			if(y)break;
			++ans;
			
			if(o==1)for(int i=1;i<=n;i+=2)if(i!=n){//printf("[%d]",i);
				if(a[i+1]<a[i]){int t=a[i+1];a[i+1]=a[i],a[i]=t;}
			}
			if(o==0) for(int i=2;i<n;i+=2){//printf("[%d]",i);
				if(a[i+1]<a[i]){int t=a[i+1];a[i+1]=a[i],a[i]=t;}
			}
			o^=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}

