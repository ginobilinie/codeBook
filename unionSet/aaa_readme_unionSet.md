1. numIslands.cpp: We need to find the number of independent connected components. The problem is that it is a 2d matrix, but union-set is mostly
work in 1d vector, so we create a row*col parent vector to represent it. To find those in the same connected components, we just need to scan
the 2d matrix, and for the current positive item, we have to union the neighboring positive items.

2. numIslands.\_rewrite.cpp: let's use union find to solve this problem
      The main problem is that grid is a 2D MATRIX, how can we use 1d vector to represent 
      the parent of each node? We can use rows*cols+1 based vector to represent each item.
      A next question: how we determine the parent-child relationship, in other words, how we know
      they are in a same group? We can check 4 directions, if one point is neighouring to the current visited 
      point, then we make a union operation
