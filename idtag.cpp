#include "idtag.h"
#include<fstream>
#include<string>
#include<iostream>
//constructor
idtag::idtag(std::string mp3){
	std::fstream mp;

        //opening the mp3
        mp.open(mp3.c_str());
        if(!mp.is_open())
        {
                std::cerr<<"failed to open the file"<<std::endl;
        }
        else
        {
                mp.read(tag,3);//read the tag bytes
                tag[3]='\0';
                mp.read(Title,30);//read the song titile
                Title[30]='\0';//read the title bytes
                mp.read(artist,30);//read the artist bytes
                artist[30]='\0';
                mp.read(album,30);//read the album bytes
                album[30]='\0';
                mp.read(year,30);//read theyear bytes
                year[30]='\0';
                mp.read(comment,28);//read the comments bytes
                comment[28]='\0';
                for(int y=0;y<30;y++)
                {
              		std::cout<<Title[y]<<"\n";
                }
	}
}
//descructor
idtag::~idtag(){
	
}
//methods
