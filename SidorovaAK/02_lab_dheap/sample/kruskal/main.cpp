#include <iostream>
#include <vector>
#include <time.h>

#include "exceptions.h"
#include "kruskal.h"
#include "graph.h"

using namespace std;

void Test_ClassExample()
{
    cout << endl << "CLASS EXAMPLE" << endl;

    float weights[36] = { -1, 8, -1, -1, 3, 2,
                          8, -1, 10, 1, 0, 2,
                         -1, 10, -1, 5, 2, 9,
                         -1, 1, 5, -1, 4, -1,
                          3, 0, 2, 4, -1, -1,
                          2, 2, 9, -1, -1, -1 };

    Graph graph(weights, 6);
    cout << graph;

    vector<vector<Edge> > newGraph;
    cout << "Kruskal's Algorithm is loading..." << endl;
    Kruskal::Algorithm(graph, newGraph);

    if (newGraph.size() == 0)
    {
        cout << "Graph don't have edges." << endl;
        return;
    }

    for (int i = 0; i < newGraph.size(); i++)
    {
        cout << endl << "Connection " << i << ": " << endl;

        for (int j = 0; j < newGraph[i].size(); j++)
            cout << newGraph[i][j] << endl;
    }

    newGraph.clear();
};

void Test_RandomGraph()
{
    cout << endl << "RANDOM GRAPH" << endl;

    int size = 5;
    Graph graph(size);
    graph.GenerateCommonGraph();
    cout << graph;

    vector<vector<Edge> > newGraph;
    cout << "Kruskal's Algorithm is loading..." << endl;
    Kruskal::Algorithm(graph, newGraph);

    if (newGraph.size() == 0)
    {
        cout << "Graph don't have edges." << endl;
        return;
    }

    for (int i = 0; i < newGraph.size(); i++)
    {
        cout << endl << "Connection " << i << ": " << endl;

        for (int j = 0; j < newGraph[i].size(); j++)
            cout << newGraph[i][j] << endl;
    }

    newGraph.clear();
};

void Test_InputGraph()
{
    cout << endl << "INPUT GRAPH" << endl;

    Graph graph;
    cin >> graph;
    cout << graph;

    vector<vector<Edge> > newGraph;
    cout << "Kruskal's Algorithm is loading..." << endl;
    Kruskal::Algorithm(graph, newGraph);

    if (newGraph.size() == 0)
    {
        cout << "Graph don't have edges." << endl;
        return;
    }

    for (int i = 0; i < newGraph.size(); i++)
    {
        cout << endl << "Connection " << i << ": " << endl;

        for (int j = 0; j < newGraph[i].size(); j++)
            cout << newGraph[i][j] << endl;
    }

    newGraph.clear();
};
//-------------------------------------------------------------

void main()
{
    srand((unsigned int)time(0));

    cout << "##### TEST KRUSKAL'S ALGORITHMS #####" << endl;

    int choice = 0;

    cout << "Auto mode - 0, Input mode - 1. Your choice - ";
    cin >> choice;

    switch (choice)
    {
    case 0:
    {
        try
        {
            Test_ClassExample();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        try
        {
            Test_RandomGraph();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }
        
        break;
    }
    case 1:
        try
        {
            Test_InputGraph();
        }
        catch (const Exception & ex)
        {
            cout << "[ERROR] " << ex.what() << endl << endl;
        }

        break;
    default:
        cout << "Wrong choice!";
    }
}