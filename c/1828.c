/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countPoints(int** points, int pointsSize, int* pointsColSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    *returnSize = queriesSize;
    int * answer = (int*)malloc(sizeof(int)*queriesSize);
    int dis;
    memset(answer,0,sizeof(int)*queriesSize);
    for(int i = 0;i<queriesSize;++i){
        dis = pow(queries[i][2],2);
        for(int j = 0;j<pointsSize;++j){
            if(pow(points[j][0] - queries[i][0],2)+pow(points[j][1] - queries[i][1],2) <= dis){
                ++answer[i];
            }
        }
    }
    return answer;
}