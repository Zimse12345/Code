#include <bits/stdc++.h>
using namespace std;

const int N=1.01e6;
int x;

signed main(){
    int s=0;
    cin>>x;
    for(int i=1;i<=9;i++)for(int j=1;j<=9;j++){
        if(i*j!=x)s+=i*j; 
    }
    printf("%d\n",s);
    return 0;
}


