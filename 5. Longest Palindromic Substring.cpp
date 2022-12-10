class Solution {
private:
/*
    // 輸入一字串，判斷是否為回文
    bool isPalindrome( string s ) {

        // 字串偶數長度
        int len = s.length() ;
        if ( len % 2 == 0 ) {
            for ( int i = 0, j = len-1 ; i < (len/2) || j >= (len/2) ; i++, j-- ) {
                if ( s[i] != s[j] )
                    return false ;
            } // for 
        } // if

        // 字串奇數長度
        else {
            for ( int i = 0, j = len-1 ; i <= (len/2) || j >= (len/2) ; i++, j-- ) {
                if ( s[i] != s[j] )
                    return false ;
            } // for 
        } // else

        return true ;
    }

public:
    string longestPalindrome(string s) {
        string subString = "" ;
        for ( int subLen = s.length() ; subLen > 0 ; subLen-- ) {
            for ( int leftIndex = 0 ; leftIndex <= ( s.length() - subLen ) ; leftIndex++ ) {
                subString = s.substr( leftIndex, subLen ) ;
                if ( isPalindrome( subString ) )
                    return subString ;

                subString = "" ;
            } // for

        } // for

        return "" ;
    }
};
*/ // 這笨方法會超時

public:
    string longestPalindrome(string s) {
        int n = s.length() ;
        if ( n == 0 ) 
            return "" ;
        
        bool dp[n][n] ; 
        // dp[i][j] 表示字串區間 [i, j] 是否為回文
        //
        // 當 i = j 時，只有一個字符，是回文
        //
        // 當 i = j + 1 時，是相鄰字符，此時要判斷 s[i] 是否等於 s[j]
        //
        // 當 i 和 j 不相鄰時，如果 s[i] 和 s[j] 相等，往 dp[i + 1][j - 1] 遞迴也相等，就是回文

        // 以下為遞迴表達式
        // dp[i, j] = true                                  if i == j
        // dp[i, j] = ( s[i] == s[j] )                      if j = i + 1
        // dp[i, j] = ( s[i] == s[j] && dp[i + 1][j - 1] )  if j > i + 1

        int leftIndex = 0, len = 1 ;
        // 假設 n = 3，0為not visited，1為visited
        // 第一層迴圈  第二層迴圈  第三層迴圈
        //   1 0 0      1 1 0      1 1 1
        //   0 0 0      0 1 0      0 1 1
        //   0 0 0      0 0 0      0 0 1
        for ( int j = 0 ; j < n ; j++ ) {
            dp[j][j] = true ;
            for (int i = 0 ; i < j ; i++ ) {
                dp[i][j] = ( s[i] == s[j] && ( j - i < 2 || dp[i + 1][j - 1] ) ) ;
                if ( dp[i][j] && len < j - i + 1 ) {
                    len = j - i + 1 ;
                    leftIndex = i ;
                } // if
            } // for
        } // for

        return s.substr( leftIndex, len ) ;
    }
};
