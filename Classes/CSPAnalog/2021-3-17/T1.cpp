#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int cntr;
char curLight;
string lightsStr;
unordered_multiset<int> lights;
set<int> ans;

int main(){
    //freopen("/home/dell/src/csp/a.in","r",stdin);
    //freopen("/home/dell/src/csp/a.out","w",stdout);
    cin>>cntr>>lightsStr;
    for(int i=0;i<=cntr-1;i++){
        curLight=lightsStr[i];
        switch (curLight)
        {
        case 'R':
            lights.insert(0);
            break;

        case 'G':
            lights.insert(1);
            break;

         case 'B':
            lights.insert(2);
            break;  
        
        default:
            break;
        }
    }

    for(int i=0;i<=2;i++)ans.insert(lights.count(i));

    cout<<*ans.begin()<<endl;
}
