/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        unordered_map<Node*,Node*> cloned_graph;
        Node* first_node = new Node(node->val,{});
        queue<Node*> q;
        q.push(node);
        cloned_graph[node] = first_node;
        while(!q.empty())
        {
            Node* currentNode = q.front();
            q.pop();
            for(auto adjacent:currentNode->neighbors)
            {
                if(cloned_graph.find(adjacent) == cloned_graph.end())
                {
                    cloned_graph[adjacent] = new Node(adjacent->val, {});
                    q.push(adjacent);
                }
                cloned_graph[currentNode]->neighbors.push_back(cloned_graph[adjacent]);
            }
        }
        return first_node;
    }
};