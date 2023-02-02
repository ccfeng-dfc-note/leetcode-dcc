class Solution { 
// 2023-02-02 (FEB-Day-02) 29:34:16
// https://leetcode.com/problems/verifying-an-alien-dictionary/solutions/3129280/easy-beats-100-with-video-java-c-python/
public:
    int mapping[26];
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i = 0; i < 26; i++){
            mapping[order[i] - 'a'] = i;
        }
        for(int j = 1; j < words.size(); j++){
            if(!compare(words[j], words[j - 1])){
                return false;
            }
        }
        return true;
    }

    bool compare(string s1, string s2){
        int j = 0;
        while(j < s1.length() && j < s2.length()){
            if(s1[j] == s2[j]){
                j++;
            } else if(mapping[s1[j] - 'a'] > mapping[s2[j] - 'a']){
                return true;
            } else{
                return false;
            }
        }
        if(s1.length() < s2.length()){
            return false;
        }
        return true;
    }
};
