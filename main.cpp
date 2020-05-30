#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//First commit by *&^-=0-("")><--Michael Bolshakov--><()""-=0-^&*

String to_rusian(string stri)
{
    return sf::String::fromUtf8(begin(stri), end(stri));
}
class one_tasck
{
public:
    string text;
    string answer;
    void add(string text_, string answer_)
    {
        text = text_;
        answer = answer_;
    }
    void print_task(int index,Text &text_s)
    {
        text_s.setString(text_s.getString()+to_rusian(to_string(++index)+") " +text) + "\n");
    }
};
class task
{
private:
    vector<one_tasck> tasks;

public:
    void add(string text, string answer)
    {
        one_tasck t;
        t.add(text, answer);
        tasks.push_back(t);
    }
    bool check(int index, string answer)
    {
        return tasks[index].answer == answer;
    }
    void print(Text &text)
    {
        for (int i = 0; i < tasks.size(); i++)
        {
            tasks[i].print_task(i,text);
        }
    }
};

int main()
{
    task Task;
    Task.add("2+2 сколько стало полороплаолпоалоплаоплаоплаолпоалполаоплаоплоплаопло","5");
    Task.add("50+60","110");
    // Task.add("5+5","10");
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    const int size = 52;
    Font font;
    font.loadFromFile("./Score.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(80);
    text.setPosition(10, 10);

    text.setFillColor(Color::Blue);
    // string str = "првиет";
    string strl;
    Task.print(text);
    while (window.isOpen())
    {
        Event ev;
        while (window.pollEvent(ev))
        {

            if (ev.type == sf::Event::Closed)
                window.close();
        }

        // text.setString(to_rusian(str));
        window.clear();

        window.draw(text);

        window.display();
    }

    return 0;
}