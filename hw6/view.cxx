#include "view.hxx"

// Convenient type aliases:
using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

// You can change this or even determine it some other way:
static int const grid_size = 80;

static int const tilegap = 5;

static int const circleroom = 5;

static int const radius = 5;

static int const ss = 35;

//colors
Color const black{0,0,0};
Color const white{255,255,255};
Color const green{0,120,0};
Color const red{255,0,0};
Color const miniblack{40,40,40};
Color const miniwhite{210,210,210};
Color const grey{190,190,190};



View::View(Model const& model)
        : model_(model),
        dark(radius*3, black),
        light(radius*3, white),
        minidark(radius*2, miniblack),
        minilight(radius*2, miniwhite),
        validmove({ss, ss}, red),
        tile({ss, ss}, green),
        wintile({ss, ss}, grey)


        // You may want to add sprite initialization here
{ }

void View::draw(Sprite_set& set, ge211::Posn<int> positionmouse)
{

    for(Position pos: model_.board()) {
        Position pos2 = board_to_screen(pos) + ge211::geometry::Dims<int>
                {10, 10};
        set.add_sprite(tile, pos2, 0);
        if (model_[pos] == Player::dark) {
            set.add_sprite(dark, pos2, 10);
        }
        if (model_[pos] == Player::light) {
            set.add_sprite(light, pos2, 10);
        }
        if(model_.is_game_over()){
            for(Position pos: model_.board()){
                Position pos2 = board_to_screen(pos) +
                        ge211::geometry::Dims<int>{10, 10};
                if (model_[pos] == model_.winner()){
                    set.add_sprite(wintile, pos2, 1);
                }
            }
        }
        const Move* movep = model_.find_move(screen_to_board(positionmouse));
        if (movep != nullptr) {
            for(auto position: movep->second){
                Position position2 = board_to_screen(position) +
                        ge211::geometry::Dims<int>{10, 10};
                set.add_sprite(validmove, position2, 1);
            }
        }

        if(model_.turn() == Player::dark) {
            set.add_sprite(minidark, positionmouse, 2);
        }
        if(model_.turn() == Player::light) {
            set.add_sprite(minilight, positionmouse, 2);
        }



        // TODO, PROBABLY
    }

}

View::Position
View::board_to_screen(
        Model::Position logical )
const
{
    logical = {logical.x * grid_size, logical.y * grid_size};
    return logical;
}


Model :: Position
View :: screen_to_board (
        View :: Position physical )
const
{
    physical = {physical.x / grid_size, physical.y / grid_size};
    return physical;
}



View::Dimensions
View::initial_window_dimensions() const
{
    // You can change this if you want:
    return (grid_size) * model_.board().dimensions();
}

std::string
View::initial_window_title() const
{
    // You can change this if you want:
    return "Reversi";
}

