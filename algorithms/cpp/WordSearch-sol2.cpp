/*******************************************************************************
 * Problem: https://leetcode.com/problems/word-search/
 * 问题：https://leetcode-cn.com/problems/word-search/
 *       https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2020-12-26
 * 
 * Summary:
 * For each grid in board, we start a DFS for the given word.
 * Once we find a path for the word, we stop and return true.
 * Once any gird is out of bound, has been visited, or does not match the word, 
 * we trace back and try another path. 
 * After we traveres all possible path but still cannot find a path, we stop 
 * and return false.
 * 我们分别从二维网格中的每个格点出发，深搜给定的单词。
 * 一旦找到一条单词路径，就停止并返回true。
 * 一旦发现某个格点超出二维网格范围，或者已访问过，或者不符合单词，则回溯并尝试其他路
 * 径。
 * 在尝试了所有可能的路径并且未找到单词路径后，返回false。
 * 
 * Since board and word consists only of lowercase and uppercase English 
 * letters, we could mark visited grid directly on board using some special 
 * character, such as '\0'. When we need to trace back, we could restore the 
 * marked grid with the corresponding character in the word, since that grid 
 * matches the word.
 * In this case, we don't have to clear the visited record when starting DFS. 
 * It saves time. 
 * What's more, we don't have to access the board and the visited record back 
 * and forth. It improves the spatial locality.
 * 由于二维网格board和单词word只包含大小写英文字母，我们可以用特殊字符，比如'\0'，在
 * board上直接标记已访问单元格。当回溯时，可以将单元格恢复为单词中对应的字母，因为该单
 * 元格符合单词中的某个字母。
 * 这样一来，在每次深搜开始时，我们就不需要创建或清空单独的已访问记录visited，节约了时
 * 间。
 * 而且，我们不需要来回访问board和visited。这样提高了空间局部性，提高了运行效率。
 * 
 * Acknowledgement: This solution is inspired by the solution on https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/
 * 该解法受到了 https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof/solution/mian-shi-ti-12-ju-zhen-zhong-de-lu-jing-shen-du-yo/ 的启发。
 * 
 ******************************************************************************/

class Solution
{
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int height = board.size();
        int width = board[0].size();

        // For each grid, DFS for the given word.
        // 从每个单元格开始对单词进行深搜。
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                if (dfs(board, word, row, col, 0))
                {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string &word, 
             int row, int col, int step)
    {
        // Base case: Out of bound.
        // 基本情况：当前位置超出二维网格。
        int height = board.size();
        int width = board[0].size();
        if (row < 0 || row >= height || col < 0 || col >= width)
        {
            return false;
        }
        
        // Base case: Current character does not match.
        // 基本情况：当前字符不符合单词。
        if (board[row][col] != word[step])
        {
            return false;
        }
        
        // Base case: The word is found.
        // 基本情况：单词已找到。
        if (step == word.size() - 1)
        {
            return true;
        }

        // Recursive case:
        // Mark the current gird.
        // We mark directly on board. So, we don't have to init visited record 
        // for every starting grid. It saves time.
        // We don't have to access board and visited record back and forth. It 
        // improves spatial locality. 
        // However, if board or word contains characters other than lowercase 
        // and uppercase English letters, we may still need a visited record.
        // 递归情况：
        // 标记当前单元格。
        // 我们直接在网格board上标记，这样就不需要初始化已访问记录visited，节约时间。
        // 同时，我们不需要来回访问二维网格board和已访问记录visited。这样提高了空间局
        // 部性，运行效率更高。
        // 但是，如果二维网格board和单词word包含出英文大小写字母以外的字符，我们可能
        // 仍然需要单独的已访问记录visited。
        board[row][col] = '\0';
        
        // Recursively DFS up, down, right, left.
        // 对上下左右相邻单元格进行递归深搜。
        if (dfs(board, word, row - 1, col, step + 1) 
            || dfs(board, word, row + 1, col, step + 1)
            || dfs(board, word, row, col + 1, step + 1)
            || dfs(board, word, row, col - 1, step + 1))
        {
            return true;
        }
        
        // Unmark the current grid.
        // Since the current gird matches the word, we could restore the board 
        // by the current character in word.
        // 去除当前单元格标记。
        // 因为当前单元格原有字符符合单词，我们可以利用单词来恢复它。
        board[row][col] = word[step];
        
        return false;
    }
};
