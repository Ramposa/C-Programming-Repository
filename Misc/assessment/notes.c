#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

/*

We need:
    * pokemonList
       * pokemonName [CHAR] [20];
       * pokemonType [CHAR] [20];
       * pokemonAbility [CHA] [20];
    * playerList
       * playerName
       * pokemonCaught
    * Pokedex
       * Contains 
    * Linked list style

    * Voids to return functions from the node

    * main:
      * AddPlayerToList
      * DisplayPlayerDetails
      * AddPokemonToList
      * FindPokemon
      * PokemonToPlayer

 */

typedef struct PokemonNode { // Structure PokemonNode (old)
  char pokemonName [20]; //Pokemon variables
  char pokemonType [20];
  char pokemonAbility [30];

 //pointer to next pokemon in list
  struct PokemonNode * leftPokemon, * rightPokemon;

} PokemonNode; // PokemonNode (new, use this.)

typedef struct CaughtPokemonNode {
  char * pokemonName;
  struct CaughtPokemonNode * nextCaughtPokemon; 

} CaughtPokemonNode;

typedef struct PlayerNode { 
  char playerName[30];
  struct PlayerNode * nextPlayer;

} PlayerNode;

typedef struct pokedex { 
  struct PokemonNode * pokemonHead; // Head of X node.
  struct PlayerNode * playerHead;

} pokedex;

pokedex * NewPokedex ();

PokemonNode * NewPokemonNode(char * name, char * type, char * ability);
void AddPokemonToList( pokedex *Pokedex, char * name, char * type, char * ability);
void DisplayPokemonDetails(pokedex * Pokedex, char * name);
// Void is used to return the function. Makes the pointer universal. Also create nodes
PokemonNode * FindPokemon( pokedex * Pokedex, char * name ); // This finds the pokemin by pokemonName as name.
void AddPlayerToList(pokedex *Pokedex, char * name);

PlayerNode * FindPlayer(pokedex *Pokedex, char *name);

CaughtPokemonNode * NewCaughtPokemonNode(pokedex * Pokedex, char * pokemonName);
void DisplayPlayerDetails(pokedex * Pokedex, char * name);
int getCaughtPokemonLength(PlayerNode * player);
void PokemonToPlayer(pokedex *Pokedex, char * playerName, char * pokemonName);

// Search by type [Optional]
//void DisplayPokemonWithType(pokedex * Pokedex, char * type);

// Seach by ability [Optional]
//void DisplayPokemonWithAbility(pokedex * Pokedex, char * abilty);

// Displays head of the node
void DisplayHeadPokeNode(pokedex * Pokedex, char * pokemonName);
void DisplayHeadNameNode(pokedex * Pokedex, char * playerName);

