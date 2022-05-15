#include <bits/stdc++.h>
using namespace std;

int main(){         
    int A[3],n[3],t[3],MAX[3],MIN[3],N; scanf("%d",&N);
    scanf("%d %d %d",&n[0],&n[1],&n[2]);
    MAX[0] = n[0] , MAX[1] = n[1] ,MAX[2] = n[2];
    MIN[0] = n[0] , MIN[1] = n[1] ,MIN[2] = n[2];
    
    for(int i=1;i<N;i++){
        scanf("%d %d %d",&A[0],&A[1],&A[2]);
        t[0] = A[0] + max(MAX[0],MAX[1]);
        t[1] = A[1] + max(MAX[0],max(MAX[1],MAX[2]));
        t[2] = A[2] + max(MAX[1],MAX[2]);
        MAX[0]=t[0],MAX[1]=t[1],MAX[2]=t[2];
        
        t[0] = A[0] + min(MIN[0],MIN[1]);
        t[1] = A[1] + min(MIN[0],min(MIN[1],MIN[2]));
        t[2] = A[2] + min(MIN[1],MIN[2]);
        MIN[0]=t[0],MIN[1]=t[1],MIN[2]=t[2];
    }
    cout<<max(MAX[0],max(MAX[1],MAX[2]))<<" "<<min(MIN[0],min(MIN[1],MIN[2]));
    return 0;
}