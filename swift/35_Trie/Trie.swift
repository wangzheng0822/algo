import UIKit

/// Class of TrieNode, a simple data structure in Trie that contains node data, children array and a symbol marking the end of a string.
class TrieNode
{
    var nodeData:Character?
    lazy var nextNodeArray = [TrieNode?](repeating: nil, count: 26)
    var isEndingChar = false
    /// Default init method of class TrieNode. Use it to create a new node for Trie.
    /// - Parameters:
    ///     - nextCharacter: A character of pattern string when visiting it from start to end.
    init(nextCharacter:Character?)
    {
        nodeData = nextCharacter
    }
}

 /// Class of simple implementation of Trie. This class has two methods for inserting a new string to Trie, and finding a present string in Trie. First you need to insert all string to make a string set. Then invoke find method to search the string you are interested in.
class Trie
{
    let rootNode = TrieNode(nextCharacter: nil)
    /// Insert a new string to Trie.
    /// - Paramrters:
    ///     - newString: The string you want to insert.
    func insertStringToTrie(newString:String) -> Void
    {
        var node = rootNode
        for index in newString.indices
        {
            let ascii = Int(newString[index].utf8.first!) - 97
            if node.nextNodeArray[ascii] == nil
            {
                let newNode = TrieNode(nextCharacter: newString[index])
                node.nextNodeArray[ascii] = newNode
            }
            node = node.nextNodeArray[ascii]!
        }
        node.isEndingChar = true
    }
    /// Find the pattern string in Trie.
    /// - Parameters:
    ///     - pattern: The pattern string you wish to be found.
    /// - Returns: A bool value which means whether the pattern is found in Trie. If found, returns `true`, otherwise returns `false`.
    func findStringInTrie(toBeFind pattern:String) -> Bool
    {
        var node = rootNode
        for index in pattern.indices
        {
            let ascii = Int(pattern[index].utf8.first!) - 97
            if let tempNode = node.nextNodeArray[ascii]
            {
                node = tempNode
            }
            else
            {
                print("Pattern string is not in Trie.")
                return node.isEndingChar
            }
        }
        node.isEndingChar ? print("Found pattern string in Trie.") : print("Pattern string is a prefix of some string that contains \"\(pattern)\". Not exactly found.")
        return node.isEndingChar
    }
}

func mainTest()
{
    let trie = Trie()
    trie.insertStringToTrie(newString: "hello")
    trie.insertStringToTrie(newString: "else")
    trie.insertStringToTrie(newString: "he")
    
    trie.findStringInTrie(toBeFind: "hell")
    
}

mainTest()
