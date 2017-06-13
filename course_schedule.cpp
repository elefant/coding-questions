class Solution {
public:
    /**
     * @param numCourses a total of n courses
     * @param prerequisites a list of prerequisite pairs
     * @return the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // Write your code here
        vector<int> inDegree(numCourses);
        set<pair<int, int>> pre(prerequisites.begin(), prerequisites.end());

        // Init graph
        unordered_map<int, set<int>> graph;
        for (int i = 0; i < numCourses; i++) {
            graph[i] = set<int>();
        }

        // Init inDegree and graph
        for (auto p: pre) {
            inDegree[p.first]++;
            graph[p.second].insert(p.first);
        }

        vector<int> sol;
        while (1) {
            vector<int> toRemove;
            for (auto itr: graph) {
                auto course = itr.first;
                if (inDegree[course] == 0) {
                    sol.push_back(course);
                    toRemove.push_back(course);
                }
            }
            if (toRemove.empty()) {
                break;
            }
            for (auto r: toRemove) {
                for (auto c: graph[r]) {
                    inDegree[c]--;
                }
                graph.erase(r);
            }
        }

        if (sol.size() == numCourses) {
            return sol;
        }

        return {};
    }
};