#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct PokemonNode 
{
  char pokemonName[11];
  char pokemonType[10];
  char primaryAbility[27];

  // Binary tree structure
  struct PokemonNode *leftPokemon, *rightPokemon;

} PokemonNode;

typedef struct CaughtPokemonNode
{
  char *pokemonName;
  struct CaughtPokemonNode *nextCaughtPokemon;
} CaughtPokemonNode;

typedef struct PlayerNode 
{ 
  char playerName[30];

  // Linked list structure
  CaughtPokemonNode *firstPokemonCaught;
  struct PlayerNode *nextPlayer;
} PlayerNode;

typedef struct pokedex 
{ 
  struct PokemonNode *pokemonHead;
  struct PlayerNode *playerHead;
} pokedex;

pokedex *NewPokedex ();
PokemonNode *NewPokemonNode(char *name, char *type, char *ability);
void AddPokemonToList( pokedex *Pokedex, char *name, char *type, char *ability);
void displayPokemonDetails(pokedex *Pokedex, char *name);
PokemonNode *FindPokemon( pokedex *Pokedex, char *name );
void AddPlayerToList(pokedex *Pokedex, char *name);
PlayerNode *FindPlayer(pokedex *Pokedex, char *name);
CaughtPokemonNode *NewCaughtPokemonNode(pokedex *Pokedex, char *pokemonName);
void DisplayPlayerDetails(pokedex *Pokedex, char *name);
int getCaughtPokemonLength(PlayerNode *player);
void AddPokemonToPlayer(pokedex *Pokedex, char *playerName, char *pokemonName);

int main(void) 
{
  pokedex *mainPokedex = NewPokedex();


  // Add Players to the pokedex
  AddPlayerToList(mainPokedex, "Ash");
  AddPlayerToList(mainPokedex, "Misty");
  AddPlayerToList(mainPokedex, "Dawn");

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
  displayPokemonDetails(mainPokedex, "Bulbasaur");
    displayPokemonDetails(mainPokedex, "Charmander");
    displayPokemonDetails(mainPokedex, "Squirtle");
    displayPokemonDetails(mainPokedex, "Butterfree");
    displayPokemonDetails(mainPokedex, "Pidgey");
    displayPokemonDetails(mainPokedex, "Vgnomoth");
    displayPokemonDetails(mainPokedex, "Poliwag");
    displayPokemonDetails(mainPokedex, "Psyduck");

  printf("\n----------------------------------------------|");

  // Testing the display player function
  DisplayPlayerDetails(mainPokedex, "Ash");
  DisplayPlayerDetails(mainPokedex, "Misty");
  DisplayPlayerDetails(mainPokedex, "Dawn");
  DisplayPlayerDetails(mainPokedex, "NULL_VALUE");

  //mainPokedex = realloc(mainPokedex, sizeof(pokedex) * 2);
  printf("\n----------------------------------------------|\n\n");
  AddPokemonToPlayer(mainPokedex, "Ash", "Charmander");
    AddPokemonToPlayer(mainPokedex, "Ash", "Pidgey");
    AddPokemonToPlayer(mainPokedex, "Ash", "Zoroark");
    AddPokemonToPlayer(mainPokedex, "Misty", "Squirtle");
    AddPokemonToPlayer(mainPokedex, "Dawn", "Poliwag");
    AddPokemonToPlayer(mainPokedex, "Dawn", "Pidgey");
  //AddPokemonToPlayer
  NewCaughtPokemonNode(mainPokedex, "Charizard");
  NewCaughtPokemonNode(mainPokedex, "Pichu");
  NewCaughtPokemonNode(mainPokedex, "Blastoise");
  PokemonNode *PokemonHead = mainPokedex -> pokemonHead;
  NewCaughtPokemonNode(mainPokedex, "Eternatus");
  printf("\nGot here 0.1\n");
  mainPokedex -> pokemonHead = PokemonHead;
  NewCaughtPokemonNode(mainPokedex, "Pichu");
  mainPokedex -> pokemonHead = PokemonHead;
  NewCaughtPokemonNode(mainPokedex, "Blastoise");*/

  return 0;
}

pokedex *NewPokedex ()
{
  pokedex *newPokedex = NULL;
  newPokedex = (pokedex*)malloc(sizeof(pokedex));
  newPokedex -> pokemonHead = NULL;
  newPokedex -> playerHead = NULL;
  free(newPokedex);

  return newPokedex;
}

PokemonNode *NewPokemonNode(char *name, char *type, char *ability) 
{ 
  PokemonNode *newNode = NULL;

  newNode = (PokemonNode*)malloc(sizeof(PokemonNode));

  if (newNode != NULL) 
  {
    strcpy(newNode -> pokemonName, name);
    strcpy(newNode -> pokemonType, type);
    strcpy(newNode -> primaryAbility, ability);
    newNode -> leftPokemon = newNode -> rightPokemon = NULL; 
  }

  return newNode;
}

