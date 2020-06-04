class Solution {
public:
    vector<string> generateParenthesis(int n) {
    	vector<string> res;
    	backtrack(res,"" ,n ,0 ,0 );
    	return res;
	}
	void backtrack(vector<string> &v, string current, int max, int open,int close){
		if(current.size()== max*2 ){//base case.
		    v.push_back(current);
			return;
		}
		// make all possible decisions in these recursive.
		
		if(open < max) backtrack(v, current + "(", max, open + 1, close);
		if(close < open) backtrack(v, current + ")" , max, open, close + 1);
	}
};
