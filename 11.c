int maxArea(int* height, int heightSize) {
    int area=0;
    int left=0;
    int right=heightSize-1;
    while(left<right){
        int min;
        if(*(height+left)>=*(height+right))
        min=*(height+right);
        else
        min=*(height+left);
        if(area<min*(right-left))
        area=min*(right-left);
         if (min==*(height+left)) {
            left++;
        } else {
            right--;
        }
    }
    return area;
}