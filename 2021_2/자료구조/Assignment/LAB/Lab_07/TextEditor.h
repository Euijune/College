#pragma once
#include <iostream>

struct LineType;


// 구조 : Header -> Top(=line1) -> line2 -> line3 -> ... -> Bottom -> Trailer
class TextEditor
{
public:
    TextEditor();     // Class constructor
    ~TextEditor();

    void GoToTop();
    //Funtion : Goes to top of the list
    //Postcondition : currentLine is set to access the first line of text

    void GoToBottom();
    //Function: Goes to bottom of the list
    //Postcondition : currentLine is set to access the first line of text

    void InsertLine(char newline[]);
    //Function : Inserts newLine at the current Line
    //Postcondtions : newLine has been inserted after current - Line.currentLine points to newLine

    void PrintText();
    // 디버깅용, currentline의 text정보를 보여줌.


private:
    LineType* currentLine;
};


struct LineType
{
    char text[80];
    LineType* next;
    LineType* back;
};


TextEditor::TextEditor() {
    LineType* Header = new LineType;
    LineType* Trailer = new LineType;

    Header->back = NULL;
    Header->next = Trailer;
    strcpy_s(Header->text, "--- Top of file ---");
    //strcpy_s(Header->text, 80, "--- Top of file ---");

    Trailer->back = Header;
    Trailer->next = NULL;
    strcpy_s(Trailer->text, "--- Bottom of file ---");

    currentLine = Header;
}

TextEditor::~TextEditor() {

}

void TextEditor::GoToTop() {
    if (currentLine->back == NULL || currentLine->next == NULL)
        // line이 하나도 없는 경우 
        // case 1. currline = header
        // case 2. currline = trailer
    {
        while (currentLine->next != NULL)   // Post : currline = trailer
        {
            currentLine = currentLine->next;
        }
    }
    else 
    {
        while (currentLine->back->back != NULL)   // Post : currline = top
        {
            currentLine = currentLine->back;
        }
    }
}

void TextEditor::GoToBottom() {
    if (currentLine->back == NULL || currentLine->next == NULL)
        // line이 하나도 없는 경우 
        // case 1. currline = header
        // case 2. currline = trailer
    {
        while (currentLine->back != NULL)   // Post  : currline = header
        {
            currentLine = currentLine->back;
        }
    }
    else
    {
        while (currentLine->next->next != NULL)   // Post : currline = bottom
        {
            currentLine = currentLine->next;
        }
    }
}

void TextEditor::InsertLine(char newline[]) {
    LineType* newLine = new LineType;
    strcpy_s(newLine->text, newline);

    if (currentLine->next == NULL)  // currline이 trailer를 가리키는 경우
    {
        newLine->back = currentLine->back;
        currentLine->back->next = newLine;
        currentLine->back = newLine;
        newLine->next = currentLine;
    }
    else
    {
        newLine->back = currentLine;
        newLine->next = currentLine->next;
        currentLine->next->back = newLine;
        currentLine->next = newLine;
    }
    currentLine = newLine;
}

void TextEditor::PrintText() {
    std::cout << currentLine->text << std::endl;
}