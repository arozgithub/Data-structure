#include <iostream>
#include<Windows.h>
#include<iterator>
#include<list>
using namespace std;

class Graph {
	int V; // No. of vertices 
	list<int>* adj; // adjacency lists 
	bool* visit; // Bool value used to see if a node is visited or not
public:
	Graph()
	{
		V = 0;
		adj = NULL;
		visit = NULL;
	}
	Graph(int v)
	{
		V = v;
		adj = new list<int>[V];
		visit = new bool[V];
	}
	~Graph()
	{
		delete[]adj;
		delete[]visit;
	}
	void TakeInput(int n, int w)
	{
		adj[n].push_back(w);
	}
	void ExploreFunction(int start)
	{
		cout << start << " ";
		visit[start] = true;
		list<int>::iterator i;
		for (i = adj[start].begin(); i != adj[start].end(); i++)
		{
			if (!visit[*i])
			{
				ExploreFunction(*i);
				visit[start] = false;
			}
			else if (*i == start)
			{
				visit[start] = false;
			}
		}
	}
};

int main()
{
	Graph obj(4);
	obj.TakeInput(0, 1);
	obj.TakeInput(0, 2);
	obj.TakeInput(1, 2);
	obj.TakeInput(2, 0);
	obj.TakeInput(2, 3);
	obj.TakeInput(3, 3);

	cout << "Following is Depth First Traversal (starting from vertex 2) " << endl;
	obj.ExploreFunction(2);

	cout << endl;

	cout << "Following is Depth First Traversal (starting from vertex 1) " << endl;
	obj.ExploreFunction(1);

	return 0;
}