#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, m, br, timee; //има вградена функция time, което може да причини конфликт, за предпочитане е да се ползва локална променлива за time или променлива с друго име (в случая timee)
vector<vector<int> >a;
vector<bool>used;
vector<int>t, f;

void dfs(int v, int p){                 //връх и родител
    used[v]=1;                          //маркираме върха като обходен
    f[v]=timee;                          //задаваме стойност на масива f (времето за влизане във върха)
    t[v]=timee;                          //задаваме стойност на масива t
    timee++;                             //увеличаваме брояча за време за вход във върха
    for(int i=0; i<a[v].size(); i++){   //обхождаме графа
        int h=a[v][i];                  //задаваме на h номера на наследника
        if(h==p)continue;               //ако родителя и наследика съвпадат, продължаваме със следващата операция
        if(used[h]==1){                 //ако наследникът е обходен
            f[v]=min(f[v], t[h]);       //минимизираме f[v]
        }
        else {                          //ако не е
            dfs(h, v);                  //викаме дфс
            f[v]=min(f[v], f[h]);       //минимизираме f[v]
            if(f[h]>t[v]) br++;         //IS_BRIDGE (v, h)
        }
    }
}

int main ()
{
    cin>>n>>m;
    a.resize(n+1);
    used.resize(n+1);
    t.resize(n+1);
    f.resize(n+1);
    int x, y;
    for(int i=0; i<m; i++){
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1, -1);
    cout<<br<<endl;


    return 0;
}
