#include <iostream>
#include <cstring>

using namespace std;
typedef struct pixcel_
{
    int col;
    int row;
    char c;
}Pix;

class GraphicalEditor{
public:
    GraphicalEditor(int cols, int rows);
    ~GraphicalEditor();
    void clearAll();
    void colorPixel(int col, int row, char c);
    void drawVecticalLine(int col, int startRow, int endRow, char c);
    void drawHorizontalLine(int row, int startCol, int endCol, char c);
    void fillRectangle(int startRow, int endRow, int startCol, int endCol, char c);
    void saveFile(string fileName);
    void fillRegion(int col, int row, char c);
private:
    int cols_;
    int rows_;
    Pix* pix_;
};

GraphicalEditor::GraphicalEditor(int cols, int rows):cols_(cols), rows_(rows) {
    pix_ = new Pix[cols_*rows_];
    for(int i=0; i<cols_*rows_; i++){
        pix_[i].c = '0';
        pix_[i].row = i/cols_;
        pix_[i].col = i%cols_;
    }
}
GraphicalEditor::~GraphicalEditor() {
    if(pix_ != NULL){
        cout << "~GraphicalEditor" << endl;
        delete[] pix_;
    }
}
void GraphicalEditor::clearAll() {
    for(int i=0; i<cols_*rows_; i++){
        pix_[i].c = '0';
    }
}

void GraphicalEditor::colorPixel(int col, int row, char c) {
    for(int i=0; i<cols_*rows_; i++){
        if(pix_[i].col == col-1 && pix_[i].row == row-1){
            pix_[i].c = c;
        }
    }
}

void GraphicalEditor::saveFile(string fileName) {
    cout << fileName << endl;
    for(int i=0; i<cols_*rows_; i++){
        //cout << pix_[i].col << " " << pix_[i].row << " " << pix_[i].c << endl;

        cout << pix_[i].c;
        if(pix_[i].col == 4){
            cout << endl;
        }

    }
}
void GraphicalEditor::drawHorizontalLine(int row, int startCol, int endCol, char c) {

}

void GraphicalEditor::drawVecticalLine(int col, int startRow, int endRow, char c) {

}
void GraphicalEditor::fillRegion(int col, int row, char c) {

}

void GraphicalEditor::fillRectangle(int startRow, int endRow, int startCol, int endCol, char c) {

}
class ParseCommand{
public:
    ParseCommand();
    ~ParseCommand(){
        if(editor_ != NULL) {
            cout << "~ParseCommand" << endl;
            delete editor_;
        }
    }
    int parse(string command);
private:
    GraphicalEditor *editor_;
};
ParseCommand::ParseCommand(){
    editor_ = NULL;
}

int ParseCommand::parse(string command) {
    if(command[0] != 'I' && editor_ == NULL){
        return -1;
    }
    if(command[0] == 'I' && editor_ != NULL)
    {
        return -1;
    }

    switch (command.at(0))
    {
        case 'I':{
            int cols = command.at(1) - '0';
            int rows = command.at(2) - '0';
            editor_ = new GraphicalEditor(cols, rows);
            break;
        }
        case 'C' : {
            editor_->clearAll();
            break;
        }
        case 'L': {
            int col = command.at(1) - '0';
            int row = command.at(2) - '0';
            char c = command.at(3);
            editor_->colorPixel(col, row, c);
            break;
        }
        case 'V':
            break;
        case 'H':
            break;
        case 'K':
            break;
        case 'F':
            break;
        case 'S': {
            string fname = command.substr(1);
            editor_->saveFile(fname);
            break;
        }
        default:
            break;
    }
    return 0;
}
int main (int ac, char *av[])
{
    string line;
    ParseCommand parseCommand;
    while(cin >> line){
        if(line.compare("X") == 0){
            break;
        }
        if(parseCommand.parse(line)== -1)
        {
            continue;
        }
    }
    return 0;
}