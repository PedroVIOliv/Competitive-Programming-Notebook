
vector<int> adj[MAXN];
int visited[MAXN];

void dfs(int p) {
    memset(visited, 0, sizeof visited);
    stack<int> st;
    st.push(p);
    visited[p] = 1;

    while (!st.empty()) {
        int curr = st.top();
        st.pop();
        if (visited[curr]==1)continue;
        visited[curr]=1;
        // process current node here

        for (auto i : adj[curr]) {
            st.push(i);
        }

    }
}