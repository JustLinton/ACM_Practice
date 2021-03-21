#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

map<int,unordered_set<int> > noddles;
map<int,unordered_set<int> > visitors;
vector<int> ti,si;

unordered_set<int> flavor;
unordered_set<int> curVF,curNF;

int n,m,k;
int curTypeCnt,tmp,tmpSerail=0;

int curSi,curTi;

bool noddle_ok=false;

int main(){
    //freopen("/home/dell/src/csp/a.in","r",stdin);
   // freopen("/home/dell/src/csp/a.out","w",stdout);

    cin>>n>>m>>k;
    for(int k=1;k<=n;k++){
        cin>>tmp;
        ti.push_back(tmp);
    }
    for(int k=0;k<=n-1;k++)
    {
        flavor.clear();
        cin>>curTypeCnt;
        for(int i=0;i<=curTypeCnt-1;i++){
            cin>>tmp;
            flavor.insert(tmp);
        }

        noddles[ti[k]]=flavor;
        tmpSerail=0;
    }
    
    for(int k=1;k<=m;k++){
        cin>>tmp;
        si.push_back(tmp);
    }
    for(int k=0;k<=m-1;k++)
    {
        flavor.clear();
        cin>>curTypeCnt;
        for(int i=0;i<=curTypeCnt-1;i++){
            cin>>tmp;
            flavor.insert(tmp);
        }
        visitors[si[k]]=flavor;
        tmpSerail=0;
    }

    for(auto iteV = visitors.begin();iteV!=visitors.end();iteV++){

        curVF.clear();
        curSi=iteV->first;
        curVF=iteV->second;
        noddle_ok=false;    
        for(auto iteN=noddles.begin();iteN!=noddles.end();iteN++){  
    
            curTi=iteN->first;
            if(curTi<=curSi){
                
                curNF.clear();
                curNF=iteN->second;

                for(int i=0;i<=2;i++){
                   if(curVF.count(i)){
                       if(!curNF.count(i))break;
                   }
                   if(i==2)noddle_ok=true;
                }
            }      

            if(noddle_ok){
                noddles.erase(curTi);
                cout<<curSi-curTi<<endl;
                break;
            }
        }

        if(!noddle_ok){
            cout<<"Angry"<<endl;
        }

    }

}
