#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

// Linked List

/*

We need:
    * pokemonList
       * pokemonName [CHAR] [20];
       * pokemonType [CHAR] [20];
       * pokemonAbility [CHA] [20];
    * playerList
       * player
    * Linked list style
    * Voids
       * AddPokemonToList
       * displayPokemonDetails
       * AddPlayerToList
       * DisplayPlayerDetails
       * AddPokemonToPlayer
    * s

*/

typedef struct PokemonNode {
    char pokemonName[20];
    char pokemonType[20];
    char pokemonAbility[30];

    // Bianry tree structure
    struct PokemonNode * leftPokemon, * rightPokemon;

} PokemonNode;


typedef struct CaughtPokemonNode {
    char * pokemonName;
    struct CaughtpokemonNode * nextCaughtPokemon;

} CaughtPokemonNode;


typedef struct PlayerNode {
    char playerName[30];

    CaughtPokemonNode * firstPokemonCaught;
    struct PlayerNode * nextPlayer;

} PlayerNode;


typedef struct pokedex {
    struct PokemonNode * pokemonHead; // Define the head of the node
    struct PlayerNode * playerHead;

} pokedex;

pokedex * NewPokedex();
PokemonNode * NewPokemonNode(char * name, char * type, char * ability);
void AddPokemonToList(pokedex * Pokedex, char * name, char * type, char * ability);
void displayPokemonDetail(pokedex * Pokedex, char * name);

PokemonNode * FinePokemon(pokedex * Pokedex, char * name);
void AddPlayerToList(pokedex * Pokedex, char * name);

PlayerNode * FindPokemon(pokedex * Pokedex, char * name);

CaughtPokemonNode * NewCaughtPokemon(pokedex * Pokedex, char * name);
void DisplayPlayerDetails(pokedex *Pokedex, char *name);
int getCaughtPokemonLength(PlayerNode *player);
void AddPokemonToPlayer(pokedex *Pokedex, char *playerName, char *pokemonName);


int main(void) {
    pokedex * mainPokedex = NewPokedex();

    // Add players to the pokedex.
    AddPlayerToList(mainPokedex, "Ash");
    AddPlayerToList(mainPokedex, "Misty");
    AddPlayerToList(mainPokedex, "Dawn");

    // Add Pokemon to Pokedex.
    AddPokemonToList(mainPokedex, "Bulbasaur", "Grass", "Overgrow"); 
    AddPokemonToList(mainPokedex, "Charmander", "Fire", "Blaze");
    AddPokemonToList(mainPokedex, "Squirtle", "Water", "Torrent");
    AddPokemonToList(mainPokedex, "Butterfree", "Bug", "Compound Eyes");
    AddPokemonToList(mainPokedex, "Pidgey", "Normal", "Tangled Feet");
    AddPokemonToList(mainPokedex, "Vgnomoth", "Bug", "Shield Dust");
    AddPokemonToList(mainPokedex, "Poliwag", "Water", "Water Absorb");
    AddPokemonToList(mainPokedex, "Psyduck", "Water", "Damp");

    // Stores in main pokedex
    FindPokemon(mainPokedex, "Bulbasaur");
    FindPokemon(mainPokedex, "Charmander");
    FindPokemon(mainPokedex, "Squirtle");
    FindPokemon(mainPokedex, "Butterfree");
    FindPokemon(mainPokedex, "Pidgey");
    FindPokemon(mainPokedex, "Vgnomoth");
    FindPokemon(mainPokedex, "Poliwag");
    FindPokemon(mainPokedex, "Psyduck");

    

    AddPokemonToPlayer(mainPokedex, "Ash", "Charmander");
    AddPokemonToPlayer(mainPokedex, "Ash", "Pidgey");
    AddPokemonToPlayer(mainPokedex, "Ash", "Zoroark");
    AddPokemonToPlayer(mainPokedex, "Misty", "Squirtle");
    AddPokemonToPlayer(mainPokedex, "Dawn", "Poliwag");
    AddPokemonToPlayer(mainPokedex, "Dawn", "Pidgey");

    return 0;

}

