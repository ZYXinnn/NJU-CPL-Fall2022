/*
 * @Author: ZYXin
 * @Date: 2022-11-28 14:09:40
 * @LastEditTime: 2022-12-31 16:27:28
 * @FilePath: \c\project\calculator.c
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
// 以下为检查括号匹配的栈
#define STACK_SIZE 2000
char contents[STACK_SIZE];
char str[STACK_SIZE];
int top = 0;
bool is_empty(void)
{
    return top == 0;
}
void push(char i)
{
    contents[top++] = i;
}
void pop(void)
{
    contents[top - 1] = '\0';
    top--;
}
void leftright(char i)
{
    if (i == '(')
        push(i);
    else if (i == ')')
    {
        if (contents[top - 1] == '(')
            pop();
        // else
        //    arr[t] = 0;
    }
}
void make_empty()
{
    top = 0;
}
// 栈到此结束
int m[100000], n[100000]; // m存每行token结束数,n存每行结果1/error,2/输出
typedef struct token
{
    int type; // 整数1，浮点数2，运算符3，变量4，error5
    char str[32];
} Token;
Token tokens[100000];
int testtype(int x)
{
    int a, count = 0, b = 0, c = 0; // a为字符串长度，b为第一次'.'出现的位置，count为'.'的数量，c判断是否全部为整数
    a = strlen(tokens[x].str);
    for (int i = 0; i <= a - 1; i++) // 判断浮点数
    {
        if (tokens[x].str[i] != '.' && ((int)tokens[x].str[i] < 48 || (int)tokens[x].str[i] > 57))
        {
            count = 0;
            break;
        } // 存在非'.'及数字
        if (tokens[x].str[i] == '.')
        {
            count++;
            if (count == 1)
                b = i;
        }
    }
    if (count > 1)
        return 5;
    else if (count == 1)
    {
        if (tokens[x].str[0] == '0' && b != 1)
            return 5;
        else if (b == 0)
            return 5;
        else if ((int)tokens[x].str[b + 1] < 48 || (int)tokens[x].str[b + 1] > 57)
            return 5;
        else
            return 2;
    }
    else if (count == 0)
    {
        if (a == 1) // 判断运算符
        {
            if (tokens[x].str[0] == '=' || tokens[x].str[0] == '+' || tokens[x].str[0] == '-' || tokens[x].str[0] == '*' || tokens[x].str[0] == '/' || tokens[x].str[0] == '(' || tokens[x].str[0] == ')')
                return 3;
        }
        for (int i = 0; i <= a - 1; i++) // 判断整数
        {
            if ((int)tokens[x].str[i] < 48 || (int)tokens[x].str[i] > 57)
            {
                c = 1;
                break;
            }
        }
        if (c == 0)
        {
            if ((int)tokens[x].str[0] == 48 && b > 1)
                return 5;
            else
                return 1;
        }
        if (tokens[x].str[0] == '_') // 判断变量及其他error
            return 4;
        else if ((int)tokens[x].str[0] >= 65 && (int)tokens[x].str[0] <= 90)
            return 4;
        else if ((int)tokens[x].str[0] >= 97 && (int)tokens[x].str[0] <= 122)
            return 4;
        else
            return 5;
    }
    return 5;
}
int check_parentheses(int a, int b)
{
    if (tokens[a].str[0] == '(' && tokens[b].str[0] == ')')
    {
        for (int k = a + 1; k <= b - 1; k++)
            leftright(tokens[k].str[0]);
        if (is_empty())
        {
            make_empty();
            return 1;
        }
        else
        {
            make_empty();
            return 0;
        }
    }
    else
        return 0;
}
int search_op(int a, int b)
{
    int x = 0, y = 0; // 判定是否在括号内
    for (int i = b; i >= a; i--)
    {
        if (tokens[i].str[0] == '+')
        {
            for (int j = i + 1; j <= b; j++)
            {
                if (tokens[j].str[0] == ')')
                    y++;
                if (tokens[j].str[0] == '(')
                    y--;
            }
            for (int j = i - 1; j >= a; j--)
            {
                if (tokens[j].str[0] == '(')
                    x++;
                if (tokens[j].str[0] == ')')
                    x--;
            }
            if (x == 0 && y == 0)
                return i;
            x = 0;
            y = 0;
        }
        if (i >= a + 1)
        {
            if (tokens[i - 1].str[0] != '+' && tokens[i - 1].str[0] != '-' && tokens[i - 1].str[0] != '*' && tokens[i - 1].str[0] != '/')
            {
                if (tokens[i].str[0] == '-')
                {
                    for (int j = i + 1; j <= b; j++)
                    {
                        if (tokens[j].str[0] == ')')
                            y++;
                        if (tokens[j].str[0] == '(')
                            y--;
                    }
                    for (int j = i - 1; j >= a; j--)
                    {
                        if (tokens[j].str[0] == '(')
                            x++;
                        if (tokens[j].str[0] == ')')
                            x--;
                    }
                    if (x == 0 && y == 0)
                        return i;
                    x = 0;
                    y = 0;
                }
            }
        }
    }
    for (int i = b; i >= a; i--)
    {
        if (tokens[i].str[0] == '*' || tokens[i].str[0] == '/')
        {
            for (int j = i + 1; j <= b; j++)
            {
                if (tokens[j].str[0] == ')')
                    y++;
                if (tokens[j].str[0] == '(')
                    y--;
            }
            for (int j = i - 1; j >= a; j--)
            {
                if (tokens[j].str[0] == '(')
                    x++;
                if (tokens[j].str[0] == ')')
                    x--;
            }
            if (x == 0 || y == 0)
                return i;
            x = 0;
            y = 0;
        }
    }
    return -1;
}
int check_minus(int a, int b)
{
    if (search_op(a, b) == -1)
    {
        if (tokens[a].str[0] == '-')
            return 1;
        else
            return 0;
    }
    return 0;
}
typedef struct X
{
    char p;
    int q;
} Op;
enum Type
{
    INT,
    DOUBLE,
    ERROR
};
typedef struct value
{
    enum Type type;
    union
    {
        int iVal;
        double fVal;
    } val;
} Value;
Value valar[100000];
Value meetValue(Value v1, Value v2, Op op)
{
    Value val3;
    if (v1.type == ERROR || v2.type == ERROR)
    {
        val3.type = ERROR;
        return val3;
    }
    if (v1.type != v2.type)
    {
        val3.type = DOUBLE;
        if (v1.type == INT)
        {
            v1.val.fVal = (double)v1.val.iVal;
            v1.type = DOUBLE;
        }
        else if (v2.type == INT)
        {
            v2.val.fVal = (double)v2.val.iVal;
            v2.type = DOUBLE;
        }
    }
    if (op.p == '+')
    {
        val3.type = v1.type;
        if (val3.type == INT)
            val3.val.iVal = v1.val.iVal + v2.val.iVal;
        else if (val3.type == DOUBLE)
            val3.val.fVal = v1.val.fVal + v2.val.fVal;
    }
    else if (op.p == '-')
    {
        val3.type = v1.type;
        if (val3.type == INT)
            val3.val.iVal = v1.val.iVal - v2.val.iVal;
        else if (val3.type == DOUBLE)
            val3.val.fVal = v1.val.fVal - v2.val.fVal;
    }
    else if (op.p == '*')
    {
        val3.type = v1.type;
        if (val3.type == INT)
            val3.val.iVal = v1.val.iVal * v2.val.iVal;
        else if (val3.type == DOUBLE)
            val3.val.fVal = v1.val.fVal * v2.val.fVal;
    }
    else if (op.p == '/')
    {
        val3.type = v1.type;
        if (val3.type == INT)
            val3.val.iVal = v1.val.iVal / v2.val.iVal;
        else if (val3.type == DOUBLE)
            val3.val.fVal = v1.val.fVal / v2.val.fVal;
    }
    return val3;
}
typedef struct assignment
{
    char name[32];
    Value value1;
} Assignment;
Assignment as[10000];
int g = 0; // g为as数
Value eval(int l, int r)
{
    Value val;
    if (l > r)
    {
        val.type = ERROR;
        return val;
    }
    else if (l == r)
    {
        if (tokens[l].type == 1)
        {
            val.type = INT;
            val.val.iVal = atoi(tokens[l].str);
            return val;
        }
        else if (tokens[l].type == 2)
        {
            val.type = DOUBLE;
            val.val.fVal = atof(tokens[l].str);
            return val;
        }
        else if (tokens[l].type == 4)
        {
            for (int i = 0; i <= g - 1; i++)
            {
                if (strcmp(tokens[l].str, as[i].name) == 0)
                {
                    val = as[i].value1;
                    return val;
                }
            }
            val.type = ERROR;
            return val;
        }
        else
        {
            val.type = ERROR;
            return val;
        }
    }
    else if (check_parentheses(l, r) == 1)
    {
        return eval(l + 1, r - 1);
    }
    else if (check_minus(l, r) == 1)
    {
        Value val1 = {INT, -1};
        Op op;
        op.p = '*';
        return meetValue(val1, eval(l + 1, r), op);
    }
    else if (r - l == 1)
    {
        val.type = ERROR;
        return val;
    }
    else
    {
        Op op;
        Value val1, val2;
        if (search_op(l, r) != -1)
        {
            op.q = search_op(l, r);
            op.p = tokens[op.q].str[0];
            val1 = eval(l, op.q - 1);
            val2 = eval(op.q + 1, r);
            return meetValue(val1, val2, op);
        }
        else
        {
            val1.type = ERROR;
            return val1;
        }
    }
}
Value evalAssign(int l, int r)
{
    int p, q, x = 0; // x用于判断是否之前有该赋值
    Value vall;
    for (int i = l; i <= r; i++)
    {
        if (tokens[i].str[0] == '=')
            p = i;
        if (i < l)
        {
            if (tokens[i].type != 4 && tokens[i].str[0] != '=')
            {
                vall.type = ERROR;
                return vall;
            }
        }
    }
    q = g;
    for (int i = l; i <= p; i++)
    {
        if (i == l)
        {
            if (tokens[i].type != 4)
            {
                vall.type = ERROR;
                return vall;
            }
        }
        else
        {
            if (tokens[i - 1].type == 4 && tokens[i].str[0] != '=')
            {
                vall.type = ERROR;
                return vall;
            }
            if (tokens[i - 1].str[0] == '=' && tokens[i].type != 4)
            {
                vall.type = ERROR;
                return vall;
            }
        }
    }
    for (int i = l; i <= p; i++)
    {
        if (tokens[i].type == 4)
        {
            for (int l = 0; l <= g - 1; l++)
            {
                if (strcmp(tokens[i].str, as[l].name) == 0)
                {
                    if (eval(p + 1, r).type != ERROR)
                    {
                        as[l].value1 = eval(p + 1, r);
                        x = 1;
                        break;
                    }
                    else
                    {
                        x = 1;
                        break;
                    }
                }
            }
            if (x != 1)
            {
                strcpy(as[g].name, tokens[i].str);
                g++;
                x = 0;
            }
        }
    }
    for (int i = q; i < g; i++)
        as[i].value1 = eval(p + 1, r);
    return eval(p + 1, r);
}
void printValue(Value v)
{
    if (v.type == INT)
        printf("%d\n", v.val.iVal);
    if (v.type == DOUBLE)
        printf("%f\n", v.val.fVal);
    if (v.type == ERROR)
        printf("Error\n");
}
int main()
{
    char a, b = '\n';               // b用于判断\n前是否有空格
    int p = 0, t = 0, o = 0, q = 0; // p为行数，t判断是否词法错误，t输入时++,q为总token数
    while ((a = getchar()) != EOF)
    {
        if (a != '\n' && a != ' ')
        {
            tokens[q].str[o] = a;
            o++;
        }
        else if (a == '\n' || (a == ' ' && b != ' ' && b != '\n'))
        {
            q++;
            o = 0;
            if (a == '\n' && b != ' ')
            {
                m[p] = q;
                p++;
            }
            else if (a == '\n' && b == ' ')
            {
                q--;
                m[p] = q;
                p++;
            }
        }
        b = a;
    }
    for (int i = 0; i <= q - 1; i++) // 处理type
        tokens[i].type = testtype(i);
    t = 0;
    for (int t1 = 0; t1 <= m[t] - 1; t1++) // 判断词法错误
    {
        if (tokens[t1].type == 5)
            n[t] = 1;
        if (t1 == m[t] - 1)
            t++;
    }
    t = 0;
    for (int t1 = 0; t1 <= m[t] - 1; t1++) // 判断括号匹配
    {
        if (n[t] != 1)
        {
            leftright(tokens[t1].str[0]);
            if (t1 == m[t] - 1)
            {
                if (is_empty())
                    n[t] = 0;
                else
                    n[t] = 1;
                t++;
                make_empty();
            }
        }
        else
            t++;
    }
    t = 0;
    for (int t1 = 0; t1 <= p - 1; t1++) // 判断是否有赋值语句
    {
        if (n[t1] != 1)
        {
            if (t1 == 0)
            {
                for (int t2 = 0; t2 <= m[0] - 1; t2++)
                {
                    if (tokens[t2].str[0] == '=')
                    {
                        n[t1] = 2;
                        break;
                    }
                }
            }
            else if (t1 > 0)
            {
                for (int t2 = m[t1 - 1]; t2 <= m[t1] - 1; t2++)
                {
                    if (tokens[t2].str[0] == '=')
                    {
                        n[t1] = 2;
                        break;
                    }
                }
            }
        }
    }
    for (int t1 = 0; t1 <= p - 1; t1++)
    {
        if (n[t1] == 0)
        {
            int l, r;
            if (t1 != 0)
                l = m[t1 - 1];
            else
                l = 0;
            r = m[t1] - 1;
            valar[t1] = eval(l, r);
        }
        else if (n[t1] == 2)
        {
            int l, r;
            if (t1 != 0)
                l = m[t1 - 1];
            else
                l = 0;
            r = m[t1] - 1;
            valar[t1] = evalAssign(l, r);
        }
    }
    for (int t1 = 0; t1 <= p - 1; t1++)
    {
        if (n[t1] == 1)
            printf("Error\n");
        else
            printValue(valar[t1]);
    }
    return 0;
}
