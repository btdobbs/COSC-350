#include "Graph.h"
#include <iostream>
#include <random>

using namespace std;

int main() {
    Graph *graph;
    Element e1;
    Vertex *v1 = graph->insert_vertex(e1);
    Element e2;
    Vertex *v2 = graph->insert_vertex(e2);
    Element e3;
    Edge *e = graph->insert_edge(v1, v2, e3);
    return 0;
}
