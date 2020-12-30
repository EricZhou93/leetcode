/*******************************************************************************
 * Problem: 640. Solve the Equation
 * https://leetcode.com/problems/solve-the-equation/
 * 问题：640. 求解方程
 * https://leetcode-cn.com/problems/solve-the-equation/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-30
 * 
 * Summary:
 * 1. Convert equation ax+b=x-c to +ax+b-1x+c.
 *  (1) If the first term is not negative, add '+' at front.
 *  (2) Add coefficient 1 for +x and -x terms.
 * 2. Move the terms on the right side of '=' to the left side.
 *  (1) On the right side of '=', set '+' to '-' and set '-' to '+'.
 *  (2) Set '=' to '-'.
 * 3. Merge x terms and constant terms.
 * 4. Let a be the coefficient of x and c be the constant term, i.e. the 
 * equation is ax + c = 0.
 *  (1) If a = c = 0, return "Infinite solutions".
 *  (2) If a = 0 but c != 0, return "No solution".
 *  (3) Otherwise, return -c / x.
 * 
 * 1. 将等式ax+b=x-c转化为+ax+b-1x+c的形式，即：
 *  (1) 若第一项非负，则在前面添加'+'；
 *  (2) 对于+x和-x，添加系数'1'。
 * 2. 将等号右侧所有项移到等号左侧，即：
 *  (1) 将'='右侧的'+'改为'-'，'-'改为'+'；
 *  (2) 将'='改为'-'。
 * 3. 分别合并x项和常数项。
 * 4. 假设x的系数为a，常数项为c，即等式为ax+c=0。
 *  (1) 若a=c=0，则返回“Infinite solutions”；
 *  (2) 若a=0且c!=0，则返回“No solution”；
 *  (3) 其他情况，返回-c/x。
 ******************************************************************************/

class Solution
{
public:
    string solveEquation(string equation)
    {
        // Convert ax+b=x+c to +ax+b-1x-c.
        // Add "+" at front.
        string expression;
        if (equation[0] != '-')
        {
            expression.push_back('+');
        }
        // Add 1 for +x and -x.
        int curr = 0;
        int len = equation.size();
        while (curr < len)
        {
            if (equation[curr] == 'x' && (curr == 0 || equation[curr - 1] == '+' || equation[curr - 1] == '-' || equation[curr - 1] == '='))
            {
                expression.push_back('1');
            }
            expression.push_back(equation[curr]);
            curr++;
        }
        // Flip signs on the right side of "=".
        len = expression.size();
        curr = 0;
        while (curr < len)
        {
            if (expression[curr] == '=')
            {
                expression[curr] = '-';
                curr++;
                break;
            }
            curr++;
        }
        while (curr < len)
        {
            if (expression[curr] == '+')
            {
                expression[curr] = '-';
            }
            else if (expression[curr] == '-')
            {
                expression[curr] = '+';
            }
            curr++;
        }
        // return expression; // TEST

        // Read expression and merge x's and constants.
        int x = 0; // Coefficient of x.
        int c = 0; // Constant term.
        int value = 0;
        int sign = 1;
        curr = 0;
        while (curr < len)
        {
            // If '+', add the last value to constant term and start to read a new value.
            if (expression[curr] == '+')
            {
                c += sign * value;
                value = 0;
                sign = 1;
            }
            // If '-', add the last value to constant term and start to read a new value.
            else if (expression[curr] == '-')
            {
                c += sign * value;
                value = 0;
                sign = -1;
            }
            // If 'x', record the last value to coefficent of x and start to read a new value.
            else if (expression[curr] == 'x')
            {
                x += sign * value;
                value = 0;
            }
            // If a digit, append to the current value.
            else
            {
                value *= 10;
                value += expression[curr] - '0';
            }

            curr++;
        }
        c += sign * value;
        // return "x = " + to_string(x) + ", c = " + to_string(c); // TEST

        // Get result.
        if (x == 0)
        {
            if (c == 0)
            {
                return "Infinite solutions";
            }
            else
            {
                return "No solution";
            }
        }
        string result = "x=";
        result += to_string(-c/x);
        return result;
    }
};
