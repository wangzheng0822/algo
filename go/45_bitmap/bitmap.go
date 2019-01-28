package bitmap

// BitMap implement bitmap
type BitMap []byte

// New create BitMap
func New(length uint) BitMap {
	return make([]byte, length/8+1)
}

// Set set value in bitmap
func (b BitMap) Set(value uint) {
	byteIndex := value / 8
	if byteIndex >= uint(len(b)) {
		return
	}
	bitIndex := value % 8
	[]byte(b)[byteIndex] |= 1 << bitIndex
}

// Get check whether value exist or not
func (b BitMap) Get(value uint) bool {
	byteIndex := value / 8
	if byteIndex >= uint(len(b)) {
		return false
	}
	bitIndex := value % 8
	return []byte(b)[byteIndex]&(1<<bitIndex) != 0
}
