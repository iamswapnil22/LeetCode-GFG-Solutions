```
class Solution{
public:
	int rowWithMax1s(vector<vector<int> > mat, int n, int m) {
	    int i=0,j=m-1,ans=-1;
	    while(i<n and j>=0){
	        if(mat[i][j]==1){
			   ans=i;
	            j--;
	        }
	        if(mat[i][j]==0){
	        i++;
	        }
	   }
	    return ans;
	}

};
```
