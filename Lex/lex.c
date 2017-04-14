 #include <stdio.h>
 #include <stdlib.h>
  
int DFA(char *ch,char (*id)[100],int (*num)[100]){
    //puts(ch);
    int i=0; 
    int j=0;
    int k=0;
    int p=0;
    while(ch[i]!='\0'){
        if((ch[i]>64&&ch[i]<91)||(ch[i]>96&&ch[i]<123)){
            p=0;
            id[j][p]=ch[i];//printf("%c",ch[i]);
            while((ch[i+1]>64&&ch[i+1]<91)||(ch[i+1]>96&&ch[i+1]<123)||(ch[i+1]>47&&ch[i+1]<58)){
                id[j][p+1]=ch[i+1];
                p++;
                //printf("%c",id[j][i]);
                i++;
            }
            i++;
            printf("<id,%d>\n",j+1);
            //puts(id[j]);
            //printf("%c",id[0][2]);
            j++;
        }
        else if(ch[i]>47&&ch[i]<58){
            p=0;
            num[k][p]=ch[i]-48;
            while(ch[i+1]>47&&ch[i+1]<58){
                num[k][p+1]=ch[i+1]-48;
                p++;
                i++;
            }
            printf("<num,%d>\n",k+1);
            i++;
            k++;
        }
        else if(ch[i]==92){
            if(ch[i+1]=='s'){
                printf("<sum>\n");
                i=i+4;
            }
            else if(ch[i+1]=='i'){
                printf("<int>\n");
                i=i+4;
            }
            else{
                printf("xie error");
                exit(1);
            }
            //printf("<xie>\n");
            //i++;
        }
        else if(ch[i]=='('){
            printf("<(>\n");
            i++;
        }
        else if(ch[i]==')'){
            printf("<)>\n");
            i++;
        }
        else if(ch[i]=='{'){
            printf("<{>\n");
            i++;
        }
        else if(ch[i]=='}'){
            printf("<}>\n");
            i++;
        }
        else if(ch[i]=='_'){
            printf("<_>\n");
            i++;
        }
        else if(ch[i]=='^'){
            printf("<^>\n");
            i++;
        }
        else if(ch[i]==' '){
            printf("<blank>\n");
            i++;
        }
        else{
            printf("none error");
            exit(1);
        }

    }
    return(j);
}

 
 
 
 int main(){
     char id[100][100]={0};
     int num[100][100]={0};
     FILE *fp;
     int i=0;
     int x=0;
     char ch[100];
     if((fp=fopen("test.txt","r"))==NULL){
         printf("don't exist");
         exit(1);
     }
     while(1){
         fscanf(fp,"%c",&ch[i]);
         if(ch[i]=='$'){
             //ch[i]=fgetc(fp);
             break;
         }
         if(ch[i]==EOF){
             ch[i]='\0';
         }
     }
     i=0;
     while(ch[i]!=EOF){
         fscanf(fp,"%c",&ch[i]);
         if(ch[i]=='$'){
             ch[i]='\0';//ch[i]=fgetc(fp);
             break;
         }
         i++;
     }
     
     
     x=DFA(ch,id,num);
     for(i=0;i<x;i++){
         puts(id[i]);
     }
     i=0;
     x=0;
     while(num[i][0]!=0){
         while(num[i][x]!=0){

         printf("%d",num[i][x]);
         x++;
         }
         printf("\n");
         i++;
     }


     return(1);
 
 
 }

