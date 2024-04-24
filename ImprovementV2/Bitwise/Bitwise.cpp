int copyBit(int src, int dst, int pos)
{
    // Check if the bit at position pos in src is set (1) or not (0)
    // If its 1 then 1 & 1 will return 1 otherwise bitValue will be 0.
    int bitValue = (src >> pos) & 1;
    
    // Clear the bit at position pos in dst
    // This translates to dst = 0010 1010 & 1111 1011. The result is still 0010 1010
    dst &= ~(1 << pos);

    // Set the bit in dst to the value obtained from pos
    // This translates to dst = 0010 1010 | 0000 0100. The result is 0010 1110
    dst |= (bitValue << pos);

    return dst;
}

int manipulateBit(int num, int pos, int bitVal)
{
    //Create a mask (just marking what bit you want to manipulate in a piece of data
    int mask = (1 << pos);
    //~mask: Inverses the mask (1000 to 0111). Thus, when used with the AND operator all bits will remain the same except for the single bit at 1 << pos
    //a & ~b is a common way to reset a specific bit to zero.
    //(num & ~mask): Reset the desired bit to zero, as & returns 1 if both bits are 1. num is 0001 0010 and ~mask is 1111 0111.
    //(bitVal << pos): creates an r value that represents 1 bit shifted left 3 spaces. 0000 1000
    //0001 0010 | 0000 1000: Uses the OR operator to set a bit to 1 if either of the corresponding bits in the two original values is 1. Result is 0001 1010;
    return ((num & ~mask) | (bitVal << pos));
}

int main()
{
    int result = copyBit(14, 42, 2);
    result = manipulateBit(18, 3, 1);
    return 0;
}