pokedex * NewPokedex() {
    pokedex *newPokedex = NULL;
    newPokedex = (pokedex*)malloc(sizeof(pokedex)); // malloc allocates 50 bites of memory
    newPokedex -> pokemonHead = NULL;
    newPokedex -> playerHead = NULL;
    free(newPokedex);

    return newPokedex;

} //malloc(sizeof) - basically allocates enough memory to hold chars.

PokemonNode * NewPokemonNode(char * name, char * type, char * ability) {
    PokemonNode *newNode = NULL;

    newNode = (PokemonNode*)malloc(sizeof(PokemonNode));

    if (newNode != NULL) {
        strcpy(newNode -> pokemonName, name);
        strcpy(newNode -> pokemonType, type);
        strcpy(newNode -> pokemonAbility, ability);
        newNode -> leftPokemon = newNode -> rightPokemon = NULL; 
    }

    return newNode;

}

void AddPokemonToList( pokedex *Pokedex, char *name, char *type, char *ability) {
    PokemonNode *new_pokemon = NewPokemonNode(name, type, ability);
    if (Pokedex -> pokemonHead == NULL) {
        Pokedex -> pokemonHead = new_pokemon;
        return;
    }

    else {
        PokemonNode *temp = NULL;
        temp = Pokedex -> pokemonHead;
        bool inPlace = false;

        while (!inPlace) {
      int alphaFirst = strcasecmp(temp -> pokemonName, name);
      if (alphaFirst > 0) 
      {
        if (temp -> leftPokemon != NULL) 
        { 
          temp = temp -> leftPokemon;
        }
        else 
        {
          temp -> leftPokemon = new_pokemon;
          break;
        }
      }
      else 
      {
        if (temp -> rightPokemon != NULL) 
        {
          temp = temp -> rightPokemon;
        }
        else 
        {
          temp -> rightPokemon = new_pokemon;
          break;
        }
      }
    }
  }
  return;

}

// Displays pokemon and its details
void displayPokemonDetails(pokedex *Pokedex, char *name) {

  PokemonNode *pokemon = FindPokemon(Pokedex, name); 

  printf("\nPokemon Name : %s\nPokemon Type : %s\nPokemon Ability : %s\n", 
  pokemon -> pokemonName, pokemon -> pokemonType, pokemon -> pokemonAbility);
  
  return;

}

PlayerNode *NewPlayerNode (char *name) { 

  PlayerNode *newNode = NULL;
  newNode = malloc(sizeof(PlayerNode));
  
  if (newNode != NULL) {

    strcpy(newNode -> playerName, name);
    CaughtPokemonNode *firstPokemonCaught = NULL;
    struct PlayerNode *nextPlayer = NULL;
  }

  return newNode; 

}

void AddPlayerToList(pokedex *Pokedex, char *name) {
  PlayerNode *newPlayer = NewPlayerNode(name);
  if (Pokedex -> playerHead == NULL) { 

    Pokedex -> playerHead = newPlayer;
    return;
  }
  
  else { 

    PlayerNode *temp = NULL;
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

PlayerNode *FindPlayer(pokedex *Pokedex, char *name) { 

  if (Pokedex -> playerHead == NULL) {

    return NULL;
  }

  PlayerNode *temp = Pokedex -> playerHead;
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
void DisplayPlayerDetails(pokedex *Pokedex, char *name) {

  PokemonNode *pokemon = FindPokemon(Pokedex, name);
  printf("\n\nPlayer Name: %s\n", name); // Find players name
  
  return;

}

void AddPokemonToPlayer(pokedex *Pokedex, char *playerName, char *pokemonName) {
    
    PlayerNode *selectedPlayer = FindPlayer(Pokedex, playerName);
    printf("Found Player : %s\n", selectedPlayer -> playerName);
    printf("Caught Pokemon :%s\n\n", pokemonName);  

    return;

  }