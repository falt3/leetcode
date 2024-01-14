#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <map>

using namespace std;

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


class Solution {
public:
    map<int, Node*> nodes_view;
    Node* cloneGraph2(Node* node) {
        if (node == nullptr) return nullptr;

        if (auto it = nodes_view.find(node->val); it == nodes_view.end()) {
            Node* node0 = new Node(node->val);
            nodes_view[node->val] = node0;
            
            for_each(node->neighbors.begin(), node->neighbors.end(), 
                [&](auto el) {
                    // Node* new_node = new Node(el->val);
                    auto new_node = cloneGraph2(el);
                    node0->neighbors.push_back(new_node);
                    // cout << "node: " << node0->val << "  neighbors: " << new_node->val << endl;
                }
            );
            return node0;
        }
        else 
            return it->second;
    }
};


int main() {
    Node node[4];
    node[0].val = 1;
    node[0].neighbors.push_back(&node[1]);
    node[0].neighbors.push_back(&node[3]);
    
    node[1].val = 2;
    node[1].neighbors.push_back(&node[0]);
    node[1].neighbors.push_back(&node[2]);

    node[2].val = 3;
    node[2].neighbors.push_back(&node[1]);
    node[2].neighbors.push_back(&node[3]);

    node[3].val = 4;
    node[3].neighbors.push_back(&node[0]);
    node[3].neighbors.push_back(&node[2]);

    // Node* n = Solution::cloneGraph(node);
    Solution sol;
    Node* n = sol.cloneGraph2(node);
    cout << endl;
    cout << n->val << " " << n->neighbors.size() << endl;

    set<int> nodes_view;
    stack<Node*> queue_nodes;
    queue_nodes.push(n);

    while (!queue_nodes.empty()) {
        Node* node1 = queue_nodes.top();
        queue_nodes.pop();
        if (auto fl = nodes_view.find(node1->val); fl == nodes_view.end()) {
            nodes_view.insert(node1->val);
            
            cout << "node: " << node1->val << "  neighbors:";
            
            for (auto el: node1->neighbors) {
                queue_nodes.push(el);
                cout << el->val << " ";
            }
            cout << endl;
        }        
    }

}