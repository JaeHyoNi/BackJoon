# [戚遭 伊事 闘軒](https://www.acmicpc.net/problem/1539)
### 析舘 湛昔雌精 習趨左昔陥

***
舘授馬惟 戚遭闘軒研 幻級嬢獄形辞 貸 arr拭 煽舌背辞, 2稽 蟹喚 呪 赤澗 呪幻鏑 +研 背爽檎 吃依旭陥.

欠闘葛球研 1採斗 獣拙背辞 切縦葛球拭 蓄亜背醤拝 凶 原陥 *2 箸精 *2+1聖 背辞 segment tree幻球澗依坦軍 馬檎 鞠走 省聖猿 粛陥.

<br/>
悦汽 闘軒 壕伸稽 幻級形艦猿 析舘 五乞軒亜 斗霜依旭陥. 25幻精 岨...
益撹 亜舌 置悦税 是帖研 煽舌馬悟 ans拭 郊稽郊稽 希背操醤 拝 依 旭陥. 
<br/>
<br/>


```c++
#include <bits/stdc++.h>
using namespace std;
vector<int> arr(530000,-1);
int ans = 0;

void insert(int n){
    int iter = 1,dep = 1;
    //搾嬢赤澗 葛球研 達聖凶猿走 鋼差
    while(arr[iter] != -1 ){
        //薄仙 葛球税 収切亜 n左陥 拙陥檎
        if(arr[iter] < n){
            //図楕 葛球稽
            iter = iter * 2;
        }
        //益 須 神献楕 葛球稽
        else iter = iter*2+1;
        //燕戚研 希背捜
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
虞澗 坪球澗 企叔鳶梅陥. 持唖背左艦猿 N=250000戚壱 廃楕生稽幻 帖酔庁陥檎 畳短貝 壕伸戚 琶推馬陥. 
`2 ^ 250000` せせせせせせせせせせせせせせせせせせせせ

焼....

> 益掘辞 `vector<葵,陥製是帖>`研 紫遂背辞 葛球研 是帖稽 煽舌背辞 闇格禽澗 号狛聖 持唖背 左紹陥. 
<br/>薦降鞠虞岨


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
        //図楕生稽 亜醤 廃陥檎
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
        //神献楕生稽 亜醤 廃陥檎
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
    printf("%d 蓄亜 dep : %d  / ans : %d\n",n,dep,ans);
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
益企稽 困斗稽 郊蚊左紹陥.

戚腰殖 獣娃段引亜 貝陥. 訊走

格巷 劾股生稽 馬形壱 梅蟹左陥. 企兜壱 N^2稽 背挫澗汽 獣娃段引革

2談汽 格巷廃暗 焼還?

持唖聖 希 背左切.

掻娃 域至引舛聖 肢薦背醤馬澗牛 馬陥.

持唖背左艦 暁 廃楕生稽 薯形赤澗井酔拭澗 2+3+4+5+6+7...戚 域紗吉陥

焼....


闘軒税 姥繕研 左壱 域紗 持唖馬陥左艦 vector<>研 潤辞 lower研 搭背 呪研 達壱 丞楕葛球 収切掻 笛暗+1研 馬檎 舛岩戚 吉陥澗杏 溌昔梅陥.
<br/>
益訓汽 庚薦澗 vector<insert>尻至聖 馬檎 250000 , 249999...戚訓縦生稽 亜檎 益��原陥 N腰税 尻至生稽 暁 N^2戚陥. 
<br/>
益掘辞 姥越伊事敗 せ

舛岩掻拭 [戚 越](https://blog.joonas.io/161)拭辞 map生稽 lower_bound研 醗遂馬澗杏 溌昔梅陥.
<br/>
鯵他陥...

map生稽亀 lower_bound , upper_bound研 醗遂拝 呪 赤陥. 硝焼砧切.


> `answer` 拭 long long 照�Т抂� 堂携陥...<br/>
>戚暗��拭 獣娃聖 杖原蟹 劾鍵暗醤....<br/>
><br/>
>益掘亀 叔蝿 雌雁備 弦戚梅陥. 鎧析 蓄亜敗


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
            printf("[%d 蓄亜 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans += tree[tmp];
        }
        else if(K==tree.end()){
            K--;
            tree[tmp] = K->second + 1;
            printf("[%d 蓄亜 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
        else{
            auto J = K;
            J--;
            tree[tmp] = max(K->second+1 , J->second+1);
            printf("[%d 蓄亜 , tree[%d] = %d]\n ",tmp,tmp,tree[tmp]);
            ans+= tree[tmp];
        }
    }
    cout<<ans<<endl;
    return 0;
}

```