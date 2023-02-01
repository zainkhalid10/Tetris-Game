

#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;
using namespace sf;
int main(){
    srand(time(0));
    
    
    Texture obj1, obj2, obj3, obj4, obj5,obj6,obj7;
    
	


    obj1.loadFromFile( "img/tiles.png");
    obj2.loadFromFile( "img/background.png");
    obj3.loadFromFile( "img/frame.png");
    obj4.loadFromFile("img/s.png");
    obj5.loadFromFile("img/f.png");
    obj6.loadFromFile("img/tetris-invaders.png");
    obj7.loadFromFile("img/gover.png");
    
    Font font1, font2;
    
    font1.loadFromFile("font/technofosiano.ttf");
   font2.loadFromFile("font/ToonyNoodleNF.ttf");

    
    Sprite sprite(obj1), background(obj2), frame(obj3), shadow(obj4), leftbar(obj5) ,nextt(obj1);
    Sprite startscreen(obj6) ,gameover(obj7);
    
    int delta_x=0, colorNum=1;   // 1 - 7
    float timer=0, delay=0.5;
    bool rotate=0;
    bool fallcheck=0;
    int score=0,level=0;
    int highscore=0;
    int xxxx=0;
    int choosed=0;
    int ts=0;
    

	


    
    Clock clock;

       RenderWindow window(VideoMode( 1500, 844), title);
    while (window.isOpen())
    {
    
    Text ex("EXIT (E)",font1,25);
        ex.setPosition(360,10);
        
    if(choosed==0)
    {
   
    window.draw(startscreen);
    window.display();
    
     Event e;
        while (window.pollEvent(e)){   
                                                  
            if (e.type == Event::Closed)                  
                window.close();     
                                       
            if (e.type == Event::KeyPressed){
            
                if (e.key.code == Keyboard::P)            
                    choosed=1;                                             
                else if (e.key.code == Keyboard::E)     
                  choosed=2;                    
             }
        
        }
    
    
    
    }
    
    else if (choosed==2)
    {
    window.close();
    return 0;
    }
    else if(choosed==1){

rotate=0,delta_x=0,delay=0.5;
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        //---Event Listening Part---//
        Event e;
        while (window.pollEvent(e))
        {                                             //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed)              //If any other key (not cross) is pressed
            {
                if (e.key.code == Keyboard::Up)            //Check if the other key pressed is UP key
                    rotate = true;                         //Rotation gets on
                else if (e.key.code == Keyboard::Left)     //Check if the other key pressed is LEFT key
                  {
                  delta_x = -1; 			  //Change in X-Axis - Negative                    
                  }   
                else if (e.key.code == Keyboard::Right)    //Check if the other key pressed is RIGHT key
                 { 
                  delta_x = 1; 			         //Change in X-Axis - Positive
                  }                        
            }
        
        }
        
        
        if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.1;                                    //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
	
	
	
	if(Keyboard::isKeyPressed(Keyboard::Space))
	fallcheck=1;
	
	if(Keyboard::isKeyPressed(Keyboard::P))
	{
	choosed=1;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::S))
	{
		choosed=0;
	}
	
	if(Keyboard::isKeyPressed(Keyboard::E))
	{
		window.close();
	}
        
        
        Text text1("TETRIS",font1,25);
        text1.setPosition(360,10);
        
        Text t2("SCORE: ",font1,25);
        t2.setPosition(360,50);
        
        Text gamescore(to_string(score),font2,25);
        gamescore.setPosition(380,80);
        
        Text Levels("LEVEL:",font1,25);
        Levels.setPosition(360,150);
        	
        	
       Text levelno(to_string(level),font2,30);
        levelno.setPosition(380,190);
         	
        Text nextpiece("Next piece:",font1,25);
        nextpiece.setPosition(330,230);
        
        
         ifstream scorefile;
        scorefile.open("Scoress.txt");
        while(scorefile>>ts)
        {
        if(highscore<ts)
        {
        highscore=ts;
        
        }
        
        
        }
      
        scorefile.close();
        
        
        
        
        Text hs("High Score:",font1,25);
        hs.setPosition(360,350);
        
        Text hsv(to_string(highscore),font1,25);
        hsv.setPosition(360,380);
        
	
	  
       
        
        
        

        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///
        
        levelcheck(level,score);
        fall(fallcheck);
         move(delta_x);      
	rotatecheck(rotate);	
	linecheck(score);	                                                  //score and line deletition	
         shado();                 
         fallingPiece(timer, delay,colorNum);               //Example: fallingPiece() function is called here

        
    //  savetofile(score);
        
        
        
    
        
       
        
        
        for(int i=0;i<9;i++)
        {
          if(gameGrid[0][i])
           {
           
           RenderWindow ggoo(VideoMode( 1000, 1000), title);
          while(ggoo.isOpen()){
          ggoo.draw(gameover);
          ggoo.display();
          choosed=0;
       //   window.close();
       while (window.pollEvent(e))
        {                                             //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed)              //If any other key (not cross) is pressed
            {
                if (e.key.code == Keyboard::E)            //Check if the other key pressed is UP key
                    ggoo.close();                        //Rotation gets on
                    
            }
        
        }
       
       
       
       
            }
            }
          }



     
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////

       window.draw(text1);
       window.draw(t2);
       window.draw(gamescore);
       window.draw(Levels);
       window.draw(levelno);
       window.draw(background);
       window.draw(nextpiece);
       window.draw(hs);
       window.draw(hsv);

       
    
       
         
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                shadow.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18)); 
              nextt.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));              
                sprite.setPosition(j*18,i*18);
                shadow.setPosition(j*18,i*18);

                sprite.move(28,31); //offset
                shadow.move(28,31);

                window.draw(sprite);
                window.draw(shadow);

            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            
            nextt.setPosition((point4[i][0]*18)+350,(point4[i][1]*18)+300);
            
            shadow.setPosition((point3[i][0]*18),((point3[i][1])*18));
            
            sprite.move(28,31);
            shadow.move(28,31);

            window.draw(sprite);
            window.draw(shadow);
            window.draw(nextt);
             window.draw(hs);
            
          }
          
          
        //---The Final on Which Everything is Drawn Over is Loaded---//
        window.draw(frame);
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    
  
    
    }
      ofstream scorefile;
   scorefile.open("Scoress.txt",ios::out | ios::app);
   scorefile<<score;
   scorefile<<"\n";
   scorefile.close();
    return 0;
}
