#include "Meow.h"
int main(int argc, char const *argv[])
{
	Meow lang;
	for(int i=1;i< argc;i++){
		string ag = argv[i];
		if(lang.exists_(ag)){
			vector<string> s = lang.readfile(argv[i]);
			for(int j =0;j< s.size();j++){
				//lang.line = i;
				//cout<<j<<endl;
				lang.worker(s[j],true);
			}
		}
		if(ag == "-e"){
			lang.worker(argv[i+1],false);
		}else if(ag == "-h"){
 			lang.help(0);
 		}else if(ag == "-v"){
			cout<<"Meow "<<lang.data["VERSION"]<<endl;
		}else if((ag == "-e")&&(i+1 < argc)){
			lang.decode(argv[i+1]);
		}}
		if(!argv[1]){
			string test;
			while(true){
			cout<<">>> ";
			getline(cin,test);
			if(!lang.terminalcmd(test))
				lang.worker(test,false);
			cout<<endl;
			}
		}
		
	
	return 0;
}
