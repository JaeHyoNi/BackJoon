#include <bits/stdc++.h>
using namespace std;
int inorder[100001] , postorder[100001];

void preorder(int ins,int ine, int pos,int poe){
    printf("%d ",postorder[poe]);
    if(ins == ine){return;}
    int tmp=ins,offset=0;
    while(inorder[tmp] != postorder[poe]) {tmp++; offset++;}
    if(tmp != ins) preorder(ins ,tmp-1 ,pos,pos+offset-1);
    if(tmp != ine) preorder(tmp+1, ine ,pos+offset,poe-1);    
    return;
}
int main(){
    int N,left,right,root; scanf("%d",&N);
    for(int i=0;i<N;i++){scanf("%d",&inorder[i]);}
    for(int i=0;i<N;i++){scanf("%d",&postorder[i]);}
    preorder(0,N-1,0,N-1);
}

// 9
// 8 4 9 2 5 1 6 3 7
// 8 9 4 5 2 6 7 3 1