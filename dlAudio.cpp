#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    bool dl = 0;
    bool help = 0;
  	std::string url,of = "best";
    for (int i = 1; i < argc; ++i)
    {
    	std::string arg = argv[i];
    	if (arg == "-url" && argc >= 3)
    	{
    		dl = 1;
    		url = argv[i+1];
    	}
    	if (arg == "-of" && argc >= 5)
    		of = argv[i+1];
    	if (arg == "-h" && argc == 2)
    	{
    		help = 1;
    		std::cout<<"-ulr {ulr} to download best quality\n-of {of} [wav,mp3, ...etc]\n";
    	}
    }
    if(argc <= 2 && !help) std::cout<<"-ulr {ulr} to download best quality\n-of {of} [wav,mp3, ...etc]\n";
    if (dl)
    {
    	std::string exec = "youtube-dl --audio-format " + of + " -x " + url;
    	system(exec.c_str());
    }
    return 0;
}