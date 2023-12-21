int longestValidParentheses(char* s) {
    int n=strlen(s);
    // int left=0;
    // int right=0;
    if(n==0){
        return 0;
    }
    int ans=0;

    for(int i=0;i<n;i++){
        int left=0;
        int right=0;
        for(int k=i;k<n;k++){
            if(s[k]=='('){
                left++;
            }else{
                right++;
            }
            if(right>left){
                break;
            }
            if(left==right && left+right>ans){
                ans=left+right;
            }
        }
    }
    return ans;
}
