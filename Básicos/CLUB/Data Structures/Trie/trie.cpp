#include <iostream>
#include <map>

using namespace std;

struct Trie{
	
	map<char, Trie*> tree;
	bool isWord; //Es final
	int wordCount; //Veces que ha aparecido una palabra
	int charCount; //Cuantos veces ha aparecido un caracter

	Trie(){
		isWord = false;
		wordCount = 0;
		charCount = 0;
		tree = map<char, Trie*>();
	}

	void insert(string &str){
		Trie *aux = this;
		for(auto c: str){
			if(aux->tree.count(c) != 0)
				aux = aux->tree[c];
			else {
				tree[c] = new Trie();
				aux = tree[c];
			}
			aux->charCount++;
		}
		aux->isWord = true;
		aux->wordCount++;
	}

	bool find(string &str){
		Trie *aux = this;
		for(auto c: str){
			if(aux->tree.count[c] == 0)
				return false;
			else
				aux = aux->tree[c];
		}
		return aux->isWord;
	}

	int count(string &str){
		Trie *aux = this;
		for(auto c: str){
			if(aux->tree.count[c] == 0)
				return 0;
			else
				aux = aux->tree[c];
		}
		return aux->wordCount;
	}

	void erase(string &str){
		Trie *aux = this;
		if(aux->find(str)){
			for(auto c: str){
				aux = aux->tree;
				aux->charCount--;
			}
			aux->wordCount--;
			aux->isWord=(aux->wordCount != 0);
		}
	}

};

int main(){
	
}