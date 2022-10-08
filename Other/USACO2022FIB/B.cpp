#include <cstdio>
#include <algorithm>

using namespace std;

inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

const int N=100007;
int n,s[N],t[N],a[N],ans, Mx;

signed main(){
	n=read();
	for(int i=1;i<=n;++i)s[i]=read();
	for(int i=1;i<=n;++i)t[read()] = i;
	for(int i=1;i<=n;++i)s[i]=t[s[i]];
	Mx = s[1];
	for(int i=2;i<=n;i++){
		if(s[i] < Mx) ++ans;
		Mx = max(Mx, s[i]);
	}
	printf("%d\n",ans);
	return 0;
}

