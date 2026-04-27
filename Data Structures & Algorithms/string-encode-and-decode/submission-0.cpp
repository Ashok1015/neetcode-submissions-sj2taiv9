class Solution {
public:

    string encode(vector<string>& strs) {
        char delim= '#';
        string result;
        for(const string& str: strs){
            result += std::to_string(str.size()) + delim +str;
        }
        return result;
    }

    vector<string> decode(string s) {
        char delim= '#';
        int i=0;
        int j=0;
        vector<std::string> strs;
        while(i< s.size()){
            j=i;
            while(s[j]!=delim){
                j++;
            }
            int length;
            sscanf(s.substr(i,j-i).c_str(), "%d", &length);
            i= j+1;
            strs.emplace_back(s.substr(i,length));
            i+= length;
        }
        return strs;
    }
};
