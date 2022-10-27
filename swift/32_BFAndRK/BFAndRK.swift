import UIKit

/// Class of non-official implementation of Rabin-Karp algorithm for string matching.
///
/// You can use this class to match any string format in a main string. This class offers three method to calculate hash value, including:
/// 1. Twenty-six Decimal hash function, but cannot process string that contains both numbers and characters and may cause integer overflow.
/// 2. Thirty-Six Decimal hash function, can process string that contains both numbers and characters, but may cause integer overflow.
/// 3. Thirty-Six Decimal hash function, can process string that contains both numbers and characters and No overflow will occur. Nonetheless, there may be a hash conflict in process which has been avoided.
///
/// See more in three hash functions' implementation.
public class RKAlgorithm
{
    var mainString:String = ""
    var matchString:String = ""
    var mainStringSize:Int { mainString.count }
    var matchSize:Int { matchString.count }
    /// computational property, to get the string array of main string and match string.
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
    lazy var hashValueOfMainString:[Int] = []
    lazy var hashValueOfMatchString:Int = 0
    lazy var mainStringASCII:[Int] = []
    lazy var matchStringASCII:[Int] = []
    lazy var powerSeries:[Int] = []
    
    /// Default init method, set main string and match string. All string will be lowercased automatically for convenient calculation.
    /// - Parameters:
    ///     - main: main string input.
    ///     - match: match string input.
    public init(main:String, match:String)
    {
        mainString = main.lowercased()
        matchString = match.lowercased()
    }
    
    /// The function calculating power series using a given decimal.
    /// - Parameters:
    ///     - baseOfPower: The base of power series to be given. Must be a decimal.
    public func calculatePowerSeries(baseOfPower:Decimal) -> Void
    {
        for m in (0 ..< matchString.count)
        {
            let powerValue = (pow(baseOfPower, m) as NSDecimalNumber).intValue
            powerSeries.append(powerValue)
        }
    }
    
    /// Twenty-six Decimal hash function, but cannot process string that contains both numbers and characters and may cause integer overflow if the match string is too long.
    open func hashFunctionWithoutNumber() -> Void
    {
        let ASCIIOf_a = "a".utf8.first!
        // n - m + 1
        let loopTime = mainStringSize - matchSize + 1
        hashValueOfMainString = Array<Int>(repeating: 0, count: loopTime)
        
        for offset in (0 ..< loopTime)
        {
            if offset == 0
            {
                for matchIndex in (0..<matchSize)
                {
                    hashValueOfMainString[offset] += Int(mainStringArray[matchIndex].utf8.first! - ASCIIOf_a) * powerSeries[matchSize-matchIndex-1]
                }
            }
            // Next hashvalue can be calculated by last hashvalue.
            else
            {
                hashValueOfMainString[offset] = (hashValueOfMainString[offset-1] - powerSeries[matchSize-1]*Int(mainStringArray[offset-1].utf8.first! - ASCIIOf_a)) * powerSeries[1]
                hashValueOfMainString[offset] += Int((mainStringArray[offset+matchSize-1].utf8.first! - ASCIIOf_a))
            }
        }
        for index in (0..<matchSize)
        {
            hashValueOfMatchString += Int(matchStringArray[index].utf8.first! - ASCIIOf_a) * powerSeries[matchSize-index-1]
        }
    }
    
    /// The mapping function. Mapping numbers and characters to 0~35, in order to using thirty-six decimal hash function.
    open func convertCharacterToASCII() -> Void
    {
        for char in mainString
        {
            // 87
            if char.utf8.first! > 96 && char.utf8.first! < 123
            {
                let mapping = Int(char.utf8.first! - 87)
                mainStringASCII.append(mapping)
            }
            else
            {
                let ASCIIOfNum = Int(char.utf8.first! - 48)
                mainStringASCII.append(ASCIIOfNum)
            }
        }
        for char in matchString
        {
            if char.utf8.first! > 96 && char.utf8.first! < 123
            {
                let mapping = Int(char.utf8.first! - 87)
                matchStringASCII.append(mapping)
            }
            else
            {
                let ASCIIOfNum = Int(char.utf8.first! - 48)
                matchStringASCII.append(ASCIIOfNum)
            }
        }
    }
    
    /// Thirty-Six Decimal hash function, can process string that contains both numbers and characters, but may cause integer overflow if the match string is too long.
    open func hashFunctionWithNumber() -> Void
    {
        self.convertCharacterToASCII()
        let loopTime = mainStringSize - matchSize + 1
        hashValueOfMainString = Array<Int>(repeating: 0, count: loopTime)
        for offset in (0 ..< loopTime)
        {
            if offset == 0
            {
                for matchIndex in (0..<matchSize)
                {
                    hashValueOfMainString[offset] += mainStringASCII[matchIndex] * powerSeries[matchSize-matchIndex-1]
                }
            }
            else
            {
                hashValueOfMainString[offset] = (hashValueOfMainString[offset-1] - powerSeries[matchSize-1] * mainStringASCII[offset-1]) * powerSeries[1]
                hashValueOfMainString[offset] += mainStringASCII[offset+matchSize-1]
            }
        }
        for index in (0..<matchSize)
        {
            hashValueOfMatchString += matchStringASCII[index] * powerSeries[matchSize-index-1]
        }
    }
    
    /// Thirty-Six Decimal hash function, can process string that contains both numbers and characters and integer overflow will not occur. Nonetheless, there may be a hash conflict in process which has been avoided.
    open func simpleHashFunction() -> Void
    {
        self.convertCharacterToASCII()
        let loopTime = mainStringSize - matchSize + 1
        hashValueOfMainString = Array<Int>(repeating: 0, count: loopTime)
        for offset in (0 ..< loopTime)
        {
            for index in (offset ..< (offset+matchSize))
            {
                hashValueOfMainString[offset] += mainStringASCII[index]
            }
        }
        for index in (0..<matchSize)
        {
            hashValueOfMatchString += matchStringASCII[index]
        }
    }
    
    /// Match with main string and match string.
    /// - Returns: A tuple contains start and end indexes of match string in main string.
    public func matchWithHashValue() -> (Int?, Int?)
    {
        // Just like brute force.
        for i in hashValueOfMainString.indices
        {
            if hashValueOfMainString[i] == hashValueOfMatchString
            {
                var tempArray:[Character] = []
                for index in (i ..< (i+matchSize))
                {
                    tempArray.append(mainStringArray[index])
                }
                if tempArray == matchStringArray
                {
                    print("Found match string in main string.")
                    print("From index \(i), to index \(i + matchString.count - 1) in main string.")
                    return (startIndex:i, endIndex:i + matchString.count - 1)
                }
                // if hash confict occurred, continue search next hash value in array because there may be match string behind.
                // just like: mainString: bad12Def12, matchSting: 12d
                else
                {
                    print("Not match, and there is a hash confict occurred.")
                    print("Now checking strings behind...")
                    continue
                }
            }
        }
        print("Not find match string.")
        return (nil, nil)
    }
}

func mainTest()
{
    let RK = RKAlgorithm(main:"bad12Def12", match:"12d")
    // change baseOfPower according to the hash function you use.
    RK.calculatePowerSeries(baseOfPower: 36)
    //RK.simpleHashFunction()
    RK.hashFunctionWithNumber()    // baseOfPower: 36
    //RK.hashFunctionWithoutNumber() // baseOfPower: 26
    
    RK.matchWithHashValue()
}

mainTest()
