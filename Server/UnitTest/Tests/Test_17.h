#ifndef Test_17_h__
#define Test_17_h__
/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
注意空字符串可被认为是有效字符串。
示例 1:
	输入: "()"
	输出: true
示例 2:
	输入: "()[]{}"
	输出: true
示例 3:
	输入: "(]"
	输出: false
示例 4:
	输入: "([)]"
	输出: false
示例 5:
	输入: "{[]}"
	输出: true
*/
#include "Solution.h"
class Test_17 : public Solution 
{
public:
	void Excute() 
	{
		string s = "((";
		bool result = isValid(s);
	}

	bool isValid(string s) 
	{
		if (s.empty()) return true;
		if (s.size() % 2 != 0) return false;
		std::stack<char> lefts;
		for (int i =0; i < s.size(); ++i) 
		{
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') 
			{
				lefts.push(s[i]);
			}
			else 
			{
				if (lefts.size() == 0 && (s[i] == '}' || s[i] == ']' || s[i] == ')')) 
				{
					return false;
				}
				if ((lefts.top() == '{' && s[i] == '}') || (lefts.top() == '[' && s[i] == ']') || (lefts.top() == '(' && s[i] == ')')) 
				{
					lefts.pop();
				}
				else 
				{
					return false;
				}
			}
		}
		return lefts.size() == 0;
	}
};
#endif // Test_17_h__
