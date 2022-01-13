#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;
const int k = 5; // parameter for cluster size
const int MAXN = 2000 + 5; // max node number
const int INF = 0x3f3f3f3f;
struct node
{
    /*
    Do not save subordinate information in node
    */
    int nid;
    int delay;
    int bandwidth; // original bandwidth
    int bw; // actual bandwidth
    bool reachable; // true iff there exists a path in the multicast tree from X to a layer-0 peer.
    bool addable; // true iff there exists a pathin the multicast tree from X to a layer-0 peer whose cluster¡¯s size is in [k, 3k - 1]
    int nparent; // the node get content from (is linked by)
    set <int> children; // the node provide content for (link to)
    int degree; // alive children number
    int nhead; // cluster head index
    bool deleted;
    int layer; // highest layer
    int clusterid; // highest cluster

    void init()
    {
        nid = 0;
        delay = 0; // temporarily use random number
        bandwidth = rand() % 1000 + 1; // temporarily use random number
        reachable = false;
        addable = false;
        nparent = 0;
        children.clear();
        degree = 0;
        nhead = 0;
        deleted = false;
        layer = 0;
        clusterid = 0;
    }
}a[MAXN];
struct cluster
{
    int cid;
    int layer;
    int chead; // head node id
    set <int> subordinate; // do not contain head
    int csize; // always setsize + 1 ?
    bool deleted;
    int cparent; // cluster parent
}c[MAXN];
int G[MAXN][MAXN];
int N, NODECOUNT, C, CLUSTERCOUNT, H, op;
void init();

void printlog();

void join(int x);

void split(int x); // split cluster x

void scan();

void reset();

void maintain(int x);

void departure(int x);