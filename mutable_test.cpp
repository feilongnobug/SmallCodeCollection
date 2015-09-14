#include <iostream>
#include <cstring>

class CTextBlock{
public:
    void init();
    void set_text(char* s = NULL);
	std::size_t length() const;
	void show();
private:
	char* pText;
	mutable std::size_t textLength;
	mutable bool lengthIsValid;
};

std::size_t CTextBlock::length() const
{
	if(!lengthIsValid){
		textLength = std::strlen(pText);
		lengthIsValid = true;
	}
	return textLength;
}

void CTextBlock::show(){
    std::cout<<"textLength = "<<textLength<<std::endl<<"isValid = "<<lengthIsValid<<std::endl;
}

void CTextBlock::set_text(char* s){
    pText = s;
}

void CTextBlock::init(){
    pText = NULL;
    textLength = 0;
    lengthIsValid = false;
}

int main(){
    char s[] = "hello";
	CTextBlock ctb;
	ctb.init();
	ctb.show();
	std::cout<<std::endl;
	ctb.set_text(s);
	ctb.length();
	ctb.show();
	return 0;
}
