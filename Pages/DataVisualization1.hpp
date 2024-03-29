#ifndef _DATAVISUALIZATION1_HPP_
#define _DATAVISUALIZATION1_HPP_

#include "../Components/Button.hpp"
#include "../Components/Textbox.hpp"
#include "../Components/Image.hpp"
#include "../Globals.hpp"

struct ArrayElement // one memory slot
{
    int value;
    sf::RectangleShape rect;
    sf::Text data;

    void setValue();
};

struct DataVisualization_1
{
    sf::Font font;
    sf::Font titlefont;
    sf::Text Title;

    Button backButton;
    
//Flow Control
    sf::RectangleShape FlowControlMenu;
    Image PauseButton;
    Image ReplayButton;
    Image NextButton;
    Image SkipButton;
    Image NextButtonReverse;
    Image SkipButtonReverse;
    bool isPause;

    sf::Text speedText;
    int speed;

    Image IncreaseSpeedButton;
    Image DecreaseSpeedButton;

// HighLight Code
    sf::Vector2f CodeScriptPosition;
    sf::RectangleShape CodeHighLight;
    sf::Vector2f CodeHighLightPosition;
    Image CodeScript;
    Image DeleteCodeScriptButton;
    bool CodeScriptVisible = false;

    sf::RectangleShape menuTable;

// Create Buttons
    // #1
    Button ControlMenu_btn1;
    Button CreateFromFileButton;
    Button CreateRadom;
    Button CreateRandomSort;
    Button CreateRandomFixedSize;
    Textbox CreateRandomFixedSize_Textbox;
    Button CreateUserDefinedListButton;
    Textbox CreateUserDefinedList_Textbox;
    
    // #2
    Button ControlMenu_btn2;
    Button AddFrontButton;
    Textbox AddFront_Textbox;
    Button AddBackButton;
    Textbox AddBack_Textbox;
    Button AddMiddleButton;
    Textbox AddMiddle_Textbox;
    
    // #3
    Button ControlMenu_btn3;
    Button DeleteFrontButton;
    Button DeleteBackButton;
    Button DeleteMiddleButton;
    Textbox DeleteMiddle_Textbox;
    Button ClearArrayButton;

    // #4
    Button ControlMenu_btn4;
    Button UpdateButton;
    Textbox UpdateButton_Textbox;
    Button AccessButton;
    Textbox AccessButton_Textbox;
    // #5
    Button ControlMenu_btn5;
    Button SearchButton;
    Textbox SearchButton_Textbox;
    // #6
    Button ControlMenu_btn6;
    Button SortButtonAscending;
    Button SortButtonDescending;

    int size;
    int capacity;
    int funcstate;
    ArrayElement Array[10];

    DataVisualization_1();
    
    void display(sf::RenderWindow &window);
    void handleEvent(sf::RenderWindow &window, sf::Vector2f mousePos, sf::Event &ev);
    void drawArray(sf::RenderWindow &window);

    // #1
    void createArrayFromFile();
    void createRandomArray();
    void createRandomSort();
    void createRandomFixedSizeArray(sf::RenderWindow &window, sf::Event &event);
    void createRandomFixedSize(int size);
    void createUserDefinedArray(sf::RenderWindow &window, sf::Event &event);
    void createUserDefined(sf::RenderWindow &window, std::vector<int> &values);

    void AddFrontArray(sf::RenderWindow &window, sf::Event &event);
    void AddFront(sf::RenderWindow &window, int value);
    void AddBackArray(sf::RenderWindow &window, sf::Event &event);
    void AddBack(sf::RenderWindow &window, int value);
    void AddMiddleArray(sf::RenderWindow &window, sf::Event &event);
    void AddMiddle(sf::RenderWindow &window, int index, int value);

    void DeleteFront(sf::RenderWindow &window);
    void DeleteBack(sf::RenderWindow &window);
    void DeleteMiddleArray(sf::RenderWindow &window, sf::Event &event);
    void DeleteMiddle(sf::RenderWindow &window, int index);

    void UpdateArray(sf::RenderWindow &window, sf::Event &event);
    void Update(sf::RenderWindow &window, int index, int value);
    void AccessArray(sf::RenderWindow &window, sf::Event &event);
    void AccessValue(sf::RenderWindow &window, int index);

    void SearchArray(sf::RenderWindow &window, sf::Event &event);
    void Search(sf::RenderWindow &window, int value);

    void swapNodes(sf::RenderWindow &window, int index1, int index2);
    void SortAscendingArray(sf::RenderWindow& window);
    void SortDescendingArray(sf::RenderWindow& window);

    bool checksize(sf::RenderWindow &window, int size);
    bool printMessage(sf::RenderWindow &window, std::string message);

    void updateChanges(sf::Font tempFont);
};

#endif