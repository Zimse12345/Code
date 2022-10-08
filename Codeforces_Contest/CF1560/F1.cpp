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
while(qrc<'0'||qrc>'9'){if(qrc=='-'){qry=-1,qrc=getchar();}qrc=getchar();}
while(qrc>='0'&&qrc<='9')qrx=qrx*10+qrc-48,qrc=getchar();return qrx*qry;}

const int N=1e2+7,Mod=998244353,INF=2e15+7;
int T,v,V,n,a[N],k,u[N],cnt,b[N],ans;

signed main(){
	T=read();
	while(T--){
        V=v=read(),n=0,k=read(),cnt=0;
        for(int i=0;i<10;i++)u[i]=0;
        while(v){
            a[++n]=v%10,v/=10;
            if(!u[a[n]])u[a[n]]=1,++cnt;
        }
        if(cnt<=k){
            printf("%lld\n",V);
            continue;
        }
        for(int i=0;i<10;i++)u[i]=0;
        cnt=0,ans=INF;

        for(int i=n;i>=1;i--){
            if(cnt==k-1){
                for(int w=0;w<10;w++){
                	int r=u[w]?0:1;
                    u[w]=1;
                    int Y=1;

                    for(int j=i;j>=1;j--){
                        int y=0,p=a[j];
                        for(int d=p;d<10;d++)if(u[d]){
                            y=1,b[j]=d;
                            break;
                        }
                        if(!y){
                            Y=0;
                            break;
                        }
                        
                        int tag=0;
                        if(a[j]==b[j]){
                        	tag=1;
                        	for(int d=p+1;d<10;d++)if(u[d]){
                        		b[j]=d;
                        		break;
							}
						}
						int q=9;
						for(int d=0;d<10;d++)if(u[d]){
							q=d;
							break;
						}
						
						if(b[j]>a[j]){
							int o=0;
							for(int d=n;d>=j;d--)o=o*10+b[d];
							for(int d=j-1;d>=1;d--)o=o*10+q;
							ans=min(ans,o);
						}
						
						if(tag)b[j]=a[j];
                    }
                    
                    if(Y){
                        int p=0;
                        for(int j=n;j>=1;j--)p=p*10+b[j];
                        ans=min(ans,p);
                    }

                    if(r)u[w]=0;
                }
                
                break; 
            }

            if(u[a[i]]){b[i]=a[i];continue;}
            if(!u[a[i]])u[a[i]]=1,++cnt,b[i]=a[i];
        }
        printf("%lld\n",ans);
	}
	return 0;
}
