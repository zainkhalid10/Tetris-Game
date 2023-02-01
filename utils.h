




const char title[] = "Tetris-Project";

//---Height and Width of the Actual Interactive Game---//
const int M = 20;   //Number of rows for a piece to cover on the screen (not the entire screen) = 20
const int N = 10;   //Number of columns for a piece to cover on the screen (not the entire screen) = 10

//---The Actual Interactive Game Grid - Built Over (MxN)---//
int gameGrid[M][N] = {0};

//---To Hold the Coordinates of the Piece---//
int point_1[4][2]={0}, point_2[4][2]={0};
int point3[4][2]={0},point4[4][2]={0};                          //shaddow


//---Check Uncertain Conditions---//
bool anamoly(){
    for (int i=0;i<4;i++){
        if (point_1[i][0]<0 || point_1[i][0]>=N || point_1[i][1]>=M)                                                       //ensure starting from particular position
            return 0;
        else if (gameGrid[point_1[i][1]][point_1[i][0]])                                                                      //prevents blocks to overerite eachother
            return 0;
            }
    return 1;
    
};





bool anamoly2(){
    for (int i=0;i<4;i++){
        if (point3[i][0]<0 || point3[i][0]>=N || point3[i][1]>=M)                                                       //ensure starting from particular position
            return 0;
        else if (gameGrid[point3[i][1]][point3[i][0]])                                                                      //prevents blocks to overerite eachother
            return 0;
            }
    return 1;
    
};
