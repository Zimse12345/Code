#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n;

signed main(){
    cin>>n;
    if(n&1){
        for(int i=1;i<=n;i++)printf("%d ",i);
    }
    else{
        for(int i=1;i<=n;i+=2)printf("%d %d ",i+1,i);
    }
    return 0;
}


