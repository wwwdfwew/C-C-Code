class Solution{
public:
    int evalRPN(vector<string>&tokens) {
        stack<int> st;
      for (auto& str : tokens)//遇到比较大的数据的最好加引用，防止多次的拷贝构造
      {
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            int right = st.top();
            st.pop();
            int left = st.top();
            st.pop();//这里取出两个操作数别忘了每次出栈，不然就会出错。
            switch (str[0])//这里用str[0]是为了让switch能够进行，因为这里接收的必须是常性表达式，这里得到的是单个字符
            {
                case '+':
                st.push(left + right);
                break;
                 case '-':
                st.push(left - right);
                break;
                 case '*':
                st.push(left * right);
                break;
                 case '/':
                st.push(left / right);
                break;
            }
        }
        else
        {
            st.push(stoi(str));
        }
      }
      return st.top();
    }
};