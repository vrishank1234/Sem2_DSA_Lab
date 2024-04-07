#include "iostream"
using namespace std;

class Graph {
private:
    int **adjMatrix;
    int numVertices;

public:
    Graph(int numVertices) {
        this->numVertices=numVertices;
        adjMatrix=new int*[numVertices];

        for(int i=0;i<numVertices;i++) {
            adjMatrix[i]=new int[numVertices];

            for(int j=0;j<numVertices;j++) {
                adjMatrix[i][j]=0;
            }
        }
    } //vertices for graph created
    void addEdge(int i, int j) {
        adjMatrix[i][j]=1;
        adjMatrix[j][i]=1;
    } //edges added

    void DFS(int startVertex, bool visited[]) {
        visited[startVertex]=true;
        cout<<startVertex<<" ";

        for(int i=0;i< numVertices;i++) {
            if(adjMatrix[startVertex][i] && !visited[i]) {
                DFS(i, visited); //recursive calls for inscreased depth till depth isnt 0
            }
        }
    }//depth first search

    void BFS(int startVertex) {
        bool *visited=new bool[numVertices];
        for(int i=0;i<numVertices;i++)
            visited[i]=false;

        int queue[numVertices];
        int front=-1, rear=-1;

        visited[startVertex]=true;
        queue[++rear]=startVertex;

        while(front!=rear) {
            int currentVertex=queue[++front];
            cout<<currentVertex<<" ";

            for(int i=0;i<numVertices;i++) {
                if(adjMatrix[currentVertex][i] && !visited[i]) {
                    visited[i]=true;
                    queue[++rear]=i;
                }
            }
        }

        delete[] visited;
    }//breadth first search
};

int main() {
    int choice, vertices, edges, v1, v2;
    cout<<"Enter the number of vertices in the graph: ";
    cin>>vertices;

    Graph graph(vertices);

    do {
        cout<<"\nGraph Traversal Techniques:\n";
        cout<<"1. Add Edge\n";
        cout<<"2. Depth First Search (DFS)\n";
        cout <<"3. Breadth First Search (BFS)\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice) {
            case 1:
                cout<<"Enter edge (vertex1 vertex2): ";
                cin>>v1>>v2;
                graph.addEdge(v1, v2);
                break;
            case 2:
                cout<<"DFS Traversal: ";
                bool *visitedDFS;
                visitedDFS=new bool[vertices];
                for(int i=0;i<vertices;i++) {
                    visitedDFS[i]=false;
                }
                for(int i=0;i<vertices;i++) {
                    if(!visitedDFS[i])
                        graph.DFS(i, visitedDFS);
                }
                delete[] visitedDFS;
                cout << endl;
                break;
            case 3:
                cout<<"BFS Traversal: ";
                cout<<"Enter starting vertex for BFS: ";
                cin>>v1;
                graph.BFS(v1);
                cout<<endl;
                break;
            case 4:
                cout<<"Exiting program.\n";
                break;
            default:
                cout<<"Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}