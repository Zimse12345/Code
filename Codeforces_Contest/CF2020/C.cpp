#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int T,b,c,d;

signed main(){
    cin>>T;
    while(T--){
        cin>>b>>c>>d;
        int a=0;
        for(int i=0,t=1;i<=60;i++,t*=2){
            int x=(b&t)?1:0,y=(c&t)?1:0,z=(d&t)?1:0;
            if(x!=z){
                if(1-y!=z){
                    a=-1;
                    break;
                }
                a+=t;
            }
        }
        printf("%lld\n",a);
    }
    return 0;
}


