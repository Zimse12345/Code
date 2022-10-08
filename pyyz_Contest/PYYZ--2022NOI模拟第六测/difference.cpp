#include "difference.h"
#include <vector>

vector<int> S, ret;
int A[1024]; 

inline int dis(int x,int y){
	return x<y?y-x:x-y;
}

void find(int n, int M1, int M2) {
	A[0]=qry1(0),A[1]=qry1(1);
	for(int i=2;i<n;i++){
		S.resize(0),S.push_back(0),S.push_back(i);
		int d1=qry2(S)[0];
		S.resize(0),S.push_back(1),S.push_back(i);
		int d2=qry2(S)[0];
		if(dis(A[0]-d1,A[1])==d2)A[i]=A[0]-d1;
		if(dis(A[0]+d1,A[1])==d2)A[i]=A[0]+d1;
	}
	for(int i=0;i<n;i++)ret.push_back(A[i]);
	answer(ret);
	return;
}
