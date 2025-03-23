#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=1.01e6;
int n;

signed main(){
    cin>>n;
    for(int i=1,j=1;i*i*i-(i-1)*(i-1)*(i-1)<=n;i++){
        while(i*i*i-(j+1)*(j+1)*(j+1)>=n)++j;
        if(i*i*i-j*j*j==n){
            printf("%lld %lld\n",i,j);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}


