/*
 * @lc app=leetcode.cn id=826 lang=c
 * @lcpr version=30204
 *
 * [826] 安排工作以达到最大收益
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
typedef struct JOB_STRU {
    int difficulty;
    int profit;
} JOB;

int CompareJobs(const void *a, const void *b)
{
    return ((JOB *)a)->difficulty - ((JOB *)b)->difficulty;
}

int CompareWorkers(const void *a, const void *b)
{
    return *((int *)a) - *((int *)b);
}

int MaxProfitAssignment(int *difficulty, int difficultySize, int *profit, int profitSize, int *worker, int workerSize)
{
    JOB *job = malloc(sizeof(JOB) * difficultySize);
    if (job == NULL) {
        return 0;
    }
    // sort the difficulty in ascending order
    for (int i = 0; i < difficultySize; i++) {
        job[i].difficulty = difficulty[i];
        job[i].profit = profit[i];
    }
    qsort(job, difficultySize, sizeof(JOB), CompareJobs);

    // sort the worker in ascending order
    qsort(worker, workerSize, sizeof(int), CompareWorkers);
    int res = 0, curMax = 0;
    for (int curWorker = 0, curProfit = 0; curWorker < workerSize; curWorker++) {
        // for each worker, get the biggest profit of all jobs he can do
        while (curProfit < profitSize && worker[curWorker] >= job[curProfit].difficulty) {
            curMax = curMax > job[curProfit].profit ? curMax : job[curProfit].profit;
            curProfit++;
        }
        res += curMax;
    }
    free(job);
    return res;
}
// @lc code=end

/*
// @lcpr case=start
// [2,4,6,8,10]\n[10,20,30,40,50]\n[4,5,6,7]\n
// @lcpr case=end

// @lcpr case=start
// [85,47,57]\n[24,66,99]\n[40,25,25]\n
// @lcpr case=end

 */
