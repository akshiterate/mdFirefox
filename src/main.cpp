#include <md4c-html.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

//this is a callback function, the parameters to this can be found in /external/md4c/src/md4c-html.h
void process_output(const MD_CHAR *text,MD_SIZE size,void *userdata){
	std::string *html = static_cast<std::string*>(userdata);
	html->append(text,size);
}

int main(int argc,char **argv){
	if(argc != 2){
		std::cerr<<"incorrect number of arguments";
		return -1;
	}
	std::string path(argv[1]);
	std::ifstream h_file(path);
	
	if(!h_file){
		std::cerr<<"enter a valid path.";
		return -1;
	}
	std::string md;
	std::string line;
	while(getline(h_file,line)){
		md+=line;
	}
	std::ifstream t_file("template.html");
	if(!t_file){
		std::cerr<<"template is missing!";
		return -1;
	}
	std::string ml;
	std::string html;
	while(getline(t_file,ml)){
		html+=ml;
	}
	html+="\n";
	md_html(md.c_str(),md.size(),process_output,&html,MD_DIALECT_COMMONMARK,MD_HTML_FLAG_XHTML);
	std::cout<<html<<std::endl;
	std::ofstream ofile("output.html");
	ofile<<html;
	return 0;
}

