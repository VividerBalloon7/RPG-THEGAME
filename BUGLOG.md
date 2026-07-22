# BUGLOG

Name: Darius McLendon

## Bug #1 : In the first void function the parameters where wrong, it should be Character hero, due to the fact that C++ is case sensitive and pass-by-reference is necessary

## Bug #2 : The first void function should also pass by reference so it shouldn't be just Character, it should be Character&.

## Bug #3 : In the for loop under character the int i = 0; i <= 3; i++ should be int i = 0; i <3; i++ , so that the battle ends after 3 rounds.

## Bug #4 :  Broken header guard in character.h, the ifdef and ifndef names don't match

## Bug #5 : The battle loop uses || instead of &&, this means the battle will continue running even after the hero or monster dies.


## Bug #6 : Potions can raise above maximum hp, the Character class already contains int maxHp.
