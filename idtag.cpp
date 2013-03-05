#include "idtag.h"
#include<fstream>
#include<string>
#include<iostream>
//constructor
idtag::idtag(std::string mp3):title(""),genre(""),artist(""),year(""),track(""),comment(""),album(""),tag(""){
	std::fstream song;

        //opening the mp3
        song.open(mp3.c_str());
	//checking existence of mp3 file
        if(!song.is_open())
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

		//reading the id3v1 tag
		song.read(waste,count-128);
		//printing the remaining bytes
		char *idtag = new char[128];
		
		song.read(idtag,128);
		for (int i=0;i<128;i++){
			if (i<2){
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
	}
}
//descructor
idtag::~idtag(){
	
}
//methods
std::string idtag::getTag(){
	return tag;
}
std::string idtag::getTitle(){
	return title;
}
std::string idtag::getArtist(){
	return artist;
}
std::string idtag::getAlbum(){
	return album;
}
std::string idtag::getYear(){
	return year;
}
std::string idtag::getComment(){
	return comment;
}
std::string idtag::getTrackNumber(){
	return track;
}
std::string idtag::getGenre(){
	return genre;
}
