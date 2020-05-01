class MyArray
    def initialize(data=[], capacity)
        @data = data
        @capacity = capacity
    end

    def print_data()
        puts @data.join(", ")
    end

    def find(index)
        result = @data[index]
        if result == nil
            return "nil"
        else
            return result
        end
    end

    def insert(index, value)
        if @data.length() >= @capacity
            return false
        else
            @data.insert(index, value)
            return true
        end
    end

    def delete(index)
        value = @data.delete_at(index)
        return value == nil ? false : true
    end

end


if __FILE__ == $0
    array = MyArray.new([1, 2, 3, 4, 5, 6], 8)
    array.print_data()

    puts array.find(0)
    puts array.find(8)

    puts array.insert(4, "apple")
    array.print_data()

    puts array.insert(4, "banana")
    array.print_data()

    puts array.delete(10)
    array.print_data()

    puts array.delete(4)
    array.print_data()    
end