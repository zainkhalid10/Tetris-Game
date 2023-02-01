

//---Piece Starts to Fall When Game Starts---//


void shado();

void fallingPiece(float& timer, float& delay,int &colorNum)
{

    if (timer>delay)
    {
    
        for (int i=0;i<4;i++){ 
        point_2[i][0]=point_1[i][0];                                                                           //replacing col from p1 -> p2
        point_2[i][1]=point_1[i][1];									       //replacing rows p1->p2
        point_1[i][1]+=1;                    							               //How much units downward  // down movement
        }
        
        
        if (!anamoly())
        {
        
        
                   
        
        	for(int i=0;i<4;i++)
        	{
        		gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;   
        		       		 			
        	}
        	        		
            colorNum=1+rand()%5;
            int n=rand()%8;
            for (int i=0;i<4;i++){
        point4[i][0]=point_1[i][0] ;
        point4[i][1]=point_1[i][1] ;
                   }
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
              for (int i=0;i<4;i++)
              {
                   point_1[i][0] = BLOCKS[n][i] % 2;
                   point_1[i][1] = BLOCKS[n][i] / 2;  
                   
                              for(int i=0;i<4;i++)
                            {
                            point4[i][0]=point_1[i][0];
                            point4[i][1]=point_1[i][1];
                            }
                   
                }
                    
        }
        timer=0;  
        delay=0.5;
        

    }
  
  
  
  
  
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

void move(int &delta_x)
{
        if (delta_x)
        {
     	   for(int i=0;i<4;i++)
     	   {
		point_2[i][0]=point_1[i][0];
		point_1[i][0]+=delta_x;				     
     	   }
          	 
          	  if(!anamoly())
          	  for(int i=0;i<4;i++)
          	  {
          	  point_2[i][0]=point_1[i][0];
		  point_1[i][0]-=delta_x;		 
		 
		  }
       	          
           }
delta_x=0;
}


void rotatecheck( bool &rotate)
{
if(rotate){
for(int i=0;i<4;i++)
{
point_2[i][0]=point_1[i][0];
point_2[i][1]=point_1[i][1];
}

	         int newpoint[4][2]={0};
	         
		 newpoint[0][0]=point_1[0][0];
		 newpoint[0][1]=point_1[0][1];

			for(int i=0;i<4;i++)
			{
			int x=point_1[i][1]-newpoint[0][1];
			int y=point_1[i][0]-newpoint[0][0];
			
			point_1[i][0]=newpoint[0][0]-x;
			point_1[i][1]=newpoint[0][1]+y;
			}
			
			if(!anamoly()){
				for(int i=0;i<4;i++)
			
			
				{
					point_1[i][0]=point_2[i][0];
					point_1[i][1]=point_2[i][1];
				}
	}


    }
    rotate=0;
        
}


void linecheck(int &score)
{
 int NewM=M-1;                                        //19
      
      for(int i=M-1;i>0;i--)                       // 19    to 1
      {
      	 int count=0;
       	 for(int c=0;j<N;j++)                      //   0 to 9
      	 {
      		if(gameGrid[i][c])                   
      		count++;     		
      		gameGrid[NewM][j]=gameGrid[i][c];
      		
      	 }
        if(count<N)
        {
         NewM--;        
         }
         else if(count==10)
         score+=10;
      
      }

}


void shado()
{
	for(int i=0;i<4;i++){
		point3[i][0]=point_1[i][0];
		point3[i][1]=point_1[i][1];
	}


	while(anamoly2()){
		for(int i=0;i<4;i++){
		 point3[i][1]+=1;
		}
	}
		if(!anamoly2()){
			for(int i=0;i<4;i++){
			point3[i][1]-=1;
			}									
		}			
}


void fall(bool &fallcheck)
{

	if(fallcheck)
	{
		while(anamoly())
		{
			for(int i=0;i<4;i++)
			{
			point_1[i][1]+=1;
			}
		}
		if(!anamoly())
			{
				for(int i=0;i<4;i++){
				point_1[i][1]-=1;
				}
			}
		
			
			
	}
fallcheck=0;
}







void levelcheck(int &level,int s)
{
switch(s)
{
case 0 ... 49:
level=1;
break;
case 50 ... 99:
level=2;
break;
case 100 ... 150:
level=3;
break;

}

}

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
