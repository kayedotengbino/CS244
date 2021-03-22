//Finding length of LCS through RECURSIVE Algorithm

int lcs(char *A, char *B, int i, int j)
{
    if(A[i] == '\0' || B[j] == '\0')
        return 0;
    
    if(A[i] == B[j])
        return 1 + lcs(A, B, i, j);
    else
        return max(lcs(A, B, i+1, j), lcs(A, B, i, j+1));
}