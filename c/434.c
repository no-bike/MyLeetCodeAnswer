int countSegments(char * s){
    int res=0;
    for(int i=0;i<strlen(s);i++)
    {
        if((i==0||s[i-1]==' ')&&s[i]!=' ') res++;
    }

    return res;
}