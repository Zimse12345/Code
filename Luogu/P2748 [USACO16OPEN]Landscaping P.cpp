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
#define Lid (id<<1)
#define Rid ((id<<1)|1)

using namespace std;

int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}else qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}
inline void write(int x){if(x<0){putchar('-'),x=-x;}if(x>9)write(x/10);putchar(x%10+'0');}

const int N=5e5+7,Mod=998244353,INF=1e9+7;
int n,X,Y,Z,ans;
priority_queue<int> q1,q2;

signed main(){
	n=read(),X=read(),Y=read(),Z=read();
	for(int i=1,a,b;i<=n;i++){
		a=read(),b=read();
		if(a<b){
			for(int j=a;j<b;j++){
				if(!q1.size()||i*Z-q1.top()>X)ans+=X,q2.push(i*Z+X);
				else ans+=i*Z-q1.top(),q2.push(i*Z*2-q1.top()),q1.pop();
			} 
		}
		else{
			for(int j=b;j<a;j++){
				if(!q2.size()||i*Z-q2.top()>Y)ans+=Y,q1.push(i*Z+Y);
				else ans+=i*Z-q2.top(),q1.push(i*Z*2-q2.top()),q2.pop();
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

