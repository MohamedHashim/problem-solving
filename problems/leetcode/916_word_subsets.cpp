class Solution {
public:
    bool isContain(string s1, string s2){
	int cnt =0;
	for(int i=0;i<s2.size();i++){
		for(int j=0;j<s1.size();j++){
			if(s2[i]==s1[j]){
                s1[j]='0';
				cnt++;
				break;
			}
		}
	}
	if(cnt==s2.size())
		return true;
	else
		return false;
}
    
    vector<string> wordSubsets(vector<string>& A, vector<string>& B) {
        vector<string> res;
        for(int i=0;i< A.size();i++){
            res.push_back(A[i]);
        }
        for(int i =0;i<B.size();i++){
            for(int j=0;j<res.size();j++){
                if(!isContain(res[j],B[i])){
                   res.erase(find(res.begin(),res.end(),res[j]));
                   j--;
                }
            }
        }
        return res;
        
    }
};