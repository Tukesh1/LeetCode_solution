class Solution {
public:
    bool canBeValid(string s, string locked) {
        stack<int> open, flexi;
        int n = s.length();
        if(n%2 == 1)
        {
            return false;
        }
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '(' && locked[i] == '1')
            {
                open.push(i);
            }
            else if(s[i] ==')' && locked[i] == '1')
            {
                if(!open.empty())
                {
                    open.pop();
                }
                else if(!flexi.empty())
                {
                    flexi.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                flexi.push(i);
            }
        }

        while(!open.empty() && !flexi.empty() && flexi.top() > open.top())
        {
            open.pop();
            flexi.pop();
        }

        return open.empty();
    }
};