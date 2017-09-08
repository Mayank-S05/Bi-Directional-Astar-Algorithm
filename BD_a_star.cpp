#include "BD_graph.h"
//#include "BD_expand.cpp"
/*
class graph{
int v;
list < pair<int , int> > *edg;
public:
graph(int x);
void addEdge(int x,int y ,int w);
void dijkstra(int s,int d);
};

graph::graph(int a)
{
    this->v = a;
    edg = new list< pair<int,int> > [a];
}

void graph::addEdge(int x, int y, int w)
{
    edg[x].push_back(make_pair(y,w));
    edg[y].push_back(make_pair(x,w));
}
*/
 priority_queue< pair<float,long> , vector< pair<float,long> > , greater< pair<float,long> > > qa;
     priority_queue< pair<float,long> , vector< pair<float,long> > , greater< pair<float,long> > > qb;

    vector<long> preva;
    vector<long> prevb;

    vector<float> dista;
    vector<float> distb;



void expand_fwd(std::vector<float>& closeda , std::vector< pair<long,float> >& potentiala,unordered_map<long, adjList>& myvec,priority_queue< pair<float,long> , vector< pair<float,long> > , greater< pair<float,long> > >& qa,vector<float>& dista)
    {
        long x = qa.top().second;

        //cout<<"\ntopa is : "<<x;
        qa.pop();
        closeda[x] = 1;
        unordered_map<long, adjList>::iterator itr = myvec.find(x);
        auto itr1 = (*itr).second.begin();



            for(itr1; itr1!=(*itr).second.end() ; ++itr1)
        {

            long y = (*itr1).first;
            float w = (*itr1).second;

            if(closeda[y]==1 || closeda[y]==2)
            continue;

            if(dista[x] + w < dista[y] )
            {

                dista[y] = dista[x] + w;
                preva[y] = x;
                //cout<<"pot: "<<potential[y].second<<endl;
               // cout<<"relaxing : "<<y<<" "<<(dist[y] + potential[y].second)<<endl;
                qa.push(make_pair( (dista[y] + potentiala[y].second) , y));
               // cout<<"\n pushinga : "<<y<<endl;
            }

        }
    }

    void expand_bwd(std::vector<float>& closedb , std::vector< pair<long,float> >& potentialb,unordered_map<long, adjList>& myvec,priority_queue< pair<float,long> , vector< pair<float,long> > , greater< pair<float,long> > >& qb,vector<float>& distb)
    {
        long x = qb.top().second;
       // cout<<"\ntopb is : "<<x;
        qb.pop();
        closedb[x] = 1;
        unordered_map<long, adjList>::iterator itr = myvec.find(x);
        auto itr1 = (*itr).second.begin();



            for(itr1; itr1!=(*itr).second.end() ; ++itr1)
        {

            long y = (*itr1).first;
            float w = (*itr1).second;

            if(x<y)
            continue;

            if(closedb[y]==1 || closedb[y]==2)
            continue;

            if(distb[x] + w < distb[y] )
            {

                distb[y] = distb[x] + w;
                prevb[y] = x;
                //cout<<"pot: "<<potential[y].second<<endl;
               // cout<<"relaxing : "<<y<<" "<<distb[y]<<" "<<potentialb[y].second<<" "<<(distb[y] + potentialb[y].second)<<endl;
               //cout<<"\n pushingb : "<<y<<endl;
                qb.push(make_pair( (distb[y] + potentialb[y].second) , y));

            }

        }
    }

    int tracepath(vector<long>& preva , vector<long>& prevb , long d)
    {

        cout<<"\nShortest Path is : \n";

    int u =d;
    while(preva[d]!=-1)
    {
            cout<<d<<" ";
            d = preva[d];
    }
cout<<endl;
    while(prevb[u]!=-1)
    {
            cout<<u<<" ";
            u = prevb[u];
    }
    return 0;
    }


int graph::BD_a_star(long s , long d)
{
    srand(time(NULL));

    vector<long> :: iterator it;

    closeda.reserve(V);
    closedb.reserve(V);
    preva.reserve(V);
    prevb.reserve(V);
    dista.reserve(V);
    distb.reserve(V);
   for(int z =0; z<V; ++z)
    {
        closeda[z]=0;
        closedb[z]=0;
        preva[z]=-1;
        prevb[z]=-1;
        dista[z]=99999;
        distb[z]=99999;
    }

    /* for(auto i = potential.begin(); i != potential.end() ; ++i)
    {
        (*i).second = 0;
    }
    */


     for(int i=101;i<100;i++)
    {
        int x = rand()%400+1;
        if(x!=d && x!=s)
        closeda[x] = 2;
        closedb[x] = 2;
        //cout<<"x is : "<<x<<endl;
    }

    qa.push(make_pair(0,s));
    qb.push(make_pair(0,d));
    dista[s]=0;
    distb[d]=0;


    while(!qa.empty() && !qb.empty())
    {
        int s=0;
        for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
        {
           if( closeda[ s ] == 1 && closedb[ s ] == 1)
           {
               d=s;
               cout<<"d is: "<<d<<" s is : "<<s;
               tracepath(preva , prevb , d);
               return 0;
           }
           s++;
        }

        //cout<<"\n size a is : "<<qa.size()<<" size B is : "<<qb.size();
        if(qa.size()  <= qb.size())
            expand_fwd(closeda , potentiala,myvec,qa,dista);
        else
            expand_bwd(closedb , potentialb,myvec,qb,distb);
    }



}

/*int main()
{
    int v=9;
    graph g(v);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    int s=0,d=4;
    g.dijkstra(s,5);

return 0;
}
*/

