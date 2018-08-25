//Implementation for Dijkstra's SSSP(Single source shortest path) algorithm
//This is an optimized algorithm running in O(E*log(V))
// Shreyans Sheth's very nice implementation, taken from here: 
//https://www.quora.com/What-is-the-most-simple-efficient-C%2B%2B-code-for-Dijkstras-shortest-path-algorithm/answer/Shreyans-Sheth-1?srid=imWH
 
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;
#define INF INT_MAX //Infinity
 
const int sz=10000001; //Maximum possible number of vertices. Preallocating space for DataStructures accordingly
vector<pair<int,int> > a[sz]; //Adjacency list
int dis[sz]; //Stores shortest distance
bool vis[sz]={0}; //Determines whether the node has been visited or not
int arrs[1000][1000]; //full of the conditions and what not
int dx[4] = {0,0,1,-1}; 
int dy[4] = {1,-1,0,0}; 

ofstream fout("dream.out"); 
ifstream fin("dream.in"); 

void Dijkstra(int source, int n) //Algorithm for SSSP
{
    for(int i=0;i<sz;i++) //Set initial distances to Infinity
        dis[i]=INF;
    //Custom Comparator for Determining priority for priority queue (shortest edge comes first)
    class prioritize{public: bool operator ()(pair<int, int>&p1 ,pair<int, int>&p2){return p1.second>p2.second;}};
    priority_queue<pair<int,int> ,vector<pair<int,int> >, prioritize> pq; //Priority queue to store vertex,weight pairs
    pq.push(make_pair(source,dis[source]=0)); //Pushing the source with distance from itself as 0
    while(!pq.empty())
    {
        pair<int, int> curr=pq.top(); //Current vertex. The shortest distance for this has been found
        pq.pop();
        int cv=curr.first,cw=curr.second; //'cw' the final shortest distance for this vertex
        if(vis[cv]) //If the vertex is already visited, no point in exploring adjacent vertices
            continue;
        vis[cv]=true;
        for(int i=0;i<a[cv].size();i++) //Iterating through all adjacent vertices
            if(!vis[a[cv][i].first] && a[cv][i].second+cw<dis[a[cv][i].first]) //If this node is not visited and the current parent node distance+distance from there to this node is shorted than the initial distace set to this node, update it
                pq.push(make_pair(a[cv][i].first,(dis[a[cv][i].first]=a[cv][i].second+cw))); //Set the new distance and add to priority queue
    }
}


int main() //Driver Function for Dijkstra SSSP
{
    int N,M,x,y,w;//Rows by Column, N by M 
    cin>>N>>M;
    for (int i = 0; i<N; i++){
    	for (int j = 0; j< M ; j++){
    		cin >> arrs[i][j]; 
    	}
    }
    int V = N*M; // number of vertices

    int vert; 
    for (int i = 0; i<N; i++){
    	for (int j = 0; j<M; j++){
    		vert = M*i+j; //node value
    		for (int k= 0; k<4; k++){// direction of neighbor
    			
    		}
    	}
    }
    a[x].push_back(make_pair(y,w));
    a[y].push_back(make_pair(x,w));
    //cout<<"Enter source for Dijkstra's SSSP algorithm\n";
    int source;
    cin>>source;
    Dijkstra(source,V);//SSSP from source (Also passing number of vertices as parameter)

    return 0;
}