#include <iostream>

void clearScreen(){
    	std::cout << "\032[2J\033[1;1H";
	return;
}

class MorseTree{
	private:
		struct Node{
			char letter{'\0'};
			Node* left{nullptr};
			Node* right{nullptr};
		};
		
		Node* root;
		Node* current;

		void insert(const std::string& code, char letter) {
			Node* current = root;
			for (char symbol : code) {
		  		if (symbol == '.') {
					if (!current->left) {
			    			current->left = new Node();
					}
					current = current->left;
		    		} 
				else if (symbol == '-') {
					if (!current->right) {
			    			current->right = new Node();
					}
					current = current->right;
		    		}
			}
			current->letter = letter;
	    	}

		void buildTree() {

			//    		--- Letters ---
			
			insert(".-", 'A');
			insert("-...", 'B');
			insert("-.-.", 'C');
			insert("-..", 'D');
			insert(".", 'E');
			insert("..-.", 'F');
			insert("--.", 'G');
			insert("....", 'H');
			insert("..", 'I');
			insert(".---", 'J');
			insert("-.-", 'K');
			insert(".-..", 'L');
			insert("--", 'M');
			insert("-.", 'N');
			insert("---", 'O');
			insert(".--.", 'P');
			insert("--.-", 'Q');
			insert(".-.", 'R');
			insert("...", 'S');
			insert("-", 'T');
			insert("..-", 'U');
			insert("...-", 'V');
			insert(".--", 'W');
			insert("-..-", 'X');
			insert("-.--", 'Y');
			insert("--..", 'Z');
			
			//		--- Numbers ---

			insert("-----", '0');
			insert(".----", '1');
			insert("..---", '2');
			insert("...--", '3');
			insert("....-", '4');
			insert(".....", '5');
			insert("-....", '6');
			insert("--...", '7');
			insert("---..", '8');
			insert("----.", '9');

			return;
		}


	public:
		MorseTree(){
			root = new Node;
			buildTree();
			current = root;
		}

		
		void moveLeft(){
			if(current && current->left) 	
				current = current->left;
		}
		void moveRight(){
			if(current && current->right)
				current = current->right;
		}
		char flushLetter(){
			char res = current ? current->letter : '?';
			current = root;
			return res;
		}
};


int main(){
	MorseTree tree;
	char symbol, letter = '\0';
	std::string word = "";
	while(true){
		std::cin.get(symbol);
		if(symbol == '.'){
			tree.moveLeft();
		}
		else if(symbol == '-'){
			tree.moveRight();
		}
		else if(symbol == ' '){
			word = "";
		}
		else{
			letter = tree.flushLetter();
			word += letter;
			clearScreen();
		}
		std::cout<<letter<<' '<<word<<'\n';
	}
	return 0;
}
