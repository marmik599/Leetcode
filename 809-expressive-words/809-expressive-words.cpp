class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size(); ++i){
            if(words[i].size() > S.size()) continue;
            int k = 0, j = 0;
            while(j < words[i].size()){
                if(words[i][j] != S[k]) break;
                int subCount = 1, sCount = 1;
                while(j < words[i].size()-1 && words[i][j] == words[i][j+1]) {
                    ++subCount; ++j;
                }
                while(k < S.size()-1 && S[k] == S[k+1]){
                    ++sCount; ++k;
                }
                if(subCount > sCount || (sCount != subCount && sCount < 3)) break;
                if(j == words[i].size()-1 && k != S.size()-1) break;
                ++k; ++j;
            }
            if(j == words[i].size() && k == S.size()) ++count;
        }
        return count;
    }
};