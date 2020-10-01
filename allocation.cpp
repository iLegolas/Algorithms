// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3f56
/*
Problem
There are N houses for sale. The i-th house costs Ai dollars to buy. You have a budget of B dollars to spend.

What is the maximum number of houses you can buy?
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int counter = 0;
    while(t--){
        counter++;
        int n,b,i,x,sum=0,c=0;
        cin>>n>>b;
        multiset<int> a;
        for(i=0;i<n;i++){
            cin>>x;
            a.insert(x);
        }
        multiset<int>::iterator it;
        for(it=a.begin();it!=a.end();it++){
            sum += *it;
            if(sum<=b){
                c++;
                continue;
            }
            else
                break;
        }
        cout<<"Case #"<<counter<<": "<<c<<endl;
    }
}
