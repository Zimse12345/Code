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

const int N=3e5+7,Mod=998244353,INF=1e9+7;
int T,n,q,a[N],sum1[N],sum2[N];
char s[N];

int main(){
	T=read();
	while(T--){
		n=read(),q=read();
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='-')a[i]=1;
			else a[i]=0; 
		}
		
		for(int i=1;i<=n;i++){
			sum1[i]=sum1[i-1]+(a[i]^(i%2));
			sum2[i]=sum2[i-1]+(a[i]^((i+1)%2));
		}
		
		while(q--){
			int l=read(),r=read();
			int k=r-l+1,t0=0,t1=0;
			int sum=0;
			
			if(l%2)sum=sum1[r]-sum1[l-1];
			else sum=sum2[r]-sum2[l-1];
			
			if(sum*2==k){
				printf("0\n");
				continue;
			}
			if(k%2==1){
//				int s0=0,s1=0,y=0;
//				for(int i=l;i<=r;i++){
//					if(a[i]^((i-l)%2))--t1;
//					else --t0;
//					
//					if((s0+t1)*2==k){
//						printf("1\n"),y=1;
//						break;
//					}
//					if(a[i]^((i-l)%2))++s1;
//					else ++s0;
//				}
//				if(!y)printf("3\n");
				printf("1\n");
			}
			else printf("2\n");
		}
	}
	return 0;
}

