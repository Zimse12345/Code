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
#define ull unsigned long long

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=1e9+7;
int T,n,a[N];

signed main(){
	T=read();
	while(T--){
        n=read();
        int L=0,R=1e8,p=0;
        while(L<=R){
            int M=(L+R)>>1;
            if(M*(M+1)/2>=n)p=M,R=M-1;
            else L=M+1;
        }
        int k=p*(p+1)/2;//1++p
        if(k==n+1||k==n+p)++p;
        printf("%lld\n",p);
	}
	return 0;
}
