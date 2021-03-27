class Solution {
public:
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        for(int i=0;i< A.size();i++){
            res.push_back(A[i]);
        }
        for(int i =0;i<B.size();i++){
            for(int j=0;j<res.size();j++){
                if(res[j].find(B[i]) == std::string::npos)
                   res.erase(find(res.begin(),res.end(),res[j]));
            }
        }
        return res;
        
    }
};