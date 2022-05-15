#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[8002] = {0,},N,MAX=-8000 , MIN = 5000 , mean=0,mean_value;
    double sum=0;
    bool yes = true;
    vector<int> num;
    cin>>N;num.resize(N);
    for(int i=0;i<N;i++){
        scanf("%d",&num[i]);
        arr[num[i]+4000] += 1;
        sum += num[i];
        MIN = MIN < num[i] ? MIN : num[i];
        MAX = MAX > num[i] ? MAX : num[i];
        mean = mean < arr[num[i]+4000] ? arr[num[i]+4000] : mean;
    }
    sort(num.begin(),num.end());
    for(int i=0;i<MAX + 4001;i++){
        if(arr[i] == mean){
            if(yes){yes = false;mean_value = i;}
            else {mean_value = i;break;
            }
        }
    }
    cout<<(int)round(sum/N)<<endl;
    cout<<num[N/2]<<endl;
    cout<<mean_value-4000<<endl;
    cout<<MAX-MIN<<endl;
    return 0;
}