class Solution {
public:
    bool isPalindrome(int x) {
        long originX = x ;
        long reverseX = 0 ;
        while ( x > 0 ) {
            reverseX = reverseX * 10 + x % 10 ;
            x = x / 10 ;
        } // while

        if ( reverseX == originX )
            return true ;
        return false ;
    }
};
