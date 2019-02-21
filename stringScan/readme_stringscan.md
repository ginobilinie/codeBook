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
  
3. BasicCalculator.cpp: Problem: Implement a basic calculator to evaluate a simple expression string. The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces.
My solution: use signstack to store the sign and valuestack to store the left value when we encounter the '(', reinitialize res and sign. when we encouter ')', we just pop the stack top and update the res with the top sign and top history value. In other cases, we donot need to use the stack.

4. BasicCalculatorII.cpp: 
Problem: Implement a basic calculator to evaluate a simple expression string. The expression string contains only non-negative integers, +, -, \*, \/ operators and empty spaces . The integer division should truncate toward zero.
Solution: Use two queues (signqueue and valqueue) to store the sign and value. When we encouter + or -, we just input to the queue, and when we encoutner a number, then we just check what's current sign is, if + or -, we push into the queue, if * or /, we just do the operation. In the end, we just scan the queue and do the '+' or '-' operations. 
