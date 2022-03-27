#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;


struct token
{
	string name;
	string type;
	int ligne;
};
struct error
{
	vector<int> indice;
	int ligne = 0;
};
struct syn_err
{
	string err;
	int ligne;
};
struct  deb_svt
{
	list<string> debut;
	list<string> suivant;

};
class lex_analyser
{

public:
	error vect;
	queue<error> err;
	queue<token> tokens;
	vector<string> regle[46]; // les regles de grammaire
	list<string>::iterator it;
	stack<string> pile; // la pile de travaille (table d'analyse)
	deb_svt debut_suivant[18];//les debuts et les suivants des non terminales
	vector<syn_err> syn_err;
	int key_words[33][27] = { -1 };
	int table_analyse[18][25] = { -1 };
	int ids[2][74] = { -1 };
	int cmp_logic[5][6] = { -1 };
	char cmp[6] = { "" };
	string filepath;
	bool etat_lex=false, etat_syn=false, etat_gen=true;

	lex_analyser();
	bool is_marke(char c);
	bool is_operator(char c, int&);
	void add_token(string, string);
	bool is_kw(string, int, int&);
	bool is_id(string, int, int&);
	bool is_separator(string, int&);
	int get_cmp(char c);
	bool is_cmp(string, int, int&);
	bool line_analyser(string& s, int i);
	void text_file_analyser(string);
	bool is_number(string, int&);
	int Terminale(string s);// fonction return l'indice de s dans la table d'analyse s'il est terminale sinon -1
	int N_Terminale(string s);// fonction return l'indice de s dans la table d'analyse s'il est non terminale sinon -1
	bool debut(string s); // verifier si s est l'une des debuts de la sommet de la pile
	bool suivant(string s);
	void empiler(int i); // empiler la regle i
	void regler_table_symboles();
	bool syn_analyser();
	void correction();

};
lex_analyser::lex_analyser()
{
	for (size_t i = 0; i < 33; i++)
		for (size_t j = 0; j < 27; j++)
			key_words[i][j] = -1;
	for (size_t i = 0; i < 18; i++)
		for (size_t j = 0; j < 25; j++)
			table_analyse[i][j] = -1;
	for (size_t i = 0; i < 2; i++)
		for (size_t j = 0; j < 74; j++)
			ids[i][j] = 1;

	for (size_t i = 0; i < 17; i++)
		ids[0][i] = -1;

	for (size_t i = 91 - '0'; i < 'a' - '0'; i++)
		ids[0][i] = ids[1][i] = -1;
	ids[1][95 - '0'] = 1;

	// key words :

	key_words[0]['v' - 'a'] = 1;
	key_words[1][0] = 2;
	key_words[2]['r' - 'a'] = 3;
	key_words[3][26] = 4;
	key_words[4]['i' - 'a'] = 23;
	key_words[4]['b' - 'a'] = 23;
	key_words[4]['c' - 'a'] = 23;
	key_words[4]['f' - 'a'] = 23;
	key_words[0]['w' - 'a'] = 5;
	key_words[0]['i' - 'a'] = 8;
	key_words[0]['n' - 'a'] = 31;
	key_words[31]['i' - 'a'] = 8;
	key_words[0]['f' - 'a'] = 9;
	key_words[0]['r' - 'a'] = 11;
	key_words[8]['f' - 'a'] = 23;
	key_words[9]['u' - 'a'] = 20;
	key_words[5]['h' - 'a'] = 6;
	key_words[5]['r' - 'a'] = 17;
	key_words[6]['i' - 'a'] = 7;
	key_words[7]['l' - 'a'] = 24;
	key_words[24]['e' - 'a'] = 23;
	key_words[1]['o' - 'a'] = 25;
	key_words[25]['i' - 'a'] = 26;
	key_words[26]['d' - 'a'] = 23;
	key_words[16]['a' - 'a'] = 17;
	key_words[17]['i' - 'a'] = 18;
	key_words[18]['t' - 'a'] = 19;
	key_words[19]['e' - 'a'] = 23;
	key_words[11]['e' - 'a'] = 12;
	key_words[9]['o' - 'a'] = 10;
	key_words[10]['r' - 'a'] = 23;
	key_words[12]['t' - 'a'] = 13;
	key_words[12]['a' - 'a'] = 26;
	key_words[13]['u' - 'a'] = 14;
	key_words[14]['r' - 'a'] = 15;
	key_words[15]['n' - 'a'] = 23;
	key_words[9]['u' - 'a'] = 20;
	key_words[20]['n' - 'a'] = 21;
	key_words[21]['c' - 'a'] = 27;
	key_words[27]['t' - 'a'] = 28;
	key_words[28]['i' - 'a'] = 29;
	key_words[29]['o' - 'a'] = 30;
	key_words[30]['n' - 'a'] = 23;
	key_words[21][26] = 22;
	key_words[22]['r' - 'a'] = 23;
	key_words[22]['w' - 'a'] = 23;


	debut_suivant[0].debut = { "type"  ,"void " ,"main " };
	debut_suivant[1].debut = { "type","void","e" };
	debut_suivant[2].debut = { "[","(" ,";"};
	debut_suivant[3].debut = { "=",";" };
	debut_suivant[4].debut = { ";","," };
	debut_suivant[5].debut = { "id","for","while","if","e","write" };
	debut_suivant[6].debut = { "id","for","while","if","write" };
	debut_suivant[7].debut = { "if" };
	debut_suivant[8].debut = { "else","e" };
	debut_suivant[9].debut = { "{","if" };
	debut_suivant[10].debut = { "[","(","=" };
	debut_suivant[11].debut = { "id","const","(","read" };
	debut_suivant[12].debut = { "[","(","e" };
	debut_suivant[13].debut = { "arth","cmp","logic" };
	debut_suivant[14].debut = { "id","const","(","bool" };
	debut_suivant[15].debut = { ",","e" };
	debut_suivant[16].debut = { "return","e" };
	debut_suivant[17].debut = { "[","e" };


	debut_suivant[0].suivant = { "#" };
	debut_suivant[1].suivant = { "main" };
	debut_suivant[2].suivant = { "type","void","main" };
	debut_suivant[3].suivant = { "type","void","main" };
	debut_suivant[4].suivant = { "type","void","main" };
	debut_suivant[5].suivant = { "return","}" };
	debut_suivant[6].suivant = { ";" };
	debut_suivant[7].suivant = { ";" };
	debut_suivant[8].suivant = { ";" };
	debut_suivant[9].suivant = { ";" };
	debut_suivant[10].suivant = { ";" };
	debut_suivant[11].suivant = { ";" };
	debut_suivant[12].suivant = { ";" };
	debut_suivant[13].suivant = { ")" };
	debut_suivant[14].suivant = { "arth","logic","cmp","=",";",",",")" };
	debut_suivant[15].suivant = { ")" };
	debut_suivant[16].suivant = { "}" };
	debut_suivant[17].suivant = { "=",";" };



	regle[0] = { "decl","main","{","instructions","}" };
	regle[1] = { "type","id","var_func","decl" };
	regle[2] = { "void","id","(","type","id","param",")","{","instructions","returns","}",";","decl" };
	regle[3] = { "e" };
	regle[4] = { "table","var_cmp" };
	regle[5] = { "(","type","id","param",")","{","instructions","returns","}",";" };
	regle[6] = { "=","variable","var_suit" };
	regle[7] = { ";" };
	regle[8] = { ";" };
	regle[9] = { ",","id","table","var_cmp" };
	regle[10] = { "instruction",";","instructions" };
	regle[11] = { "e" };
	regle[12] = { "id","instr" };
	regle[13] = { "for","(","type","id","=","variable",",","variable","exp",",","variable","exp",")","{","instructions","}" };
	regle[14] = { "while","(","variable","exp",")","{","instructions","}" };
	regle[15] = { "ifs" };
	regle[16] = { "if","(","variable","exp",")","{","instructions","}","if2" };
	regle[17] = { "nif","if3" };
	regle[18] = { "e" };
	regle[19] = { "{","instructions","}" };
	regle[20] = { "ifs" };
	regle[21] = { "[","variable","]","=","variable" };
	regle[22] = { "(","type","id","param",")" };
	regle[23] = { "=","rest" };
	regle[24] = { "id","rest2" };
	regle[25] = { "const" };
	regle[26] = { "(", "variable","exp",")" };
	regle[27] = { "[","variable","]" };
	regle[28] = { "(","type","id","param",")" };
	regle[29] = { "e" };
	regle[30] = { "arth","variable" };
	regle[31] = { "cmp","variable" };
	regle[32] = { "logic","variable" };
	regle[33] = { "=","variable" };
	regle[34] = { ",","type","id","param" };
	regle[35] = { " e" };
	regle[36] = { "id" };
	regle[37] = { "const" };
	regle[38] = { "(","variable","exp",")" };
	regle[39] = { "bool" };
	regle[40] = { "return","variable",";" };
	regle[41] = { "e" };
	regle[42] = { "[","variable","]" };
	regle[43] = { "e" };
	regle[44] = { "write","(","variable",")" };
	regle[45] = { "read","(",")" };




	table_analyse[0][0] = 1;
	table_analyse[0][1] = 1;
	table_analyse[0][19] = 1;
	table_analyse[1][0] = 4;
	table_analyse[1][1] = 3;
	table_analyse[1][19] = 2;
	table_analyse[2][3] = 6;
	table_analyse[2][2] = 5;
	table_analyse[2][7] = 5;
	table_analyse[2][10] = 5;
	table_analyse[3][2] = 7;
	table_analyse[3][10] = 8;
	table_analyse[4][9] = 10;
	table_analyse[4][10] = 9;
	table_analyse[5][6] = 4;
	table_analyse[5][11] = 11;
	table_analyse[5][12] = 11;
	table_analyse[5][13] = 4;
	table_analyse[5][14] = 11;
	table_analyse[5][16] = 11;
	table_analyse[6][11] = 14;
	table_analyse[6][12] = 15;
	table_analyse[6][14] = 13;
	table_analyse[6][16] = 16;
	table_analyse[7][16] = 17;
	table_analyse[8][10] = 4;
	table_analyse[8][15] = 18;
	table_analyse[9][5] = 20;
	table_analyse[9][16] = 21;
	table_analyse[10][2] = 24;
	table_analyse[10][3] = 23;
	table_analyse[10][7] = 22;
	table_analyse[11][3] = 27;
	table_analyse[11][14] = 25;
	table_analyse[11][17] = 26;
	table_analyse[12][3] = 29;
	table_analyse[12][7] = 28;
	table_analyse[12][10] = 4;
	table_analyse[13][2] = 34;
	table_analyse[13][20] = 31;
	table_analyse[13][21] = 32;
	table_analyse[13][22] = 33;
	table_analyse[14][3] = 39;
	table_analyse[14][14] = 37;
	table_analyse[14][17] = 38;
	table_analyse[14][18] = 40;
	table_analyse[15][4] = 4;
	table_analyse[15][9] = 35;
	table_analyse[16][6] = 4;
	table_analyse[16][13] = 41;
	table_analyse[17][2] = 4;
	table_analyse[17][7] = 43;
	table_analyse[17][10] = 4;
	table_analyse[6][23] = 45;
	table_analyse[11][24] = 46;




	//cmp :
	cmp_logic[0][0] = 1;
	cmp_logic[0][1] = 1;
	cmp_logic[0][2] = 1;
	cmp_logic[0][3] = 4;
	cmp_logic[0][4] = 3;
	cmp_logic[0][5] = 2;
	cmp_logic[1][2] = 5;
	cmp_logic[2][5] = 5;
	cmp_logic[3][4] = 5;
	cmp_logic[4][2] = 5;
}

