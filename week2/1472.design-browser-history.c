/*
 * @lc app=leetcode.cn id=1472 lang=c
 * @lcpr version=30204
 *
 * [1472] 设计浏览器历史记录
 */

// @lcpr-template-start

// @lcpr-template-end
// @lc code=start
#include <stdio.h>
#include <string.h>

#define INIT_SIZE 100
typedef struct {
    char **urls;
    int curIndex;
    int capacity;
    int size;
} BrowserHistory;

BrowserHistory *BrowserHistoryCreate(char *homepage)
{
    BrowserHistory *browserHistory = malloc(sizeof(BrowserHistory));
    if (browserHistory == NULL) {
        return NULL;
    }
    browserHistory->capacity = INIT_SIZE;
    browserHistory->urls = (char **)malloc(sizeof(char *) * browserHistory->capacity);
    if (browserHistory->urls == NULL) {
        free(browserHistory->urls);
        free(browserHistory);
        return NULL;
    }

    browserHistory->curIndex = 0;
    browserHistory->urls[browserHistory->curIndex] = strdup(homepage);
    if (browserHistory->urls[browserHistory->curIndex] == NULL) {
        free(browserHistory->urls);
        free(browserHistory);
        return NULL;
    }
    browserHistory->size = 0;
    return browserHistory;
}

void BrowserHistoryVisit(BrowserHistory *obj, char *url)
{
    while (obj->size > obj->curIndex) {
        free(obj->urls[obj->size]);
        obj->size--;
    }
    obj->curIndex++;
    obj->size++;
    if (obj->size >= obj->capacity) {
        obj->capacity *= 2;
        char **temp = (char **)realloc(obj->urls, obj->capacity * sizeof(char *));
        if (temp == NULL) {
            return;
        }
        obj->urls = temp;
    }
    obj->urls[obj->curIndex] = strdup(url);
    if (obj->urls[obj->curIndex] == NULL) {
        obj->curIndex--;
        obj->size--;
        return;
    }
    return;
}

char *BrowserHistoryBack(BrowserHistory *obj, int steps)
{
    obj->curIndex -= steps;
    if (obj->curIndex < 0) {
        obj->curIndex = 0;
    }
    return obj->urls[obj->curIndex];
}

char *BrowserHistoryForward(BrowserHistory *obj, int steps)
{
    obj->curIndex += steps;
    if (obj->curIndex > obj->size) {
        obj->curIndex = obj->size;
    }
    return obj->urls[obj->curIndex];
}

void BrowserHistoryFree(BrowserHistory *obj)
{
    if (obj == NULL) {
        return;
    }
    if (obj->urls == NULL) {
        return;
    }
    for (int i = 0; i <= obj->size; i++) {
        if (obj->urls[i] != NULL) {
            free(obj->urls[i]);
        }
    }
    free(obj->urls);
    free(obj);
    return;
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);

 * char* param_2 = browserHistoryBack(obj, steps);

 * char* param_3 = browserHistoryForward(obj, steps);

 * browserHistoryFree(obj);
*/
// @lc code=end

/*
// @lcpr case=start
// ["BrowserHistory","visit","visit","visit","back","back","forward","visit","forward","back","back"]\n[["leetcode.com"],["google.com"],["facebook.com"],["youtube.com"],[1],[1],[1],["linkedin.com"],[2],[2],[7]]\n
// @lcpr case=end

 */
