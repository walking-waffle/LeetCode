class Solution {
public:
    string convert(string s, int numRows) {
        if ( numRows < 2 )
            return s ;

        // 宣告 numRows 個 vector
        vector <char> vec[numRows] ;
        int i = 1 ;
        // 先把第一個字元放入第一個vecor
        vec[0].push_back( s[0] ) ;

        // 遍歷整個字串
        while ( i < s.length() ) {
            // 依序放入第二個、第三個...第numRows個 vector
            for ( int position = 1 ; position < numRows && i < s.length() ; position++, i++ )
                vec[position].push_back( s[i] ) ;
                
            // 依序放入第numRows個、第numRows-1個...第一個 vector
            for ( int position = numRows - 2 ; position >= 0 && i < s.length() ; position--, i++ )
                vec[position].push_back( s[i] ) ;

        } // while

        string result = "" ;
        for ( int i = 0 ; i < numRows ; i++ )
            for ( int j = 0 ; j < vec[i].size() ; j++ )
                result = result + vec[i][j] ;
        
        return result ;
    }
};
