#include <iostream>
#include <vector>
using namespace std;

//大整数存放方式：把每一位存到一个数组里去
//数组下标为0的存个位（存储低位优先），依次往后推

const int N = 1e6+10;//防止存在边界问题

//c=A+B
vector<int> add(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t=0;
    for(int i=0;i<A.size()||i<B.size();i++){
        if(i<A.size()) t+=A[i];
        if(i<B.size()) t+=B[i];
        C.push_back(t%10);
        t/=10;
    }
    if(t) C.push_back(1);
    return C;
}



int main() {
    string a,b;
    vector<int> A,B;
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
        A.push_back(a[i]-'0');
    for(int i=b.size()-1;i>=0;i--)
        B.push_back(b[i]-'0');
         
}