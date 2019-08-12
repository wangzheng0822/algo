mod stack_based_on_linked_list;

use stack_based_on_linked_list::{LinkedListStack};

#[derive(Hash, Eq, PartialEq, Debug, Default, Clone)]
struct Browser {
    forward_stack: LinkedListStack,
    back_stack: LinkedListStack,
    current_page: String,
}

impl Browser {
    fn new() -> Self {
        Default::default()
    }

    fn open(&mut self, url: &String) {
        if !self.current_page.is_empty() {
            self.back_stack.push(self.current_page.clone());
            self.forward_stack.clear();
        }
        self.show_url(&url, "Open".to_string());
    }

    fn go_back(&mut self) -> String {
        if self.can_go_back() {
            self.forward_stack.push(self.current_page.clone());
            let back_url = self.back_stack.pop();
            self.show_url(&back_url, "Back".to_string());
            return back_url;
        }

        println!("Can not go back, there is no page behind.");
        "-1".to_string()
    }

    fn go_forward(&mut self) -> String {
        if self.can_go_forward() {
            self.back_stack.push(self.current_page.clone());
            let forward_url = self.forward_stack.pop();
            self.show_url(&forward_url, "Forward".to_string());
            return forward_url;
        }

        println!("Can not go forward, there is no page behind.");
        "-1".to_string()
    }

    fn can_go_back(&self) -> bool {
        !self.back_stack.is_empty()
    }

    fn can_go_forward(&self) -> bool {
        !self.forward_stack.is_empty()
    }

    fn show_url(&mut self, url: &String, prefix: String) {
        self.current_page = url.to_string();
        println!("{:?} page == {:?}", prefix, url);
    }

    fn check_current_page(&self) {
        println!("current page == {:?}", self.current_page);
    }
}
fn main() {
    let mut browser = Browser::new();
    browser.open(&"http://www.baidu.com".to_string());
    browser.open(&"http://news.baidu.com/".to_string());
    browser.open(&"http://news.baidu.com/ent".to_string());
    browser.go_back();
    browser.go_back();
    browser.go_forward();
    browser.open(&"http://www.qq.com".to_string());
    browser.go_forward();
    browser.go_back();
    browser.go_forward();
    browser.go_back();
    browser.go_back();
    browser.go_back();
    browser.go_back();
    browser.check_current_page();
}
