#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;

bool isCharLower(const char * c){
    return *c>='a'&&*c<='z';
}

bool isCharUpper(const char * c){
    return *c>='A'&&*c<='Z';
}

bool isCharNumber(const char * c){
    return *c>='0'&&*c<='9';
}

int checkCharType(const char * c){
    if(isCharLower(c))return 0;
    if(isCharUpper(c))return 1;
    if(isCharNumber(c))return 2;
    return 3;
}

string passwd;
int strength;
char curChar;
int lastCharT=-1,curCharT=-1;

int main(){
    //freopen("/home/dell/src/csp/a.in","r",stdin);
    //freopen("/home/dell/src/csp/a.out","w",stdout);

    cin>>passwd;
    if(passwd.length()<6){
        cout<<0<<endl;
        return 0;
    }

    for(int i=0;i<=passwd.length()-1;i++){
        curChar=passwd[i];
        curCharT=checkCharType(&curChar);
        if(lastCharT!=curCharT)strength++;
        lastCharT=curCharT;
    }

    cout<<strength<<endl;
    return 0;
}
