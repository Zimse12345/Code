#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n,q,a[N],t;

signed main(){
    cin>>n>>q;
    for(int i=0;i<n;i++)a[i]=i+1;
    while(q--){
        int ty=0,p=0,x=0;
        cin>>ty>>p;
        if(ty==1){
            --p;
            cin>>x;
            a[(p+t)%n]=x;
        }
        if(ty==2){
            --p; 
            printf("%lld\n",a[(p+t)%n]);
        }
        if(ty==3){
            t=(t+p)%n;
        }
    }
    return 0;
}


