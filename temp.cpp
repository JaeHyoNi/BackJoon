#include <bits/stdc++.h>
using namespace std;
int main(void)
{
    vector<int> arr = {10,20,20,30,20};
    cout<<max_element(arr.begin(),arr.end())-arr.begin();    
}