namespace algo08_stack
{
    /// <summary>
    /// 利用链栈实现浏览器怎么进后退
    /// </summary>
    public class LinkedStackBrowser
    {
        private readonly LinkedStack<string> _backStack = new LinkedStack<string>();
        private readonly LinkedStack<string> _forwardStack = new LinkedStack<string>();

        public void Open(string url)
        {
            _backStack.Push(url);

            _forwardStack.Clear();
        }

        public string Backward()
        {
            if (_backStack.Count == 0) return string.Empty;

            string url = _backStack.Pop();

            _forwardStack.Push(url);

            return url;
        }

        public string Forward()
        {
            if (_forwardStack.Count == 0) return string.Empty;

            string url = _forwardStack.Pop();
            _backStack.Push(url);

            return url;
        }
    }
}