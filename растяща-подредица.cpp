#include<iostream>
using namespace std;
int n, a[128], dp[128], p[128], maxi;

void parent(int i){ //връща елементите от редицата
    if(p[i]==i){
        cout<<a[i]<<" ";
        return ;
    }cout<<a[i]<<" ";
    parent(p[i]);

}

int main ()
{
    cin>>n;
    for(int i=0; i<n; i++){cin>>a[i]; p[i]=i;}
    dp[0]=1;
    for(int i=1; i<n; i++){
        maxi=0;
        for(int j=0; j<i; j++){
            if(a[j]<a[i] && dp[j]>maxi){//ако намерим по-малък елемент по-рано в редицата, за който имаме по-дълга растяща редица
                    maxi=dp[j];
                    p[i] = j;   //добавяме позиция j към опашката
            }
        }
        dp[i]=maxi+1;
    }
    int sol=0, sol_position= 1;
    for(int i=0; i<n; i++){
        if(dp[i]>sol) {         //от най-дългата растяща подредица
            sol = dp[i];
            sol_position = i;   //взимаме индекса на последния елемент от нея
        }

    }
    for(int i=0; i<n; i++)cout<<p[i]<<" "; cout<<endl;
    cout<<sol<<endl;
    parent(sol_position);       //печатаме подредицата
    cout<<endl;

    return 0;
}
