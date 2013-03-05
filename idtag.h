#ifndef IDT
#define IDT
#include<string>
class idtag{
	public:
		idtag(std::string mp3name);
                ~idtag();
		std::string tag;
                std::string title;
                std::string artist;
                std::string album;
                std::string year;
                std::string comment;
                std::string zero_byte;
                std::string track;
                std::string genre;
		std::string getTag();
		std::string getTitle();
		std::string getArtist();
		std::string getAlbum();
		std::string getYear();
		std::string getComment();
		std::string getTrackNumber();
		std::string getGenre();
	private:
		std::string getZero_byte();
		
};
#endif
