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

#define int __int128
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){qrc=getchar();if(qrc=='-'){qry=-1,qrc=getchar();break;}}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-'0',qrc=getchar();return qrx*qry;}
void write(int x){if(x>=10)write(x/10);putchar('0'+x%10);return;}

const int N=1e6+7,Mod=998244353,INF=1e9+7;
int n,ans,s;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int lcm(int a,int b){return b/gcd(a,b)*a;}

void exgcd(int a,int b,int& x,int& y){
    if(b)exgcd(b,a%b,y,x),y-=(a/b)*x;
    else x=1,y=0;return;
}

signed main(){
	n=read()-1,s=read(),ans=read();
	for(int i=1,a,x,y;i<=n;i++)a=read(),exgcd(s,a,x,y),x*=(((read()-ans)%a)/gcd(s,a)),ans+=x*s,s=lcm(s,a);
	ans=(ans%s+s)%s;
	write(ans),putchar(10);
	return 0;
}
