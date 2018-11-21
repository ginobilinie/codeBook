#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include<sstream>
using namespace std;
 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* headL1 = l1;
        ListNode* headL2 = l2;
        ListNode* newL;
        
        while(l1 && l2)
        {    
			int currSum = l1->val + l2->val;
            if (l1->next)
                l1->next->val = l1->next->val + currSum/10;
            else if (l2->next)
            {
                l2->next->val = l2->next->val + currSum/10;
            }
            else
            {
                if (currSum>=10)
                {
                    ListNode* newNode = new ListNode(0);
                    newNode->val = currSum/10;
                    newNode->next = NULL;
                    l1->next = newNode;
                }
            }

	        l1->val = currSum%10;
            l2->val = currSum%10;

            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1)
        {
            while(l1)
            {
                if ((l1->val)/10>0)
                {
                    if (l1->next)
                        l1->next->val  = l1->next->val + (l1->val)/10; 
                    else
                    {
                        ListNode* newNode = new ListNode(0);
                        newNode->val = (l1->val)/10;
                        newNode->next = NULL;
                        l1->next = newNode;
                    }
					l1->val = (l1->val)%10;
                }
                l1 = l1->next;
            }
            newL = headL1;
        }
		else if (l2)
        {
            while(l2)
            {
                if ((l2->val)/10>0)
                {
					if (l2->next)
                        l2->next->val = l2->next->val + l2->val/10; 
                    else
                    {
                        ListNode* newNode = new ListNode(0);
                        newNode->val = (l2->val)/10;
                        newNode->next = NULL;
                        l2->next = newNode;
                    }
					l2->val = (l2->val)%10;
                }
                l2 = l2->next;
            }
            newL = headL2;
        }
		else
			newL = headL1;

        return newL;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    //for(int item : list) {
	for (int i=0; i< list.size();i++)
	{
		int item = list[i];
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {

		stringstream ss;
		ss << node->val;
		string str = ss.str();

        //result += std::to_string((int)node->val) + ", ";
		result += str + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        ListNode* l1 = stringToListNode(line);
        getline(cin, line);
        ListNode* l2 = stringToListNode(line);
        
        ListNode* ret = Solution().addTwoNumbers(l1, l2);

        string out = listNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}
