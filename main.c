#include <stdio.h>
#include <stdlib.h>

char maze[5][105];
int total=0;
long long shp=0;
void solve(int str,int stc,char map[5][105],long long count,int boundr,int boundc){





//move up down left right
int move[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
  //printf("%d countd\n",count);
for(int i=0;i<4;i++){
    if(str+move[i][0]<boundr && str+move[i][0]>=0 && stc+move[i][1]<boundc && stc+move[i][1]>=0 && map[str+move[i][0]][stc+move[i][1]]=='$'){// if the idex is legal

            //make the floor unreachable
            map[str+move[i][0]][stc+move[i][1]]='#';
       solve(str+move[i][0],stc+move[i][1],map,count+1,boundr,boundc);
     //once the function is over switch back the char
      map[str+move[i][0]][stc+move[i][1]]='$';
    }
else if(str+move[i][0]<boundr && str+move[i][0]>=0 && stc+move[i][1]<boundc && stc+move[i][1]>=0 && map[str+move[i][0]][stc+move[i][1]]=='F'){
  //printf("fuck yeah\n");
   total+=1;
   long long finall=count+1;
 if(shp==0 && finall!=0){
    shp=finall;
 }
 else{
    if(finall!=0 && finall<shp)
        shp=finall;
 }

}
}
return;






}
int main()
{

   int n;
   scanf("%d",&n);

   for(int q=0;q<n;q++){
        //reset the global variable
        total=0;
   shp=0;
    int row,col;
    scanf("%d %d",&row,&col);
    for(int i=0;i<row;i++)
        scanf("%s",maze[i]);
//find s
int sr,sc;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(maze[i][j]=='S'){
            sr=i;sc=j;
        }
    }
}

solve(sr,sc,maze,0,row,col);
if(shp==0)
    shp=-1;
printf("%d %lld\n",total,shp);


   }
    return 0;
}
