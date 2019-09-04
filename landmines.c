#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<stdbool.h>
#include<limits.h>
#define R 12
#define C 10

int row[4] = {0,-1,0,1};
int col[4] = {-1,0,1,0};

bool valid(int r, int c) {

	if (r >=0 && 
	    r < R &&
	    c >=0 &&
	    c < C) {
	return true;
	}
	return false;

}

void marksafe(int mat[R][C]) {
	int i =0, j = 0;
	for(i =0; i < R; ++i) {
		for(j=0; j < C; ++j) {
		
		if (mat[i][j] == 0 ) {
		int k = 0;
			for (k = 0; k < 4; ++k) {
			if (valid(i+row[k], j+col[k])) {
				mat[i+row[k]][j+col[k]] = -1;
			}								
			}
		}
		}
	}

	for (i = 0; i < R; ++i) {
	for (j = 0; j < C; ++j) {
		if (mat[i][j] == -1) {
			mat[i][j] =0;
		}
	}
	}
}
void print(int mat[R][C]) {
	int i =0;
	int j =0;
    for (i = 0; i < R; i++) 
    { 
        for ( j = 0; j < C; j++) 
        { 
            printf("%d  ",mat[i][j]); 
        } 
        printf("\n");
    }
}

bool safe(int i, int j, int mat[R][C], int visited[R][C]) {

	if (valid(i,j) && mat[i][j] ==1 && visited[i][j] == 0) {
		return true;
	}
	return false;
}
#define MIN(x,y) x<y?x:y
void util(int mat[R][C],int i, int j, int dist, int *min_dist, int visited[R][C]) {

	if ( j == C -1) {
	     if (mat[i][j] == 1)
	        *min_dist = MIN(dist,*min_dist);	
	     return;
	}

	visited[i][j] = 1;	
	int k =0;
	for (k = 0; k < 4; ++k) {
	     if (safe(i+row[k], j+col[k], mat, visited)) {
		util(mat, i+row[k], j+col[k], dist +1, min_dist, visited);
	     }
	}
	visited[i][j] = 0;	

}


void findshortestPath(int mat[R][C]) {
	int min_dist = INT_MAX;
	
	int visited[R][C];
	memset(visited, 0, sizeof(visited));
	
        int dis = 0;
	printf("Initial =============\n");
	print(mat);
	printf("=============\n");
	marksafe(mat);	
	int i =0;
	for (i=0; i < R; ++i) {
		dis = 0;
		if (mat[i][0] == 1) {
			util(mat, i, 0,dis, &min_dist, visited);	
		}	
	}
	
	print(mat);
	printf("\n ======== shortest path is %d",min_dist);

}

int main() {

	int mat[R][C] = 
    { 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 0, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 0, 1, 1, 1, 1, 1, 1, 0, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 0, 1, 1, 1, 1, 0, 1, 1, 1, 1 }, 
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }, 
        { 1, 1, 1, 0, 1, 1, 1, 1, 1, 1 } 
    }; 

    findshortestPath(mat);

    

}

