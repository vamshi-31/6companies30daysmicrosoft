class Solution {
public:
    int evalRPN(vector<string>& tokens) { 
    std::stack<int> stack;
    for (const std::string& token : tokens) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int right = stack.top();
            stack.pop();
            int left = stack.top();
            stack.pop();
            int result;
            if (token == "+") {
                result = left + right;
            } else if (token == "-") {
                result = left - right;
            } else if (token == "*") {
                result = left * right;
            } else {
                result = left / right;
            }
            stack.push(result);
        } else {
            stack.push(std::stoi(token));
        }
    }
    return stack.top();
}
};