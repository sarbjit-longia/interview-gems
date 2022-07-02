
// Input = Array of integers that represent the height of apartments. Left most apartment is in index 0 & the array lists the apartments from left to right. After the rightmost apartment, we hit the ocean. Apartments are of the same width and in a straight line from left to right towards the ocean.
// Output = Take in the Array and return the indexes of the apartments that have ocean view

// Ocean View
// Input: [4, 3, 2, 3, 1]
// Output: [0, 3, 4]
//
//   ___
// 4 |  |  ___         ___
// 3 |  |  |  |  ___   |  |
// 2 |  |  |  |  |  |  |  |  ___
// 1 |  |  |  |  |  |  |  |  |  |
//                               ~~~~~ Ocean
//   b0,    b1,   b2,   b3,   b4
// Input: [4, 3, 2, 3, 1]
// Output: [0, 3, 4]

// [1, 2, 3, 4]
// 4, 3, 2, 1

class OceanView final {

public:
  vector<int> solve_ocean_view(vector<int>& input){
    stack<pair<int, int> st;

    for(int i = 0; i < input.size(); i++){ // O(n)
        if(st.empty()){
          st.push({input[i], i});  // O(1)
        }
        else{
          int last_height = st.top().first;

          if(input[i] >= last_height){
            while(!st.empty()){ // O(k)
              auto e = st.top().first;
              if(e > input[i]) break;
              st.pop();
            }
          }
          st.push({input[i], i});
        }
    }

    vector<int> result;
    while(!st.empty()) result.push_back(st.top().second), st.pop();

    return result;
  }
};

/*Given a string 's' and a list of strings 'dict', you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict.
If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag.
Also, if two substrings wrapped by bold tags are consecutive, you need to combine them.

Input:
s = "abcxyz123"
dict = ["abc","123"]
Output:
"<b>abc</b>xyz<b>123</b>"

Input:
s = "aaabbcc"
dict = ["aaa","aab","bc"]
Output:
"<b>aaabbc</b>c"
*/

//1. To find the location of dict in the main string   -> (a, b)
//2. Once you have the intervals you need to merge them

class MakeBold final {

public:

  pair<int, int> find_word(string& dict_word, string& text){ // O(n)
    auto it = text.find(dict_word);
    if(it == string::npos){
      return {-1, -1};
    }
    return {it, dict.word.length()};
  }


  vector<pair< int, int> > merge_intervals(vector<pair<int, int>& input){  // O(klogk)
    // merge the intervals

    sort(input.begin(), input.end()); // O(klogk)
    vector<pair< int, int> > result;

    auto curr = input[0];

    // (0, 4)    (2, 3)
    // (0, 4).   (2, 6)   -> (0, 6)
    // (0, 4), (6, 8)

    for(int i = 1; i < input.size(); i++){  // O(k)
      if(curr.second > input[i].second){
        // total overlap
        continue;
      }
      else if(curr.second < input[i].second){
         // merge
         curr.second = input[i].second;
      }
      else if( input[i].first > curr.second){
        result.push_back(curr);
        curr = input[i].second;
      }
    }
    result.push_back(curr);
    return result;
  }


  string process(string text, vector<string> dict){

  // TODO validations

    vector<pair<int, int>> intervals;
    for(auto word : dict){ // O( len(dict) * O(k))
      auto loc = find_word(word, text);
      if(loc.first != -1 && loc.second != -1){
        intervals.push_back(loc);
      }
    }

    auto merged_intervals = merge_intervals(intervals); // O(len_of_intervals * log len_of _intervals)

    //sort(merged_intervals.begin(), merged_intervals.end());

    string result;
    int interval_index = 0; // (0, 6)
    for(int i = 0; i < text.length(); i++){ // O(len_of_text)
      if(merged_intervals[interval_index].first == i){
        result += "<b>";
        while(i != merged_intervals[interval_index].second){
          result += text[i++];
        }
        result += "</b>";
        interval_index++;

        if(interval_index >= merged_intervals.size()){
        // Exit prematurely once done
          result += text.substr(i);
          break;
        }
      }
    }
    return result;
  }

};

