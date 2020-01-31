#include<bits/stdc++.h>
using namespace std;

const  int  MAX_V = ...; 
int  V, E; 
vector  < int > g[MAX_V]; 
int  dfn[MAX_V], low[MAX_V], tot, bccid[MAX_V], bcc_cnt; 
bool  cut[MAX_V]; 
stack  < int > S; 

void  dfs ( int  x,  int  fa) { 
    int  child =  0 ; 
    dfn[x] = low[x] = ++tot; 
    S.push(x); 
    for ( int  i =  0 ; i < sz(g[x]); i++){ 
        int  v = g[x][i]; 
        if (!dfn[v]){ 
            dfs(v, x); 
            child++; 
            low[x] = min(low[x], low[v]); 
            if (low[v] >= dfn[x]){ 
                cut[x] =  true ; 
                while ( 1 ){ 
                    int  u = S.top(); S.pop(); 
                    bccid[u] = bcc_cnt; 
                    if (u == v)  break ; 
                } 
                bccid[x] = bcc_cnt; 
                bcc_cnt++; 
            } 
        } 
        else  if (dfn[v] < dfn[x] && v != fa){  // 反向邊 
            low[x] = min(low[x], dfn[v]); 
        } 
    } 
    // 樹根 
    if (fa ==  -1  && child <  2 ) cut[x] =  false ; 
} 

void  bcc_tarjan () { 
    bcc_cnt =  0 ; 
    for ( int  i =  0 ; i < V; i++){ 
        if (!dfn[i]) dfs(i,  -1 ); 
    } 
} 
