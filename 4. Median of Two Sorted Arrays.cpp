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

        // 目前剩下比較大的數字還未插入
        // ex. [1,3,5] [2,4,6,8,10] => [1,2,3,4,5,6] [8,10]
        //      nums1   nums2           merge         rest
        int mergeLen = merge.size() ;
        int restLen = 0 ;  //還未插入的數組大小
        int totalLen = 0 ; // 全數排序後的總長度，就是merge和rest的長度

        // s2數字比較大
        if ( i == nums1.size() ){
            restLen = nums2.size() - j ;

            // ex. [1,3] [2,4,6,8,10,12] => [1,2,3,4] [6,8,10,12]
            //     nums1   nums2             merge     rest
            if ( mergeLen == restLen ) {
                return float(merge[mergeLen-1] + nums2[j]) / 2 ;
            } // if

            // ex. [1] [2,4,6,8,10] => [1,2] [4,6,8,10,12]
            //     nums1   nums2       merge   rest
            else if ( mergeLen < restLen ) {
                totalLen = mergeLen + restLen ;
                if ( totalLen % 2 == 1 )
                    return nums2[j + (totalLen/2 - mergeLen)] ;
                else
                    return float(nums2[j + (totalLen/2 - mergeLen)]+nums2[j + (totalLen/2 - 1 - mergeLen)]) / 2 ;
            } // else if

            // ex. [1,3,5] [2,4,6,8] => [1,2,3,4,5,6] [8]
            //     nums1   nums2         merge        rest
            else {
                totalLen = mergeLen + restLen ;
                if ( totalLen % 2 == 1 )
                    return merge[totalLen/2] ;
                else
                    return float(merge[totalLen/2]+merge[totalLen/2 - 1]) / 2 ;
            } // else
        } // if

        // s1數字比較大，基本和上面一樣
        else {
            restLen = nums1.size() - i ;
            if ( mergeLen == restLen ) {
                return float(merge[mergeLen-1] + nums1[i]) / 2 ;
            } // if
            else if ( mergeLen < restLen ) {
                totalLen = mergeLen + restLen ;
                if ( totalLen % 2 == 1 )
                    return nums1[i + (totalLen/2 - mergeLen)] ;
                else
                    return float(nums1[i + (totalLen/2 - mergeLen)]+nums1[i + (totalLen/2 - 1 - mergeLen)]) / 2 ;
            } // else if
            else {
                totalLen = mergeLen + restLen ;
                if ( totalLen % 2 == 1 )
                    return merge[totalLen/2] ;
                else
                    return float(merge[totalLen/2]+merge[totalLen/2 - 1]) / 2 ;
            } // else
        } // else
    }
};
