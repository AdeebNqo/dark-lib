#dark-lib

This is a simple library reading the id3v1 tags from mp3 files
in c++.

##Usage
		
		std::string mp3("/home/user/Music/07 Bronu Msra - Natalie.mp3");
	        idtag id(mp3);
		std::string artistName = id.getArtistName();
		std::string albumName = id.getAlbumName();

