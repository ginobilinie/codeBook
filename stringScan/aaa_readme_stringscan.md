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

5. BasicCalculatorII.cpp: 
Problem: 输入一个string，有可能有+-\*/以及括号。写一个计算器函数。
Solution: 1. op记录着上一个operation，我们可以在式子左边假设一个0+...，所以op开场是'+'
          2. 每次遇到s[i]是+-/ or \*，我们处理用op去处理右边的元素，到了最后一个元素的时候，我们用当前存留的op去处理就行。也就是n-1个op处理n个item，然后记得去用s[i]去更新op.
        3. 遇到(，go through直到遇到平衡后的)(也就是要记录左右括号数量，要平衡)，然后调用递归算法。
        这种方法，不用stack，不用queue。但是这种方法设计非常巧妙，我们需要先处理num以及()，最后时刻处理+ - \* / 以及最后一个字符。同时有意不处理空格。
        
6. minWindow.cpp: Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
Solution: 从左边往右边扫描。设计一个num记录cover T中字符个数，设计一个hash来记录哪些元素被cover了。当某一个substring能够cover所有T时，我们从左边开始缩减这个substring里不必要的chars，然后拿这个substring去比历史最短。。

7. lengthOfLongestSubstringTwoDistinct_faster.cpp: Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
Solution: 从左往右扫描string，用一个全局map记录当前字符，如果map.size大于2，从记录的left元素开始减去map里的元素，如果某个元素为0了，将该元素从map里去掉。当然，每次记录下当前最大长度。该算法完美用到K个distinct chars上面去。
