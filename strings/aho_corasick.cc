#include<iostream>
#include<vector>

using namespace std;
typedef long long int ll;
#define pb push_back
#define fi first
#define se second
#define ld double
const int md = 1e9+7;

const int K = 26;
struct node{
    int next[K],go[K],link = -1,e_link = -1;
    bool leaf = 0;
    char pch;
    int p = -1;
    int id;
    node(int p = -1,char ch = '#'):p(p),pch(ch){
        fill(next,next+K,-1);
        fill(go,go+K,-1);
    }
};
vector<node> t(1);
void add_string(string s,int id){
    int c = 0;
    for(char ch: s){
        int v = ch-'a';
        if(t[c].next[v]==-1){
            t[c].next[v] = t.size();
            t.emplace_back(c,ch);
        }
        c = t[c].next[v];
    }
    t[c].leaf = 1;
    t[c].id = id;
}
int go(int c,char ch);
int get_link(int c){
    if(t[c].link==-1){
        if(c==0 || t[c].p==0)
            t[c].link = 0;
        else
            t[c].link = go(get_link(t[c].p),t[c].pch);
        get_link(t[c].link);
        if(t[t[c].link].leaf)
            t[c].e_link = t[c].link;
        else
            t[c].e_link = t[t[c].link].e_link;
    }
    return t[c].link;
}

int go(int c,char ch){
    int v = ch-'a';
    if(t[c].go[v]==-1){
        if(t[c].next[v]!=-1)
            t[c].go[v] = t[c].next[v];
        else
            t[c].go[v] = (c==0)? 0: go(get_link(c),ch);
    }
    return t[c].go[v];
}

void search(char s[]){
    int n = strlen(s);
    int c = 0;
    for(int i=0;i<n;i++){
        c = go(c,s[i]);
        int cc = c;
        while(cc!=-1){
            if(t[c].leaf)
                cout<<i<<" "<<t[cc].id<<endl; // end position and string id
            cc = t[cc].e_link;
        }
    }
}
signed main() {
    string arr[4] = {"he", "his", "hers", "she"};
    for(int i=0;i<4;i++)
        add_string(arr[i],i);
    for(int i = 1; i < t.size(); i++) //
        get_link(i); //
    char s[] = "ahishers";
    search(s);
    return 0;
}