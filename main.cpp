#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

//hello
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
    // Adope Flash
    void print_task(int index, Text &text_s)
    {
        text_s.setString(text_s.getString() + to_rusian(to_string(++index) + ") " + text) + "\n");
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
            tasks[i].print_task(i, text);
        }
    }
};

class aplication
{
private:
    Sprite sprite;
    Texture texture;

public:
    void aplication_(string s)
    {
        texture.loadFromFile(s);
        sprite.setTexture(texture);
        sprite.setScale(2, 2);
    }
    Sprite getsprite()
    {
        return sprite;
    }
    void set_Position(int x, int y)
    {
        sprite.setPosition(x, y);
    }
};
int show_tasks(RenderWindow &TasksWindow, task &Task, Text &text)
{

    text.setFillColor(Color(227, 66, 52));
    text.setString("");
    Task.print(text);
    Texture fone_texture;
    fone_texture.loadFromFile("./papirus.jpg");
    Sprite fone;
    fone.setTexture(fone_texture);
    fone.setScale(3, 3);
    fone.setPosition(-300, -300);
    bool b = true;
    while (TasksWindow.isOpen() && b)
    {
        Event ev;
        while (TasksWindow.pollEvent(ev))
        {

            if (ev.type == sf::Event::Closed)
                TasksWindow.close();
            if (ev.key.code == Keyboard::Left)
                text.move(5, 0);
            if (ev.key.code == Keyboard::Right)
                text.move(-5, 0);
            if (ev.key.code == Keyboard::Up)
                text.move(0, 5);
            if (ev.key.code == Keyboard::Down)
                text.move(0, -5);
            if (ev.key.code == Keyboard::Q)
                b = false;
        }

        // text.setString(to_rusian(str));
        TasksWindow.clear();
        TasksWindow.draw(fone);
        TasksWindow.draw(text);

        TasksWindow.display();
    }

    return 0;
}
int main()
{
    task Task;
    Task.add("2+2 сколько стало паопло", "5");
    Task.add("50+60", "110");
    Task.add("Привет Maxim", "110");
    Task.add("5+5", "10");
    RenderWindow window(sf::VideoMode(1920, 1080), "SFML works!");
    window.setMouseCursorVisible(false);
    const int size = 52;
    Font font;
    font.loadFromFile("./Score.TTF");
    Text text;
    text.setFont(font);
    text.setCharacterSize(80);
    text.setPosition(10, 10);
    CircleShape shape(20.0f);
    shape.setPosition(10, 10);
    shape.setFillColor(Color::Red);
    Texture Cursor_texture;
    Cursor_texture.loadFromFile("./cursor.png");
    Sprite Cursor;
    Cursor.setTexture(Cursor_texture);
    aplication app[2];
    app[0].aplication_("./app1.png");
// dfg
    while (window.isOpen())
    {
        Vector2i pixelPos = Mouse::getPosition(window);
        Vector2f pos = window.mapPixelToCoords(pixelPos);
        Cursor.setPosition(pos.x, pos.y);
        Event ev;
        while (window.pollEvent(ev))
        {

            if (ev.type == sf::Event::Closed)
                window.close();

            if (Mouse::isButtonPressed(Mouse::Left))
            {

                if (Cursor.getGlobalBounds().intersects(app[0].getsprite().getGlobalBounds()))
                {
                    show_tasks(window, Task, text);
                }
                        }
        }

        // window.clear(Color(250,250,250));
        window.clear();
        // window.draw(shape);
        window.draw(Cursor);
        window.draw(app[0].getsprite());

        window.display();
    }
}
