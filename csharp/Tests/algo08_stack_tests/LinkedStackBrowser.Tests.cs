using algo08_stack;
using Xunit;
using Xunit.Abstractions;

namespace algo08_stack_tests
{
    public class LinkedStackBrowserTests
    {
        private readonly ITestOutputHelper _output;

        public LinkedStackBrowserTests(ITestOutputHelper output)
        {
            _output = output;
        }

        [Fact]
        public void Browser_Open_4_Links_Back_2_Return_Right_Link()
        {
            var browser = new LinkedStackBrowser();
            browser.Open("www.google.com");
            browser.Open("www.baidu.com");
            browser.Open("www.qq.com");
            browser.Open("www.dadu.com");

            string url = browser.Backward();
            url = browser.Backward();

            Assert.Equal("www.qq.com", url);
        }

        [Fact]
        public void Browser_Open_4_Links_Back_4_Return_Empty()
        {
            var browser = new LinkedStackBrowser();
            browser.Open("www.google.com");
            browser.Open("www.baidu.com");
            browser.Open("www.qq.com");
            browser.Open("www.dadu.com");

            browser.Backward();
            browser.Backward();
            browser.Backward();
            browser.Backward();
            string url = browser.Backward();

            Assert.Equal(string.Empty, url);
        }

        [Fact]
        public void Browser_Forward_Before_End()
        {
            var browser = new LinkedStackBrowser();
            browser.Open("www.google.com");
            browser.Open("www.baidu.com");
            browser.Open("www.qq.com");
            browser.Open("www.dadu.com");

            browser.Backward();
            browser.Backward();
            browser.Backward();

            browser.Forward();
            string url = browser.Forward();

            Assert.Equal("www.qq.com", url);
        }

        [Fact]
        public void Browser_Forward_Until_End()
        {
            var browser = new LinkedStackBrowser();
            browser.Open("www.google.com");
            browser.Open("www.baidu.com");
            browser.Open("www.qq.com");
            browser.Open("www.dadu.com");

            browser.Backward();
            browser.Backward();
            browser.Backward();

            browser.Forward();
            browser.Forward();
            browser.Forward();
            string url = browser.Forward();

            Assert.Equal(string.Empty, url);
        }

        [Fact]
        public void Browser_Backward_And_Open_New_Then_Cannot_Forward()
        {
            var browser = new LinkedStackBrowser();
            browser.Open("www.google.com");
            browser.Open("www.baidu.com");
            browser.Open("www.qq.com");

            browser.Backward();
            browser.Backward();
            
            browser.Open("www.dadu.com");

            string url = browser.Forward();

            Assert.Equal(string.Empty, url);
        }
    }
}