#include <cstdlib>
#include "DrawCard.h"
#include "../Game.h"
#include "../net/GameServer.h"

DrawCard::DrawCard(string original_name, string name, int count, int draw_count)
        : InstantCard(original_name, name, count), draw_count_(draw_count) { }

int DrawCard::play(Game *game, Player *player, int position, int target, int target_card) {
    if (player->isPending()) {
        return Game::ERROR_INVALID_REACTION;
    }

    if (isTargetable()) {
        // Draw a card from another player
        if ((target_distance_ && game->getDistance(player, target) == 1) || target_any_) {
            Player *target_player = game->getPlayers()[target];
            if (target_card >= 0) {
                // Draw laid permanent card
                auto & cards = target_player->getPermanentCards();
                if (target_card >= (int) cards.size()) {
                    return Game::ERROR_INVALID_TARGET_CARD;
                }
                player->addCard(cards[target_card]);
                cards.erase(cards.begin() + target_card);
            } else {
                // Draw random card from hand
                target_card = rand() % (int) target_player->getCards().size();
                auto & cards = target_player->getCards();
                player->addCard(cards[target_card]);
                cards.erase(cards.begin() + target_card);
            }
        } else {
            return Game::ERROR_OUT_OF_RANGE;
        }
    } else {
        // Draw a card from pack
        for (int i = 0; i < draw_count_; i++) {
            game->drawCard(player);
        }
    }

    game->discardCard(player, position);

    return Game::SUCCESS;
}

bool DrawCard::isCardTargetable() const {
    return isTargetable();
}