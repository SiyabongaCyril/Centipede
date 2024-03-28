#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Segments.h"
#include "Centipede.h"
#include "Window.h"
#include "Splashscreen.h"
#include "Player.h"
#include "Bullet.h"
#include "Resources.h"
#include "Update.h"
#include <sstream>

/// ------------- Tests for Window Class ----------------

TEST_CASE("Should access the size of the window")
{
    Window window( sf::Vector2u(800,600), "Centipede++" );
    CHECK( window.getWindowSize()== sf::Vector2u(800,600));
}

/// ------------- Testing Collisions----------------

TEST_CASE("Entities should collide")
{
    Bullet bullet;
    Segments segment;
    float x = 200.0f;
    float y = 340.0f;

    bullet.loadBullet(x,y);
    segment.creategeneralSegment("resources/segmentblock.png",x,y);

    CHECK(isColliding( bullet.getBullets()[0], segment.getSegment()) == true);
}

/// ------------- Tests for Player  Class----------------

TEST_CASE("The player positions X and Y can be accessed")
{

    Player player;
    sf::Vector2f defaultWindowSize = sf::Vector2f(1600,900);
    auto defaultXPos = defaultWindowSize.x/2;
    auto defaultYPos = defaultWindowSize.y*0.98;

    CHECK(player.getPlayer().getPosition().x == defaultXPos);
    CHECK(player.getPlayer().getPosition().y== defaultYPos);
}


TEST_CASE("The player is moved right")
{

   vector<sf::Sprite> mushrooms;
    Player player;
    auto movementSpeed = 4.0f;
    auto defaultXPos = player.getPlayer().getPosition().x;
    auto defaultYPos = player.getPlayer().getPosition().y;

    player.movePlayer(Direction::RIGHT, mushrooms);
    CHECK(player.getPlayer().getPosition() == sf::Vector2f(defaultXPos+movementSpeed,defaultYPos));
}


TEST_CASE("The player is moved down")
{
     vector<sf::Sprite> mushrooms;
    Player player;
    auto movementSpeed = 4.0f;
    auto defaultXPos = player.getPlayer().getPosition().x;
    auto defaultYPos = player.getPlayer().getPosition().y;

    player.movePlayer(Direction::DOWN, mushrooms);
    CHECK(player.getPlayer().getPosition() == sf::Vector2f(defaultXPos,defaultYPos+movementSpeed));
}


TEST_CASE("The player is moved up")
{
    vector<sf::Sprite> mushrooms;
    Player player;
    auto movementSpeed = 4.0f;
    auto defaultXPos = player.getPlayer().getPosition().x;
    auto defaultYPos = player.getPlayer().getPosition().y;

    player.movePlayer(Direction::UP, mushrooms);
    CHECK(player.getPlayer().getPosition() == sf::Vector2f(defaultXPos,defaultYPos-movementSpeed));
}

TEST_CASE("The player is moved left")
{
    vector<sf::Sprite> mushrooms;
    Player player;
    auto movementSpeed = 4.0f;
    auto defaultXPos = player.getPlayer().getPosition().x;
    auto defaultYPos = player.getPlayer().getPosition().y;

    player.movePlayer(Direction::LEFT,  mushrooms);
    CHECK(player.getPlayer().getPosition() == sf::Vector2f(defaultXPos-movementSpeed,defaultYPos));
}

/// ------------- Tests for Bullets Class----------------

TEST_CASE("No bullet is shot before the game begins/space is pressed")
{
    Bullet bullet;
    CHECK( bullet.getBullets().empty() == true);
}

TEST_CASE("Bullets can be loaded")
{
    Bullet bullet;
    bullet.loadBullet(300.0f,500.0f);
    bullet.loadBullet(350.0f,400.0f);
    bullet.loadBullet(300.0f,570.0f);
    CHECK(bullet.getBullets().size() == 3);
}

TEST_CASE("Number of bullets shot can be accessed")
{
    Bullet bullet;
    bullet.loadBullet(300.0f,500.0f);
    bullet.loadBullet(350.0f,400.0f);

    CHECK(bullet.getBullets().size() == 2);
}

TEST_CASE("Bullet should be loaded at a specified position above the player")
{
    Bullet bullet;
    bullet.loadBullet(300.0f,400.0f);
    CHECK(bullet.getBullets()[0].getPosition() == sf::Vector2f(300.0f,400.0f));
}

