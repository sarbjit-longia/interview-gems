// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Very good question

class Solution {
public:
    class Trie
    {
        public:
           Trie *child[2];
           int val = 0;
    };


    void insert(int x, Trie *root){

        Trie* curr=root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x >> i) & 1;
            if(curr->child[bit] == NULL)
                curr->child[bit] = new Trie();

            curr = curr->child[bit];
        }
        curr->val = x;

    }

    int findAns(int x, Trie *root)
    {
        Trie* curr = root;
        for(int i=31;i>=0;i--)
        {
            int bit = (x >> i) & 1;

            if(curr->child[!bit]!=NULL) // try to go to opposite bit to maximize XOR
                curr = curr->child[!bit];

            else if(curr->child[bit]!=NULL)
                curr=curr->child[bit];
        }
        return curr->val;
    }

    int findMaximumXOR(vector<int>& nums) {

        int ans = INT_MIN;

        Trie* root = new Trie();

        for(auto n:nums)
            insert(n, root);


        for(auto n:nums)
            ans = max(ans, n ^ findAns(n, root));

        return ans;
    }
};