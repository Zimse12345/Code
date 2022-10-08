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

using namespace std;

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=4e7+7,Mod=998244353;
int z[N];
char s[N],t[N];
int n,m,ans1,ans2;

signed main(){
	scanf("%s",s);
	scanf("%s",t);
	n=strlen(s),m=strlen(t);
	for(int i=0;i<n;i++)t[m+i]=s[i];
	for(int i=1,l=0,r=0;i<n+m;i++){
		if(i<=r&&z[i-l]<r-i+1)z[i]=z[i-l];
		else{
			z[i]=max(0ll,r-i+1);
			while(i+z[i]<n+m&&t[i+z[i]]==t[z[i]])++z[i];
		}
		if(i+z[i]-1>r)l=i,r=i+z[i]-1;
		if(i<m)ans1^=((min(z[i],m-i)+1)*(i+1));
		else ans2^=((z[i]+1)*(i-m+1));
	}
	ans1^=(m+1);
	printf("%lld\n%lld\n",ans1,ans2);
	return 0;
}

