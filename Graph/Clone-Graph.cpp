// ─────────────────────────────────────────
// Problem : Clone Graph
// Difficulty: Medium
// Topic    : Graph
// Tags     : Hash Table, Depth-First Search, Breadth-First Search, Graph Theory
// Date     : 2026-04-16
// ─────────────────────────────────────────
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        unordered_map<Node*, Node*> visited;

        function<Node*(Node*)> dfs = [&](Node* currentNode) {
            if (visited.find(currentNode) != visited.end())
                return visited[currentNode];

            Node* newNode = new Node(currentNode->val);
            visited[currentNode] = newNode;

            for (auto neighbor : currentNode->neighbors) {
                newNode->neighbors.push_back(dfs(neighbor));
            }

            return newNode;
        };

        return dfs(node);
    }
};