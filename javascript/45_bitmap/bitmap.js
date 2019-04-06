
class BitMap {
    constructor(n) {
        this.nbits = n;
        this.blk = new Array(Math.floor(n / 16) + 1);
        this.blk.fill(0);
    }

    get(k) {
        if( k > this.nbits) return false; 

        let byteIndex = Math.floor(k / 16);
        let bitIndex = k % 16;

        return !((this.blk[byteIndex] & (1 << bitIndex)) === 0);
    }

    set(k) {
        if( k > this.nbits) return; 

        let byteIndex = Math.floor(k / 16);
        let bitIndex = k % 16;

        this.blk[byteIndex] = this.blk[byteIndex] | (1 << bitIndex);

    }
}

let aBitMap = new BitMap(20);

aBitMap.set(1);
aBitMap.set(3);
aBitMap.set(5);
aBitMap.set(7);
aBitMap.set(9);
aBitMap.set(11);
aBitMap.set(13);
aBitMap.set(15);
aBitMap.set(17);
aBitMap.set(19);

for(let i = 0; i < 21; i++) {
    console.log(aBitMap.get(i));
}