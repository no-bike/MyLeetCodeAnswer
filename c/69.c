int mySqrt(int x) {
    if(x==0) return 0;
    if(x==1) return 1;
    int front = 0;
    int rear = x;
    int temp;
    temp = (front+rear)/2;
    while(temp > x/temp||(temp+1)< x/(temp+1)){
        if(temp > x/temp){
            rear = temp;
        }
        else{
            front = temp;
        }
        temp = (front+rear)/2;
    }
    return x/(temp+1) == temp+1?temp+1:temp;
}