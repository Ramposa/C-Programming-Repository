#include <stdio.h>

int main () {

  int var = 20;       
  int *ip1 = &var;    
  int *ip2;
  return 0;
}

// Exercise Tasks
// 1 Run the code. What is ip2 pointing at? Is this safe?
// 2 ip2 might be pointing at an integer. Print out the value ip2 is pointing at as an integer
// 3 Initialise ip2 to NULL. Comment out the line printing out ip2 as an integer. Run the code.
// 4 Uncomment the line you just commented out and run the code. Why doe s the code crash?
// 5 Add checks before trying to use ip1 or ip2, test to make sure they are not NULL before accessing them.