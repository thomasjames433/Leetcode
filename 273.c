void addword(int a, char *str){
    if (a == 1) strcat(str, "One ");
    else if (a == 2) strcat(str, "Two ");
    else if (a == 3) strcat(str, "Three ");
    else if (a == 4) strcat(str, "Four ");
    else if (a == 5) strcat(str, "Five ");
    else if (a == 6) strcat(str, "Six ");
    else if (a == 7) strcat(str, "Seven ");
    else if (a == 8) strcat(str, "Eight ");
    else if (a == 9) strcat(str, "Nine ");
}

void intword(int a, char *str) {
    if (a / 100 != 0) {
        addword(a/100, str);
        strcat(str, "Hundred ");
    }
    a = a % 100;

    if (a < 20 && a > 9) {
        if (a == 10) strcat(str, "Ten ");
        if (a == 11) strcat(str, "Eleven ");
        else if (a == 12) strcat(str, "Twelve ");
        else if (a == 13) strcat(str, "Thirteen ");
        else if (a == 14) strcat(str, "Fourteen ");
        else if (a == 15) strcat(str, "Fifteen ");
        else if (a == 16) strcat(str, "Sixteen ");
        else if (a == 17) strcat(str, "Seventeen ");
        else if (a == 18) strcat(str, "Eighteen ");
        else if (a == 19) strcat(str, "Nineteen ");
        return;
    } else if (a >= 20) {
        if (a/10 == 2) strcat(str, "Twenty ");
        else if (a/10 == 3) strcat(str, "Thirty ");
        else if (a/10 == 4) strcat(str, "Forty ");
        else if (a/10 == 5) strcat(str, "Fifty ");
        else if (a/10 == 6) strcat(str, "Sixty ");
        else if (a/10 == 7) strcat(str, "Seventy ");
        else if (a/10 == 8) strcat(str, "Eighty ");
        else if (a/10 == 9) strcat(str, "Ninety ");
    }
    a %= 10;
    addword(a, str);
}

char* numberToWords(int num) {

    char *str=(char*)malloc(3000*sizeof(char));
    str[0]='\0';
    if(num==0){
        strcat(str,"Zero");
        return str;
    }
    if(num/1000000000!=0){
        intword(num/1000000000,str);
        strcat(str,"Billion ");
    }
    num%=1000000000;
    if(num/1000000!=0){
        intword(num/1000000,str);
        strcat(str,"Million ");
    }
    num%=1000000;
    if(num/1000!=0){
        intword(num/1000,str);
        strcat(str,"Thousand ");
    }
    num%=1000;
    intword(num,str);
    str[strlen(str)-1]='\0';
    return str;
}