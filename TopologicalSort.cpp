/* topological sort of DAG
          3 --> 6
          ^ --> 1 --> 2
          |
          0 ---> 4 -- > 5
   o/p : 1 5 4 2 3    
*/   

#define vi vector<int>
#define vvi vector<vector<int> >

vi dfs(int& index, bool *visited, vi& visitedNodes, vvi& graph)
{
    if (visited[index]) return visitedNodes;
    visited[index] = true;
    for (int i  = 0; i < graph[index].size(); i++)
    {
        if ( !visited[graph[index][i]] )
            dfs(graph[index][i], visited, visitedNodes, graph);
    }
    visitedNodes.push_back(index--);
    return visitedNodes;
}
vi topologicalSort(vvi& graph)
{
    int N = graph.size();
    bool visited[N];
    memset(visited, false, sizeof(visited));
    
    vi ordering(N);
    int index = N - 1;
    for (int i = 0; i < N; i++)
    {
        if (visited[i] == false)
        {
            vi visitedNodes;
            dfs(i, visited, visitedNodes, graph);
            for (int j = 0; j < visitedNodes.size(); j++)
            {
                ordering[index--] = visitedNodes[j];
            }
        }
    }
    return ordering;
}
int main() 
{
    vvi graph = {
                    { 3, 4},
                    { 2 },
                    {},
                    { 1, 6 },
                    { 5 },
                    {},
                    {}
                };
    
    vi ordering  = topologicalSort(graph);
    for (int& x : ordering)
        cout << x << "\t";
}
