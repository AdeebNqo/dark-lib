#ifndef IDT
#define IDT
#include<string>
class idtag{
	public:
		std::string tag("");
                std::string title("");
                std::string artist("");
                std::string album("");
                std::string year("");
                std::string comment("");
                std::string zero_byte("");
                std::string track("");
                std::string genre("");
		//constructor
		idtag(std::string mp3name);
		~idtag();
};
#endif
