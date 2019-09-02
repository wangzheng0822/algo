/**
 * 使用前后栈实现浏览器的前进后退。
 * 
 * Author nameczz
 */
const stack = require('./StackBasedOnLinkedList')

class SampleBrowser {
    constructor() {
        this.normalStack = new stack.CreatedStack()
        this.backStack = new stack.CreatedStack()
    }
    // 正常浏览页面
    pushNormal(name) {
        this.normalStack.push(name)
        this.backStack.clear()
        this.displayAllStack()
    }
    // 后退
    back() {
        const value = this.normalStack.pop()
        if (value !== -1) {
            this.backStack.push(value)
            this.displayAllStack()
        } else {
            console.log('无法后退')
        }
    }
    // 前进
    front() {
        const value = this.backStack.pop()
        if (value !== -1) {
            this.normalStack.push(value)
            this.displayAllStack()
        } else {
            console.log('无法前进')
        }
    }
    // 打印栈内数据
    displayAllStack() {
        console.log('---后退页面---')
        this.backStack.display()
        console.log('---浏览页面---')
        this.normalStack.display()
    }
}
// Test
const browser = new SampleBrowser()
browser.pushNormal('www.google.com')
browser.pushNormal('www.baidu.com')
browser.pushNormal('www.github.com')
// 后退
browser.back()
browser.back()
browser.front()
browser.pushNormal('www.new.com')