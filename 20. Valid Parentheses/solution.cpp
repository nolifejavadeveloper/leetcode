class Solution {
public:
    bool isValid(string s) {
        stack<char> order;
        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') {
                order.push(c == '(' ? c + 1 : c + 2);
            }else {
                // removee
                if (!order.empty() && c == order.top()) {
                    order.pop();
                }else {
                    return false;
                }
            }
        }

        return order.empty();
    }
};
