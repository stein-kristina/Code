#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N1 201 // 字符串长度最长为200
#define N2 11 // 分隔符最长为10
#define COUNT 20 // 分隔后字符串数量最多为20
#include <string.h>

int split(char origin[], char sep[],char (*result)[N1])
{
    int t = 0,i,j=0,lensep,lenorigin,count=1;
    lensep = strlen(sep);
    char aimstr[50];
    memset(aimstr,'0',sizeof(aimstr));
    lenorigin = strlen(origin);
    t = strstr(origin,sep)-origin;
    while(1){
    if(t==0)
    {   
        for(i=0;i<lenorigin;i++)
        {
            if(i<lenorigin-lensep)
            {
                origin[i]=origin[i+lensep];
            }
            else
            origin[i]='\0';
        }
    }
    else if(t>0){
        count++;
        for(i=0;i<t;i++){
        aimstr[i]=origin[i];
        }
        aimstr[t] = '\0';
        strcpy(result[j],aimstr);
        j++;
        for(i=0;i<lenorigin;i++)
        {
            if(i<lenorigin-t)
            {
                origin[i]=origin[i+t];
            }
            else
            origin[i]='\0';
        }
    } 
 t = strstr(origin,sep)-origin;
 lenorigin = strlen(origin);
 if(lenorigin<=lensep&&t<0){
         for(i=0;i<lenorigin;i++){
        aimstr[i]=origin[i];
        }
        aimstr[lenorigin] = '\0';
        strcpy(result[j],aimstr);
        j++;
     return count;}
}
}
int main(void){
    // freopen("test.txt","r",stdin);
    // freopen("ans2.txt","w",stdout);
    char origin[N1];
    char sep[N2];
    char result[COUNT][N1];

    gets(origin);
    gets(sep);
    int n_result = split(origin,sep,result);
    int i;
    for(i=0;i<n_result;i++){
        printf("%s\n",result[i]);
    }
    system("pause");
    return 0;
}