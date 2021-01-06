/*******************************************************************************
 * Problem: 1245. Tree Diameter
 * https://leetcode.com/problems/tree-diameter/
 * 问题：1245. 树的直径
 * https://leetcode-cn.com/problems/tree-diameter/
 * 
 * Authors:  Keren Zhou
 * 
 * Date: 2021-01-06
 * 
 * Summary:
 * Assume the only diameter is ab. (Case of multiple diameters is similar.)
 * We can prove that, for any node i, the furthest node from i is a or b.
 * And the furthest node from a is b.
 * 
 * 1. Convert the graph represent from edge array to adjacency list.
 * Adjacency list of each node is a hash map of its adjacent nodes.
 * All the adjacency lists are stored in an array by node indices.
 * So, we can access the adjacency list for each node in constant time.
 * And, we can check if 2 nodes are adjacent in constant time as well.
 * 2. Take any node i in tree. Use BFS to find the node a that is the furthest 
 * from node i.
 * 3. Use BFS to find the node b that is the furthest from node a.
 * 4. ab is the diameter of this tree.
 * 
 * 
 * 思路：
 * 树种所有的节点都连通（任意两个节点之间必有一条路径），且没有回路。
 * 一颗无向树的直径是树内部的最长路径。
 * 假设直径为ab。我们可以证明，任取一个节点i，距离i最远的节点必定是a或b。而距离a最远的
 * 节点必定是b。
 * 
 * 结论1：直径的两个端点必定是叶节点。
 *  假设直径的两个端点至少一个不是叶节点。
 *  令直径为AB，且B不是叶节点。从B以AB方向延伸，可延伸到C。
 *  那么|AB| < |AB| + |BC| = |AC|。
 *  这与直径的定义相悖。
 *  所以直径的两个端点必定是叶节点。
 * 
 * 结论2：从任意一个结点出发，与其距离最远的节点必定是直径的一个端点。
 *  假设唯一的直径为AB，任意一个结点为C。若直径不唯一，情况类似。
 *  情况1：C为A或B。
 *      那么根据直径的定义，C和与C距离最远的节点必定是A和B。
 *  情况2：C在AB上。
 *      假设与C距离最远的节点不是A或B，而是D。
 *      那么|CD| > |AC|且|CD| > |CB|。
 *      那么|AC| + |CD| > |AC| + |CB|
 *      |AD| > |AB|
 *      这与直径的定义相悖。
 *      因此，与C距离最远的节点必定是A或B。
 *  情况3：C在AB外。
 *      令D为AB上与C最近的节点。
 *      D不可能为A或B。
 *      否则，A或B不是叶节点，与结论1相悖。
 *      假设C距离最远的节点不是A或B，而是E。
 *      那么|CE| > |AC| 且 |CE| > |BC|。
 *      情:3-1：E到AB要经过C。
 *          那么AE = AD-DC-CE，BE=BD-DC-CE。
 *          那么|CE| > |AD| + |DC| 且 |CE| > |BD| + |DC|。
 *          |AE| 
 *          = |AD| + |DC| + |CE| 
 *          > |AD| + |DC| + |BD| + |DC| 
 *          = |AB| + 2|DC|
 *          则|AE| > |AB|，与直径定义相悖。
 *      情况3-2：E到AB不经过C。
 *          令AB上距离E最近的点是F。
 *          F必定不是A或B。
 *          否则，A或B不是叶节点，与结论1相悖。
 *          F可能是D，即|DF| >= 0。
 *          情况3-2-1：假设F在BD上。
 *              |CE| > |CB|
 *              |CD| + |DF| + |FE| > |CD| + |DF| + |FB|
 *              那么，|DF| + |FE| > |DF| + |FB|
 *              |AD| + |DF| + |FE| > |AD| + |DF| + |FB|
 *              |AE| > |AB|
 *              这与直径的定义相悖。
 *          情况3-2-2：假设F在AD上。
 *              |CE| > |CA|
 *              |CD| + |DF| + |FE| > |CD| + |DF| + |FA|
 *              |DF| + |FE| > |DF| + |FA|
 *              |BD| + |DF| + |FE| > |BD| + |DF| + |FA|
 *              |BE| > |BA|
 *              这与定义相悖。
 *  综上所述，从任意一个结点出发，与其距离最远的节点必定是直径的一个端点。
 * 
 * 算法：
 * 1. 将图的表示从边的数组转化为邻接表。
 * 每一个节点的邻接列用哈希表保存。所有节点的邻接列用数组保存。
 * 这样，我们可以在O(1)时间内访问任意一个节点的邻接列，可以在O(n)时间内遍历任意一个节
 * 点的邻接列，可以在O(1)时间内判断任意两个节点是否邻接。
 * 2. 取任意一个节点i，用广搜找出离i最远的节点a。
 * 3. 用广搜找出离a最远的节点b。
 * 4. ab即是直径。
 ******************************************************************************/

class Solution
{
public:
    int treeDiameter(vector<vector<int>>& edges)
    {
        // Build a an adjacency list for the graph.
        // 建立邻接表。
        int m = edges.size(); // Number of edges.
        int n = edges.size() + 1; // Number of vertices.
        vector<unordered_set<int> > graph(n); // Adjacency list.
        int a, b; // Endpoints of an edge.
        for (int i = 0; i < m; i++)
        {
            a = edges[i][0];
            b = edges[i][1];
            graph[a].insert(b);
            graph[b].insert(a);
        }

        // Find the furthest node from node 0, and call it node a.
        // 找出离节点0最远的节点a。
        a = 0;
        int max = 0; // The longest distance from node 0. 距离节点0最远的距离。
        pair<int, int> curr; // Current node. 当前节点。
            // curr.first is the node index. curr.first是节点下标。
            // curr.second is the distance from node 0. curr.second是距离。
        queue<pair<int, int> >q; // Queue for BFS. 广搜队列。
        vector<bool> visited(n, false);
        q.push(pair<int, int>(0, 0));
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            visited[curr.first] = true;
            // Update the furthest node from node 0.
            // 更新距离节点0最远的节点。
            if (curr.second > max)
            {
                max = curr.second;
                a = curr.first;
            }
            for (auto i = graph[curr.first].begin(); i != graph[curr.first].end(); i++)
            {
                if (!visited[*i] && graph[curr.first].count(*i) > 0)
                {
                    q.push(pair<int, int>(*i, curr.second + 1));
                }
            }
        }

        // Find the furthest node from node a, and call it node b.
        // 找出离节点a最远的节点b。
        b = a;
        max = 0; // The longest distance from node a. 距离节点a最远的距离。
        visited.assign(n, false);
        q.push(pair<int, int>(a, 0));
        while(!q.empty())
        {
            curr = q.front();
            q.pop();
            visited[curr.first] = true;
            // Update the furthest node from node a.
            // 更新距离节点a最远的节点。
            if (curr.second > max)
            {
                max = curr.second;
                b = curr.first;
            }
            for (auto i = graph[curr.first].begin(); i != graph[curr.first].end(); i++)
            {
                if (!visited[*i] && graph[curr.first].count(*i) > 0)
                {
                    q.push(pair<int, int>(*i, curr.second + 1));
                }
            }
        }

        // ab is the longest path in the tree, i.e. the diameter.
        // 以ab作为直径。
        return max;
    }
};
