class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;

        if (root == NULL)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            vector<int> level;
            while (s--) {
                Node* f = q.front();
                q.pop();
                level.push_back(f->val);

                //push children in queue
                for (auto n : f->children)
                    q.push(n);
            }
            ans.push_back(level);
        }

        return ans;
    }
};