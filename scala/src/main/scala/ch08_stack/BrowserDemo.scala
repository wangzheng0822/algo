package ch08_stack

class BrowserDemo(var currentPageOpt: Option[String], val backStack: StackDemo[String],
                  val forwardStack: StackDemo[String]) {

  def this() = this(None, new StackDemo[String], new StackDemo[String])

  def open(page: String) = {
    currentPageOpt.foreach(backStack.push)
    forwardStack.clear()
    currentPageOpt = Some(page)
  }

  def canGoBack(): Boolean = backStack.size > 0

  def goBack(): Unit = {
    backStack.pop().foreach(page => {
      forwardStack.push(currentPageOpt.get)
      currentPageOpt = Some(page.data)
    })
  }

  def canGoForward(): Boolean = forwardStack.size > 0

  def goForward(): Unit = {
    forwardStack.pop().foreach(page => {
      backStack.push(currentPageOpt.get)
      currentPageOpt = Some(page.data)
    })
  }
}
