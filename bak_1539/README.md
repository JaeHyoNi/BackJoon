# [���� �˻� Ʈ��](https://www.acmicpc.net/problem/1539)
### �ϴ� ù�λ��� �������δ�

***
�ܼ��ϰ� ����Ʈ���� ���������� �� arr�� �����ؼ�, 2�� ���� �� �ִ� ����ŭ +�� ���ָ� �ɰͰ���.

��Ʈ��带 1���� �����ؼ� �ڽĳ�忡 �߰��ؾ��� �� ���� *2 Ȥ�� *2+1�� �ؼ� segment tree����°�ó�� �ϸ� ���� ������ �ʹ�.

<br/>
�ٵ� Ʈ�� �迭�� ������ϱ� �ϴ� �޸𸮰� �����Ͱ���. 25���� ��...
�׳� ���� �ֱ��� ��ġ�� �����ϸ� ans�� �ٷιٷ� ������� �� �� ����. 
<br/>
<br/>


```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> arr(530000,-1);
int ans = 0;

void insert(int n){
    int iter = 1,dep = 1;
    //����ִ� ��带 ã�������� �ݺ�
    while(arr[iter] != -1 ){
        //���� ����� ���ڰ� n���� �۴ٸ�
        if(arr[iter] < n){
            //���� ����
            iter = iter * 2;
        }
        //�� �� ������ ����
        else iter = iter*2+1;
        //���̸� ������
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
��� �ڵ�� ������ߴ�. �����غ��ϱ� N=250000�̰� �������θ� ġ��ģ�ٸ� ��û�� �迭�� �ʿ��ϴ�. 
`2 ^ 250000` ����������������������������������������

��....

> �׷��� `vector<��,������ġ>`�� ����ؼ� ��带 ��ġ�� �����ؼ� �ǳʶٴ� ����� ������ ���Ҵ�. 
<br/>���ߵǶ���


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
        //�������� ���� �Ѵٸ�
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
        //���������� ���� �Ѵٸ�
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
    printf("%d �߰� dep : %d  / ans : %d\n",n,dep,ans);
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
�״�� ���ͷ� �ٲ㺸�Ҵ�.

�̹��� �ð��ʰ��� ����. ����

�ʹ� �������� �Ϸ��� �߳�����. ����� N^2�� �غôµ� �ð��ʰ���

2�̵� �ʹ��Ѱ� �ƴ�?

������ �� �غ���.

�߰� �������� �����ؾ��ϴµ� �ϴ�.

�����غ��� �� �������� ����ִ°�쿡�� 2+3+4+5+6+7...�� ��ӵȴ�

��....


Ʈ���� ������ ���� ��� �����ϴٺ��� vector<>�� �Ἥ lower�� ���� ���� ã�� ���ʳ�� ������ ū��+1�� �ϸ� ������ �ȴٴ°� Ȯ���ߴ�.
<br/>
�׷��� ������ vector<insert>������ �ϸ� 250000 , 249999...�̷������� ���� �׋����� N���� �������� �� N^2�̴�. 
<br/>
�׷��� ���۰˻��� ��

�����߿� [�� ��](https://blog.joonas.io/161)���� map���� lower_bound�� Ȱ���ϴ°� Ȯ���ߴ�.
<br/>
��¾��...

map���ε� lower_bound , upper_bound�� Ȱ���� �� �ִ�. �˾Ƶ���.


> `answer` �� long long �ț��ٰ� Ʋ�ȴ�...<br/>
>�̰ŋ��� �ð��� �󸶳� �����ž�....<br/>
><br/>
>�׷��� ���� ����� �����ߴ�. ���� �߰���


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
            printf("[%d �߰� , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans += tree[tmp];
        }
        else if(K==tree.end()){
            K--;
            tree[tmp] = K->second + 1;
            printf("[%d �߰� , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
        else{
            auto J = K;
            J--;
            tree[tmp] = max(K->second+1 , J->second+1);
            printf("[%d �߰� , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
    }
    cout<<ans<<endl;
    return 0;
}

```