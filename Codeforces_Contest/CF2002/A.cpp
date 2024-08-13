#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,m,k; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>m>>k;
        printf("%d\n",min(n,k)*min(m,k)); 
    }
    return 0;
}


