#ifndef IDT
#define IDT
#include<string>
class idtag{
	public:
		char tag[4]; //the 3 character (byte) portion of the mp3 file
		char Title[31]; //30 characters (bytes)
		char artist[31]; //30 characters (bytes)
		char album[31]; //30 characters (bytes)
		char year[5]; //4 characters (bytes)
		char comment[29]; //28 characters (bytes)
		//constructor
		idtag(std::string mp3name);
		~idtag();
};
#endif
