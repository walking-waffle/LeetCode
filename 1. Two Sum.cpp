class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int secondNum = 0 ;
        vector<int> result ;
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            secondNum = target - nums[i] ;

            for ( int j = i+1 ; j < nums.size() ; j++ ) {
                if ( nums[j] == secondNum ) {
                    result.push_back(i) ;
                    result.push_back(j) ;
                    return result ;
                } // if
            } // for

            secondNum = 0 ;
        } // for

        return result ;
    }
};
