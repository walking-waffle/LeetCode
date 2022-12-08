class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector <int> merge ;
        int i = 0 ;
        int j = 0 ;

        while ( i < nums1.size() && j < nums2.size() ) {
            if ( nums1[i] <= nums2[j] ) {
                merge.push_back( nums1[i] ) ;
                i++ ;
            } // if
            else {
                merge.push_back( nums2[j] ) ;
                j++ ;
            } // else
        } // while

        // s2數字比較大，把s2的剩餘數字放入merge
        if ( i == nums1.size() ){
            while ( j != nums2.size() ) {
                merge.push_back( nums2[j] ) ;
                j++ ;
            } // while
        } // if
        // s1數字比較大，把s1的剩餘數字放入merge
        else {
            while ( i != nums1.size() ) {
                merge.push_back( nums1[i] ) ;
                i++ ;
            } // while
        } // else

        // 偶數長度
        int len = merge.size() ;
        if ( len % 2 == 0 ) {
            return float( ( merge[len/2]+merge[(len/2)-1] )) / 2 ;
        } // if
        // 奇數長度
        else
            return float( merge[len/2]) ;
    }
};
