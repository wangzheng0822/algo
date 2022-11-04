import UIKit

/// Class of a simple impletation of Boyer-Moore algorithm for string matching.
///
/// You can use this class to match any string format in a main string. BM algorithm contains two principles to match a string, which are bad character principle and good suffix principle. The algorithm will choose one of them by specific case automatically. To be noticed, it can ONLY process NOT more than 256 character kind in a set using ASCII.
///
/// See more in these functions' implementation below.
public class BMAlgorithm
{
    let badCharAsciiTableSize = 256
    var mainString:String = ""
    var matchString:String = ""
    var mainStringSize:Int { mainString.count }
    var matchStringSize:Int { matchString.count }
    lazy var badCharTable = Array<Int>(repeating: -1, count: badCharAsciiTableSize)
    lazy var suffix = Array<Int>(repeating: -1, count: matchStringSize)
    lazy var prefix = Array<Bool>(repeating: false, count: matchStringSize)
    /// Get the string array of main string and match string because of the inconvenience of native string process in Swift.
    public var mainStringArray:[Character]
    {
        var tempArray:[Character] = []
        for i in mainString
        {
            tempArray.append(i)
        }
        return tempArray
    }
    public var matchStringArray:[Character]
    {
        var tempArray:[Character] = []
        for i in matchString
        {
            tempArray.append(i)
        }
        return tempArray
    }
    /// Default init method, set main string and match string.
    /// - Parameters:
    ///     - main: main string input.
    ///     - match: match string input.
    init(main:String, match:String)
    {
        mainString = main
        matchString = match
    }
    /// Function that generate ASCII table of 256 kinds of characters.
    public func generateAsciiTable() -> Void
    {
        for index in (0 ..< matchStringSize)
        {
            let asciiValue = Int(matchStringArray[index].utf8.first!)
            badCharTable[asciiValue] = index
        }
    }
    
    /// Function that prepare the suffix array and prefix array in process. These two arrays are very important to the algorithm.
    open func prepareSuffixAndPrefix() -> Void
    {
        // 求模式串和主串的公共后缀字串，这样可以得到模式串中第一次出现好后缀的起始下标，以及出现模式串前缀和主串后缀匹配的情况，做法非常巧妙。
        // 有几个字串就循环几次
        for substringSize in (0 ..< matchStringSize-1)
        {
            var lastCharIndex = substringSize
            var publicSubfixSize = 0
            // 求模式串子串与模式串之间的公共子串，得到第一次出现好后缀的起始下标。
            while lastCharIndex >= 0 && matchStringArray[lastCharIndex] == matchStringArray[matchStringSize-1-lastCharIndex]
            {
                // 如果相等，则说明后缀匹配成功一个字符，size+1，两个指针同时向前一个字符
                publicSubfixSize += 1
                // 使用后缀长度来记录suffix数组的值，值即为此后缀最后出现的index
                suffix[publicSubfixSize] = lastCharIndex
                lastCharIndex -= 1
            }
            // 如果一直能够匹配到子串的第一个字符，则说明该后缀也是模式串的前缀
            if lastCharIndex == -1
            {
                prefix[publicSubfixSize] = true
            }
        }
    }
    /// Calculate the move steps of next match using good suffix principle.
    /// - Parameters:
    ///     - index: The index of bad character in match string.
    /// - Returns:
    ///     The steps of match index will move in next match.
    open func moveMatchString(badCharacterIndex index:Int) -> Int
    {
        // 好后缀的长度，可以使用坏字符的index和模式串的长度计算出
        let goodSuffixSize = matchStringSize - 1 - index
        // 查找好后缀在suffix是否有值，如果有，则说明前面出现过好后缀，需要将字符串移动到好后缀最后一次出现的地方
        if suffix[goodSuffixSize] != -1
        {
            return index - suffix[goodSuffixSize] + 1
        }
        // 如果没有好后缀，则需要查找是否有好后缀的子后缀，子后缀从坏字符的后两个字符开始
        for suffixOfGoodSufIndex in (index+2 ..< matchStringSize)
        {
            // 如果找到了好后缀的子后缀，则将其移动
            if prefix[matchStringSize-suffixOfGoodSufIndex] == true
            {
                return suffixOfGoodSufIndex
            }
        }
        return matchStringSize
    }
    /// Main function of BM algorithm. This method invokes other methods which are necessary. First generate ASCII table of 256 characters, then prepare suffix and prefix that will use. After that, using bad character principle to match. Also, if there is a good suffix, using good suffix principle too. Finally, choose the max steps that two principles get above to perform next match.
    /// - Returns:
    ///     The start match index in main string. If not matched, it will return `nil` instead.
    open func Boyer_Moore() -> Int?
    {
        self.generateAsciiTable()
        self.prepareSuffixAndPrefix()
        var matchIndex = 0
        var badCharForward = 0, goodSuffixForward = 0
        // 下面的循环用来寻找坏字符出现的位置
        while matchIndex < (mainStringSize - matchStringSize + 1)
        {
            // 初始值为-1，表示没有坏字符
            var badCharIndex = -1
            for index in (0..<matchStringSize).reversed()
            {
                if mainStringArray[matchIndex+index] != matchStringArray[index]
                {
                    badCharIndex = index
                    break
                }
            }
            // 经过上方的寻找之后如果还是-1，则说明已经匹配，没有坏字符
            if badCharIndex < 0
            {
                print("Find match string.")
                print("From index \(matchIndex), to index \(matchIndex + matchStringSize - 1) in main string.")
                return matchIndex
            }
            // 坏字符原则计算得到的向前移动的步数
            badCharForward = badCharIndex - badCharTable[Int(mainStringArray[matchIndex+badCharIndex].utf8.first!)]
            // 好后缀原则计算得到的向前移动的步数
            if badCharIndex < matchStringSize - 1
            {
                goodSuffixForward = self.moveMatchString(badCharacterIndex: badCharIndex)
            }
            // 在上述二者之间取最大值，来确定要移动的步数
            matchIndex += max(badCharForward, goodSuffixForward)
        }
        print("Not find match string in main string.")
        return nil
    }
}

func mainTest()
{
    let BM = BMAlgorithm(main:"qwe321wwaaa&*12", match:"a&*1")
    BM.Boyer_Moore()
}

mainTest()
