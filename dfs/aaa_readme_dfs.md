1. numIslands.cpp: use dfs to label the connected independent components, and then just count the number of such components.
2. maxAreaOfIsland.cpp: we just use a dfs to search the maximum number of islands with used matrix.

3. maze1.cpp: a rolling ball which will not stop until it hits a wall, which means it will go through a direction and only can change direction after it hits a wall. Note the problem asks if the ball can stop at the destination point. https://leetcode.com/problems/the-maze/
solution: similar with the ordinary maze problem which only work one step at each time, we replace the if to while for next step condition judge. And use another if to check if the new step has been visited or not.
