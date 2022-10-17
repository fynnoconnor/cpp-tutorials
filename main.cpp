#include <SFML/Graphics.hpp>

int main()
{   
    int width = 1920, height = 1080;
    sf::RenderWindow window(sf::VideoMode(width, height), "My window");
    window.setVerticalSyncEnabled(true);

    sf::Clock clock;


    // Sprites and textures
    // Create a texture to hold a graphic on the GPU
    sf::Texture textureBackground;
    // Load a graphic into the texture
    textureBackground.loadFromFile("graphics/background.png");
    // Create a sprite
    sf::Sprite spriteBackground;
    // Attach the texture to the sprite
    spriteBackground.setTexture(textureBackground);
    // Set the spriteBackground to cover the screen
    spriteBackground.setPosition(0,0);

    sf::Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");
    sf::Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(810, 0);

    // Prepare the bee
    sf::Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");
    sf::Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.setPosition(0, 800);
    
    // bee speed
    srand((int)time(0));
    float beeSpeed = (rand() % 200) + 200;
    // How high is the bee
    srand((int)time(0) * 10);
    float beeHeight = (rand() % 500) + 500;
    spriteBee.setPosition(2000, beeHeight);

    sf::CircleShape player(10.f);
    player.setFillColor(sf::Color(100, 250, 50));
    player.setPosition(width/2.f, height/2.f);

    bool paused = true;

    // run the program as long as the window is open
    while (window.isOpen())
    {

        //logic//


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
        window.close();
        }

        // Start the game
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
        paused = false;
        }

        //update//
        if (!paused){
            sf::Time dt = clock.restart();

            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            // Has the bee reached the left-hand edge of the screen?
            if (spriteBee.getPosition().x < -100)
            {
                // Set it up ready to be a whole new bee next frame
                srand((int)time(0) * 10);
                beeHeight = (rand() % 500) + 500;
                spriteBee.setPosition(2000, beeHeight);
            }
        }
        


        //draw//
        window.clear(sf::Color::Black);

        
        window.draw(spriteBackground);
        window.draw(player);
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();
    }

    return 0;
}