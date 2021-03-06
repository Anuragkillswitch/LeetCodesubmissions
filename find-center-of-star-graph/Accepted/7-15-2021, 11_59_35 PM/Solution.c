// https://leetcode.com/problems/find-center-of-star-graph

int findCenter(int** edges, int edgesSize, int* edgesColSize){
    // only check the first two edges (edgesSize always >= 2 as n >= 3)
    if (edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1])
        return edges[0][0];
    return edges[0][1];
}