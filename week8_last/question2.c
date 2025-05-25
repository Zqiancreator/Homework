int isSequence(char a, char b)
{
    int aN = a - 'a';
    int bN = b - 'a';
    if ((aN + 1) % 26 == bN || (bN + 1) % 26 == aN) {
        return 1;
    }
    return 0;
}

char *resultingString(char *s)
{
    int n = strlen(s);
    char *res = malloc((n + 1));
    if (res == NULL) {
        return "";
    }
    int curIndex = -1;

    for (int i = 0; i < n; i++) {
        res[++curIndex] = s[i];
        while (curIndex >= 1 && isSequence(res[curIndex], res[curIndex - 1]) == 1) {
            curIndex -= 2;
        }
    }

    res[curIndex + 1] = '\0';
    return res;
}