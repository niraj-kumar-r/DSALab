# 0 "ques4main.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "ques4main.c"
int fun_add(int a, int b);
int fun_sub(int a, int b);
int fun_mul(int a, int b);
int fun_and(int a, int b);
int fun_or(int a, int b);

int main()
{
    int a = 10;
    int b = 20;
    int c = fun_add(a, b);
    int d = fun_sub(a, b);
    int e = fun_mul(a, b);
    int f = fun_and(a, b);
    int g = fun_or(a, b);
    return 0;
}
