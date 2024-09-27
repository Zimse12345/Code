#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int T,n,k,a[N]; 

signed main(){
    cin>>T;
    while(T--){
        cin>>n>>k;
        int s=0,c=0;
        while(n--){
            int x;
            cin>>x;
            if(x>=k)s+=x;
            else if(s&&x==0)--s,++c;
        }
        printf("%d\n",c);
    }
    return 0;
}


