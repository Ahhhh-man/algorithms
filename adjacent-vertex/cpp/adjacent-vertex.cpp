#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

/*
 * returns true when i,j are adjacent in g,
 * i.e. when there is an edge from vertex i to vertex j,
 * i.e. when j is an entry in the vector g[i]
 */
bool adjacent( vector< vector<int> >& g, int i, int j ) {
        for (size_t k = 0; k < g[i].size(); k++) {
            // std::cout << g[i].size() <<"AND" << k << '\n';                // test line
            if (g[i][k]==j) return true;
        }
        return false;
}

/* using "adjacent", determines if the graph g is simple
 * i.e. has no loops, no multiple edges, and has
 * for each edge (i,j) an edge (j,i)
 */
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

/*
 * determines number of edges in g; this is the
 * "correct" number of edges if the graph g is simple
 * or else the total number of directed edges otherwise
 */
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

/*
 * prints the graph g to cout, checking for simplicity and
 * printing g appropriately if it is simple
 */
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

/*
 * sets g to be a random digraph (with no multiple edges) for which
 * (i,j) is an edge with probability p, for all i,j
 */
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

/*
 * sets g to be a simple graph (no loops or directed edges) for which
 * (i,j) is an edge with probability p, for all i<j
 */
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
  return 0;
}