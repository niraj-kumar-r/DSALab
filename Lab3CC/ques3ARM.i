# 0 "ques3.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "ques3.c"
void str_reverse(char *str)
{
    int i = 0;
    int j = 0;
    char temp;
    while (str[i] != '\0')
    {
        i++;
    }
    i--;
    while (i > j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i--;
        j++;
    }
}

int main()
{
    char str[100] = "Hello World";
    str_reverse(str);
}
