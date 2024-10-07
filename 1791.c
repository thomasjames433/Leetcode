int findCenter(int** edges, int edgesSize, int* edgesColSize) {
    int x=edges[0][0];
    int y=edges[0][1];
    if(edges[1][0]==x || edges[1][0]==y)
        return edges[1][0];
    else 
        return edges[1][1];
}