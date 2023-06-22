# **Zork-Game-jordi-nieto**

Simple Zork-like conversational game in C++.

- **Author:** Jordi Nieto Maldonado

- **Repository:** https://github.com/Bermellet/Zork-Game-jordi-nieto

- **License:** https://github.com/Bermellet/Zork-Game-jordi-nieto/blob/master/LICENSE

<br/>

## About the implementation

My version of Zork implements the basic orders to move through rooms, get information about entities, pick/drop/use objects.

There are chests, which are items that cannot be picked and contain other objects. There is also an object that can be used on an entity to finish the game.

<br/>

## Guide to play

The main objective of the game is to recover a potion hidden inside a chest, and use it with a statue at the end of a cave.
<details>
  <summary>This are the basic commands that can be used:</summary><br/>

**help**: Shows the list of commands

**move / go _[direction]_**: Moves the player in the said directions

**[direction]**: Moves the player in the said directions

**look _[objectives]_**: Shows information about the entity

**[objectives]**: Shows information about the entity

**open _[inventory / items / chest]_**: Shows the items contained on those entities

**use [itemName]**: Uses the item

**pick / take _[itemName]_**: Picks the item from the current room

**pick / take _[items from chest]_**: Pick the items contained inside a chest from the current room

**drop _[itemName]_**: Drops the item from the inventory to the current room

**drop _[itemName in chest]_**: Drops the item from the inventory to the chest in the current room 

<br/>

**_Objectives_**: room / around, path / paths, inventory / items, itemName

**_Directions_**: north / n, south / s, east / e, west / w

</details>
<br/>

<details>
  <summary><b>Spoiler warning</b>: steps to solve the game</summary><br/>
To solve the game traversing all the rooms and picking all the objects you can execute the following commands in order:

    south
    west
    south
    open chest
    pick items from chest
    east
    east
    pick torch
    east
    inventory
    use torch
    south
    use potion
</details>

<br/>

## Other thoughts

This project has been really useful to refresh the C++ syntax and its correct use with object-oriented programming.

The idea of having to implement some extra features has made the task more enjoyable, motivating the thought of new ideas and being creative, whether they were finally implemented or not.

The **extra feature** that I have implemented is the possibility of picking objects from chests or dropping them inside. There has been also the interaction of one object with an entity, to finish the game.

These are some of the ideas that I could not implement due to the lack of personal time, but have thought about:
- Items and entities with stats
- Battle mode
- Special Rooms (e.g. can't be exited, only accessible once)
- Teleporting portals
- Traps
- Interaction with NPCs

Other possible improvements:
- Entities and configuration exported to text files, to be read by the main program
- Refactoring of repetitive code (e.g. on the execution of orders - _World.cpp_)
- Translation to Spanish

