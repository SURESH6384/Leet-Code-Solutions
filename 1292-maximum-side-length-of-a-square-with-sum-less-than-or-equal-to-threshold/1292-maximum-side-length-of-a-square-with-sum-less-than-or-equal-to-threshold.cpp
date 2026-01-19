class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>pref(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]=mat[i][j]+pref[i][j+1]+pref[i+1][j]-pref[i][j];
            }
        }
        int mx=1;
        int mn=1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int w=min(n-i,m-j);
                for(int k=mx;k<=w;k++){
                    int tot=pref[i+k][j+k]-pref[i+k][j]-pref[i][j+k]+pref[i][j];
                    if(tot<=threshold){
                        mx=max(mx,k);
                    }
                }
                mn=min(mn,mat[i][j]);
            }
        }
        if(mx==1){
            if(mn>threshold) return 0;
        }
        return mx;
    }
};