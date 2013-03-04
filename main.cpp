#include<string>
#include<iostream>
#include<fstream>
int main(){
char tag[4]; //the 3 character (byte) portion of the mp3 file
char Title[31]; //30 characters (bytes)
char artist[31]; //30 characters (bytes)
char album[31]; //30 characters (bytes)
char year[5]; //4 characters (bytes)
char comment[29]; //28 characters (bytes)
	std::string mp3 = "/home/mthjac011/Downloads/Downloads/10 - Lovesong.mp3";
	//std::fstream song(mp3.c_str());
	std::fstream mp;
	
	//opening the mp3
	mp.open(mp3.c_str());
	if(!mp.is_open())
	{
		std::cout<<"fail to open the file";
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
