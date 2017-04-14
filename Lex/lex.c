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
            printf("<id,%d>",j+1);
            //puts(id[j]);
            //printf("%c",id[0][2]);
            j++;
        }
        if(ch[i]>47&&ch[i]<58){
            p=0;
            num[k][p]=ch[i];
            while(ch[i+1]>47&&ch[i+1]<58){
                num[k][p+1]=ch[i+1];
                p++;
                i++;
            }
            printf("<num,%d>",k+1);
            i++;
            k++;
        }
        if(ch[i]==92){
            printf("<xie>");
            i++;
        }
        if(ch[i]=='('){
            printf("<(>");
            i++;
        }
        if(ch[i]==')'){
            printf("<)>");
            i++;
        }
        if(ch[i]=='{'){
            printf("<{>");
            i++;
        }
        if(ch[i]=='}'){
            printf("<}>");
            i++;
        }
        if(ch[i]=='_'){
            printf("<_>");
            i++;
        }
        if(ch[i]=='^'){
            printf("<^>");
            i++;
        }
        if(ch[i]==' '){
            printf("< >");
            i++;
        }

    }
    return(1);
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
     puts(id[1]);
     return(1);
 
 
 }

