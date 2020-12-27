/*******************************************************************************
 * Problem: 205. Isomorphic Strings
 * https://leetcode.com/problems/isomorphic-strings/
 * 问题：205. 同构字符串
 * https://leetcode-cn.com/problems/isomorphic-strings/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-27
 * 
 * Summary:
 * Let s and t be 2 strings. 
 * If there is a mapping rule from s[i] to t[i], then s[i] maps to no other 
 * character and no other character maps to t[i].
 * 
 * Here, we use 2 hash tables, s2t and t2s, to record mapping rules. 
 * We can look up what char s[i] maps in s2t. 
 * And we can look up what char maps to t[i] in t2s.
 * 
 * For each pair of s[i] and t[i]:
 * Case 1: If no rule of s[i] -> x or x -> t[i], add rule s[i] -> t[i].
 * Case 2: If there is rule s[i] -> x, check if x is t[i]. 
 *         If not, return false. 
 * Case 3: If there is rule x -> t[i], check if x is s[i]. 
 *         If not, return false. 
 * After all pairs of s[i] and t[i] have been checked and passed, return true.
 * 
 * 令s和t为两个字符串。
 * 如果s[i]映射到t[i]，那么s[i]就不映射到其他字符，且没有其他字符映射到t[i]。
 * 为此，我们创建两个哈希表，s2t和t2s，来保存映射规则。
 * 我们可以从s2t查询s[i]映射到哪个字符，可以从t2s查询t[i]被哪个字符映射。
 * 
 * 对于每一对s[i]和t[i]，
 * 情况1：s[i]没有映射到任何字符，且t[i]也没有被其他字符映射。
 *       那么添加映射规则s[t] -> t[i]。
 * 情况2：s[i]映射到字符x。
 *       那么检查x是否为t[i]。若不是，则返回false。
 * 情况3：t[i]被字符x映射。
 *       那么检查x是否为s[i]。若不是，则返回false。
 * 当每一对s[i]和t[i]都已检查并通过，则返回true。
 ******************************************************************************/

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> s2t; // Mapping rules from s[i] to t[i].
                                       // 记录s[i]映射到哪个字符。
        unordered_map<char, char> t2s; // Mapping rules from t[i] to s[i].
                                       // 记录t[i]被哪个字符映射。
        
        // Map each pair of s[i] and t[i].
        // 映射每一对s[i]和t[i]。
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            // If no rule for s[i] -> t[i], add the rule.
            // 若没有s[i] -> t[i]的映射，则添加映射规则。
            if (s2t.count(s[i]) == 0 && t2s.count(t[i]) == 0)
            {
                pair<char, char> rule;
                
                rule.first = s[i];
                rule.second = t[i];
                s2t.insert(rule);
                
                rule.first = t[i];
                rule.second = s[i];
                t2s.insert(rule);
            }
            // If there is a rule for s[i] -> x, then check if x is t[i].
            // 若存在s[i] -> x的映射，则检查x是否为t[i]。
            else if (s2t.count(s[i]) != 0)
            {
                if (s2t[s[i]] != t[i])
                {
                    return false;
                }
            }
            // If there is a rule for x -> t[i], then x cannot be s[t], or it 
            // will fall into previous case first.
            // 若存在x -> t[i]映射，那么x一定不是s[i]，否则会先进入前一个情况。
            else // if (t2s.count(t[i]) != 0)
            {
                return false;
            }
        }
        return true;
    }
};