int main(void) {
  pokedex *mainPokedex = NewPokedex();

  // Add Players to the pokedex
  AddPlayerToList(mainPokedex, "Ash");
  AddPlayerToList(mainPokedex, "Misty");
  AddPlayerToList(mainPokedex, "Dawn");
  AddPlayerToList(mainPokedex, "Brock");

  printf("\n\nList player:\n\n");

  DisplayPlayerDetails(mainPokedex, "Ash");
  DisplayPlayerDetails(mainPokedex, "Misty");
  DisplayPlayerDetails(mainPokedex, "Dawn");
  DisplayPlayerDetails(mainPokedex, "Brock");

  printf("\n\nList of pokemon by name, type & ability:\n\n");

  // Add Pokemon to the pokedex
  AddPokemonToList(mainPokedex, "Bulbasaur", "Grass", "Overgrow"); 
  AddPokemonToList(mainPokedex, "Charmander", "Fire", "Blaze");
  AddPokemonToList(mainPokedex, "Squirtle", "Water", "Torrent");
  AddPokemonToList(mainPokedex, "Butterfree", "Bug", "Compound Eyes");
  AddPokemonToList(mainPokedex, "Pidgey", "Normal", "Tangled Feet");
  AddPokemonToList(mainPokedex, "Vgnomoth", "Bug", "Shield Dust");
  AddPokemonToList(mainPokedex, "Poliwag", "Water", "Water Absorb");
  AddPokemonToList(mainPokedex, "Psyduck", "Water", "Damp");


  FindPokemon(mainPokedex, "Bulbasaur");
  FindPokemon(mainPokedex, "Charmander");
  FindPokemon(mainPokedex, "Squirtle");
  FindPokemon(mainPokedex, "Butterfree");
  FindPokemon(mainPokedex, "Pidgey");
  FindPokemon(mainPokedex, "Vgnomoth");
  FindPokemon(mainPokedex, "Poliwag");
  FindPokemon(mainPokedex, "Psyduck");


  // Testing the display pokemon function and FindPokemon function along with it
  DisplayPokemonDetails(mainPokedex, "Bulbasaur");
  DisplayPokemonDetails(mainPokedex, "Charmander");
  DisplayPokemonDetails(mainPokedex, "Squirtle");
  DisplayPokemonDetails(mainPokedex, "Butterfree");
  DisplayPokemonDetails(mainPokedex, "Pidgey");
  DisplayPokemonDetails(mainPokedex, "Vgnomoth");
  DisplayPokemonDetails(mainPokedex, "Poliwag");
  DisplayPokemonDetails(mainPokedex, "Psyduck");


  printf("\n\nList of pokemon caught by player:\n\n");
  PokemonToPlayer(mainPokedex, "Ash", "Charmander");
  PokemonToPlayer(mainPokedex, "Ash", "Pidgey");
  PokemonToPlayer(mainPokedex, "Ash", "Zoroark");
  PokemonToPlayer(mainPokedex, "Misty", "Squirtle");
  PokemonToPlayer(mainPokedex, "Dawn", "Poliwag");
  PokemonToPlayer(mainPokedex, "Dawn", "Pidgey");
  PokemonToPlayer(mainPokedex, "Brock", "Psyduck");
  
  //printf("\n\nDisplays ability:\n\n");

  //DisplayPokemonWithType(mainPokedex, "");
  //DisplayPokemonWithAbility(mainPokedex, "");

  printf("\n\nDisplays head nodes of:\n\n");
  DisplayHeadPokeNode(mainPokedex, "");
  DisplayHeadNameNode(mainPokedex, "");
  return 0;
}

pokedex * NewPokedex () {
  pokedex * newPokedex = NULL; // Pointer
  newPokedex = (pokedex*)malloc(sizeof(pokedex));
  newPokedex -> pokemonHead = NULL; // head of x
  newPokedex -> playerHead = NULL;
  free(newPokedex);

  return newPokedex;

}

PokemonNode *NewPokemonNode(char * name, char * type, char * ability) { 
  PokemonNode * newNode = NULL;

  newNode = (PokemonNode*)malloc(sizeof(PokemonNode));

  if (newNode != NULL) {
    strcpy(newNode -> pokemonName, name); // Copy string into a linked list variable
    strcpy(newNode -> pokemonType, type);
    strcpy(newNode -> pokemonAbility, ability);
    newNode -> leftPokemon = newNode -> rightPokemon = NULL; 

  }

  return newNode;

}

void AddPokemonToList( pokedex *Pokedex, char * name, char * type, char * ability) {
  PokemonNode * new_pokemon = NewPokemonNode(name, type, ability);
  if (Pokedex -> pokemonHead == NULL) {
    Pokedex -> pokemonHead = new_pokemon;
    return;

  }

  else {
    PokemonNode * temp = NULL;
    temp = Pokedex -> pokemonHead;
    bool check = false;

    while (!check) {
      int first = strcasecmp(temp -> pokemonName, name);
      if (first > 0) 
      {
        if (temp -> leftPokemon != NULL) { 
          temp = temp -> leftPokemon;
        }

        else {
          temp -> leftPokemon = new_pokemon;
          break;

        }
      }

      else {
        if (temp -> rightPokemon != NULL) {
          temp = temp -> rightPokemon;

        }

        else {
          temp -> rightPokemon = new_pokemon;
          break;

        }
      }
    }
  }

  return;

}

