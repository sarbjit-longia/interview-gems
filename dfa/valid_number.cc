//https://leetcode.com/problems/valid-number/submissions/
//Deterministic Finite Automaton (DFA)

class Solution {
public:

    std::vector<std::map<string, int>> states_;

    void create_automaton(string s){
        states_ = {
            {{"digit" , 1}, {"sign", 2}, {"dot", 3}},
            {{"digit", 1}, {"dot", 4}, {"exponent", 5}},
            {{"digit", 1}, {"dot", 3}},
            {{"digit", 4}},
            {{"digit", 4},{"exponent", 5}},
            {{"digit", 7}, {"sign", 6}},
            {{"digit", 7}},
            {{"digit", 7}}
        };
    }

    bool isNumber(string s) {
        create_automaton(s);

        int state = 0;
        for(int i = 0; i < s.length(); i++){
            char c = s[i];
            string g;
            if(c == '+' || c == '-'){
                g = "sign";
            }
            else if(c =='e' || c == 'E'){
                g = "exponent";
            }
            else if(isdigit(c)){
                g = "digit";
            }
            else if(c == '.'){
                g = "dot";
            }

            auto it = states_[state].find(g);
            if(it == states_[state].end()) return false;
            state = states_[state][g];
        }
        return state == 1 || state == 4 || state == 7;
    }
};