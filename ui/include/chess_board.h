#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


class PieceSprite;
enum class PieceColor;

class ChessPalette
{
    public:
    ChessPalette();
    ChessPalette(const sf::Color&, const sf::Color&);

    sf::Color getBlackFieldColor() const;
    sf::Color getWhiteFieldColor() const;

    private:
    const sf::Color& white_color;
    const sf::Color& black_color;

};

class ChessBoard: public sf::Drawable, public sf::Transformable
{
    public:
    void load(const sf::Vector2u&, const sf::Vector2f&, const ChessPalette&, const PieceColor&);
    void processMouseButtonPressedEvent(const sf::Vector2i&);

    private:
    sf::VertexArray vertices;
    sf::Vector2f offset;

    static constexpr int board_width = 8;
    static constexpr int board_height = 8;
    std::shared_ptr<PieceSprite> chess_field[board_height][board_width];

    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
    void load_pieces(const sf::Vector2u&, const sf::Vector2f&, const PieceColor&);
    sf::Vector2i screenCoordinatesToBoardPosition(const sf::Vector2i&);
};