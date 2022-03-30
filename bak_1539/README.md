# [이진 검색 트리](https://www.acmicpc.net/problem/1539)
### 일단 첫인상은 쉬워보인다

***
단순하게 이진트리를 만들어버려서 쭉 arr에 저장해서, 2로 나눌 수 있는 수만큼 +를 해주면 될것같다.

루트노드를 1부터 시작해서 자식노드에 추가해야할 때 마다 *2 혹은 *2+1을 해서 segment tree만드는것처럼 하면 되지 않을까 싶다.

<br/>
근데 트리 배열로 만들려니까 일단 메모리가 터질것같다. 25만은 좀...
그냥 가장 최근의 위치를 저장하며 ans에 바로바로 더해줘야 할 것 같다. 
<br/>
<br/>


```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> arr(530000,-1);
int ans = 0;

void insert(int n){
    int iter = 1,dep = 1;
    //비어있는 노드를 찾을때까지 반복
    while(arr[iter] != -1 ){
        //현재 노드의 숫자가 n보다 작다면
        if(arr[iter] < n){
            //왼쪽 노드로
            iter = iter * 2;
        }
        //그 외 오른쪽 노드로
        else iter = iter*2+1;
        //깊이를 더해줌
        dep++;
    }
    ans+=dep;
    arr[iter] = n;
}

int main(){
    int N,tmp;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        insert(tmp);
    }
    cout<<ans<<endl;
}
```
라는 코드는 대실패했다. 생각해보니까 N=250000이고 한쪽으로만 치우친다면 엄청난 배열이 필요하다. 
`2 ^ 250000` ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ

아....

> 그래서 `vector<값,다음위치>`를 사용해서 노드를 위치로 저장해서 건너뛰는 방법을 생각해 보았다. 
<br/>제발되라좀


```c++
#include <bits/stdc++.h>
using namespace std;
typedef struct {int val;int left;int right;}node;

vector<node> arr(250000);
int ans = 1;
int vector_size = 1;

void insert(int n){
    int iter = 0,dep = 1;
    while(1){
        //왼쪽으로 가야 한다면
        if(arr[iter].val > n){
            printf("left / ");
            if(arr[iter].left == 0){
                arr[vector_size] = {n,0,0};
                arr[iter].left = vector_size++;
                dep++;
                break;
            }
            else{
                iter = arr[iter].left;
                dep++;
                continue;
            }
        }
        //오른쪽으로 가야 한다면
        else{
            printf("right / ");
            if(arr[iter].right == 0){
                arr[vector_size] = {n,0,0};
                arr[iter].right = vector_size++;
                dep++;
                break;
            }
            else{
                iter = arr[iter].right;
                dep++;
                continue;
            }
        }
    }
    ans+=dep;
    printf("%d 추가 dep : %d  / ans : %d\n",n,dep,ans);
}

int main(){
    int N,tmp;
    scanf("%d",&N);
    scanf("%d",&tmp);
    arr[0] = {tmp,0,0};
    for(int i=1;i<N;i++){
        scanf("%d",&tmp);
        insert(tmp);
    }
    cout<<ans<<endl;
}
```
그대로 벡터로 바꿔보았다.

이번엔 시간초과가 난다. 왜지

너무 날먹으로 하려고 했나보다. 대놓고 N^2로 해봤는데 시간초과네

2촌데 너무한거 아님?

생각을 더 해보자.

중간 계산과정을 삭제해야하는듯 하다.

생각해보니 또 한쪽으로 쏠려있는경우에는 2+3+4+5+6+7...이 계속된다

아....


트리의 구조를 보고 계속 생각하다보니 vector<>를 써서 lower를 통해 수를 찾고 양쪽노드 숫자중 큰거+1를 하면 정답이 된다는걸 확인했다.
<br/>
그런데 문제는 vector<insert>연산을 하면 250000 , 249999...이런식으로 가면 그떄마다 N번의 연산으로 또 N^2이다. 
<br/>
그래서 구글검색함 ㅋ

정답중에 [이 글](https://blog.joonas.io/161)에서 map으로 lower_bound를 활용하는걸 확인했다.
<br/>
개쩐다...

map으로도 lower_bound , upper_bound를 활용할 수 있다. 알아두자.


> `answer` 에 long long 안썻다가 틀렸다...<br/>
>이거떔에 시간을 얼마나 날린거야....<br/>
><br/>
>그래도 실험 상당히 많이했다. 내일 추가함


```c++
#include <bits/stdc++.h>
using namespace std;


map<int, int> tree;
long long ans=1;
int main() {
    int n,tmp;
    scanf("%d", &n);
    if(n==0) {
        cout<<"0";
        return 0;
    }
    scanf("%d",&tmp);tree[tmp] = 1;
    for(int i=1;i<n;i++){
        scanf("%d",&tmp);
        auto K = tree.lower_bound(tmp);
        if(K==tree.begin()) {
            tree[tmp] = K->second + 1;
            printf("[%d 추가 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans += tree[tmp];
        }
        else if(K==tree.end()){
            K--;
            tree[tmp] = K->second + 1;
            printf("[%d 추가 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
        else{
            auto J = K;
            J--;
            tree[tmp] = max(K->second+1 , J->second+1);
            printf("[%d 추가 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
    }
    cout<<ans<<endl;
    return 0;
}

```