PokemonNode * FindPokemon( pokedex * Pokedex, char * name ) {
  if (Pokedex -> pokemonHead == NULL) {  
      return NULL;
    }
  
  PokemonNode * temp = NULL;
  temp = Pokedex -> pokemonHead;

  while (temp != NULL) {
    if (temp == NULL) {

    }
    
    int first = strcasecmp(temp -> pokemonName, name);
    if (first == 0) { 
      return temp;
    }

    else if (first > 0) {
      temp = temp -> leftPokemon;
    }

    else {
      temp = temp -> rightPokemon;
    }

  }
  return NULL;
}

// This displays the pokemon
void DisplayPokemonDetails(pokedex * Pokedex, char * name) {
  PokemonNode * pokemon = FindPokemon(Pokedex, name);

  printf("\nPokemon Name: %s\nType: %s\nAbility: %s\n", 
  pokemon -> pokemonName, pokemon -> pokemonType, pokemon -> pokemonAbility);
  
  return;

}



PlayerNode * NewPlayerNode (char * name) { 
  PlayerNode * newNode = NULL;
  newNode = malloc(sizeof(PlayerNode)); // Allocates memory to the size of the how many in player node.
  
  if (newNode != NULL) { // This statement finds player in memory.
    strcpy(newNode -> playerName, name);
    struct PlayerNode * nextPlayer = NULL; // if the if statement is comment out all players will be NULL.
  }

  return newNode; 
}

void AddPlayerToList(pokedex * Pokedex, char * name) {
  PlayerNode * newPlayer = NewPlayerNode(name);

  if (Pokedex -> playerHead == NULL) { 
    Pokedex -> playerHead = newPlayer;
    return;
  }

  else { 
    PlayerNode * temp = NULL;
    temp = Pokedex -> playerHead;
    while (temp != NULL) {

      if (temp -> nextPlayer == NULL) {

        temp -> nextPlayer = newPlayer;
        return;
      }

      else {
        temp = temp -> nextPlayer;
      }
    }
  }
  return;
}

PlayerNode * FindPlayer(pokedex * Pokedex, char * name) { 
  if (Pokedex -> playerHead == NULL) {

    return NULL;
  }

  PlayerNode * temp = Pokedex -> playerHead;
  while (temp != NULL) {

    int stringsEqual = strcasecmp(temp -> playerName, name);
    if (stringsEqual == 0) {

      return temp;
    }

    else {

      temp = temp -> nextPlayer;
    }
  }
  return NULL; 
}

// Displays player details
void DisplayPlayerDetails(pokedex * Pokedex, char *name) {
  PokemonNode * pokemon = FindPokemon(Pokedex, name);
  printf("\nPlayer Name: %s\n", name); // Find players name
  
  return;
}

// Optional: Displays pokemon to player
void PokemonToPlayer(pokedex * Pokedex, char * playerName, char * pokemonName) {
    PlayerNode * selectedPlayer = FindPlayer(Pokedex, playerName);
    printf("Player: %s\n", selectedPlayer -> playerName);
    printf("Pokemon: %s\n\n", pokemonName);  
    //printf("-----------------------|\n\n");

    return;
}

void DisplayHeadPokeNode(pokedex * Pokedex, char * pokemonName) {
  printf("Head node of Pokemon: %s\n", Pokedex -> pokemonHead -> pokemonName);

}

void DisplayHeadNameNode(pokedex * Pokedex, char * playerName) {
  printf("Head node of Player: %s\n", Pokedex -> playerHead -> playerName);

}