
#include <string.h>

using namespace std;

class Palavra{
	private:
		string word;
		string traducao;
	public:
		Palavra(string p,string t){
			word=p;
			traducao=t;
		}
		string getPalavra(){
			return word;
		}
		string getTraducao(){
			return traducao;
		}	
};




