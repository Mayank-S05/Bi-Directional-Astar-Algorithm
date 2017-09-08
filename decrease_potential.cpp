#include "BD_graph.h"
#include<iostream>
using namespace std;
void graph::dec_pot()
{
vector< pair<long,float> > :: iterator it = potentiala.begin();
for(int i=0;i<400;i++)
{
    //cout<<"pot before"<<potentiala[i].second<<endl;
    potentiala[i].second = potentiala[i].second * 0.3;
    //cout<<"pot after"<<potentiala[i].second<<endl;
}

for(int i=0;i<400;i++)
{
    //cout<<"pot before"<<potentialb[i].second<<endl;
    potentialb[i].second = potentialb[i].second * 0.3;
    //cout<<"pot after"<<potentialb[i].second<<endl;
}
/*
for(it;it!=potentiala.end();++it)
{   //cout<<"pot before"<<it->second<<endl;
    it->second = it->second * 1;
    //cout<<"pot after"<<it->second<<endl;
}


vector< pair<long,float> > :: iterator it1 = potentialb.begin();
for(it1;it1!=potentialb.end();++it1)
{   //cout<<"pot before"<<it->second<<endl;
    it->second = it->second * 1;
    //cout<<"pot after"<<it->second<<endl;
}
*/
}
