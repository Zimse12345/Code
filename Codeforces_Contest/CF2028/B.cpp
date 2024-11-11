#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,n,b,c;

signed main(){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&n,&b,&c);
        //[0,n-1]
        //[c,c+(n-1)b] 
        if(b){
            int x=(n-1-c)/b+1;
            if(c>n-1)x=0;
            int y=n-x;
            printf("%lld\n",y);
        }
        else{
            if(c>=n-2){
                if(c>n-1)printf("%lld\n",n); 
                else printf("%lld\n",n-1);
            }
            else printf("-1\n");
        }
        
    }
    return 0;
}


