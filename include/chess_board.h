#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

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
    void load(const sf::Vector2u&, const sf::Vector2f&, const ChessPalette&);

    private:
    sf::VertexArray m_vertices;
    static constexpr int board_width = 8;
    static constexpr int board_height = 8;
    virtual void draw(sf::RenderTarget&, sf::RenderStates) const;
};