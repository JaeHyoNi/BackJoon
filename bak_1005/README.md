# 1005 [ACM CRAFT](https://www.acmicpc.net/problem/1005) gold
***

## 사용한 알고리즘

> [위상정렬](https://yoongrammer.tistory.com/86)

>사용이유
<br/>

* 우선순위가 있다.
* 앞 내용이 끝나지 않으면 뒷 내용이 나올 수 없다.

```c++
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}


int main(){
    int T,N,K,from,to,target,now;
    int planet_time[1001] = {0,};   //건설시간 저장하는 배열
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d %d",&N,&K);
        int planet[1001] = {0,};        //연결된 간선개수 세는 배열
        vector<int> road[1001];
        vector<int> answer(N+1,0);
        int visit[1001] = {0,};
        for(int i=1;i<=N;i++) scanf("%d",&planet_time[i]);
        for(int i=0;i<K;i++){
            scanf("%d %d",&from,&to);
            planet[to]  ++;
            road[from].push_back(to);
        }
        scanf("%d",&target);
        queue<int> wait;
        for(int i=1;i<=N;i++){
            if(planet[i] == 0){
                wait.push(i); 
                answer[i] = planet_time[i]; 
                visit[i] = 1;
            }
        }
        vector<int> temp;
        while(!wait.empty()){
            now = wait.front();
            temp.push_back(now);
            wait.pop();
            for(auto K:road[now]){
                planet[K]--;
                answer[K] = max( answer[K] , planet_time[K] + answer[now] );
            }
            for(int i=1;i<=N;i++){
                if(visit[i] == 0 && planet[i] == 0){
                    wait.push(i);
                    visit[i] = 1;
                }
            }
        }
        textcolor(2);
        for(auto K: temp){cout<<K<<" ";}cout<<endl;
        textcolor(4);
        printf("%d\n",answer[target]);
        textcolor(7);
    }
}
```
























***

## 틀림서사




## BFS로 보임

>길을 선택하는것이 아니고 뻗어나가는 것이므로 큐에 넣고 전부 탐색하면 될것같다.
<br/>중복되는 경로는 최솟값으로 맞춰주기 위해 배열을 사용하면 될것같다.



***

<br/>

### 틀림

벡터를 잘못 선언해서 메모리 초과가 나 보다보니까 이 코드 시간초과가 날것같다.
위상정렬로 바꿧다.

내 코드는 BFS를 사용해서 새로운 길을 탐색할 수 있을 때마다 큐에 넣고 돌리는 방식을 썻는데, 방문이 중복되서 되는경우를 세주지 못해서 계속 도는 문제가 발생한다.


```C++
//첫 코드
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void textcolor(int color_number)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),color_number);
}


int main(){
    int T,N,K,from,to,target;
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        int planet[1001]={0,} , time_use[1001] ={0,};
        vector<int> road[1000],find_first;
        scanf("%d %d ",&N,&K);
        find_first.resize(N+1,0);
        for(int j=1;j<N+1;j++){scanf("%d",&planet[j]);}
        time_use[1] = planet[1];
        for(int j=0;j<K;j++){
            scanf("%d %d",&from,&to);
            road[from].push_back(to);
            find_first[to]  --;
            find_first[from] ++;
        }
        int first =0;
        first = max_element(find_first.begin(),find_first.end()) - find_first.begin();
        queue<int> arr;
        int pre = first;
        time_use[first] = planet[first];
        for(auto K:road[pre]) arr.push(first);
        while(!arr.empty()){
            for(auto K:road[arr.front()]){
                time_use[K] = max( time_use[arr.front()] + planet[K] , time_use[K] );
                for(auto K:road[K]){arr.push(K);}
                arr.push(K);
            }
            arr.pop();
        }
        time_use[to] = max( time_use[to] , time_use[from] + planet[to]);
        scanf("%d",&target);
        textcolor(4);
        if(time_use[target] == 0) cout<<planet[target]<<endl;
        else cout<<time_use[target]<<endl;
        textcolor(7);
    }
}
```





