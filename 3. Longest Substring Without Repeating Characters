class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        deque <char> maxString = {} ; 
        int maxLen = 0 ;

        for ( int i = 0 ; i < s.length() ; i++ ) {
            // 判斷是否重複
            auto it = find( maxString.begin(), maxString.end(), s[i] ) ;

            // 有重複
            if ( it != maxString.end() ) {

                // 重複元素的index
                int index = it - maxString.begin() ;

                // 去除包含index前面的值
                while ( index > -1 ) {
                    maxString.pop_front() ;
                    index-- ;
                } // while
                    
            } // if

            // 沒有重複，新增進 maxString，並確認maxString是否加長
            maxString.push_back( s[i] ) ;
            if ( maxString.size() > maxLen )
                maxLen = maxString.size() ;
        } // for

        return maxLen ;
    }
};
