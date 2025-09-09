---
layout: post
title: "Exploring Flip 7 Strategies"
date: 2025-09-08 23:00:00 +0200
tags: Game Strategy Simulation
accent_color: "#cd2a9c"
front_image: /assets/code/exploring-flip-7-strategies/flip_7.jpg
thumbnail: /assets/code/exploring-flip-7-strategies/flip_7.jpg
---

When a game has "the greatest card game of all time" on the box it has to be good, right? That was exactly my thought process when buying the game [Flip 7](https://boardgamegeek.com/boardgame/420087/flip-7), which is a card game released in 2024. The game involves players betting to gain as many points as possible without "busting", which happens when a player grabs two identical cards. Although the game mainly involves luck, there can be some interesting strategies.

## Game Rules

First, let's discuss the game rules. Players sit in a circle taking turns drawing numbered cards from a deck. Once it's a player's turn, they can choose to either draw a card from the face-down pile of cards in the middle of the table, or pass and lock in their score for that round. If they choose to draw a card from the pile, there are four different scenarios:

- **The player grabs a number card they don't have yet.** If this is the case, the current player is still in play and gains the number of points equal to the number on the card. The turn then moves to the next player (that's still in play).
- **The player already has a card with the same number.** The player has "busted" and gets zero points this round! This also means that the cards that were grabbed so far this round aren't worth any points.
- **The player grabs an action card.** There are three action cards in the game.
    - *Freeze card:* Once this has card has been revealed it must be played immediately. The player who grabbed the card must choose one active player to be forced to "pass" for the rest of the round. That player counts up their points for this round.
    - *Take 3 card:* Must also be played immediately. An active player must be chosen to be forced to draw three cards from the deck immediately, or draw util they bust (whichever comes first).
    - *Second chance:* A second chance card can be kept by the player as an extra life against busting. Once the player grabs the second of a number card, they discard both the number card and the second chance card.
- **The player grabs a bonus card.** This is like a number card but doesn't have any duplicate. There are bonus cards with +2, +4, +6, +8, +10 and x2 points.

If a player manages to get seven different number cards (bonus/action cards not included), the round ends immediately and all players count up their current scores. The player with seven cards gets 15 bonus points.

Players race to be the first to 200 points over several rounds. Note that players who are still in play during a round keep their card open in front of them. This means all players have complete information on other player's cards and the cards that have been played in previous rounds, but not of the cards that are still to come.

One more important thing of note is that the deck of cards contains 12 twelves, 11 elevens, 10 tens, and so on down to 1 one, in addition to 1 zero. There are three of each action card.

There are some more subtleties in the rules, which I won't go into here.

## Simplifying the Game

To make our lives easier, we will simplify the game a bit. We'll remove any of the bonus and actions cards, so we're just left with number cards. Further, we'll consider a game with a single player and a single turn, meaning we start with the full deck and we're the only ones taking cards out of the deck.

## A Simple Strategy

Now that we've simplified the game, let's start off with a simple strategy. One of the friends I've played Flip 7 with suggested a strategy that would target 30 points. Once this thredhold was reached, he would pass and collect his points.

So I ran some code to simulate his strategy on 10,000 games. And it turns out... The average score is only 17.2, which is a lot lower than I had expected. Surprisingly, using his strategy you would bust about 49.0% of the time. That's almost half of the time! But... Is there a different number he could have chosen that would work better? Well I tried it, and put the results below.

![Targeting a specific score before passing](/assets/code/exploring-flip-7-strategies/target_n.png)

As it turns out the target number of 30 is already pretty good, but it is slightly better to choose the lower target number of 21. Then you could expect an average score of 18.5, busting 25.2% of the time.

However, I do feel like in the actual game his scores were better. This is likely due to the bonus and action cards being in play, and because he would not always abide by his "stop at 30" rule, taking the other players' actions into account. As it turns out, this game can be pretty complicated!

## Complicated Strategies Don't Always Work

Not satisfied with these results, I decided to try to reason one move ahead by repeatedly asking a question: *"If we pick a card from the deck, will our expected score afterward be higher or lower than what we have now?"* So how do we calculate this value? Remember that we have complete knowledge of what cards we've grabbed so far, so we know which cards are left.

We need to take into account the chance of busting, and the expected score after grabbing a card without busting. Let $B$ be the chance we'll bust, which can be calculated using the number of cards left in the deck that are the same as one of the cards in our hand. Let $S$ be the current game score. Finally, let $A$ be the average value of the cards in the deck that won't make us bust. We will take a card if the following holds:

$$
    (1 - B) (S + A) > S
$$

Surely this must work pretty well, I thought. At every point in time we will see if we should continue or not, which is much smarter than taking a specific target number. Well... I was wrong. This strategy performed about the same as targeting a score of 22, with an average score of 18.7 (0.2 higher) and a 30.3% bust rate.

## ...Or Do They?!

Desperate to justify my complicated strategy, I thought of one situation where it does work well: When there are very few cards left in play! The "stop at 21" strategy performs about the same when 70 out of the 79 cards are removed from the game:

![Targeting a specific score before passing with 70 cards removed](/assets/code/exploring-flip-7-strategies/target_n_70_removed.png)

The "Is the next card worth it?" strategy, however, peforms much better as the number of cards left decreases. There is more information to take advantage of in this situation!

!["Is the next card worth it?" strategy with different numbers of cards removed](/assets/code/exploring-flip-7-strategies/is_next_move_worth_it.png)

Even then... During most of the game you won't have a couple of cards left in the deck, so the impact of this strategy won't be that big... *\*sigh\**

## Conclusion

So this is where my little experiment ends. There's clearly still much more to explore: New strategies, action cards, keeping track of other players, etc. But that's for you to explore :)

Either way, it seems the "stop at 21" rule is an easy-to-remember and good enough strategy for most players. Every now and then you can then adapt to the cards in play and action cards. Now you just have to deal with your opponents get luckier than you...

If you'd like to look at the source code and run the experiments yourself, I've posted the code on GitHub:
{% include center-button.html icon="link" text="Source code" href="https://github.com/dirckvdende/dirckvdende.github.io/tree/main/assets/code/exploring-flip-7-strategies" %}