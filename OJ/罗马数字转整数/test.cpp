int temp(char ch)
{
    switch (ch)
    {
    case 'I':
        return 1;
        break;
    case 'V':
        return 5;
        break;
    case 'X':
        return 10;
        break;
    case 'L':
        return 50;
        break;
    case 'C':
        return 100;
        break;
    case 'D':
        return 500;
        break;
    case 'M':
        return 1000;
        break;
    }
    return 0;
}

int romanToInt(char* s) {
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == 'I' && s[i + 1] == 'V') || (s[i] == 'I' && s[i + 1] == 'X'))
        {
            sum += temp(s[i + 1]) - 1;
            i++;
        }
        else if ((s[i] == 'X' && s[i + 1] == 'L') || (s[i] == 'X' && s[i + 1] == 'C'))
        {
            sum += temp(s[i + 1]) - 10;
            i++;
        }
        else if ((s[i] == 'C' && s[i + 1] == 'D') || (s[i] == 'C' && s[i + 1] == 'M'))
        {
            sum += temp(s[i + 1]) - 100;
            i++;
        }
        else
            sum += temp(s[i]);
    }
    return sum;
}