package ch08_stack

import org.scalatest.{FlatSpec, Matchers}

class BrowserDemoTest extends FlatSpec with Matchers {

  behavior of "BrowserDemoTest"

  it should "canGoBack" in {
    val browser = new BrowserDemo()
    assert(!browser.canGoBack())
    browser.open("a")
    assert(!browser.canGoBack())
    browser.open("b")
    assert(browser.canGoBack())
    browser.currentPageOpt.get should equal("b")
  }

  it should "goBack" in {
    val browser = new BrowserDemo()
    browser.open("a")
    browser.open("b")
    browser.currentPageOpt.get should equal("b")
    assert(browser.canGoBack())
    browser.goBack()
    assert(!browser.canGoBack())
    browser.currentPageOpt.get should equal("a")
  }

  it should "canGoForward" in {
    val browser = new BrowserDemo()
    browser.open("a")
    browser.open("b")
    browser.currentPageOpt.get should equal("b")
    assert(browser.canGoBack())
    browser.goBack()
    assert(!browser.canGoBack())
    browser.currentPageOpt.get should equal("a")
    assert(browser.canGoForward())
  }

  it should "goForward" in {
    val browser = new BrowserDemo()
    browser.open("a")
    browser.open("b")
    browser.currentPageOpt.get should equal("b")
    assert(browser.canGoBack())
    browser.goBack()
    assert(!browser.canGoBack())
    browser.currentPageOpt.get should equal("a")
    assert(browser.canGoForward())
    browser.goForward()
    browser.currentPageOpt.get should equal("b")
  }

  it should "open new page to clear forward stack" in {
    val browser = new BrowserDemo()
    browser.open("a")
    browser.open("b")
    browser.currentPageOpt.get should equal("b")
    assert(browser.canGoBack())
    browser.goBack()
    assert(!browser.canGoBack())
    browser.currentPageOpt.get should equal("a")
    assert(browser.canGoForward())
    browser.open("c")
    assert(!browser.canGoForward())
    browser.goBack()
    browser.currentPageOpt.get should equal("a")
  }



}
