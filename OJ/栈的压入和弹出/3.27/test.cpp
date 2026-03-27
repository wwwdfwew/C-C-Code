bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
    // write code here
    stack<int> st;
    int pushVi = 0;
    int popVi = 0;
    while (pushVi < pushV.size())
    {
        st.push(pushV[pushVi++]);
        while (!st.empty() && st.top() == popV[popVi])//只要栈不为空并且栈顶元素等于要出的元素，则弹出栈。
        {
            st.pop();
            popVi++;
        }
    }
    return st.empty();
}