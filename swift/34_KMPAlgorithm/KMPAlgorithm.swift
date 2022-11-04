import UIKit

/// Class of a simple implementation of Knuth-Morris-Pratt algorithm for string matching.
///
/// You can use this class to match any string format in a main string. What is the most important method is failure function, which is very hard to understand.
///
/// See more in these methods' implementation below.
open class KMPAlgorithm
{
    var mainString:String = ""
    var matchString:String = ""
    open var mainStringSize:Int { mainString.count }
    open var matchStringSize:Int { matchString.count }
    /// Invert string to array using closure. If using closure, it must be declared as lazy var, because closure is using other properties to set a new property, which is not allowed in swift initialization stage. Using lazy will not access other properties until new property is used.
    lazy var mainStringArray:[Character] =
    {
        var tempArray:[Character] = []
        for char in mainString
        {
            tempArray.append(char)
        }
        return tempArray
    }() // Invoke this closure immediately, must have "()" after closure, otherwise it will be reconginzed as a compute property.
    
    lazy var matchStringArray:[Character] =
    {
        var tempArray:[Character] = []
        for char in matchString
        {
            tempArray.append(char)
        }
        return tempArray
    }()
    
    lazy var nextArray = [Int](repeating: -1, count: matchStringSize)
    /// Default initializtion method of class KMP.
    /// - Parameters:
    ///     - main: main string input.
    ///     - match: match string input.
    init(main:String, match:String)
    {
        mainString = main
        matchString = match
    }
    /// Failure function of KMP algorithm.
    /// - Returns: A array contains longest match preifx's index.
    private func faliureFunction() -> [Int]
    {
        var index = -1
        for i in (1..<matchStringSize)
        {
            while index != -1 && matchStringArray[index+1] != matchStringArray[index]
            {
                index = nextArray[index]
            }
            if matchStringArray[index+1] == matchStringArray[i]
            {
                index += 1
            }
            nextArray[i] = index
        }
        return nextArray
    }
    /// Main method of KMP. First it invoke instance method `failureFunction()` to calculate failure function, then use it to match string.
    open func Knuth_Morris_Pratt() -> Void
    {
        nextArray = self.faliureFunction()
        var badCharIndex = 0
        for mainIndex in mainStringArray.indices
        {
            while badCharIndex > 0 && mainStringArray[mainIndex] != matchStringArray[badCharIndex]
            {
                badCharIndex = nextArray[badCharIndex - 1] + 1
            }
            if mainStringArray[mainIndex] == matchStringArray[badCharIndex]
            {
                badCharIndex += 1
            }
            if badCharIndex == matchStringSize
            {
                print("Find match string in main string.")
                print("From index \(mainIndex - matchStringSize + 1), to index \(mainIndex) in main string.")
                return
            }
        }
        print("Not found match string.")
    }
}

func mainTest()
{
    let kmp = KMPAlgorithm(main:"qwe321wwaaa&*12", match:"a&*1")
    kmp.Knuth_Morris_Pratt()
}

mainTest()
