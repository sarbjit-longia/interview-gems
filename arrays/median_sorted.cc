// Reference: https://www.youtube.com/watch?v=uPqPDPjtPX4
// Hard problem
// https://leetcode.com/problems/median-of-two-sorted-arrays/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Keep first array small for this to work
        int na = nums1.size();
        int nb = nums2.size();
        if(na > nb){
            nums1.swap(nums2);
            std::swap(na, nb);
        }

        int s = 0;
        int e = na;

        int required_elements_in_first_half = (na + nb + 1) / 2;
        while(s <= e){
            int m1 = (s + e)/2;
            int m2 = required_elements_in_first_half - m1;

            int min_from_second_half_a = (m1 == na) ? INT_MAX : nums1[m1];
            int max_from_first_half_a = (m1 == 0) ? INT_MIN : nums1[m1 - 1];
            int min_from_second_half_b = (m2 == nb) ? INT_MAX : nums2[m2];
            int max_from_first_half_b = (m2 == 0) ? INT_MIN : nums2[m2 - 1];


            if(max_from_first_half_a <= min_from_second_half_b
              && min_from_second_half_a >= max_from_first_half_b){
                // Partition is perfect lets get the answer and get the hell out of here
                if((na + nb) % 2 == 0){
                    double f = std::max(max_from_first_half_a, max_from_first_half_b);
                    double s = std::min(min_from_second_half_a, min_from_second_half_b);
                    return (f + s) / 2;
                }
                else{
                    return std::max(max_from_first_half_a, max_from_first_half_b);
                }
            }
            else if(max_from_first_half_a > min_from_second_half_b){
                e = m1 - 1;
            }
            else{
                s = m1 + 1;
            }
        }
        return 1.00;
    }
};