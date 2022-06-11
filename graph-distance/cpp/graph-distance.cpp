#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

bool adjacent( vector< vector<int> >& g, int i, int j ) {
    for (size_t k = 0; k < g[i].size(); k++) {
         // std::cout << g[i].size() <<"AND" << k << '\n';                // test line
         if (g[i][k]==j) return true;
    }
    return false;
}

void distances( vector< vector<int> >& g, int v0, vector<int>& dist) {
     int n = g.size();
     dist.resize(n);

     for (size_t i = 0; i < n; i++) {
         if (i==v0) {
             dist[i]=0;
         } else {
             dist[i]=-1;
         }
     }

     for (size_t d = 0; d < n; d++) {
         for (size_t i = 0; i < n; i++) {
             if (dist[i]==d) {
                 for (size_t z = 0; z < g[i].size(); z++) {
                     if (dist[g[i][z]]==-1) {
                         dist[g[i][z]]=d+1;
                     }
                 }
             }
         }
     }
}

bool connected( vector< vector<int> >& g ) {
     vector<int> dist;
     distances(g,0,dist);
     for (size_t j = 0; j < dist.size(); j++) {
         if (dist[j]==-1) { return false;}
     }
     return true;
}

 bool connectedsimple( vector< vector<int> >& g, bool skipgissimple=false ) {
     if (skipgissimple==false || connected(g)==false) {
         return false;
     } else {
         return true;
     }
 }
int findpath( vector< vector<int> >& g, int v0, int v1, vector<int>& path) {
     int n = g.size();
     path.resize(n);

     std::vector<int> dist;
     distances(g,v0,dist);
     if (dist[v1]==-1) {return 1;}

     int k = dist[v1];
     path.resize(k+1);
     path[k] = v1;
     path[0] = v0;

     for (size_t i = k-1; i > 0; i--) {
         for (size_t j = 0; j < dist.size(); j++) {
             if (dist[j]==i && adjacent(g,j,path[i+1])==true) {
                 // std::cout << i << '\n';
                 path[i]=j;
             }
         }
     }
     return 0;
 }

bool issimple( vector< vector<int> >& g ) {
  int n = g.size();
  for (int i=0; i<n; i++) {
    // test for double edges
    for (int j=0; j<g[i].size(); j++) {
      for (int k=j+1; k<g[i].size(); k++) {
	if (g[i][j] == g[i][k]) return false; // double edge
      }
    }
    // test for loops
    if (adjacent(g,i,i)) return false; // has loop
    // test for directed edges
    for (int j=0; j<n; j++) {
      if (adjacent(g,i,j) && !adjacent(g,j,i)) return false; // directed
    }
  }
  return true;
}
int nedges( vector< vector<int> >& g ) {
  int n = g.size();
  int nedges = 0;
  for (int i=0; i<n; i++) {
    nedges = nedges + g[i].size(); // number of edges incident with vertex i
  }
  if (issimple(g)) {
    return nedges/2; // edges all counted twice
  } else {
    return nedges;
  }
}
void printgraph( vector< vector<int> >& g ) {
  int n = g.size();
  bool simp = issimple(g);
  if (simp) { cout << "Simple "; }
  cout << "Graph";
  if (simp) { cout << " with " << nedges(g) << " edges"; }
  else { cout << " with " << nedges(g) << " directed edges"; }
  cout << ": V = {";
  for (int i=0; i<n-1; i++) { cout << i << ","; }
  cout << (n-1) << "};";
  cout << " E = {";
  bool started = false;
  for (int i=0; i<n; i++) {
    int s = g[i].size();
    for (int j=0; j<s; j++) {
      if (g[i][j]<=i && simp) continue; // don't repeat edges if it is simple
      if (!started) { started=true; } else { cout << ","; }
      cout << "(" << i << "," << g[i][j] << ")";
    }
  }
  cout << "}" << endl;
}
void randomdigraph( vector< vector<int> >& g, int n, double p ) {
  vector<int> empty(0);
  g.resize(n);
  for (int i=0; i<n; i++) {
    g[i] = empty; // initialise list for vertex i
    // make new edges
    for (int j=0; j<n; j++) {
      double q = double(rand())/RAND_MAX; // a random value in 0..1
      if (q<p) {
	g[i].push_back(j);
      }
    }
  }
}
void randomsimplegraph( vector< vector<int> >& g, int n, double p ) {
  vector<int> empty(0);
  g.resize(n);
  for (int i=0; i<n; i++) {
    g[i] = empty; // initialise list for vertex i
    // make new edges
    for (int j=i+1; j<n; j++) {
      double q = double(rand())/RAND_MAX; // a random value in 0..1
      if (q<p) {
	g[i].push_back(j);
      }
    }
    // check for old edges connected to i
    for (int j=0; j<i; j++) {
      // did we already add edge j:i ?
      for (int k=0; k<g[j].size(); k++) {
	if (g[j][k]==i) {
	  // yes we did
	  g[i].push_back(j);
	  break; // break "for (int k"
	}
      }
    }
  }
}

int main() {
  srand(time(NULL)); // initialialise random numbers against the time
  vector< vector<int> > g; // declare a variable for the graph
  randomsimplegraph(g,10,0.5);
  printgraph(g);
  if (adjacent(g,1,2)) {
    cout << "vertex 1 is adjacent to vertex 2" << endl;
  } else {
    cout << "vertex 1 is not adjacent to vertex 2" << endl;
  }

  int i=0, j=2;
  if (adjacent(g,i,j)==true) {
    cout << "vertex " << i << " is adjacent to vertex " << j << endl;
  } else {
    cout << "vertex " << i << " is not adjacent to vertex " << j << endl;
  }

  vector<int> dist;
  distances(g,0,dist); // using 2 as an example vertex here
  for (int i=0; i<dist.size(); i++) {
    cout << "distance from 0 to " << i << " is " << dist[i] << endl;
  }

  if (connected(g)==true) {
    cout << "connected" << endl;
  } else {
    cout << "not connected" << endl;
  }

  std::vector<int> path;
  if (findpath(g,0,4,path)==1) {
    cout << "no path" << endl;
  } else {
      for (size_t i = 0; i < path.size() - 1; i++) {
          // std::cout << i << ' ';
          std::cout << path[i] << " -> ";
      }
    std::cout << path[path.size() - 1] << endl;

  }
  return 0;
}
