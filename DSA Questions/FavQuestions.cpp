/* 
    If found '1' move in right direction, start from (0,0)

/\   -------->    found 1 move right
 |   0, 0, 0, 1   |
 |   0, 0, 0, 0   |
 |   0, 0, 0, 0   |
 |   1, 0, 0, 1   \/
     <--------    found 1 move right

*/
int i = 0, j = 0, dir = 0;

while(true){
    int dir = (mat[i][j] + dir) % 4;
    
    if(dir == 0) j++;
    else if(dir == 1) i++;
    else if(dir == 2) j--;
    else if(dir == 3) i--;

    if(i < 0){ i++; break;}
	else if(i >= row){ i--; break;}
	else if(j < 0){ j++; break;}
	else if(j >= col){ j--; break;}
}
cout<< i <<" "<< j <<endl;