void lex_analyser::text_file_analyser(string filepath)
{
	this->filepath = filepath;
	ifstream a("code",ios::in);
	char c =a.get();
	if (c=='#')
	{
		etat_gen = false;
		return;
	}
	a.close();
	ifstream file(filepath, ios::in);
	if (!file.is_open())
	{
		etat_gen = false;
		file.close();
		return;
	}
	string s;
	int i = 1;
	bool still = true;
	while (!file.eof())
	{
		getline(file, s);
		line_analyser(s, i);
		if (!vect.indice.empty())
		{
			vect.ligne = i;
			err.push(vect);
			while (!vect.indice.empty())
			{
				vect.indice.pop_back();
			}
		}
		i++;
	}
	file.close();

	ofstream token_file("./result", ios::out);
	queue<token> temp = tokens;
	if (err.empty())
	{
		etat_lex = true;
		token_file << "The code is correct : \n";
		i = 1;
		while (!temp.empty())
		{
			token_file << i << "-> " << temp.front().name << " : token of type " << temp.front().type << " in line : " << temp.front().ligne << endl;
			temp.pop(); i++;
		}
		token_file.close();
	}
	else {
		etat_lex = false;
		token_file << "Code is wrong !! \n";
		token_file << " Errors  :\n";
		while (!err.empty())
		{
			token_file << "in ligne number : " << err.front().ligne << " ->\n";
			while (!err.front().indice.empty())
			{
				token_file << "                    ";
				token_file << "error in character N^ " << err.front().indice.back() << ";\n";
				err.front().indice.pop_back();
			}
			err.pop();
		}
		token_file.close();
	}

}

