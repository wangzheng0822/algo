//
//  SortsTests.swift
//  SortsTests
//
//  Created by Wenru Dong on 2018/10/14.
//  Copyright © 2018年 Wenru Dong. All rights reserved.
//

import XCTest

class SortsTests: XCTestCase {
    
    override func setUp() {
        super.setUp()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testMergeSort() {
        var a1 = [1, 1, 1, 1]
        mergeSort(&a1)
        XCTAssertEqual(a1, [1, 1, 1, 1])
        
        var a2 = [4, 3, 2, 1]
        mergeSort(&a2)
        XCTAssertEqual(a2, [1, 2, 3, 4])
        
        var a3 = [3, 6, 9, 7, 8, -1, 9, 3, -2, 0]
        mergeSort(&a3)
        XCTAssertEqual(a3, [-2, -1, 0, 3, 3, 6, 7, 8, 9, 9])
    }
    
    func testQuickSort() {
        var a1 = [1, 1, 1, 1]
        quickSort(&a1)
        XCTAssertEqual(a1, [1, 1, 1, 1])
        
        var a2 = [4, 3, 2, 1]
        quickSort(&a2)
        XCTAssertEqual(a2, [1, 2, 3, 4])
        
        var a3 = [3, 6, 9, 7, 8, -1, 9, 3, -2, 0]
        quickSort(&a3)
        XCTAssertEqual(a3, [-2, -1, 0, 3, 3, 6, 7, 8, 9, 9])
    }
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measure the time of here.
        }
    }
    
}
