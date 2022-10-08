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

inline int read(){int qrx=0,qry=1;char qrc=getchar();
while(qrc<'0'||qrc>'9'){if(qrc=='-')qry=-1;qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int Mod=1e9+7;
int T,n,f[2][20][20][20][20][20][20];
char s[100];
inline void add(int& x,int y){(x+=y)%=Mod;return;}

void cl(int t){
	int N=19;
	for(int a=0;a<=N;a++){
		for(int b=0;a+b<=N;b++){
			for(int c=0;a+b+c<=N;c++){
				for(int ac=0;a+b+c+ac<=N;ac++){
					for(int ba=0;a+b+c+ac+ba<=N;ba++){
						for(int cb=0;a+b+c+ac+ba+cb<=N;cb++){
							f[t][a][b][c][ac][ba][cb]=0;
						}
					}
				}
			}
		}
	}
	return;
}

signed main(){
	T=read();
	while(T--){
		n=read();
		scanf("%s",s+1);
		//acb bac cba
		//a b c ac ba cb
		cl(0),f[0][0][0][0][0][0][0]=1;
		int t=0;
		for(int i=1;i<=n*3;i++){
			t^=1,cl(t);
			int N=min(i,n);
			for(int a=0;a<=N;a++){
				for(int b=0;a+b<=N;b++){
					for(int c=0;a+b+c<=N;c++){
						for(int ac=0;a+b+c+ac<=N;ac++){
							for(int ba=0;a+b+c+ac+ba<=N;ba++){
								for(int cb=0;a+b+c+ac+ba+cb<=N;cb++){
									int x=f[t^1][a][b][c][ac][ba][cb];
									if(!x)continue;
									if(s[i]=='1'||s[i]=='0'){
										if(a<N)add(f[t][a+1][b][c][ac][ba][cb],x);
										if(b)add(f[t][a][b-1][c][ac][ba+1][cb],1ll*x*b%Mod);
										if(cb)add(f[t][a][b][c][ac][ba][cb-1],1ll*x*cb%Mod);
									}
									if(s[i]=='2'||s[i]=='0'){
										if(b<N)add(f[t][a][b+1][c][ac][ba][cb],x);
										if(c)add(f[t][a][b][c-1][ac][ba][cb+1],1ll*x*c%Mod);
										if(ac)add(f[t][a][b][c][ac-1][ba][cb],1ll*x*ac%Mod);
									}
									if(s[i]=='3'||s[i]=='0'){
										if(c<N)add(f[t][a][b][c+1][ac][ba][cb],x);
										if(a)add(f[t][a-1][b][c][ac+1][ba][cb],1ll*x*a%Mod);
										if(ba)add(f[t][a][b][c][ac][ba-1][cb],1ll*x*ba%Mod);
									}
								}
							}
						}
					}
				}
			}
		}
		ll ans=f[t][0][0][0][0][0][0];
		for(int i=2;i<=n;i++)ans=(ans*i)%Mod;
		printf("%lld\n",ans);
	}
	return 0;
}

