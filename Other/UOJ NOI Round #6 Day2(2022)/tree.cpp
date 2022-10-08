#include"tree.h"
#include<iostream>
#include<cassert>
#include<cstring>
#include<algorithm>
#include<vector>

unsigned inx[11][3000],iny[11][3000];

std::vector<std::pair<int, int>> solve(int n){
	std::vector<std::vector<int>> x[11],y[11];
	std::vector<std::pair<int, int>> ans;
	std::vector<int> q;
	q.resize(n-1);
	for(int i=0;i<=10;i++){
		for(int j=0;j<n-1;j++){
			q[j]=(j&(1<<i))?1:0;
		}
		x[i]=query(q);
		for(unsigned u=0;u<x[i].size();u++){
			for(unsigned v=0;v<x[i][u].size();v++)inx[i][x[i][u][v]]=u;
		}
		for(int j=0;j<n-1;j++){
			q[j]=(j&(1<<i))?0:1;
		}
		y[i]=query(q);
		for(unsigned u=0;u<y[i].size();u++){
			for(unsigned v=0;v<y[i][u].size();v++)iny[i][y[i][u][v]]=u;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int tag=1;
			for(int k=0;k<=10;k++){
				if(inx[k][i]==inx[k][j]||iny[k][i]==iny[k][j])continue;
				else tag=0;
			}
			if(tag)ans.push_back(std::make_pair(i,j)); 
		}
	}
	return ans;
}
