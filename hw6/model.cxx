#include "model.hxx"

using namespace ge211;

Model::Model(int size)
        : Model(size, size)
{ }

Model::Model(int width, int height)
        : board_({width, height})
{
    compute_next_moves_();
    // TODO: initialize `next_moves_` to `turn_`'s available moves
}

Model::Rectangle
Model::board() const
{
    return board_.all_positions();
}

Player
Model::operator[](Position pos) const
{
    return board_[pos];
}

const Move*
Model::find_move(Position pos) const
{
    auto i = next_moves_.find(pos);

    if (i == next_moves_.end()) {
        // Nothing was found, so return NULL (nullptr in C++)
        return nullptr;
    } else {
        // Dereferences the iterator to get the value then returns a pointer
        // to that value. This is safe as the pointer is to a value living
        // within the `next_moves_` structure.
        return &(*i);
    }
}

void
Model::play_move(Position pos)
{
    if (is_game_over()) {
        throw Client_logic_error("Model::play_move: game over");
    }

    const Move* movep = find_move(pos);
    if (movep == nullptr) { // check if there was no such move
        throw Client_logic_error("Model::play_move: no such move");
    }
    really_play_move_(*movep);
    // TODO: actually execute the move, advance the turn, refill
    // `next_moves_`, etc.
}

//
// BELOW ARE HELPER FUNCTIONS
// Our tests will run on the public functions, not the helper functions
// However, these will be extremely useful in writing the above functions
//

Position_set
Model::find_flips_(Position current, Dimensions dir) const
{
    Position_set ps = {};
    Position next = current + dir;
    while(true){
        if(board_.good_position(next) && board_[next] == other_player(turn())){
            ps[next] = true;
            next += dir;
        }
        if(!board_.good_position(next) || board_[next] == Player::neither){
            return {};
        }
        if(board_[next] == turn()){
            return ps;
        }

    }

}

Position_set
Model::evaluate_position_(Position pos) const
{
    std::vector<Dimensions> direc = board_.all_directions();
    Position_set flipset = {};
    for(size_t i=0; i < sizeof(direc); i++){
        Position_set flip = find_flips_(pos, direc[i]);
        flipset |= flip;
    }
    if(!flipset.empty()) {
        flipset[pos] = true;
    }
    return flipset;
}

void
Model::compute_next_moves_()
{
    next_moves_ = {};
    for (Position pos: board_.center_positions()) {
        if (board_[pos] == Player::neither) {
            next_moves_[pos] = {pos};
        }
    }
    if(!next_moves_.empty()){
        return;
    }
    for (Position pos : board_.all_positions()) {
        Position_set flipst = {};
        if (board_[pos] == Player::neither) {
            flipst = evaluate_position_(pos);
        }
        if(!flipst.empty()) {
            next_moves_[pos] = flipst;
        }
    }
    return;


}

bool
Model::advance_turn_()
{
    turn_ = other_player(turn());
    compute_next_moves_();
    //if(!next_moves_.empty()){
      //  return true;
    //}
    //return false;
    return !next_moves_.empty(); //? is this better
}

void
Model::set_game_over_()
{
    turn_ = Player::neither;
    size_t x = board_.count_player(Player::dark);
    size_t y = board_.count_player(Player::light);
    if(x>y){
        winner_ = Player::dark;
    }else{
        winner_ = Player::light;
    }
}

void
Model::really_play_move_(Move move)
{
    board_.set_all(move.second, turn());
    bool x = advance_turn_();
    bool y = false;
    if(!x){
        y = advance_turn_();
    }

    if(!x && !y){
        set_game_over_();
    }
}
