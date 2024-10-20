#include <stdio.h>

int update_balance(int balance[], int id, int transition_type, float amount) {
  // Withdrawal case
  if (transition_type == 1) {
    if (balance[id] >= amount) {
      balance[id] -= amount; // Correct subtraction
      printf("Withdrawal successful\n");
    } else {
      printf("Insufficient balance\n");
      return 0; // Failure
    }
  }
  // Deposit case
  else if (transition_type == 2) {
    balance[id] += amount; // Correct addition
    printf("Deposit successful\n");
  }
  // Invalid transition type
  else {
    printf("Invalid transition type\n");
    return 0; // Failure
  }

  return 1; // Success
}

int main() {
  int balances[5];

  // Input balances
  for (int i = 0; i < 5; i++) {
    printf("Enter the balance of the client %d: ", i + 1);
    scanf("%d", &balances[i]);
  }

  int id;
  int transition_type;
  float amount;

  // Get transaction details
  printf("Customer ID: ");
  scanf("%d", &id);
  printf("Transition type (1 for Withdrawal, 2 for Deposit): ");
  scanf("%d", &transition_type);
  printf("Transition amount: ");
  scanf("%f", &amount);

  // Update balance
  update_balance(balances, id, transition_type, amount);

  return 0;
}
