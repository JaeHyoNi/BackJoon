#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int siz = 1;
int arr2[1000001];
int arr[1000001];
int back[1000001];
int where(int &num){
    int start=0, end = siz , tmp=0;
    while(start < end){
        tmp = (end - start) / 2 + start;
        if(arr[tmp] == num) return tmp;
        else if(arr[tmp] > num) end = tmp;
        else start = tmp+1;   
    }
    if(start == end) tmp = start;
    return tmp;
}

int main(void){
    int N,tmp,it;
    cin>>N;
    cin>>tmp;
    arr[0] = tmp;
    arr2[0] = tmp;
    for(int i=0; i<N-1;i++){
        cin>>tmp;
        arr2[i+1] = tmp;
        printf("--------------------\n");
        it = where(tmp);
        printf("IN : %d  iter : %d\n",tmp,it);
        arr[it] = tmp;
        back[i+1] = it;
        if( it == siz ) {
            siz = siz + 1;
        }
        for(int i=0;i<siz;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        printf("--------------------\n");
    }
    printf("answer = %d\n" , siz);
    cout<<endl;
    vector<int> aans(siz);
    siz = siz - 1;
    for(int i=N-1; i>=0 ; i--){
        if(back[i] == siz){
            printf("i = %d , siz = %d , plus = %d\n",i,siz,arr2[i]);
            aans[siz] = arr2[i];
            siz = siz - 1;
        }
    }
    for(int i=0;i<N;i++){
        cout<<arr2[i]<<" ";
    }cout<<endl;


    for(int i=0;i<N;i++){
        cout<<back[i]<<" ";
    }cout<<endl;
    for(auto K:aans){
        cout<<K<<" ";
    }
    return 0;
}


/*
이건 뭐냐 시발

int main(){
	int N, i, A[1010000], X[1010000]={-2000000000,}, D[1010000], R[1010000], xn=1, f1, f2, j;
	scanf("%d", &N);
	for(i=0;i<N;++i) scanf("%d", A+i);
	for(i=0;i<N;++i){
		f1=0; f2=xn;
		while(f2-f1>1){
			int temp = (f1+f2)/2;
			if(A[X[temp]] < A[i]) f1=temp;
			else f2=temp;
		}
		X[f2] = i;
		D[i] = X[f2-1];
		if(f2==xn) ++xn;
	}
	printf("%d\n", xn-1);
	//for(i=0;i<xn;++i) printf("%d ", X[i]); printf("\n");
	//for(i=0;i<N;++i) printf("%d ", D[i]); printf("\n");
	for(i=X[xn-1],j=0;i!=-2000000000;i=D[i],++j) R[j] = A[i];
	//for(i=0;i<xn;++i) printf("%d ", R[i]); printf("\n");
	//printf("%d ", A[X[1]]);
    while(j--) printf("%d ", R[j]);
	return 0;
}
*/
