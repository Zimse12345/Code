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

const int N=5e3+7,Mod=998244353,INF=1e9+7;
int n,a[N],f[N],cnt[N],m,ans;

int main(){
	n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    f[1]=cnt[1]=m=1;
    for(int i=2;i<=n;i++){
        int x=1;
        for(int j=1;j<i;j++)if(a[j]>a[i])x=max(x,f[j]+1);
        for(int j=1;j<i;j++){
            if(x==f[j]+1&&a[i]<a[j])cnt[i]+=cnt[j];
            if(x==f[j]&&a[i]==a[j])cnt[j]=0;
        }
        f[i]=x,m=max(m,x);
        if(x==1)cnt[i]=1;
    }

    for(int i=1;i<=n;i++)if(f[i]==m)ans+=cnt[i];
    printf("%d %d\n",m,ans);

	return 0;
}