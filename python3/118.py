/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int** parry = malloc(sizeof(int*)*numRows);
    * returnSize = numRows;
    * returnColumnSizes = malloc(sizeof(int)*numRows);
    int i,j;
    for(i=0;i<numRows;++i){
        (*returnColumnSizes)[i] = i+1;

        parry[i] = malloc(sizeof(int)*(i+1));
        parry[i][0] = 1;
        parry[i][i] = 1;

        for(j=1;j<i;++j){

            parry[i][j] = parry[i-1][j-1] + parry[i-1][j];

        }
    }

    return parry;
    
}