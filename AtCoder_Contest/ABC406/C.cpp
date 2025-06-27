#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,a[N],ans;

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2,x=0,y=0,z=0;i<=n;i++){
        if(a[i]>a[i-1]){
            z+=y;
            y=0;
            x+=1;
        }
        else{
            z=0;
            y+=x;
            x=0;
        }
        ans+=z;
    }
    printf("%lld\n",ans);
    return 0;
}


