using System;
using Xunit;
using Xunit.Abstractions;

public class ArrayTests
{
    private readonly Array<int> _sqList;
    private readonly ITestOutputHelper _output;

    public ArrayTests (ITestOutputHelper output)
    {
        _sqList = new Array<int> (10);
        _output = output;
    }

    private void PrintList ()
    {
        for (int idx = 0; idx < _sqList.Length; idx++)
        {
            var elem = _sqList.Find (idx + 1);
            _output.WriteLine (elem.ToString ());
        }
    }

    [Fact]
    public void Length_Equal_0_When_List_Is_Empty ()
    {
        Assert.True (_sqList.Length == 0);
    }

    [Fact]
    public void Length_Equal_1_After_InsertOneElement ()
    {
        _sqList.Insert (1, 1);
        Assert.True (_sqList.Length == 1);
    }

    [Fact]
    public void Insert_ThrowIndexOutOfRangeException_When_PositionGreaterThanLength ()
    {
        _sqList.Insert (1, 1);
        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Insert (3, 1));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void Insert_ThrowIndexOutOfRangeException_When_PositionLessThanOne ()
    {
        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Insert (0, 1));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void Insert_ThrowIndexOutOfRangeException_When_List_Is_Full ()
    {
        _sqList.Insert (1, 10);
        _sqList.Insert (2, 9);
        _sqList.Insert (3, 8);
        _sqList.Insert (4, 7);
        _sqList.Insert (5, 6);
        _sqList.Insert (6, 5);
        _sqList.Insert (7, 4);
        _sqList.Insert (8, 3);
        _sqList.Insert (9, 2);
        _sqList.Insert (10, 1);

        PrintList ();

        Exception ex = Assert.Throws<OutOfMemoryException> (() => _sqList.Insert (11, 101));
        Assert.IsType<OutOfMemoryException> (ex);
    }

    [Fact]
    public void Delete_ThrowIndexOutOfRangeException_When_PositionLessThanOne ()
    {
        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Delete (0));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void Delete_ThrowIndexOutOfRangeException_When_PositionGreaterThanLength ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Delete (3));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void Delete_First_Element ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);

        var elem = _sqList.Delete (1);
        Assert.Equal (11, elem);
    }

    [Fact]
    public void Delete_Last_Element ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.Delete (3);
        Assert.Equal (33, elem);
    }

    [Fact]
    public void Delete_Middle_Element ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.Delete (2);
        Assert.Equal (22, elem);
    }

    [Fact]
    public void GetElem_ThrowsIndexOutOfRangeException_When_PositionLessThanZero ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Find (0));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void GetElem_ThrowsIndexOutOfRangeException_When_PositionGreaterThanLength ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        Exception ex = Assert.Throws<IndexOutOfRangeException> (() => _sqList.Find (4));
        Assert.IsType<IndexOutOfRangeException> (ex);
    }

    [Fact]
    public void GetElem_Last_Position_Return_33 ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.Find (3);

        Assert.Equal (33, elem);
    }

    [Fact]
    public void GetElem_First_Position_Return_11 ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.Find (1);

        Assert.Equal (11, elem);
    }

    [Fact]
    public void IndexOf_Return_Netagive1_When_Element_Not_Exist ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.IndexOf (55);

        Assert.Equal (-1, elem);
    }

    [Fact]
    public void IndexOf_Return_First_Index ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.IndexOf (11);

        Assert.Equal (0, elem);
    }

    [Fact]
    public void IndexOf_Return_Last_Index ()
    {
        _sqList.Insert (1, 11);
        _sqList.Insert (2, 22);
        _sqList.Insert (3, 33);

        var elem = _sqList.IndexOf (33);

        Assert.Equal (2, elem);
    }

    [Fact]
    public void Clear_Length_Equal_Zero_If_Empty ()
    {
        _sqList.Insert (1, 10);
        _sqList.Insert (2, 9);
        _sqList.Insert (3, 8);
        _sqList.Insert (4, 7);
        _sqList.Insert (5, 6);
        _sqList.Insert (6, 5);
        _sqList.Insert (7, 4);
        _sqList.Insert (8, 3);
        _sqList.Insert (9, 2);
        _sqList.Insert (10, 1);

        Assert.Equal (10, _sqList.Length);

        _sqList.Clear ();

        Assert.Equal (0, _sqList.Length);
    }
}