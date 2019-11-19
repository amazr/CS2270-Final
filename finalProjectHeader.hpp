#ifndef GRAPH_H
#define GRAPH_H
#include<vector>
#include<iostream>
using namespace std;

struct node;
struct adjNode{
  node *n;
};

struct node{
  node(char newChar, node *par){
    this->searchCount = 0;
    this->c = newChar;
    this->parent = par;
    this->terminal = false;
    this->adj[0] = NULL;
  }
  char c;
  vector<adjNode> adj;
  node* parent;
  int searchCount;
  bool terminal;
};

class trie{
  public:
    void insert();
    void deleter();
    string bestGuess(string input);
  private:
    node *root;
};

#endif
