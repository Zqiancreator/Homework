int dfs(int n, int u, int *present, int *future, int **dp, int *original_profit, int *discounted_profit, int *original_cost, int *discounted_cost, int *child_count, int **children, curBudget)
{
    int max_cost = original_cost[u];
    int max_profit = 0;

    for (int j = 1; j <= n; j++) {
        dp[u][j] = -1;
    }

    dp[u][0] = 0;

    for (int j = 0; j <= n; j++) {
        if (dp[u][j] == -1)
            continue;
        for (int k = 0; k < child_count[u]; k++) {
            int v = children[u][k];
            for (int jj = 0; j + jj <= n; jj++) {
                if (dp[v][jj] != -1) {
                    if (dp[u][j + jj] < dp[u][j] + dp[v][jj]) {
                        dp[u][j + jj] = dp[u][j] + dp[v][jj];
                    }
                }
            }
        }
    }

    for (int j = original_cost[u]; j <= n; j++) {
        if (dp[u][j - original_cost[u]] != -1) {
            int current = dp[u][j - original_cost[u]] + original_profit[u];
            for (int k = 0; k < child_count[u]; k++) {
                int v = children[u][k];
                for (int jj = 0; j + jj <= n; jj++) {
                    if (dp[v][jj] != -1) {
                        if (dp[u][j + jj] < current + dp[v][jj]) {
                            dp[u][j + jj] = current + dp[v][jj];
                        }
                    }
                }
            }
        }
    }

    for (int j = discounted_cost[u]; j <= n; j++) {
        if (dp[u][j - discounted_cost[u]] != -1) {
            int current = dp[u][j - discounted_cost[u]] + discounted_profit[u];
            for (int k = 0; k < child_count[u]; k++) {
                int v = children[u][k];
                for (int jj = 0; j + jj <= n; jj++) {
                    if (dp[v][jj] != -1) {
                        if (dp[u][j + jj] < current + dp[v][jj]) {
                            dp[u][j + jj] = current + dp[v][jj];
                        }
                    }
                }
            }
        }
    }

    max_profit = 0;
    for (int j = 0; j <= n; j++) {
        if (dp[u][j] > max_profit) {
            max_profit = dp[u][j];
        }
    }

    return max_profit;
}
int maxProfit(int n, int *present, int presentSize, int *future, int futureSize, int **hierarchy,
              int hierarchySize, int *hierarchyColSize, int budget)
{
    int original_cost[n + 1];
    int discounted_cost[n + 1];
    int original_profit[n + 1];
    int discounted_profit[n + 1];
    for (int i = 1; i <= n; i++) {
        original_cost[i] = present[i - 1];
        discounted_cost[i] = floor(present[i - 1] / 2);
        original_profit[i] = future[i - 1] - present[i - 1];
        discounted_profit[i] = future[i - 1] - discounted_cost[i];
    }

    // init children and child_count
    int **children = malloc(sizeof(int *) * (n + 1));
    if (children == NULL) {
        goto ERROR_F;
    }
    for (int i = 0; i <= n; i++) {
        children[i] = malloc(sizeof(int) * (n + 1));
        if (children[i] == NULL) {
            goto ERROR_F;
        }
        memset(children[i], 0, (n + 1) * sizeof(int));
    }
    int *child_count = malloc(sizeof(int) * (n + 1));
    if (child_count == NULL) {
        goto ERROR_F;
    }
    memset(child_count, 0, (n + 1) * sizeof(int));

    for (int i = 0; i < hierarchySize; i++) {
        for (int j = 0; j < hierarchyColSize[i] - 1; j++) {
            int u = hierarchy[i][j];
            int v = hierarchy[i][j + 1];
            children[u][child_count[u]++] = v;
        }
    }

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    if (dp == NULL) {
        goto ERROR_F;
    }
    for (int i = 0; i <= n; i++) {
        dp[i] = (int *)malloc((n + 1) * sizeof(int));
        if (dp[i] == NULL) {
            goto ERROR_F;
        }
        memset(dp[i], 0, (n + 1) * sizeof(int));
    }

    int result = dfs(n, 1, present, future, dp, original_profit, discounted_profit, original_cost, discounted_cost, child_count, children, budget);

    free(child_count);
    for (int i = 0; i <= n; i++) {
        free(children[i]);
    }
    free(children);
    for (int i = 0; i <= n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
ERROR_F:
    free(child_count);
    if (children != NULL) {
        for (int i = 0; i <= n; i++) {
            free(children[i]);
        }
    }
    free(children);
    if (dp != NULL) {
        for (int i = 0; i <= n; i++) {
            free(dp[i]);
        }
    }
    free(dp);
    return -1;
}