#include <math.h>
char* intToRoman(int x) {
    int len=3;
    int y=0;
    char string[50]="";
    int i=0;
    while(len>=0){
        printf("%d ",len);
        int g=pow(10,len);
        if(x/g!=0){
            y=1;
        }
        printf("%d ",y);
        if(y==1){
            char a;
            char b;
            char c;
            
            if(len==0){
                a='I';
                b='V';
                c='X';
            }
            else if(len==1){
                a='X';
                b='L';
                c='C';
            }
            else if(len==2){
                a='C';
                b='D';
                c='M';
            }
            else if(len==3)
            a='M';
            int p=x/g;

            
            if(p<=3){
                if(p==0)
                break;

                for(int j=0;j<p;j++){
                    string[i+j]=a;
                }
                i+=p;
            
            }
            else if(p==4){
                string[i]=a;
                string[i+1]=b;
                i+=2;
            }
            else if(p==5){
                string[i]=b;
                i++;
            }
            else if(p<=8){
                string[i]=b;
                i++;
                for(int j=0;j<p-5;j++){                   
                    string[i+j]=a;
                }
                i+=p-5;
            }
            else if(p==9){
                string[i]=a;
                string[i+1]=c;
                i+=2;
            }
            while(x!=0 && g!=1){
                if(x%g-x%(g/10)==0){
                    len--;
                    g=g/10;
                }
                else
                break;
            }
            x=x%g;

        }

        len--;
    }
    string[i]='\0';
    char *s=string;
    return s;
}

// 2nd method

#include <string.h>
char* intToRoman(int x) {

    char *string = (char *)malloc(50 * sizeof(char));   // 16 * is only needed
    strcpy(string,"");
    if(x/1000!=0){
        if(x/1000==1)
        strcat(string,"M");
        if(x/1000==2)
        strcat(string,"MM");
        if(x/1000==3)
        strcat(string,"MMM");
        x=x%1000;
    }
    

    if(x/100!=0){

        if(x/100==1)
        strcat(string,"C");
        else if(x/100==2)
        strcat(string,"CC");
        else if(x/100==3)
        strcat(string,"CCC");
        else if(x/100==4)
        strcat(string,"CD");
        else if(x/100==5)
        strcat(string,"D");
        else if(x/100==6)
        strcat(string,"DC");
        else if(x/100==7)
        strcat(string,"DCC");
        else if(x/100==8)
        strcat(string,"DCCC");
        else if(x/100==9)
        strcat(string,"CM");
        x=x%100;
    }
    

    if (x/10!=0){

        if(x/10==1)
        strcat(string,"X");
        else if(x/10==2)
        strcat(string,"XX");
        else if(x/10==3)
        strcat(string,"XXX");
        else if(x/10==4)
        strcat(string,"XL");
        else if(x/10==5)
        strcat(string,"L");
        else if(x/10==6)
        strcat(string,"LX");
        else if(x/10==7)
        strcat(string,"LXX");
        else if(x/10==8)
        strcat(string,"LXXX");
        else if(x/10==9)
        strcat(string,"XC");
        x=x%10;
    }

    if (x!=0){
    x=x%10;


    if(x==1)
        strcat(string, "I");
    else if(x==2)
        strcat(string, "II");
    else if(x==3)
        strcat(string, "III");
    else if(x==4)
        strcat(string, "IV");
    else if(x==5)
        strcat(string, "V");
    else if(x==6)
        strcat(string, "VI");
    else if(x==7)
        strcat(string, "VII");
    else if(x==8)
        strcat(string, "VIII");
    else if(x==9)
        strcat(string, "IX");
    }

    return string;
}