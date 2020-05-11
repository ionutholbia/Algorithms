#include <iostream>
#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

class Node {
public:
    std::unordered_map<int, int> neighboursDistance_;
    std::vector<int> neighboursId_;
    int id_;

    Node(int id) : id_(id) {}
    
    void addNeighbour(int id, int distance) {
        neighboursId_.push_back(id);
        neighboursDistance_[id] = distance;
    };
};

std::vector<Node*> createGraph(int n, const vector<vector<int>>& edges) {
    std::vector<Node*> graph(n, nullptr);

    int count  = 1;
    for(int i = 0; i < graph.size(); i++) {
        graph[i] = new Node(count);
        count++;
    }

    for(auto& iter : edges) {
        graph[iter[0] - 1]->addNeighbour(iter[1], iter[2]);
        graph[iter[1] - 1]->addNeighbour(iter[0], iter[2]);
    }

    return graph;
}

// Complete the shortestReach function below.
vector<int> shortestReach(int n, vector<vector<int>> edges, int s) {
    auto graph = createGraph(n, edges);
    std::unordered_map<int, bool> visited;
    std::vector<int> unvisited(n);
    
    std::iota (std::begin(unvisited), std::end(unvisited), 1);
    
    if(graph[s - 1]->neighboursId_.size() == 0) return vector<int>(n - 1, -1);

    auto currentNode = s;

    while(unvisited.size() != 0) {
        visited[currentNode] = true;
        unvisited.erase(std::find(unvisited.begin(), unvisited.end(), currentNode));
        
        cout<<"Visiting: "<<currentNode;

        auto nextNode = currentNode;
        auto min = -1;
        for(auto id : graph[currentNode - 1]->neighboursId_) {
            if((min == -1 || min > graph[currentNode - 1]->neighboursDistance_[id])
                 && visited.find(id) == visited.end()) {
                min = graph[currentNode - 1]->neighboursDistance_[id];
                nextNode = id;
            }
        }

        if(nextNode == currentNode && unvisited.size() != 0) {
            nextNode = unvisited[0];
        };
        currentNode = nextNode;
    }

    return {};
}


int main(void) {
    shortestReach(4, {{1,2,24}, {1,4,20}, {3,1,3}, {4,3,12}}, 1);
}