bool lex_analyser::is_number(string s, int& index)
{
	int begin = index;
	int b = 0;
	while (index < s.length() && b < 2 && ((s[index] >= '0' && s[index] <= '9') || s[index] == '.'))
	{
		if (s[index] == '.') b++;
		index++;
	}
	if (b <= 1 && index != begin)
	{
		add_token(s.substr(begin, index - begin), "const");
		return true;
	}
	else return false;
}

bool lex_analyser::line_analyser(string& s, int i)
{
	int size = s.length();
	int begin = 0, end = 0;
	while (!vect.indice.empty()) vect.indice.pop_back();
	while (end < size && begin < size)
	{
		begin = end;
		if (s[begin] == 34)
		{
			int temp = begin;
			begin++;
			while (begin < size && s[begin] != 34)
			{
				begin++;
			}
			if (begin == size)
			{
				vect.indice.push_back(temp);
				vect.ligne = i;
			}
			else
			{
				add_token(s.substr(temp, begin - temp), "id");
				end = ++begin;
			}

		}
		else if (!is_kw(s, begin, end))
			if (!is_id(s, begin, end))
				if (!is_cmp(s, begin, end))
				{
					end = begin;
					if (!is_separator(s, end))
						if (!is_operator(s[begin], end))
						{
							if (!is_number(s, end))
							{
								vect.indice.push_back(begin);
								while (begin < s.length() && !is_separator(s, begin)) begin++;
								end = begin;

							}
						}
				}
		tokens.back().ligne = i;
	}
	return true;
}

