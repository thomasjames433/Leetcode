int romanToInt(char* s) {

    int a=0;
    int i=0;
    if(*s=='M'){
        if(*(s+1)=='M' && *(s+2)=='M'){
        a=3000;
        i+=3;
        }
        else if(*(s+1)=='M'){
        a=2000;
        i+=2;
        }
        else{
        a=1000;
        i++;
        }
    }



    if(*(s+i)=='C'){
        if(*(s+i+1)=='M'){
            a+=900;
            i+=2;
        }
        else if(*(s+i+1)=='D'){
            a+=400;
            i+=2;
        }
        else if(*(s+i+1)=='C' && *(s+i+2)=='C'){
        a+=300;
        i+=3;
        }
        else if(*(s+i+1)=='C'){
        a+=200;
        i+=2;
        }
        else{
        a+=100;
        i++;
        }
    }

    else if(*(s+i)=='D'){
        
        if(*(s+i+1)=='C' && *(s+i+2)=='C' &&*(s+i+3)=='C'){
        a+=800;
        i+=4;
        }
        else if(*(s+i+1)=='C' && *(s+i+2)=='C'){
        a+=700;
        i+=3;
        }
        else if(*(s+i+1)=='C'){
        a+=600;
        i+=2;
        }
        else {
            a+=500;
            i++;
        }
        
    }


    if(*(s+i)=='X'){
        if(*(s+i+1)=='C'){
            a+=90;
            i+=2;
        }
        else if(*(s+i+1)=='L'){
            a+=40;
            i+=2;
        }
        else if(*(s+i+1)=='X' && *(s+i+2)=='X'){
        a+=30;
        i+=3;
        }
        else if(*(s+i+1)=='X'){
        a+=20;
        i+=2;
        }
        else{
        a+=10;
        i++;
        }
    }

    else if(*(s+i)=='L'){
        
        if(*(s+i+1)=='X' && *(s+i+2)=='X' &&*(s+i+3)=='X'){
        a+=80;
        i+=4;
        }
        else if(*(s+i+1)=='X' && *(s+i+2)=='X'){
        a+=70;
        i+=3;
        }
        else if(*(s+i+1)=='X'){
        a+=60;
        i+=2;
        }
        else {
            a+=50;
            i++;
        }
        
    }


    if(*(s+i)=='I'){
        if(*(s+i+1)=='X'){
            a+=9;
            i+=2;
        }
        else if(*(s+i+1)=='V'){
            a+=4;
            i+=2;
        }
        else if(*(s+i+1)=='I' && *(s+i+2)=='I'){
        a+=3;
        i+=3;
        }
        else if(*(s+i+1)=='I'){
        a+=2;
        i+=2;
        }
        else{
        a+=1;
        i++;
        }
    }

    else if(*(s+i)=='V'){
        
        if(*(s+i+1)=='I' && *(s+i+2)=='I' &&*(s+i+3)=='I'){
        a+=8;
        i+=4;
        }
        else if(*(s+i+1)=='I' && *(s+i+2)=='I'){
        a+=7;
        i+=3;
        }
        else if(*(s+i+1)=='I'){
        a+=6;
        i+=2;
        }
        else {
            a+=5;
            i++;
        }
        
    }

    return a;
}