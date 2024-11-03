bool rotateString(char* s, char* goal) {
    int n=strlen(s);
    if(strlen(goal)!=n)
        return false;
    int x=0;
    for(int i=0;i<n;i++){
        if(s[i]==goal[0]){
            int j;
            for(j=0;j<n;j++){
                if(goal[j] !=s[(i+j)%n])
                    break;
            }
            if(j==n)
                return true;
        }
    }
    return false;
}