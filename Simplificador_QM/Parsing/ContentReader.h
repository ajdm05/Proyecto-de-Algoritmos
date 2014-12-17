#ifndef CONTENTREADER_H
#define	CONTENTREADER_H

struct Symbol{
    char symbol;
    int line;
    int column;
};

class ContentReader{
private:
    int currentPosition;
    int currentLine;
    int currentColumn;
    char * content;
public:
    ContentReader();
    ContentReader(char * content);
    
    void setContent(char * content);
    
    
    Symbol NextSymbol();
    
};

#endif	/* CONTENTREADER_H */

