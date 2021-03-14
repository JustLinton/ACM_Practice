#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <deque>
#include <math.h>
#include <set>
#include <unordered_map>
#include <string.h>
#include <algorithm>
using namespace std;


typedef long long ll;
int dataGroupCnt;
int opCnt;//本组操作数量
string curOp;//当前操作
ll curArg;
ll topped = -1;
deque<ll> windows;
set<ll> windowsSet;
unordered_map<ll, ll> chatsPerWindow;

const char opid[] = "OpId #", col[] = ": ", dot[] = ".";

int main() {
    freopen("/home/linton/Desktop/CSP/a.in", "r", stdin);
    freopen("/home/linton/Desktop/CSP/a.out", "w", stdout);
    // freopen("C:\\Users\\Lenovo\\Desktop\\a.in", "r", stdin);
    // freopen("C:\\Users\\Lenovo\\Desktop\\a.out", "w", stdout);


    cin >> dataGroupCnt;
    while (dataGroupCnt--)
    {
        cin >> opCnt;
        for (int o = 1; o <= opCnt; o++)
        {
            cin >> curOp;

            if (curOp == "Add") {

                scanf("%lld", &curArg);
                if (!windowsSet.count(curArg)) {
                    windowsSet.insert(curArg);
                    windows.push_back(curArg);
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "same likeness", dot);

            }
            else if (curOp == "Close") {

                scanf("%lld", &curArg);
                if (windowsSet.count(curArg)) {
                    if (topped == curArg)topped = -1;

                    windowsSet.erase(curArg);
                    windows.erase(find(windows.begin(), windows.end(), curArg));
                    printf("%s%lld%s%s%lld%s%lld%s\n", opid, o, col, "close ", curArg, " with ", chatsPerWindow[curArg], dot);
                    chatsPerWindow[curArg] = 0;
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "invalid likeness", dot);

            }
            else if (curOp == "Chat") {

                scanf("%lld", &curArg);
                if (topped != -1) {
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                    chatsPerWindow[topped] += curArg;
                }
                else {
                    if (!windows.empty()) {
                        printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                        chatsPerWindow[windows.front()] += curArg;
                    }
                    else printf("%s%lld%s%s%s\n", opid, o, col, "empty", dot);
                }

            }
            else if (curOp == "Rotate") {

                scanf("%lld", &curArg);
                if (curArg > windows.size()||curArg<1)printf("%s%lld%s%s%s\n", opid, o, col, "out of range", dot);
                else {
                    auto ite = windows.begin();
                    ite += curArg - 1;
                    int value = *ite;
                    windows.erase(ite);
                  
                    windows.push_front(value);
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                }

            }
            else if (curOp == "Prior") {

                if (!windows.empty()) {
                    int maxLikeness = *(windowsSet.rbegin());
                    auto ite = find(windows.begin(), windows.end(), maxLikeness);
                    int value = *ite;
                    windows.erase(ite);                   
                    windows.push_front(value);
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "empty", dot);

            }
            else if (curOp == "Choose") {

                scanf("%lld", &curArg);
                if (windowsSet.count(curArg)) {
                    auto ite = find(windows.begin(), windows.end(), curArg);
                    int value = *ite;
                    windows.erase(ite);                               
                    windows.push_front(value);
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "invalid likeness", dot);

            }
            else if (curOp == "Top") {

                scanf("%lld", &curArg);
                if (windowsSet.count(curArg)) {
                    topped = curArg;
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "invalid likeness", dot);
            }
            else if (curOp == "Untop") {

                if (topped != -1) {
                    printf("%s%lld%s%s%s\n", opid, o, col, "success", dot);
                    topped = -1;
                }
                else printf("%s%lld%s%s%s\n", opid, o, col, "no such person", dot);
            }


//  for(auto i= windows.begin();i!=windows.end();i++)cout<<*i<<","<<chatsPerWindow[*i]<<" ";
//         cout<<endl;
        }

        int curUser = 0;

        // for(auto i= windows.begin();i!=windows.end();i++)cout<<*i<<","<<chatsPerWindow[*i]<<" ";
        // cout<<endl;

        if(topped!=-1){
            if (chatsPerWindow[topped])printf("%s%lld%s%s%lld%s%lld%s\n", opid, ++opCnt, col, "Bye ", topped, ": ", chatsPerWindow[topped], dot);
            windows.erase(find(windows.begin(), windows.end(), topped));
        }
        
        while (!windows.empty())
        {
            curUser = windows.front();
            if (chatsPerWindow[curUser]) printf("%s%lld%s%s%lld%s%lld%s\n", opid, ++opCnt, col, "Bye ", curUser, ": ", chatsPerWindow[curUser], dot);
            windows.pop_front();
        }

        topped = -1;
        windowsSet.clear();
        chatsPerWindow.clear();

    }
    return 0;
}






