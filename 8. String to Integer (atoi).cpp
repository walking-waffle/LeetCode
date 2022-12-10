class Solution {
private:
    // 輸入的字元是 0 ~ 9 就返回true
    bool IsDigit( char input ) {
        if ( input == '1' || input == '2' || input == '3' ||
             input == '4' || input == '5' || input == '6' ||
             input == '7' || input == '8' || input == '9' || input == '0' )
            return true ;
        return false ;
    } // IsDigit

public:
    int myAtoi(string s) {
        int result = 0 ;
        bool positive = true ;
        bool signAppeared = false ;
        bool numAppeared = false ;
        for ( int i = 0 ; i < s.length() ; i++ ) {
            
            // 空白，跳過
            if ( s[i] == ' ' ) {
                if ( numAppeared || signAppeared )
                    break ;
            } // if

            // 判斷正負號
            else if ( s[i] == '+' || s[i] == '-' ) {
                if ( numAppeared )
                    break ;
                else {
                    if ( signAppeared )
                        return 0 ;
                    else {
                        if ( s[i] == '-' )
                            positive = false ;
                    } // else

                    signAppeared = true ; 
                } // else
            } // else if

            // 數字
            else if ( IsDigit( s[i] ) ) {
                numAppeared  = true ;
                while ( IsDigit( s[i] ) && i < s.length() ) {
                    if ( result < INT_MAX / 10 || ( result == INT_MAX / 10 && ( s[i] - '0' ) <= 7 ) ) {
                        result = result * 10  + ( s[i] - '0' ) ;
                    } // if
                    else {
                        if ( positive )
                            return INT_MAX ;
                        else
                            return INT_MIN ;
                    } // else

                    i++ ;
                } // while
                    
                i-- ;
            } // else if

            // 其他
            else {
                break ;
            } // else

        } // for

        if ( positive )
            return result ;
        else
            return result * -1 ;
    }
};