bool lex_analyser::is_marke(char c)
{
	if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || (c >= 91 && c <= 94) || (c >= 123 && c <= 126) || (c >= '0' && c <= '9'))
		return true;
	return false;
}

bool lex_analyser::is_operator(char c, int& indice)
{
	if (c == '+' || c == '-' || c == '/' || c == '*')
	{
		string s;
		s = c;
		add_token(s, "operator");
		indice++;
		return true;
	}
	return false;
}

void lex_analyser::add_token(string s, string t)
{
	tokens.push({ s,t });
}

bool lex_analyser::is_kw(string s, int begin, int& end)
{
	int e = 0;
	end = begin;
	int size = s.length();
	while (end < size && e != -1 && (e >= 0 && e <= 31) && !is_marke(s[end]))
	{
		if (s[end] != '_')
		{
			e = key_words[e][s[end] - 'a'];
			end++;
		}
		else
		{
			e = key_words[e][26];
			end++;
		}
	}
	if (e == 23)
	{
		add_token(s.substr(begin, end - begin), "key word");
		return true;
	}
	else return false;
}

bool lex_analyser::is_id(string s, int begin, int& end)
{
	end = begin;
	int size = s.length();
	int e = 0;
	while (end < size && e != -1 && !is_marke(s[end]))
	{
		e = ids[e][s[end] - '0'];
		end++;
	}
	if (e == 1 && end - begin <= 20)
	{
		add_token(s.substr(begin, end - begin), "id");
		return true;
	}
	else return false;
}

