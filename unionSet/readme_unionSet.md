1. numIslands.cpp: We need to find the number of independent connected components. The problem is that it is a 2d matrix, but union-set is mostly
work in 1d vector, so we create a row*col parent vector to represent it. To find those in the same connected components, we just need to scan
the 2d matrix, and for the current positive item, we have to union the neighboring positive items.
