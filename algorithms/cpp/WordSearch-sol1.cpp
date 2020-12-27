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
 ******************************************************************************/

class Solution
{
private:
    bool check(const vector<vector<char>>& board, const string &word, 
               vector<vector<bool>>& visited, int row, int col, int step)
    {
        // Base case: Current character does not match.
        // 基本情况：当前字符不符合单词。
        if (board[row][col] != word[step])
        {
            return false;
        }
        
        // Base case: The word is found.
        // 基本情况：单词已找到。
        if (step == word.size() - 1 && board[row][col] == word[step])
        {
            return true;
        }
        
        
        // Recursive case:
        // 递归情况：
        int height = board.size();
        int width = board[0].size();
        
        // Mark the current gird.
        // 标记当前格点。
        visited[row][col] = true;
        
        // Go up.
        // 向上。
        if (row > 0 && !visited[row - 1][col] 
            && check(board, word, visited, row - 1, col, step + 1))
        {
            return true;
        }
                
        // Go down.
        // 向下。
        if (row < height - 1 && !visited[row + 1][col] 
            && check(board, word, visited, row + 1, col, step + 1))
        {
            return true;
        }
        
        // Go right.
        // 向右。
        if (col < width - 1 && !visited[row][col + 1] 
            && check(board, word, visited, row, col + 1, step + 1))
        {
            return true;
        }
        
        // Go left.
        // 向左。
        if (col > 0 && !visited[row][col - 1] 
            && check(board, word, visited, row, col - 1, step + 1))
        {
            return true;
        }
            
        // Unmark the current grid.
        // 除去当前格点标记。
        visited[row][col] = false;
        
        return false;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        int height = board.size();
        int width = board[0].size();
        
        // Start DFS from each grid.
        // 从每个格点开始分别深搜。
        for (int row = 0; row < height; row++)
        {
            for (int col = 0; col < width; col++)
            {
                if (board[row][col] != word[0])
                {
                    continue;
                }
                
                // Init visited record.
                // 初始化已访问记录。
                vector<vector<bool>> visited(height, vector<bool>(width, false));
                
                // Start DFS from this grid.
                // 从这个格点开始深搜。
                if (check(board, word, visited, row, col, 0))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
};