bool lex_analyser::is_separator(string s, int& indice)
{
	if (s[indice] == ' ') { indice++; return true; }
	if (s[indice] == ':') { indice = s.length(); return true; }
	else if (s[indice] == '(' || s[indice] == ')' || s[indice] == '[' || s[indice] == ']' || s[indice] == '{' || s[indice] == '}' || s[indice] == ';' || s[indice] == ',')
	{
		add_token(s.substr(indice, 1), "separator");
		indice++;
		return true;
	}
	else return false;
}

int lex_analyser::get_cmp(char c)
{
	switch (c)
	{
	case '<':return 0; break;
	case '>':return 1; break;
	case '=':return 2; break;
	case '!':return 3; break;
	case '&':return 4; break;
	case '|':return 5; break;
	default:return -1;
		break;
	}
}

bool lex_analyser::is_cmp(string s, int begin, int& end)
{
	int e = 0;
	end = begin;
	int size = s.length();
	bool still = true;
	while (end < size && e != -1 && still)
	{
		if (get_cmp(s[end]) != -1)
		{
			e = cmp_logic[e][get_cmp(s[end])];
			end++;
		}
		else still = false;
	}
	if (e == 1 || e == 5)
	{
		add_token(s.substr(begin, end - begin), "logic&comp");
		return true;
	}
	else return false;
}


int lex_analyser::Terminale(string s)
{
	if (s == "main")
		return 0;
	else if (s == "void")
		return 1;
	else if (s == "=")
		return 2;
	else if (s == "(")
		return 3;
	else if (s == ")")
		return 4;
	else if (s == "{")
		return 5;
	else if (s == "}")
		return 6;
	else if (s == "[")
		return 7;
	else if (s == "]")
		return 8;
	else if (s == ",")
		return 9;
	else if (s == ";")
		return 10;
	else if (s == "for")
		return 11;
	else if (s == "while")
		return 12;
	else if (s == "return")
		return 13;
	else if (s == "id")
		return 14;
	else if (s == "nif")
		return 15;
	else if (s == "if")
		return 16;
	else if (s == "const")
		return 17;
	else if (s == "bool")
		return 18;
	else if (s == "type")
		return 19;
	else if (s == "arth")
		return 20;
	else if (s == "cmp")
		return 21;
	else if (s == "logic")
		return 22;
	else if (s == "write")
		return 23;
	else if (s == "read")
		return 24;
	else return -1;

}

int lex_analyser::N_Terminale(string s)
{
	if (s == "prog")
		return 0;
	else if (s == "decl")
		return 1;
	else if (s == "var_func")
		return 2;
	else if (s == "var_cmp")
		return 3;
	else if (s == "var_suit")
		return 4;
	else if (s == "instructions")
		return 5;
	else if (s == "instruction")
		return 6;
	else if (s == "ifs")
		return 7;
	else if (s == "if2")
		return 8;
	else if (s == "if3")
		return 9;
	else if (s == "instr")
		return 10;
	else if (s == "rest")
		return 11;
	else if (s == "rest2")
		return 12;
	else if (s == "exp")
		return 13;
	else if (s == "variable")
		return 14;
	else if (s == "param")
		return 15;
	else if (s == "returns")
		return 16;
	else if (s == "table")
		return 17;
	else return -1;

}

bool lex_analyser::debut(string s)
{
	it = debut_suivant[N_Terminale(pile.top())].debut.begin();
	auto itf = debut_suivant[N_Terminale(pile.top())].debut.end();
	for (; it != itf; it++)
		if (*it == s)
			return true;
	return false;
}

bool lex_analyser::suivant(string s)
{
	it = debut_suivant[N_Terminale(pile.top())].suivant.begin();
	auto itf = debut_suivant[N_Terminale(pile.top())].suivant.end();
	for (; it != itf; it++)
		if (*it == s)
			return true;

	return false;
}

