int s[N], v[N];
int memo[N][N];

// O(n*size) KNAPSACK 0/1
int knapsack01(int index, int size) {
	if (index == 0) return 0;

	int &ans = memo[index][size];

	if (ans != -1) return ans;
	ans = 0;
	// include
	if (s[index] <= size) // if its O/N, change knapsack(index, size-s[index])
		ans = v[index] + knapsack(index - 1, size - s[index]);
	// exclude
	ans = max(ans, knapsack(index - 1, size));

	return ans;
}