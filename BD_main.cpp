#include <bits/stdc++.h>
#include "BD_graph.h"
#include "graph_methods.cpp"
#include "BD_a_star.cpp"
#include "decrease_potential.cpp"
//#include "dijkstra_priorityq.cpp"
//#include "BD_dijkstra.cpp"
using namespace std;

int main()
{
    graph g,h;

    int a[21][21],c =0;
    for(int i=0;i<21;i++)
       {
           for(int j=0;j<21;j++)
        {

            a[i][j]=c;
            c++;

        }
    }

     for(int i=0;i<20;i++)
        for(int j=0;j<20;j++)
    {
            g.addEdge(a[i][j],a[i][j+1],1);
            g.addEdge(a[i][j],a[i+1][j],1);
            g.addEdge(a[i][j],a[i+1][j+1],0.8020);
    }

    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
        {
            if(i==12 && j ==14)
            g.potentiala.push_back(make_pair(266,0));

           float x = sqrt( pow(12-i,2) + pow(14-j,2) );
          // float x = abs(12-i) + abs(14-j);
           pair<long,float> temp = make_pair(a[i][j] , x);
           g.potentiala.push_back(temp);
            //cout<<"pot bw " <<i<<" "<<j<<" "<<a[i][j]<<"is "<<x<<endl;

        }


    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
        {
           float x = sqrt( pow(i-0,2) + pow(j-0,2) );
           //float x = abs(i-0) + abs(j-0);
           pair<long,float> temp = make_pair(a[i][j] , x);
           g.potentialb.push_back(temp);
            //cout<<"pot bw " <<i<<" "<<j<<" "<<a[i][j]<<"is "<<x<<endl;
        }

        /*for(int i=0;i<400;i++)
        {
            cout<<"\n i is "<<i<<" value is "<<g.potentialb[i].second;
        }
        */


    int i,j,k,l;
    long s=0,d =266;

    g.BD_a_star(s,d);

   cout<<"\ncloseda list after is :";
   for(int i=0;i<20;i++)
      {
        cout<<endl;//<<"line "<<i<<"  ";
    for(int j=0;j<20;j++)
        {
        //if(i<=20 && j<=20)
        if(a[i][j] == s || a[i][j]==d)
            cout<<" $";
        else if(g.closeda[ a[i][j] ] == 1)
        cout<<" 1";
        else if(g.closeda[ a[i][j] ] == 2)
        cout<<" x";
        else
        cout<<" 0";
        }

      }

cout<<"\nclosedb list after is :";
   for(int i=0;i<20;i++)
      {
        cout<<endl;//<<"line "<<i<<"  ";
    for(int j=0;j<20;j++)
        {
        //if(i<=20 && j<=20)
        if(a[i][j] == s || a[i][j]==d)
            cout<<" $";
        else if(g.closedb[ a[i][j] ] == 1)
        cout<<" 1";
        else if(g.closedb[ a[i][j] ] == 2)
        cout<<" x";
        else
        cout<<" 0";
        }

      }

    g.dec_pot();
    g.BD_a_star(s,d);


   cout<<"\ncloseda list after is :";
   for(int i=0;i<20;i++)
      {
        cout<<endl;//<<"line "<<i<<"  ";
    for(int j=0;j<20;j++)
        {
        //if(i<=20 && j<=20)
        if(a[i][j] == s || a[i][j]==d)
            cout<<" $";
        else if(g.closeda[ a[i][j] ] == 1)
        cout<<" 1";
        else if(g.closeda[ a[i][j] ] == 2)
        cout<<" x";
        else
        cout<<" 0";
        }

      }

cout<<"\nclosedb list after is :";
   for(int i=0;i<20;i++)
      {
        cout<<endl;//<<"line "<<i<<"  ";
    for(int j=0;j<20;j++)
        {
        //if(i<=20 && j<=20)
        if(a[i][j] == s || a[i][j]==d)
            cout<<" $";
        else if(g.closedb[ a[i][j] ] == 1)
        cout<<" 1";
        else if(g.closedb[ a[i][j] ] == 2)
        cout<<" x";
        else
        cout<<" 0";
        }

      }

    //cout<<endl;
   // h.a_star(d,s);
    //cout<<endl;
    //g.dec_pot();
    //g.a_star(s,d);
}

/*        cout<<"closed list after is :";
   for(int i=0;i<20;i++)
      {
        cout<<endl;//<<"line "<<i<<"  ";
    for(int j=0;j<20;j++)
        {
        //if(i<=20 && j<=20)
        if(a[i][j] == s || a[i][j]==d)
            cout<<" $";
        else if(g.closed[ a[i][j] ] == 1)
        cout<<" 1";
        else if(g.closed[ a[i][j] ] == 2)
        cout<<" x";
        else
        cout<<" 0";
        }

      }
      */

    //cout<<endl;
   // h.dec_pot();
    //cout<<endl;
   // g.a_star(s,d);
   // cout<<endl;
   // h.a_star(d,s);

    //cout << g.V << endl;