TEST_CASE("Bullet should be moved up")
{
    const vector<sf::Sprite>mushrooms;
    vector<int> mushroomsShot;
    Bullet bullet;
    auto movementSpeed = -8.0f;
    bullet.loadBullet(300.0f,400.0f);

    sf::Vector2f bulletCurrentPos =bullet.getBullets()[0].getPosition();

    bullet.moveBullets(mushrooms, mushroomsShot);

    CHECK(bullet.getBullets()[0].getPosition() == sf::Vector2f(bulletCurrentPos.x,bulletCurrentPos.y+movementSpeed));
}

/// ------------- Tests for Segment Class ----------------

TEST_CASE("Move segemt to the right")
{
    Window gameWindow{sf::Vector2u (800,600),  "Centipede++"};

    Segments segmentBlock;
    segmentBlock.creategeneralSegment("resources/segmentblock.png",40,0);

    auto initialX = segmentBlock.getSegment().getPosition().x;
    segmentBlock.moveSegment(gameWindow.getWindowSize().x,gameWindow.getWindowSize().y);
    auto finalX = segmentBlock.getSegment().getPosition().x;

    CHECK(finalX>initialX);
}

TEST_CASE("Move segemt to the left")
{
    Window gameWindow{sf::Vector2u (800,600),  "Centipede++"};

    Segments segmentBlock;
    segmentBlock.creategeneralSegment("resources/segmentblock.png",gameWindow.getWindowSize().x,0);

    auto initialX = segmentBlock.getSegment().getPosition().x;
    segmentBlock.moveSegment(gameWindow.getWindowSize().x,gameWindow.getWindowSize().y);
    auto finalX = segmentBlock.getSegment().getPosition().x;

    CHECK(initialX>finalX);
}

TEST_CASE("Move segment downwards")
{
    Window gameWindow{sf::Vector2u (800,600), "Centipede++"};

    Segments segmentBlock;
    segmentBlock.creategeneralSegment("resources/segmentblock.png",gameWindow.getWindowSize().x,0);

    auto initialY = segmentBlock.getSegment().getPosition().y;
    segmentBlock.moveSegment(gameWindow.getWindowSize().y,gameWindow.getWindowSize().y);
    auto finalY = segmentBlock.getSegment().getPosition().y;
    CHECK(finalY>initialY);
}

TEST_CASE("Move segment upwards")
{
    Window gameWindow{sf::Vector2u (800,600), "Centipede++"};

    Segments segmentBlock;
    segmentBlock.creategeneralSegment("resources/segmentblock.png",gameWindow.getWindowSize().x,gameWindow.getWindowSize().y);

    auto initialY = segmentBlock.getSegment().getPosition().y;
    segmentBlock.moveSegment(gameWindow.getWindowSize().y,gameWindow.getWindowSize().y);
    auto finalY = segmentBlock.getSegment().getPosition().y;
    CHECK(finalY<initialY);
}

TEST_CASE("Segment cannot escape player domain")
{
    Window gameWindow{sf::Vector2u (800,600), "Centipede++"};

    Segments segmentBlock;
    segmentBlock.creategeneralSegment("resources/segmentblock.png",gameWindow.getWindowSize().x,0.75*gameWindow.getWindowSize().y);

    auto initialY = segmentBlock.getSegment().getPosition().y;
    segmentBlock.moveSegment(gameWindow.getWindowSize().y,gameWindow.getWindowSize().y);
    auto finalY = segmentBlock.getSegment().getPosition().y;

    CHECK(finalY>initialY);
}

/// ------------- Tests for Centipede Class----------------

TEST_CASE("Centipede vector must not be empty")
{
    Centipede centipede;
    centipede.setCentipedeSize(10);
    CHECK(  !(centipede.getCentipedeTrains()[0].empty()));
}


TEST_CASE("Centipede vector must be no less than 10")
{
    Centipede centipede;
    auto defaultMinSize = 10;

    centipede.setCentipedeSize(3);

    CHECK(centipede.getCentipedeTrains()[0].size() == defaultMinSize);
}

TEST_CASE("Centipede vector must be no greater than 15")
{
    Centipede centipede;
    auto defaultMaxSize = 15;

    centipede.setCentipedeSize(30);
    CHECK(centipede.getCentipedeTrains()[0].size() == defaultMaxSize);
}


/// ------------- Tests for Resources Class----------------

TEST_CASE("Font is not loaded")
{
    Resources resource;
    CHECK_THROWS_AS(resource.createMessage("meaasge","resour",79,0,0),FontCannotBeLoaded);
}

TEST_CASE("Textures is not loaded")
{
    Resources resource;
    CHECK_THROWS_AS( resource.createSprite("image",0,0),FileCannotBeLoaded);
}
