#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
// #define int long long

inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c<48||57<c){
		if(c==45)y=-1;
		c=getchar();
	}
	while(47<c&&c<58)x=x*10+c-48,c=getchar();
	return x*y;
}

const int N=1000007;
int T,n,a[N];

int gcd(int x,int y){
	if(y)return gcd(y,x%y);
	return x;
}

int main(){
	T=read();
	while(T--){
		n=read();
		int tag=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)if(gcd(a[i],a[j])<=2)tag=1;
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

