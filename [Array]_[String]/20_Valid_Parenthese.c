bool isValid(char *s)
{
    int n = strlen(s);
    char stack[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        char m = s[i];

        if (m == '(' || m == '{' || m == '[')
        {
            stack[++top] = m;
        }
        else
        {
            if (top == -1)
                return false;

            char open = stack[top--];

            if ((m == ')' && open != '(') ||
                (m == ']' && open != '[') ||
                (m == '}' && open != '{'))
            {
                return false;
            }
        }
    }
    return top == -1;
}