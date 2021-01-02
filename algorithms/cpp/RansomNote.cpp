/*******************************************************************************
 * Problem: 383. Ransom Note
 * https://leetcode.com/problems/ransom-note/
 * 问题：383. 赎金信
 * https://leetcode-cn.com/problems/ransom-note/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-01-01
 * 
 * Summary:
 * Since both ransomNote and magazine contain only lowercase letters. We could 
 * use an integer array of 26 elements to record the occurrance of letters in 
 * magazine.
 * Then we traverse each letter in ransomNote and decrease the recorded 
 * occurrance of the corresponding letter by 1. Once any occurrance becomes 
 * negative, return false. If all the occurrances are positive after traversal 
 * of ransomNote, return true. 
 * 
 * If ransomNote and magazine contain not only lowercase letters, we could use 
 * hash table instead of array.
 * 
 * 由于ransomNote和magazine中只包含小写字母，可以直接用26个元素的整数型数组记录个字母
 * 在magazine中的出现次数。
 * 然后遍历ransomNote的各个字母，并将对应字母在magazine中出现的次数减1。一旦发现出现
 * 次数减到负数，就返回false。遍历ransomNote后，各字母剩余出现次数都为非负，则返回
 * true。
 * 
 * 如果没有“ransomNote和magazine中只包含小写字母”的条件，则可以用哈希表来处理。
 ******************************************************************************/

// Hash table solution.
// 哈希表解法。
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // Record chars and their counts in magazine.
        // 记录magazine的字符及其出现次数。
        std::unordered_map<char, int> counts;
        for (auto i = magazine.begin(); i != magazine.end(); i++)
        {
            if (counts.count(*i) == 0)
            {
                counts[*i] = 1;
            }
            else
            {
                counts[*i]++;
            }
        }

        // Check if each char in ransomNote is in magazine and its occurrence 
        // is no more than the one in magazine.
        // 检查ransomNote的每个字符都在magazine中出现，且出现次数不超过magazine。
        for (auto i = ransomNote.begin(); i != ransomNote.end(); i++)
        {
            if (counts.count(*i) == 0 || counts[*i] == 0)
            {
                return false;
            }
            else
            {
                counts[*i]--;
            }
        }
        return true;
    }
};

// Array solution.
// 数组解法。
class Solution
{
public:
    bool canConstruct(string ransomNote, string magazine)
    {
        // Record char counts in magazine.
        // 记录magazine各小写字母的出现次数。
        vector<int> counts(26, 0);
        for (auto i = magazine.begin(); i != magazine.end(); i++)
        {
            counts[*i - 'a']++;
        }

        // Check if char occurrence in ransomNote is no more than the one in 
        // magazine.
        // 检查ransomNote中各小写字母的出现次数是否超过magazine。
        for (auto i = ransomNote.begin(); i != ransomNote.end(); i++)
        {
            if (counts[*i - 'a'] == 0)
            {
                return false;
            }
            counts[*i - 'a']--;
        }
        return true;
    }
};

