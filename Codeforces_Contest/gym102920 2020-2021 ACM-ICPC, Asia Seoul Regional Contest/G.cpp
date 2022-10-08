
#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int read(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
signed main()
{
	int n=read(),d=read();
	int mi=2e18,mx=-2e18;
	for(int x,i=1;i<=n;i++)
		x=read()-i*d,mi=min(mi,x),mx=max(mx,x);
    int ans=mx-mi;
    printf("%lld%s",ans/2,(ans&1ll)?".5\n":".0\n");
	return 0;
}