void lex_analyser::empiler(int i)
{
	ofstream f("./syn", ios_base::app);
	if (i == 4)
	{
		f << "continue    "<<endl;
		f.close();
		return;
	}
	for (int j = regle[i - 1].size() - 1; j >= 0; j--)
	{
		pile.push(regle[i - 1][j]);
		if (N_Terminale(regle[i - 1][j])!=-1)
		{
			f <<"<"<< regle[i - 1][j] << "> ";
		}
		else
		{
			f << regle[i - 1][j] << " ";
		}
		
	}
	f << endl;
	f.close();
}

void lex_analyser::regler_table_symboles()
{
	queue<token> temp;
	int size = tokens.size();
	for (size_t i = 0; i < size; i++)
	{
		if (tokens.front().name == "+" || tokens.front().name == "-" || tokens.front().name == "*" || tokens.front().name == "/" || tokens.front().name == "%")
			tokens.front().type = "arth";
		else if (tokens.front().name == "==" || tokens.front().name == ">" || tokens.front().name == ">=" || tokens.front().name == "<" || tokens.front().name == "<=" || tokens.front().name == "!=")
			tokens.front().type = "cmp";
		else if (tokens.front().name == "||" || tokens.front().name == "&&")
			tokens.front().type = "logic";
		else if (tokens.front().name == "true" || tokens.front().name == "false")
			tokens.front().type = "bool";
		else if (tokens.front().name == "var_i" || tokens.front().name == "var_b" || tokens.front().name == "var_c" || tokens.front().name == "var_f")
			tokens.front().type = "type";
		else if (tokens.front().name == "for" || tokens.front().name == "while" || tokens.front().name == "main" || tokens.front().name == "void" || tokens.front().name == "if" || tokens.front().name == "nif" || tokens.front().name == "return" || tokens.front().name == "=" || tokens.front().name == "(" || tokens.front().name == ")" || tokens.front().name == "[" || tokens.front().name == "]" || tokens.front().name == "{" || tokens.front().name == "}" || tokens.front().name == "," || tokens.front().name == ";" || tokens.front().name == "read" || tokens.front().name == "write")
			tokens.front().type = tokens.front().name;
		temp.push(tokens.front());
		tokens.pop();
	}
	while (!temp.empty())
	{
		tokens.push(temp.front());
		temp.pop();
	}
}

bool lex_analyser::syn_analyser()
{
	bool err = false;
	ofstream f("./syn", ios::out);
	f << "------------------------------Syntaxical result---------------------------\n";
	f << "push  rule  N  1" << endl;
	f.close();
	this->empiler(1);
	f.open("./syn", ios::app);
	while (!tokens.empty() && !pile.empty())
	{

		if ( Terminale(pile.top()) != -1)
		{
			if (tokens.front().type == pile.top())
			{
				//f << "match  " << tokens.front().type << "  with  " << pile.top() << endl;;
				f<< "pop " << pile.top()<<endl;
				pile.pop();
				tokens.pop();
			}
			else
			{
				err = true;
				syn_err.push_back({ tokens.front().name,tokens.front().ligne });
				f << "err in  " << tokens.front().type << "  with  " << pile.top() << endl;
				if (!pile.empty())
				{
					while (!tokens.empty() && tokens.front().type != pile.top())
					{
						tokens.pop();
					}
				}
			}
		}
		else
		{
			int r = table_analyse[N_Terminale(pile.top())][Terminale(tokens.front().type)];
			if (r != -1)
			{
				f << "pop <" << pile.top() <<">"<< endl;
				pile.pop();
				f << "push  rule  N  " << r << endl;
				empiler(r);
			}
			else
			{
				err = true;
				syn_err.push_back({ tokens.front().name,tokens.front().ligne });
				f << "err  on  " << tokens.front().type <<"  in line  N  "<<tokens.front().ligne<< endl;
				while (!tokens.empty() &&!suivant(tokens.front().type))
				{
					tokens.pop();
				}
					if(!pile.empty()) pile.pop();
			}
		}
	}

	if (pile.empty() && !err && tokens.empty())
	{
		etat_syn = true;
		f.close();
		return true;

	}
	syn_err.push_back({ "stack" });
	f.close();
	return false;
}

