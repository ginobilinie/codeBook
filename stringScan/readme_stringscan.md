1. reorganizeString.cpp: Problem: Given a string S, check if the letters can be rearranged so that two characters that are adjacent to 
each other are not the same. If possible, output any possible result.  If not possible, return the empty string.
My solution: we first use a unordered_map<char,int> to store the chars with their frequency. If one char appears more than (len+1)/2, then it
means we cannot make it. Otherwise, we can choose the most frequency char and the 2nd most frequency char. To do it, we use a set<pair<int,char>>
to restore the items in the unordered_map. And if the set.size is larger than 2, we just choose the first two (of course, we should erase the
first one and then obtain the second one. Here is a important point, when we erase iterator, it will destroy the iterator itself, so I use
a pair type to store it), and then finish the current string organization, and reinsert the two items into the set if their frequency is still 
bigger than 0.

2. alienOrder.cpp: 
Problem: given a list of sorted words (the relationship between these words are sorted, instead of chars in the word), and we need to find the correct char-level order.
Solution: First use neighboring words to build a char order graph (unordered_map<char,vector<char>>, then build a indegree array (unordered_map<char,int>) and develop the topological sorting.
