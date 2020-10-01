// https://codingcompetitions.withgoogle.com/codejamio/round/000000000019ff03/00000000001b5e88

#include <iostream>
#include <string>

using namespace std;

int main(){
    int t,c=0;
    cin>>t;
    while(t--){
        c++;
        string str;
        int I=0;
        int i=0;
        int O=0;
        int o=0;
        int count=0;
        cin>>str;
        int j = str.length()-1;
        do{
            char ch = str.at(j);
            switch (ch)
            {
            case 'I':
                if(O>0){
                    O--;
                    count++;
                }
                else
                    o--;
                break;
            case 'i':
                if(o>0)
                    o--;
                else
                    O--;
                break;
            case 'O':
                O++;
                break;
            case 'o':
                o++;
                break;
            default:
                break;
            }
        }while(j--);
        cout<<"Case #"<<c<<": "<<count<<endl;
    }
}
