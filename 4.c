double findMedianSortedArrays(int* num1, int num1size, int* num2, int num2size) {
    if(num1size==0){
        if(num2size%2==0){
            double c;
            c=(double) (*(num2+num2size/2-1)+*(num2+num2size/2))/2;
            return c;
        }
        else{
            double c;
            c=(double) *(num2+num2size/2);
            return c;
        }
    }
    
    else if(num2size==0){
        if(num1size%2==0){
            double c;
            c=(double) (*(num1+num1size/2-1)+*(num1+num1size/2))/2;
            return c;
        }
        else{
            double c;
            c=(double) *(num1+num1size/2);
            return c;
        }
    }
    else{
        int a,b;
        int i1=0;
        int i2=0;
        while(i1+i2<(num1size+num2size)/2+1){
            if(i1<num1size && (i2>=num2size || *(num1+i1)<=*(num2+i2))){
                a=*(num1+i1);
                i1++;
                
            }
            else{
                a=*(num2+i2);
                i2++;
                
            }
            if(i1+i2<(num1size+num2size)/2+1){
                if(i1<num1size && (i2>=num2size || *(num1+i1)<=*(num2+i2))){
                    b=*(num1+i1);
                    i1++;
                    
                }
            
                else{
                    b=*(num2+i2);
                    i2++;
                }
            }
        }
        if((num1size+num2size)%2==0){
            double c;
            c=(double) (a+b)/2;
            return c;
        }
        else{
            if(((num1size+num2size)+1)%4==0)
            return b;
        }
        return a;
    }
    
}