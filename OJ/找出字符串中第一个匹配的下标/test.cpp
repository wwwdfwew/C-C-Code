int strStr(char* haystack, char* needle) {
    if (strlen(haystack) < strlen(needle))
        return -1;
    char* prve = haystack;
    char* cur1 = haystack;
    char* cur2 = needle;
    int count = 0;
    while (*cur2 && *cur1)
    {
        if (*cur1 == *cur2)
        {
            cur1++;
            cur2++;
        }
        else
        {
            prve++;
            cur1 = prve;
            cur2 = needle;
            count++;
        }

    }
    if (*cur2 == '\0')
        return count;
    else
        return -1;
}