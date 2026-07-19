#include <bits/stdc++.h>
using namespace std;

void itinerary(unordered_map<string,string>tickets){
    unordered_set<string>s;
    for(pair<string,string>p : tickets){
        s.insert(p.second);
    }
    string start;
    for(pair<string,string>p : tickets){
        if(s.find(p.first) == s.end()){
            start = p.first;
        }
    }
    cout<<start<<"->";
    while(tickets.count(start)){
        cout<<tickets[start]<<"->";
        start = tickets[start];
    }
    cout<<endl;
}
int main(){
    unordered_map<string,string>tickets;
    tickets["chennai"] = "bengaluru";
    tickets["mumbai"] = "delhi";
    tickets["goa"] = "chennai";
    tickets["delhi"] = "goa";
    itinerary(tickets);
    return 0;
}