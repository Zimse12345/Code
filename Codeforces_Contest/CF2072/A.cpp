#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,p; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k>>p;
        if(k<0)k=-k;
        if(n*p<k)printf("-1\n");
        else printf("%d\n",(k+p-1)/p);
    }
    return 0;
}


