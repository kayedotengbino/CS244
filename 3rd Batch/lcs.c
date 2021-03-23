//Finding length of LCS through RECURSIVE Algorithm

int lcs(char *A, char *B, int i, int j)
{
    if(A[i] == '\0' || B[j] == '\0')    //String terminators
        return 0;
    
    if(A[i] == B[j])
        return 1 + lcs(A, B, i, j);
    else
        return max(lcs(A, B, i+1, j), lcs(A, B, i, j+1));
}

/*
    Finding length of LCS through Tabulation, Bottom-up Dynamic Programming
    Bottom up because it uses the previusly solved subproblem
*/
int lcs(char *A, char *B, int m, int n)
{
    int LCS[m+1][n+1];
    int i, j;

    for(i = 0; i <= m; i++)
    {
        for(j = 0; j <= n; j++)
        {
            if(i == 0 || j == ))
                LCS[i][j] = 0;
            else if(A[i-1] == B[j-1])
                LCS[i][j] = LCS[i-1][j-1] + 1;
            else
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    return LCS[m][n];
}