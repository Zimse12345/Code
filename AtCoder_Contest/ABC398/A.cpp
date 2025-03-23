#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int n; 

signed main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        if(i==(n+1)/2||i==(n+2)/2)printf("=");
        else printf("-");
    }
    return 0;
}


