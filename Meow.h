#include <iostream>
#include <regex>
#include <string>
#include <fstream>

using namespace std;
class Meow
 {
 public:
 	map<string,string> data = {{"VERSION","2.0.6"}};
 	string meow = "Meow";
	string gtext = "";
 	void worker(string text,bool t){
 		smatch m;
 		if (regex_search(text, m, regex(R"((\$[[:alpha:]][[:alnum:]]*))")))
        		text = text.replace(m[1].first,m[1].second,existV(std::string(m[1].first, m[1].second),data));
		

 		regex rg_filter("@"+meow+"(:on|:off|)");
 		regex rg_code(meow+".gets\\(([0-9,]+)\\)");
 		regex rg_value("var.([a-zA-Z0-9]+) =[ ]{0,1}(.*)");
 		regex rg_ucode(meow+".puts\\((.*)\\)");
		regex rg_system(meow+".system\\((.*)\\)");
		regex rg_range(meow+".1to\\(([0-9,]+)\\)");
		regex rg_setting("@set ([a-zA-Z0-9]+)");
		regex rg_text("@set.text\\((.*)\\)");

	 	if(regex_match(text,rg_code)){
	 		smatch value;
	    	regex_search(text, value,rg_code);
	    	vector<string> v = splitString(value[1],',');
	    	int i ;
	    	for(auto x : v){
	    		i = stoi(x);
	 			cout<<char(i);
	 		}
	 	}
		else if(regex_match(text,rg_range)){
			smatch value;
	    	regex_search(text, value,rg_range);
			Mood = true;
			Meowput(to_i(value[1]));
			Mood = false;
		}
		else if(regex_match(text,rg_text)){
	 		smatch value;
	    	regex_search(text, value,rg_text);
			gtext = value[1];
	 	}
	 	else if(regex_match(text,rg_system)){
	 		smatch value;
	    	regex_search(text, value,rg_system);
	    	string s = value[1];
			system(s.c_str());
	 	}
		else if(regex_match(text,rg_setting)){
	 		smatch value;
	    	regex_search(text, value,rg_setting);
			meow = value[1];
	 	}
		else if(text == "exit"){
			exit(0);
		}
	 	else if(regex_match(text,rg_ucode)){
	    	smatch value;
	    	regex_search(text, value,rg_ucode);
	    	string v = value[1];
	    	for(int i=0;i < v.length();i++){
	    		//cout<<v[i];
	    		//char c = v[i];  // Access the string representation and then the character
            	Meowput(static_cast<int>(v[i]));
            	if(i+1 < v.length()){
            		cout<<",";}
	    	}

	    }else if(regex_match(text,rg_filter)){
	    	smatch value;
	    	regex_search(text,value,rg_filter);
	    	if(value[1] == "")
	    		put(Mood);
	    	else{
	    		if(value[1] == ":on")
	    			Mood = true;
	    		else
	    			Mood = false;
	    		//put(Mood);
	    	}
	    }else if(text.at(0) == '#'){

	    }else if(regex_match(text,rg_value)){
    		smatch value;string input;
		    regex_search(text, value,rg_value);
			if(value[2] == meow+".input"){
				getline(cin,input);
			}else
				input = value[2];
		    if(!exist(value[1],data))
				data.insert({value[1],input});
			else{
				auto itr = data.find(value[1]);
				if(itr != data.end()){
					(*itr).second = input;
				}
			}

	    }else{
	    	cout<<"Error Command in this line \n=>"<<text<<endl;
	    	if(t)
	    		exit(0);
	    }
}
string decode(string text){
	string rtn = "";int no; 
	for(auto a : split(text,",")){

		no = split(a,meow).size()-1;
		cout<<no;
	 	cout<<char(no);

	}
 return rtn;
}

vector<string> readfile(string text){
		ifstream file(text.c_str());
		if(!file){
    	cout<<text<<": No such file or directory "<<endl;
    	exit(0);
    	return {text+": No such file or directory "};
    }else{
    string line;
    vector<string> lines;
    while (getline(file, line)){
    	if(line != "")
    		
    		lines.push_back(line); 
    }
    file.close();
    return lines;
	}
}
void passive(){
	string text = GetEnv("HOME");
	text = text+"/.Meowrc";
	ifstream file(text.c_str());
	if(!file){
		ofstream { text.c_str() };
	}else{
	string line;
    while (getline(file, line)){
		if(line != "")
    	 worker(line,true);
    }
	}

}
void help(int v){
	if(v == 0){
	cout<<"Usage: Meow [--] [programfile] [arguments]\n"
				  "  -h              show this message \n"
				  "  -v              print the version number\n"
				  "  -e 'command'    one line of script\n"
				  <<endl;
	}else if(v==1){
			cout<<"  .help show this message\n"
				  "  .exit Exit this program\n"
				  <<endl;

	}
}
bool terminalcmd(string text){
	if(text == ".exit")
		exit(0);
	else if(text == ".help")
		help(1);
	else
		return false;
	return true;

}


inline bool exists_ (const std::string& name) {
    ifstream f(name.c_str());
    return f.good();
}

 private:
 	map<string,int> line ;
 	bool Mood = false;
 	//int line = 0;
	string GetEnv( const string & var ) {
     const char * val = getenv( var.c_str() );
     if ( val == nullptr ) { // invalid to assign nullptr to string
         return "";
     }
     else {
         return val;
     }
}
 	void puts(string text){
 		cout<<text<<endl;
 	}void put(bool id){
 		if(id == true)
 			cout<<"on"<<endl;
 		else
 			cout<<"off"<<endl;
 	}void Meowput(int no){
 		if(Mood == true){
	 		int j=0;
	 		while(j < no ){
				if(gtext != ""){
					cout<<gtext;j++;
				}else{
	 			cout<<meow;j++;
	 			}
			//if(j+1 < no){
            		cout<<" ";//}
	 		}
 		}else
 			cout<<no;
 	}vector<string> splitString(const string& s, char delimiter) {
	    vector<string> tokens;
	    stringstream ss(s);
	    string token;
	    while (getline(ss, token, delimiter)) {
	        tokens.push_back(token);
	    }
	    return tokens;
	}bool exist(string text,map<string,string> data){
    for (auto itr = data.begin(); itr != data.end(); ++itr)
    {
    if (text == itr->first)
        {
            return true;
        }
    }
    return false;
}string existV(string text,map<string,string> data){
	text.erase(0,1);
    for (auto itr = data.begin(); itr != data.end(); ++itr)
    {
    if (text == itr->first)
        {
            return itr->second;
        }
    }
    return "$"+text;
}int existL(string text,map<string,int> data){
	//text.erase(0,1);
    for (auto itr = data.begin(); itr != data.end(); ++itr)
    {
    if (text == itr->first)
        {
            return itr->second;
        }
    }
    return -1;
}
string value_system(string text){
	regex str("\"(.*)\"");
	regex num("([0-9]+)");
	if(text == "<>"){
		cin >> text;
		return text;
	}else if(regex_match(text,str)){
		smatch value;
		regex_search(text,value,str);
		return value[1];
	}else if(regex_match(text,num)){
		smatch value;
		regex_search(text,value,num);
		return value[1];
	}

}
int to_i(string str){
	int i ;
	istringstream ( str ) >> i;
	return i;
}
vector<string> split(string s, string delimiter)
{

    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;
    while ((pos_end = s.find(delimiter, pos_start)) != string::npos)
    {
        token = s.substr(pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

}; 
