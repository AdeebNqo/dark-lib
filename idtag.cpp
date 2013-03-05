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
		//getting total bytes of mp3
		std::ifstream file(mp3.c_str());
		char byte;
		int count=0;
		while(!file.eof()){
			count++;
			file.get(byte);
		}
		//reading the first 'useless' bytes to our waster bin
		char *waste = new char[count-128];
		mp.read(waste,count-128);
		//printing the remaining bytes
		char *idtag = new char[128];
		mp.read(idtag,128);
		std::string tag("");
		std::string title("");
		std::string artist("");
		std::string album("");
		std::string year("");
		std::string comment("");
		std::string zero_byte("");
		std::string track("");
		std::string genre("");
		for (int i=0;i<128;i++){
			if (i<3){
				tag+=idtag[i];
			}
			else if (i<32){
				title+=idtag[i];
			}
			else if (i<62){
				artist+=idtag[i];
			}
			else if (i<92){
				album+=idtag[i];
			}
			else if (i<96){
				year+=idtag[i];
			}
			else if (i<126){
				comment+=idtag[i];
			}
			else if (i<127){
				zero_byte+=idtag[i];
			}
			else if (i<128){
				track+=idtag[i];
			}
			else if (i<129){
				genre +=idtag[i];
			}
		}
		std::cout<<genre<<std::endl;
		/*
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
                }*/
	}
}
//descructor
idtag::~idtag(){
	
}
//methods