void AddPokemonToList( pokedex *Pokedex, char *name, char *type, char *ability) 
{
  PokemonNode *new_pokemon = NewPokemonNode(name, type, ability);
  if (Pokedex -> pokemonHead == NULL) 
  {
    Pokedex -> pokemonHead = new_pokemon;
    return;
  }
  else 
  {
    PokemonNode *temp = NULL;
    temp = malloc(sizeof(PokemonNode));
    temp = Pokedex -> pokemonHead;
    bool inPlace = false;
    while (!inPlace) 
    {
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

PokemonNode *FindPokemon( pokedex *Pokedex, char *name )
{
  
  if (Pokedex -> pokemonHead == NULL)
    { 
      
      return NULL;
    }
  
  PokemonNode *temp = NULL;
  temp = Pokedex -> pokemonHead;
  
  if (Pokedex -> pokemonHead -> pokemonName == 0) { printf("IS NULL"); }
  printf("Current Pokedex Pokemon Head : %s\n\n", Pokedex -> pokemonHead -> pokemonName);
  while (temp != NULL)
  {
    if (temp == NULL)
    {

    }
    printf("Current Pokedex Pokemon Head : %s\n\n", Pokedex -> pokemonHead -> pokemonName);
    int alphaFirst = strcasecmp(temp -> pokemonName, name);
    if (alphaFirst == 0) 
    { 
      return temp;
    }
    else if (alphaFirst > 0) 
    {
      temp = temp -> leftPokemon;
    }
    else
    {
      temp = temp -> rightPokemon;
    }

  }
  return NULL;
}

void displayPokemonDetails(pokedex *Pokedex, char *name) 
{
  PokemonNode *pokemon = FindPokemon(Pokedex, name);
  if (pokemon == NULL) 
  { 
    printf("\nCould not find Pokemon by name : %s\n", name); 
    return; 
  }
  printf("\nPokemon Name : %s\nPokemon Type : %s\nPokemon Primary Ability : %s\n", 
  pokemon -> pokemonName, pokemon -> pokemonType, pokemon -> primaryAbility);
  return;
}

PlayerNode *NewPlayerNode (char *name) 
{ 
  PlayerNode *newNode = NULL;
  newNode = malloc(sizeof(PlayerNode));
  
  if (newNode != NULL) 
  {
    strcpy(newNode -> playerName, name);
    CaughtPokemonNode *firstPokemonCaught = NULL;
    struct PlayerNode *nextPlayer = NULL;
  }

  return newNode; 
}

void AddPlayerToList(pokedex *Pokedex, char *name) 
{
  PlayerNode *newPlayer = NewPlayerNode(name);
  if (Pokedex -> playerHead == NULL)
  { 
    Pokedex -> playerHead = newPlayer;
    return;
  }
  else 
  { 
    PlayerNode *temp = NULL;
    temp = Pokedex -> playerHead;
    while (temp != NULL) 
    {
      if (temp -> nextPlayer == NULL)
      {
        temp -> nextPlayer = newPlayer;
        return;
      }
      else
      {
        temp = temp -> nextPlayer;
      }
    }
  }
  return;
}

PlayerNode *FindPlayer(pokedex *Pokedex, char *name) 
{ 
  if (Pokedex -> playerHead == NULL)
  {
    return NULL;
  }

  PlayerNode *temp = Pokedex -> playerHead;
  while (temp != NULL)
  {
    int stringsEqual = strcasecmp(temp -> playerName, name);
    if (stringsEqual == 0)
    {
      return temp;
    }
    else
    {
      temp = temp -> nextPlayer;
    }
  }
  return NULL; 
}

// Displays player details
void DisplayPlayerDetails(pokedex *Pokedex, char *name)
{
  PlayerNode *player = FindPlayer(Pokedex, name);
  if (player == NULL)
  {
    printf("\nCould not find player by name : %s\n", name);
    return;
  }
  printf("\n\nPlayer Name : %s\n\nCaught Pokemon :", name);
  CaughtPokemonNode *temp = player -> firstPokemonCaught;
  if (player -> firstPokemonCaught == NULL)
  {
    printf("\nNo Pokemon caught yet.\n");
  }
  return;
  /*PlayerNode *player = FindPlayer(Pokedex, name);
  return;*/
}

void AddPokemonToPlayer(pokedex *Pokedex, char *playerName, char *pokemonName)
  {
    printf("Found pokemonHead : %s\n", Pokedex -> pokemonHead -> pokemonName);
    PlayerNode *selectedPlayer = FindPlayer(Pokedex, playerName);
    printf("Found Player : %s\n", selectedPlayer -> playerName);
    PokemonNode *selectedPokemon = FindPokemon(Pokedex, pokemonName);
    printf("Found Pokemon : %s\n", selectedPokemon -> pokemonName);
    Create new caught pokemon linked list node
    CaughtPokemonNode *newCaughtPokemon = NULL;
     //allocate the node some memory
    newCaughtPokemon = (CaughtPokemonNode*)malloc(sizeof(CaughtPokemonNode));

    if (newCaughtPokemon != NULL)
    {
     printf("ptr string : %s\n", newCaughtPokemon -> pokemonName);
      char *pokemonName_ptr = selectedPokemon -> pokemonName;
      newCaughtPokemon -> pokemonName = pokemonName_ptr;
      free(newCaughtPokemon);
    }

    printf("ptr string : %s\n", newCaughtPokemon -> pokemonName);
    if (selectedPlayer -> firstPokemonCaught == NULL)
    {
      printf("Got here!!!!\n");
      selectedPlayer -> firstPokemonCaught = newCaughtPokemon;
    }
    else
    {
      CaughtPokemonNode *temp = NULL;
      temp = selectedPlayer -> firstPokemonCaught;
      while (temp -> nextCaughtPokemon != NULL)
      {
        if (temp -> nextCaughtPokemon == NULL)
        {
          printf("Got here!\n");
          temp -> nextCaughtPokemon = newCaughtPokemon;
          //return;
          break;
        }
        printf("Current node : %s", temp -> pokemonName);
        
        temp = temp -> nextCaughtPokemon;
      
        printf("Current node : %s", temp -> pokemonName);
      }
    }
    printf("ptr string : %s\n", newCaughtPokemon -> pokemonName);
    printf("caught pokemon name : %s\n", newCaughtPokemon -> pokemonName);
    printf("first caught pokemon : %s\n\n", selectedPlayer -> firstPokemonCaught -> pokemonName);
    
    return;
  }

