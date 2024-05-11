#include "Meow.h"
int main(int argc, char const *argv[])
{
	
	Meow lang;
	for(int i=1;i< argc;i++){
		string ag = argv[i];
		if(lang.exists_(ag)){
			lang.passive();
			vector<string> s = lang.readfile(argv[i]);
			for(int j =0;j< s.size();j++){
				//lang.line = i;
				//cout<<j<<endl;
				lang.worker(s[j],true);
			}
		}
		if(ag == "-e"){
			lang.passive();
			lang.worker(argv[i+1],false);
		}else if(ag == "-h"){
 			lang.help(0);
 		}else if(ag == "-v"){
			cout<<"Meow "<<lang.data["VERSION"]<<endl;
		}else if((ag == "-e")&&(i+1 < argc)){
			lang.decode(argv[i+1]);
		}else if(ag == "-p"){
			lang.passive();
			cout<<"Pointer: "+lang.meow<<endl;
		}else if(ag == "-his"){
			lang.history("",true);
		}
		}
		if(!argv[1]){
			string test;
			cout<<"Welcome to Meow v"+lang.data["VERSION"]+"\n"
				  "Type \"help\" for more information.\n";
			lang.passive();
			while(true){
			cout<<lang.data["PS1"]+" ";
			getline(cin,test);
			lang.history(test,false);
			lang.worker(test,false);
			cout<<endl;
			}
		}
		
	
	return 0;
}
