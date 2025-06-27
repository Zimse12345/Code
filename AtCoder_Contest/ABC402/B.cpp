#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int q[N],n,l=1,r;

signed main(){
    cin>>n;
    while(n--){
        int x=0;
        cin>>x;
        if(x==1){
            ++r;
            cin>>q[r];
        }
        else printf("%d\n",q[l]),++l;
    }
    return 0;
}


