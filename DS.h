#define DSARRAY_H
#include <iostream>
#include <map>
#include <vector>
using namespace std;
template <typename T> class DisjoinSetArray {
private:
  T *parent;
  int *rank;
  int count;
  vector<T> data;

public:
  DisjoinSetArray(vector<T> data) {
    this->data = data;
    this->parent = new T[data.size()];
    this->rank = new int[data.size()];
    this->count = data.size();
    MakeSet();
  }

  ~DisjoinSetArray() {
    delete[] parent;
    delete[] rank;
  }
 
  void MakeSet() {
    for (int x = 0; x < count; x++) {
      parent[x] = x;
      rank[x] = 0;
    }
  }
  T Find(int x) { 
    if (x != parent[x]) {
      parent[x] = Find(parent[x]); 
    }
    return parent[x];
  }
 
  void Union(int x, int y) {
    int xRoot = Find(x);
    int yRoot = Find(y);
    cout << "Uniendo ... " << xRoot << " , " << yRoot << endl;
    if (xRoot == yRoot) {
      return;
    }
    if (rank[xRoot] < rank[yRoot])
      parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
      parent[yRoot] = xRoot;
    else {
      parent[yRoot] = xRoot;
      ++rank[xRoot];
    }
  }

  bool isConnected(int x, int y) { return Find(x) == Find(y); }
  int size() { return count; }
  int sets() {
    int numSets = 0;
    for (int i = 0; i < count; i++) {
      if (parent[i] == i) {
        numSets++;
      }
    }
    return numSets;
  }

int size(int x) {
    int xRoot = Find(x);
    int setSize = 0;
    for (int i = 0; i < count; i++) {
      if (Find(i) == xRoot) {
        setSize++;
      }
    }
    return setSize;
  }
  vector<T> getElementsSet(int x) {
    int xRoot = Find(x);
    vector<T> elementsSet;
    for (int i = 0; i < count; i++) {
      if (Find(i) == xRoot) {
        elementsSet.emplace_back(data[i]);
      }
    }
    return elementsSet;
  }
};
