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




/*
	9 1 4 9 4
      + 1 3 4 5 1
-----------------
      1 0 4 9 4 5
 
*/
vector<int> vec1 = {9,1,4,9,4};
vector<int> vec2 = {1,3,4,5,1};
vector<int> ans;
int size1 = vec1.size()-1, size2 = vec2.size()-1, ifHaveCarry = 0;
while(size1 >= 0 || size2 >= 0){
     int i = size1 >= 0 ? vec1[size1--] : 0;
     int j = size2 >= 0 ? vec2[size2--] : 0;
     int sum = i + j + ifHaveCarry;
     ans.push_back(sum%10);
     ifHaveCarry = sum/10;
}
ans.push_back(ifHaveCarry);
