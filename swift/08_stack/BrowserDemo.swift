//
// Created by Jiandan on 2018/10/12.
// Copyright (c) 2018 Jiandan. All rights reserved.
//

import Foundation

struct Page {
    /// 存储前进 url
    private var forwardArray = [String]()
    /// 存储后退 url
    private var backArray = [String]()
    
    var currentURL: String { return forwardArray.last! }

    init(url: String) {
        forwardArray.append(url)
    }
    /// 前进
    mutating func goForward(url: String) {
        forwardArray.append(url)
    }
    /// 后退
    mutating func goBack() {
        backArray.append(forwardArray.popLast()!)
    }
}
