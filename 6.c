char* convert(char* s, int num) {
    int len=0;
    while (*(s+len)!='\0')
    len++;
    char string[len+1];

    int x=0;
    int k=0;
    int y=0;

    while(x<num){
        if(num>len){
            while( y<len){
                string[y]=*(s+y);
                y++;
            }
        }
        else if(k==0 && num==1){
            while( y<len){
                string[y]=*(s+y);
                y++;
            }
        }
        else if(k==0 &num!=1){
            while( k<len){
                string[y]=*(s+k);
                y++;
                k+=num-1+num-2+1;
            };
        }
        else{
            int change=0;
            string[y]=*(s+k);
            y++;
            while(k<len){
                if(change==0){
                    k+=2*(num-x-1);
                    if(k>=len)
                    break;
                    if(x!=num-1){
                        string[y]=*(s+k);
                        y++;
                        }
                    change=1;
                }
                else if(change==1){
                    k+=2*(x);
                    if(k>=len)
                    break;
                    string[y]=*(s+k);
                    y++;
                    change=0;
                }
            }
        }
        x++;
        k=x;
    
    };
    string[len]='\0';
    s=string;
    
     printf("%s",string);

    return s;
}