#include <iostream>
#include <string>
#include <cstring>
int main(int argc, char** argv)
{
    bool dl = 0, help = 0, list = 0, id = 0;
    
  	std::string exec, url, of = "best";
  	
    for (int i = 1; i < argc; ++i)
    {
    	std::string arg = argv[i];

        if (arg == "-url" && argc >= 3)
    	{
    		dl = 1;
    		url = argv[i+1];
    		if (url.find("list") != std::string::npos) list = 1;
    		if (url.find("?v=") != std::string::npos) id = 1;
    	}

    	if (arg == "-of" && argc >= 5) of = argv[i+1];

    	if (arg == "-h" && argc == 2 )
    	{
    		help = 1;
    		std::cout<<"-ulr {ulr} to download best quality\n-of {of} [wav,mp3, ...etc]\n";
    	}
    }

    if(argc <= 2 && !help) std::cout<<"-ulr {ulr} to download best quality\n-of {of} [wav,mp3, ...etc]\n";

    if (id && list ) 
    {
    	
    	int id_pos = url.find("v=");
    	int list_pos = url.find("list=");
        int len = list_pos - id_pos;
        url.replace(id_pos,len,"");

    }
    if (dl)
    {	
        exec = "youtube-dl --extract-audio --audio-format " + of +" -cio \"%(title)s.%(ext)s\" " + url;
    	if (!list) exec = "youtube-dl --audio-format " + of + " -x " + url; 
    	system(exec.c_str());
    }
    return 0;
}
