//动态规划 二维数组 边界情况

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {
    int f[triangleSize][triangleSize];
    memset(f,0,sizeof(f));
    f[0][0]=triangle[0][0];
    int min=triangle[0][0];
    if(triangleSize==1){
        return min;
    }
    else{
    for(int i=1;i<triangleSize;i++)
    {
         int m=f[i][0];
        for(int j=0;j<i+1;j++)
        {
           
            if(j==0)
            {
                f[i][0]=f[i-1][0]+triangle[i][0];
            }
            else if(j==i)
            {
                f[i][i]=f[i-1][i-1]+triangle[i][i];
            }
            else
            {
                
            f[i][j]=((f[i-1][j-1]<f[i-1][j])?f[i-1][j-1]:f[i-1][j])+triangle[i][j];
            }
        }
    }
    int ans=f[triangleSize-1][0];
    for(int j=0;j<triangleSize;j++)
    {
        if(f[triangleSize-1][j]<ans){ans=f[triangleSize-1][j];}
    }
    return ans;
    }
}
