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

int T,n;
char str[N];

int main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",str+1);
		int s=0,tag=1;
		for(int i=1;i<=n/2;i++){
			if(str[i]!=str[n-i+1]){
				if(!s)s=i;
				else if(i==s+1)++s;
				else{
					tag=0;
					break;
				}
			}
		}
		if(tag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}


