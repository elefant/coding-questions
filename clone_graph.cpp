/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
map<UndirectedGraphNode*, UndirectedGraphNode*> toCloned;
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if (!node) {
        return nullptr;
    }
    auto newNode = new UndirectedGraphNode(node->label);
    toCloned[node] = newNode;
    for (int i = 0; i < node->neighbors.size(); i++) {
        newNode->neighbors.resize(node->neighbors.size());
        auto nb = node->neighbors[i];
        if (!nb) {
            newNode->neighbors[i] = nullptr;
            continue;
        }
        auto clonedItr = toCloned.find(nb);
        if (clonedItr != toCloned.end()) {
            newNode->neighbors[i] = clonedItr->second;
        } else {
            newNode->neighbors[i] = cloneGraph(nb);
        }
    }
    return newNode;
}
